!/usr/bin/env bash
echo $(uname)
if [ $(uname) == "Linux" ];then
    rm test 
    gcc main.c -o test
    ./test
elif [ $(uname) == "MINGW32_NT" ];then
    del test.exe
    gcc main.c -o test
    # test.exe
fi