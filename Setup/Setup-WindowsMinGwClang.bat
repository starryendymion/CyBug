@echo off

pushd ..
Vendor\Binaries\Premake\Windows\premake5.exe --cc=clang --file=Build.lua gmake2
popd
pause