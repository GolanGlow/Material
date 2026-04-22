# CMake compile & run tests

### Git submodules

Ensure you have the submodules checkout out:

```shell
# this populates inlude/ with the repo content from https://sgit.iue.tuwien.ac.at/360062/include
git submodule update --init --recursive
```

### All at once

```shell
rm -rf build output .cache
cmake --preset debug
cmake --build build
ctest --test-dir build --output-on-failure
```

### Individual builds and tests

```shell
rm -rf build output .cache
cmake --preset debug
cmake --build build --target task1 && ctest --test-dir build --output-on-failure -R "^task1$"
cmake --build build --target task2 && ctest --test-dir build --output-on-failure -R "^task2$"
cmake --build build --target task3 && ctest --test-dir build --output-on-failure -R "^task3$"
cmake --build build --target task3 && ctest --test-dir build --output-on-failure -R "^task3py$"
```

### VSCode

**Debug using GUI steps (code-server/vscode)**

- press `F1` > type `CMake: Select Configure Preset` -> select `debug`
- press `F1` > type `CMake: Delete Cache and Reconfigure`
- press `F1` > type `CMake: Build`
- press `F1` > type `CMake: Run Tests`
- press `F1` > type `CMake: Set Build Target` -> select `all` or a single target
- press `F1` > type `Testing: Focus on Test Explorer View` -> run/debug any of the tests via buttons

# Direct compile & run

```shell
rm -rf build .cache
mkdir -p build output
g++ -std=c++20 src/task1.main.cpp -o build/task1 && ./build/task1
g++ -std=c++20 src/task2*.cpp -o build/task2     && ./build/task2
g++ -std=c++20 -Iinclude src/task2.cpp src/task3*.cpp -o build/task3 && ./build/task3
```