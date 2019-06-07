@echo off

:: Ищем git. В комплекте git под Windows есть утилита tee и sed.
call %~dp0expand_path.bat GIT_FULL_PATH dp$Path: git.exe
if "%GIT_FULL_PATH%" == "" (
    echo Error. Git not found [%f0].
    exit 1
)

:: Ищем tee.
if not exist "%GIT_FULL_PATH%..\usr\bin\tee.exe" (
    echo Error. 'tee' not found [%f0].
    exit 1
)

:: Ищем sed.
if not exist "%GIT_FULL_PATH%..\usr\bin\sed.exe" (
    echo Error. 'sed' not found [%f0].
    exit 1
)

set Path=%GIT_FULL_PATH%..\usr\bin;%Path%

set DEBUG=
set OUTPUT_DIR=
set QDOC=
:parse_arguments
if "%~1" == "--help" (
    call :usage
    exit 0
) else if "%~1" == "-h" (
    call :usage
    exit 0
) else if "%~1" == "--setenv" (
    set "%~2"
    shift /1
) else if "%~1" == "--outputdir" (
    set OUTPUT_DIR=%~2
    shift /1
) else if "%~1" == "--qdoc" (
    set QDOC=%~2
    shift /1
) else if "%~1" == "--debug" (
    set DEBUG= --debug
) else (
    goto :main
)
shift /1
goto :parse_arguments

:main
if "%QDOC%" == "" (
    echo Error. QDOC not set. See --qdoc [%~f0].
    exit 1
)

if "%OUTPUT_DIR%" == "" (
    echo Error. Output dir not defined [%~f0].
    exit 1
)

call %~dp0expand_path.bat QDOCCONF, x, "%~1"

if not "%QDOCCONF%" == ".qdocconf" (
    echo Error. Unknown qdocconf file {%~1} [%~f0].
    exit 1
)

set QDOC_COMMAND=%QDOC%%DEBUG% --outputdir "%OUTPUT_DIR%" "%~1"

if not "%DEBUG%" == "" (
    echo QDOCCONF:     %QDOCCONF%
    echo OUTPUTDIR:    %OUTPUT_DIR%
    echo QDOC:         %QDOC%"
    echo QDOC_COMMAND: %QDOC_COMMAND%
)

%QDOC_COMMAND% 2>&1 | tee qdoc_log.txt | sed "/Undocumented return value/d" >&2

exit 0

:: ------------------------------------------------------------------------------------------------
:usage
echo Usage: %~nx0 [options] file.qdocconf
echo Options:
echo   --help or -h         - this screen
echo   --outputdir ^<dir^>    - specify output directory, overrides setting in qdocconf file
echo   --debug              - enable debug output
echo   --qdoc ^<command^>     - command for Qt qdoc application, may be 'call path\qdoc.bat'
echo   --setenv "NAME=VAL"  - set system environment variable NAME with value VAL
exit /b 0

