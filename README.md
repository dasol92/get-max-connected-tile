## 실행 환경
- Windows 11
- VS code with MSVC 2022 Community
- CMake 3.25.2

## 빌드 방법
```
mkdir build
cd build
cmake ..
cmake --build . --config Release -j 
```

## 실행 방법
1. main 프로그램
```
cd build/Release
.\max_connected_num.exe ..\..\sample_good.txt
...
.\max_connected_num.exe ..\..\sample_good.txt
```

2. 단위 테스트
```
cd build
ctest
```