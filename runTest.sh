#!/bin/sh


touch > output.txt

./a.out Units/Unit1.json Units/Unit2.json >> output.txt
./a.out Units/Unit1.json Units/Unit3.json >> output.txt
./a.out Units/Unit2.json Units/Unit1.json >> output.txt
./a.out Units/Unit2.json Units/Unit3.json >> output.txt
./a.out Units/Unit3.json Units/Unit1.json >> output.txt
./a.out Units/Unit3.json Units/Unit2.json >> output.txt

if cmp -s output.txt result.txt
then
    exit 0
else
    exit 1
fi

