@echo off

:label

IF EXIST build (
    echo Deleting the build folder...
    rmdir /s /q build
    pause
)


echo Creating the build folder...
mkdir build

cd build
cmake -G "MinGW Makefiles" ..
cmake --build . --config Release
ctest --output-on-failure
cmake --install .

pause

cd ../

goto label
