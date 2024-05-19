# AAO Project.
This Project contains various algorithms and tests for verifying their functionality.
The project is configured to use CMake and supports multiple compilers and platforms.
## Directory Structure.
```
.
├── CMakeLists.txt
├── CMakeSettings.json
├── LICENSE
├── out
│   ├── build
│   │   └── <build configurations>
│   └── install
│       └── <install configurations>
└── src
    └── tests
        └── does_it_run_test.cpp
```

## Prerequisites

- **CMake**: Ensure CMake is installed. You can download it from [here](https://cmake.org/download/).
- **Ninja**: Ensure Ninja build system is installed. You can download it from [here](https://ninja-build.org/).
- **Compilers**: Depending on your platform, you will need appropriate compilers:
  - **Windows**: Visual Studio (MSVC)
  - **Linux**: GCC or Clang

## Compiling on Different Platforms

### Windows (MSVC)

1. **Install Visual Studio** with C++ development tools.
2. **Clone the repository**:
    ```sh
    git clone https://github.com/riken127/aao-uflp.git
    cd aao-uflp
    ```
3. **Configure the project**:
    - Open the project in Visual Studio.
    - Visual Studio will detect `CMakeLists.txt` and configure the project using `CMakeSettings.json`.
4. **Build the project**:
    - Select the desired configuration (e.g., `x64-Debug-MSVC`).
    - Build the project (Build -> Build All).

### Linux (GCC)

1. **Install GCC and Ninja**:
    ```sh
    sudo apt-get install g++ ninja-build
    ```
2. **Clone the repository**:
    ```sh
    git clone https://github.com/riken127/aao-uflp.git
    cd aao-uflp
    ```
3. **Create a build directory** and navigate into it:
    ```sh
    mkdir -p out/build/x64-Debug-GCC
    cd out/build/x64-Debug-GCC
    ```
4. **Run CMake** to configure the project:
    ```sh
    cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++ ../../..
    ```
5. **Build the project**:
    ```sh
    ninja
    ```

### Linux (Clang)

1. **Install Clang and Ninja**:
    ```sh
    sudo apt-get install clang ninja-build
    ```
2. **Clone the repository**:
    ```sh
    git clone https://github.com/riken127/aao-uflp.git
    cd aao-uflp
    ```
3. **Create a build directory** and navigate into it:
    ```sh
    mkdir -p out/build/x64-Debug-Clang
    cd out/build/x64-Debug-Clang
    ```
4. **Run CMake** to configure the project:
    ```sh
    cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ ../../..
    ```
5. **Build the project**:
    ```sh
    ninja
    ```

## Running Tests

After building the project, you can run the tests using CTest.

1. **Navigate to the build directory**:
    ```sh
    cd out/build/x64-Debug-GCC  # Or the respective build directory for your configuration
    ```
2. **Run the tests**:
    ```sh
    ctest -VV
    ```

## License

This project is licensed under the terms of the [GPL License](LICENSE).
