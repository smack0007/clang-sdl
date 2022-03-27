@ECHO OFF

IF NOT EXIST "%~dp0bin" (
    MKDIR "%~dp0bin"
)

IF NOT EXIST "%~dp0bin\SDL2.dll" (
    COPY "%~dp0\ext\SDL\lib\x64\SDL2.dll" "%~dp0bin"
)

clang "%~dp0src\main.c" -g -std=c17 -o "%~dp0bin\Game.exe" "-I%~dp0\ext\khronos" "-I%~dp0\ext\SDL\include" "-L%~dp0\ext\SDL\lib\x64" "-Wl,/SUBSYSTEM:CONSOLE" -lSDL2main -lSDL2 -lShell32 -lOpenGL32
