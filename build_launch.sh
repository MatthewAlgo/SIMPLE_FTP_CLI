#!/bin/bash
bash build.sh


echo "Dissasembling Binary..."

objdump --disassemble-all Program > Dissassembled.obj

# read VAR
if [[ "$1" == "Build" ]]; then
    echo "Program has been built and is ready to be run";
elif [[ "$1" == "Launch" ]]; then
    echo "Lauching binary..."
    ./Program
elif [[ -z "$1" ]]; then
    echo "No command given, your program has been built";
else
    echo "No command given, your program has been built"
fi

exit
# EXECUTION

