mkdir "VS2022 x86"
cd "VS2022 x86"
cmake .. -G "Visual Studio 17 2022" -A Win32
::cmake --build . --config Release
cd ..
pause