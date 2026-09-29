
:: Call build.bat to generate cmake files and executable
call .\build.bat

:: Get build info to find the name of the program
for /f "tokens=1,* delims==" %%A in (build\build_info.txt) do (
    set "%%A=%%B"
)

"%EXECUTABLE_PATH%"