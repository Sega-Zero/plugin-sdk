call clear.bat

::build
brcc32.exe icon.rc icon.res
brcc32.exe form.rc form.res
dcc32.exe -B sample.dpr
if errorlevel 1 exit /b 1

call clear.bat "1"
exit /b 0
