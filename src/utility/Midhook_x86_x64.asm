; This file is supposed to be compiled with nasm to get the shellcode as output from it, this is the 64 bit configuration
[BITS 64]

; First 32 bytes reserved for the offsets to variables
contextPtrOffset    dq (contextPtr - start)     ; Offset of the thread context address in the shellcode
thisPtrOffset       dq (thisPtr - start)        ; Offset of the this pointer of the MidHook object in the shellcode
callWrapperOffset   dq (callWrapper - start)    ; Offset of the call wrapper address in the shellcode
trampolineOffset    dq (trampoline - start)     ; Offset of the trampoine address in the shellcode

align 16                ; Align the code to 16
start:
; Save the stack position
;mov rspBack, rsp

; Store the thread context
push rax
mov rax, strict qword [rel contextPtr]

; Integer registers
mov qword [rax + 8], rbx
mov qword [rax + 16], rcx
mov qword [rax + 24], rdx
mov qword [rax + 40], rbp
mov qword [rax + 48], rsi
mov qword [rax + 56], rdi
mov qword [rax + 64], r8
mov qword [rax + 72], r9
mov qword [rax + 80], r10
mov qword [rax + 88], r11
mov qword [rax + 96], r12
mov qword [rax + 104], r13
mov qword [rax + 112], r14
mov qword [rax + 120], r15

; Save the original RSP
add rsp, 8                      ; Because we pushed RAX (8 bytes) ourselves
mov qword [rax + 32], rsp
sub rsp, 8

; Flags... it's hopeless
push rbx                        ; Store RBX because we're gonna put the flags in it
pushfq                          ; Push the flags on stack because we can't directly read the flags register
pop rbx                         ; Pop the flags we just pushed into the RBX register to copy it to our context struct
mov [rax + 128], rbx            ; Copy the RBX flag which now contains the flags into our struct
pop rbx                         ; Restore the RBX register that we saved on stack

; Vector registers
movaps [rax + 144], xmm0
movaps [rax + 160], xmm1
movaps [rax + 176], xmm2
movaps [rax + 192], xmm3
movaps [rax + 208], xmm4
movaps [rax + 224], xmm5
movaps [rax + 240], xmm6
movaps [rax + 256], xmm7
movaps [rax + 272], xmm8
movaps [rax + 288], xmm9
movaps [rax + 304], xmm10
movaps [rax + 320], xmm11
movaps [rax + 336], xmm12
movaps [rax + 352], xmm13
movaps [rax + 368], xmm14
movaps [rax + 384], xmm15

; Store RAX last, the origina RAX is stored on stack, we copy it from there
push rbx
mov rbx, qword [rsp]
mov qword [rax], rbx
pop rbx

; Restore RAX
pop rax

;mov [rel rspBack], rsp  ; Store the stack pointer to restore after we are done

; Align the stack to 16
sub rsp, 16
and rsp, -16

sub rsp, 0x20           ; Allocate 32 bytes of shadow space

mov rcx, [rel thisPtr]  ; Pass the this pointer as first argument

call [rel callWrapper]  ; Call the call wrapper

;add rsp, 0x20           ; Deallocate the shadow space

; Restore the thread context
mov rax, strict qword [rel contextPtr]

; Integer registers
mov rbx, qword [rax + 8]
mov rcx, qword [rax + 16]
mov rdx, qword [rax + 24]
mov rsp, qword [rax + 32]
mov rbp, qword [rax + 40]
mov rsi, qword [rax + 48]
mov rdi, qword [rax + 56]
mov r8,  qword [rax + 64]
mov r9,  qword [rax + 72]
mov r10, qword [rax + 80]
mov r11, qword [rax + 88]
mov r12, qword [rax + 96]
mov r13, qword [rax + 104]
mov r14, qword [rax + 112]
mov r15, qword [rax + 120]

; Flags
push rbx                        ; Store RBX away
mov rbx, qword [rax + 128]      ; Load the flags into RBX
push rbx                        ; Push RBX which contains flags onto stack
popfq                           ; Pop the flags we just pushed
pop rbx                         ; Restore RBX

; Vector registers
movaps xmm0, [rax + 144]
movaps xmm1, [rax + 160]
movaps xmm2, [rax + 176]
movaps xmm3, [rax + 192]
movaps xmm4, [rax + 208]
movaps xmm5, [rax + 224]
movaps xmm6, [rax + 240]
movaps xmm7, [rax + 256]
movaps xmm8, [rax + 272]
movaps xmm9, [rax + 288]
movaps xmm10, [rax + 304]
movaps xmm11, [rax + 320]
movaps xmm12, [rax + 336]
movaps xmm13, [rax + 352]
movaps xmm14, [rax + 368]
movaps xmm15, [rax + 384]

; Restore RAX last
mov rax, strict qword [rax]

; Restore the rsp
;mov rsp, rspBack  

jmp [rel trampoline]    ; Execute the stolen bytes

align 16                ; Make sure the variables are aligned to 16
;rspBack     dq 0        ; Where rsp is stored to be restored later
thisPtr     dq 0        ; Where the this pointer for the MidHook object is stored
contextPtr  dq 0        ; Where the pointer is stored to where we have stored the thread context
callWrapper dq 0        ; Where the pointer to where we want to call is stored
trampoline  dq 0        ; Where the pointer to the trampoline is stored
