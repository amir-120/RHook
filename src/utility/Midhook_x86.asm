; This file is supposed to be compiled with nasm to get the shellcode as output from it, this is the 32 bit configuration
[BITS 32]

; First 16 bytes reserved for the offsets to variables
contextPtrOffset    dd (contextPtr - start)      ; Offset of the thread context address in the shellcode
thisPtrOffset       dd (thisPtr - start)        ; Offset of the this pointer of the MidHook object in the shellcode
callWrapperOffset   dd (callWrapper - start)    ; Offset of the call wrapper address in the shellcode
trampolineOffset    dd (trampoline - start)     ; Offset of the trampoine address in the shellcode

align 16                ; Align the code to 16
start:
; Store the stack pointer to restore after we are done
;mov espBack, esp 

; Store the thread context
push eax
mov eax, dword [contextPtr]

; Integer registers
mov dword [eax + 4], ebx
mov dword [eax + 8], ecx
mov dword [eax + 12], edx
mov dword [eax + 16], esi
mov dword [eax + 20], edi
mov dword [eax + 28], ebp

; Save the original ESP
add esp, 4                      ; Because we pushed EAX (4 bytes) ourselves
mov dword [eax + 24], esp
sub esp, 4

; Flags... it's hopeless
push ebx                        ; Store EBX because we're gonna put the flags in it
pushfd                          ; Push the flags on stack because we can't directly read the flags register
pop ebx                         ; Pop the flags we just pushed into the EBX register to copy it to our context struct
mov [eax + 32], ebx             ; Copy the EBX flag which now contains the flags into our struct
pop ebx                         ; Restore the EBX register that we saved on stack

; Vector registers
movaps [eax + 48], xmm0
movaps [eax + 64], xmm1
movaps [eax + 80], xmm2
movaps [eax + 96], xmm3
movaps [eax + 112], xmm4
movaps [eax + 128], xmm5
movaps [eax + 144], xmm6
movaps [eax + 160], xmm7

; Store EAX last, the origina EAX is stored on stack, we copy it from there
push ebx
mov ebx, dword [esp]
mov dword [eax], ebx
pop ebx

; Restore EAX
pop eax

sub esp, 0x04           ; Allocate 4 bytes for the this pointer parameter

; Pass the parameters right to left on stack
mov ecx, [rel thisPtr]  ; Load the first parameters
mov [esp], ecx          ; Put on stack

call [rel callWrapper]  ; Call the call wrapper

;add esp, 0x04           ; Clean up the stack

; Restore the thread context
mov eax, dword [rel contextPtr]

; Integer registers
mov ebx, dword [eax + 4]
mov ecx, dword [eax + 8]
mov edx, dword [eax + 12]
mov esi, dword [eax + 16]
mov edi, dword [eax + 20]
mov esp, dword [eax + 24]
mov ebp, dword [eax + 28]

; Flags
push eax                        ; Store EAX away
mov eax, dword [eax + 128]      ; Load the flags into EAX
push eax                        ; Push EAX which contains flags onto stack
popfd                           ; Pop the flags we just pushed
pop eax                         ; Restore EAX

; Vector registers
movaps [eax + 48], xmm0
movaps [eax + 64], xmm1
movaps [eax + 80], xmm2
movaps [eax + 96], xmm3
movaps [eax + 112], xmm4
movaps [eax + 128], xmm5
movaps [eax + 144], xmm6
movaps [eax + 160], xmm7

; Restore EAX last
mov eax, dword [eax]

; Restore ESP
;mov esp, espBack

jmp [rel trampoline]    ; Execute the stolen bytes

align 16                ; Make sure the variables are aligned to 16
;espBack     dd 0        ; Where esp is stored to be restored later
thisPtr     dd 0        ; Where the this pointer for the MidHook object is stored
contextPtr  dd 0        ; Where the pointer is stored to where we have stored the thread context
callWrapper dd 0        ; Where the pointer to where we want to call is stored
trampoline  dd 0        ; Where the pointer to the trampoline is stored
