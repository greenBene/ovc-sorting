#!/bin/zsh

PYTHON=python3
GEN_SCRIPT=generateTestData.py

N=(1000 10000 100000 1000000)
K=(10)
SEED=1337

counter=0
for n in "${N[@]}"; do
  for k in "${K[@]}"; do

      COMMAND="$PYTHON $GEN_SCRIPT --order onlyduplicates --number $n --keylength $k --out data/test_${n}_${k}_onlyduplicates.txt"
      echo "$COMMAND"
      eval "$COMMAND"

      COMMAND="$PYTHON $GEN_SCRIPT --order ordered --number $n --keylength $k --out data/test_${n}_${k}_ordered.txt"
      echo "$COMMAND"
      eval "$COMMAND"

      next_seed=$((SEED + counter))
      counter=$((counter + 1))
      COMMAND="$PYTHON $GEN_SCRIPT --seed $next_seed --order random --number $n --keylength $k --out data/test_${n}_${k}_random_1.txt"
      echo "$COMMAND"
      eval "$COMMAND"

      next_seed=$((SEED + counter))
      counter=$((counter + 1))
      COMMAND="$PYTHON $GEN_SCRIPT --seed $next_seed --order random --number $n --keylength $k --out data/test_${n}_${k}_random_2.txt"
      echo "$COMMAND"
      eval "$COMMAND"

      next_seed=$((SEED + counter))
      counter=$((counter + 1))
      COMMAND="$PYTHON $GEN_SCRIPT --seed $next_seed --order random --number $n --keylength $k --out data/test_${n}_${k}_random_3.txt"
      echo "$COMMAND"
      eval "$COMMAND"
  done
done