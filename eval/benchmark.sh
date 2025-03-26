#!/bin/zsh

ALGORITHMS=(basesort heapsort heapsortovc mergesort mergesortovc quicksort quicksortovc quicksortaovc quicksortaovc+uc)
PROGRAM=../release/OVCSorting


RESULTS="results.csv"

echo "algorithm, M, input, N, k, rowCmp, ovcDecisions, colCmp, timeInUS" > $RESULTS

for alg in ${ALGORITHMS[@]}; do
  for file in ./test_*_random.txt; do
    COMMAND="$PROGRAM --algorithm $alg --input $file"
    echo $COMMAND
    eval $COMMAND >> $RESULTS
  done
done