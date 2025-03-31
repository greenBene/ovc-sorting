#!/bin/zsh


PYTHON=python3
GEN_SCRIPT=generateTestData.py

N=(1000 10000 100000 1000000 5000000)
K=(5 20)
ORDERS=(random ordered)


for n in "${N[@]}"; do
  for k in "${K[@]}"; do
    for o in "${ORDERS[@]}"; do
      COMMAND="$PYTHON $GEN_SCRIPT --order $o --number $n --keylength $k --out test_${n}_${k}_${o}.txt"
      echo "$COMMAND"
      eval "$COMMAND"
    done
  done
done