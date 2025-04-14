#!/bin/zsh

PROGRAM=../release/OVCSorting

RESULTS="results_q.csv"
echo "algorithm,M,input,N,k,rowCmp,ovcDecisions,colCmp,timeInUS" > $RESULTS


evaluate_random () {
  #   ALGORITHMS: string list
  #   N: string list
  #   K: string list
  for alg in "${ALGORITHMS[@]}"; do
    for n in "${N[@]}"; do
      for k in "${K[@]}"; do
        for file in ./data/test_"${n}"_"${k}"_random_*.txt; do
            for m in "${M[@]}"; do
              COMMAND="$PROGRAM --algorithm $alg --input $file --M $m"
              echo "$COMMAND"
              eval "$COMMAND" >> $RESULTS
            done
        done
      done
    done
  done
}

evaluate_ordered () {
  #   $1 - ALGORITHMS: string list
  #   $2 - N: string list
  #   $3 - K: string list
  for alg in "${ALGORITHMS[@]}"; do
    for n in "${N[@]}"; do
      for k in "${K[@]}"; do
        file="./data/test_${n}_${k}_ordered.txt"
        COMMAND="$PROGRAM --algorithm $alg --input $file"
        echo "$COMMAND"
        eval "$COMMAND" >> $RESULTS
        echo "$COMMAND"
        eval "$COMMAND" >> $RESULTS
        echo "$COMMAND"
        eval "$COMMAND" >> $RESULTS
      done
    done
  done
}


M=(0)

# MAIN ALGORITHMS
## EVAL N
ALGORITHMS=(basesort heapsort heapsortovc mergesort mergesortovc)
N=(1000 10000 100000 1000000)
K=(10 )
evaluate_random
evaluate_ordered

## EVAL (missing) K
ALGORITHMS=(basesort heapsort heapsortovc mergesort mergesortovc)
N=(100000)
K=(5 20 50)
evaluate_random


# INSERTION_SORT
## EVAL N
ALGORITHMS=(insertionsort insertionsortovc)
N=(1000 10000)
K=(10)
evaluate_random
ALGORITHMS=(insertionsort insertionsortovc)
N=(1000 10000 100000 1000000)
K=(10)
evaluate_ordered

## EVAL (missing) K
ALGORITHMS=(insertionsort insertionsortovc)
N=(10000)
K=(5 20 50)
evaluate_random


# QUICKSORT
## EVAL N
ALGORITHMS=(quicksort quicksortovc quicksortaovc quicksortaovc+uc)
N=(1000 10000 100000 1000000)
K=(10)
evaluate_random

ALGORITHMS=(quicksortaovc quicksortaovc+uc)
N=(1000 10000 100000 1000000)
K=(10)
evaluate_ordered
ALGORITHMS=(quicksortovc)
N=(1000 10000 100000)
K=(10)
evaluate_ordered
ALGORITHMS=(quicksort)
N=(1000 10000)
K=(10)
evaluate_ordered

## EVAL (missing) K
ALGORITHMS=(quicksort quicksortovc quicksortaovc quicksortaovc+uc)
N=(100000)
K=(5 20 50)
evaluate_random

ALGORITHMS=(quicksort quicksortovc quicksortaovc quicksortaovc+uc)
N=(1000 10000 100000 1000000)
K=(10)
M=(5 10 20 50)
evaluate_random