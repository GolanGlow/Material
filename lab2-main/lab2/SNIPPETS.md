# CMake compile & run tests

### All at once

```shell
rm -rf build .cache
cmake --preset debug
cmake --build build
ctest --test-dir build --output-on-failure
```

### Individual builds and tests

```shell
rm -rf build .cache
cmake --preset debug
cmake --build build --target taskA && ctest --test-dir build --output-on-failure -R "^taskA$"
cmake --build build --target taskB && ctest --test-dir build --output-on-failure -R "^taskB$"
cmake --build build --target taskC && ctest --test-dir build --output-on-failure -R "^taskC$"
```

### VSCode

**Run/Debug using GUI steps (code-server/vscode)**

- press `F1` > type `CMake: Select Configure Preset` -> select `debug`
- press `F1` > type `CMake: Delete Cache and Reconfigure`
- press `F1` > type `CMake: Set Build Target` -> select `all` or a single target
- press `F1` > type `CMake: Build`
- press `F1` > type `Testing: Focus on Test Explorer View` -> **run/debug** any of the tests via buttons

# Direct compile & run

```shell
rm -rf build .cache
mkdir -p build
g++ -std=c++20 src/taskA.cpp -o build/taskA && ./build/taskA
g++ -std=c++20 src/taskB.cpp -o build/taskB && ./build/taskB
g++ -std=c++20 src/taskC.cpp -o build/taskC && ./build/taskC
```
