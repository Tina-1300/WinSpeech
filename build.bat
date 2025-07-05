@echo off
setlocal

:start_loop

IF EXIST build (
    echo Deleting the build folder...
    rmdir /s /q build
    PAUSE
)

echo Creating the build folder...
mkdir build

pushd build
IF %ERRORLEVEL% NEQ 0 (
    echo Error: Unable to enter build folder.
    goto :end_script
)

echo CMake configuration...
cmake .. -DCMAKE_BUILD_TYPE=Release
IF %ERRORLEVEL% NEQ 0 (
    echo CMake configuration error.
    popd
    goto :end_script
)

echo Compilation CMake...
cmake --build .
IF %ERRORLEVEL% NEQ 0 (
    echo CMake compilation error.
    popd
    goto :end_script
)

echo Installation CMake...
cmake --install .
IF %ERRORLEVEL% NEQ 0 (
    echo CMake installation error.
    popd
    goto :end_script
)

popd

PAUSE
goto :start_loop

:end_script
PAUSE
endlocal