@echo off
del /F /Q *.~dsk 2>nul
del /F /Q dcu\*.dcu 2>nul
del /F /Q *.dcu 2>nul
del /F /Q *.ddp 2>nul
del /F /Q *.~pas 2>nul
del /F /Q *.~ddp 2>nul
del /F /Q *.~dpr 2>nul
del /F /Q *.~dfm 2>nul
del /F /Q *.~inc 2>nul
del /F /Q *.~rc 2>nul
rd /S /Q __history 2>nul