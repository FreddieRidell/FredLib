#!/bin/zsh

clang-format -i Inc/**/*.hpp Src/**/*.cpp Test/**/*.cpp -style=file -dump-config
