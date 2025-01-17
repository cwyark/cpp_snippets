# My C and CPP Snippets

Install required packages using cnonan

```bash
conan install . --output-folder=build --build=missing
```

Construct a cmake build folder

```bash
cmake -Bbuild -H. -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake  -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
```

Build the whole project

```bash
cmake --build build

```
