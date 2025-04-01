#!/bin/bash

# Path to the program
PROGRAM="./bin/sorter"

# Sorting algorithms
ALGORITHMS=("HEAP" "INSERTION" "QUICK" "SHELL" "DRUNK_INSERTION")

# Data types
TYPES=("int" "float" "double" "char" "BoardGame")

# Sizes of the sorted set
SIZES=(10000 20000 40000 80000 160000)

# Initial distributions of elements
DISTRIBUTIONS=("random" "sorted_desc" "sorted_asc" "partially_sorted_33" "partially_sorted_66")

# Function to run study 1
run_study_1() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for size in "${SIZES[@]}"; do
            echo "Running study 1: Algorithm=${ALGORITHMS[$algorithm]}, Size=$size"
            $PROGRAM --test $algorithm 0 $size "output_${ALGORITHMS[$algorithm]}_${size}.txt"
        done
    done
}

# Function to run study 2
run_study_2() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for distribution in "${DISTRIBUTIONS[@]}"; do
            echo "Running study 2: Algorithm=${ALGORITHMS[$algorithm]}, Distribution=$distribution"
            $PROGRAM --test $algorithm 0 10000 "output_${ALGORITHMS[$algorithm]}_${distribution}.txt"
        done
    done
}

# Function to run study 3
run_study_3() {
    selected_algorithm=2 # Index for QUICK algorithm
    for type in "${!TYPES[@]}"; do
        echo "Running study 3: Algorithm=${ALGORITHMS[$selected_algorithm]}, Type=${TYPES[$type]}"
        $PROGRAM --test $selected_algorithm $type 10000 "output_${ALGORITHMS[$selected_algorithm]}_${TYPES[$type]}.txt"
    done
}

# Run studies
run_study_1
run_study_2
run_study_3

echo "All studies completed."