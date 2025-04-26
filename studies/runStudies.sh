#!/bin/bash

# Path to the program
PROGRAM="../bin/sorter"

# Sorting algorithms
ALGORITHMS=("HEAP" "INSERTION" "QUICK" "SHELL" "DRUNK_INSERTION")

# Data types
TYPES=("int" "float" "double" "char" "BoardGame")

# Sizes of the sorted set
SIZES=(10000 20000 30000 40000 80000 160000)

# Number of iterations
ITERATIONS=100

# Initial distributions of elements
DISTRIBUTIONS=("random" "sorted_desc" "sorted_asc" "partially_sorted_33" "partially_sorted_66")

# Log file
LOG_FILE="./studies.log"

# Clear the log file
> $LOG_FILE

# Clear previous output directories
cleanup() {
    FOLDERS=("HEAP" "INSERTION" "QUICK" "SHELL" "DRUNK_INSERTION" "DrunkInsertionSort" "ShellSort_with_gaps" "QuickSort_with_pivot")

    for folder in "${FOLDERS[@]}"; do
            rm -rf "$folder"/*
            mkdir -p "$folder"
    done
}

# Function to run study 1
run_study_1() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for size in "${SIZES[@]}"; do
            echo "Running study 1: Algorithm=${ALGORITHMS[$algorithm]}, Size=$size" | tee -a $LOG_FILE
            $PROGRAM --test $algorithm 0 $size "${ALGORITHMS[$algorithm]}/output_${ALGORITHMS[$algorithm]}_${size}.txt" 0 $ITERATIONS 2>&1 | tee -a $LOG_FILE
        done
    done
}

# Modification for Shell Sort
run_study_1_sh() {
    for size in "${SIZES[@]}"; do
        echo "Running study 1: Algorithm=SHELL, Size=$size" | tee -a $LOG_FILE
        $PROGRAM --test 3 0 $size "SHELL/output_SHELL_${size}.txt" 3 $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done
}

# Function to run study 2
run_study_2() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for distribution in "${DISTRIBUTIONS[@]}"; do
            echo "Running study 2: Algorithm=${ALGORITHMS[$algorithm]}, Distribution=$distribution" | tee -a $LOG_FILE
            $PROGRAM --file $algorithm 0 "test_cases/${distribution}.txt" "${ALGORITHMS[$algorithm]}/output_${ALGORITHMS[$algorithm]}_${distribution}.txt" 0 $ITERATIONS 2>&1 | tee -a $LOG_FILE
        done
    done
}

run_study_2_sh() {
    for distribution in "${DISTRIBUTIONS[@]}"; do
        echo "Running study 2: Algorithm=SHELL, Distribution=$distribution" | tee -a $LOG_FILE
        $PROGRAM --file 3 0 "test_cases/${distribution}.txt" "SHELL/output_SHELL_${distribution}.txt" 3 $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done
}

# Function to run study 3
run_study_3() {
    selected_algorithm=2 # Index for QUICK algorithm
    for type in "${!TYPES[@]}"; do
        echo "Running study 3: Algorithm=${ALGORITHMS[$selected_algorithm]}, Type=${TYPES[$type]}" | tee -a $LOG_FILE
        $PROGRAM --test $selected_algorithm $type 10000 "${ALGORITHMS[$selected_algorithm]}/output_${ALGORITHMS[$selected_algorithm]}_${TYPES[$type]}.txt" 0 $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done
}

# Additional gaps for ShellSort
GAPS1=(1 4 10)
GAPS2=(1 3 7)

# Study 1 for DrunkInsertionSort
run_study_1_drunk() {
    for drunkenness in 0 25 50 75 100; do
        echo "Running DrunkInsertionSort with drunkenness=$drunkenness" | tee -a $LOG_FILE
        $PROGRAM --test 4 0 30000 "DrunkInsertionSort/output_drunk_${drunkenness}.txt" $drunkenness $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done
}

run_study_2_drunk() {
    for drunkenness in 0 25 50 75 100; do
        for distribution in "${DISTRIBUTIONS[@]}"; do
            echo "Running study 2: Algorithm=DRUNK_INSERTION, Distribution=$distribution, Drunkenness=$drunkenness" | tee -a $LOG_FILE
            $PROGRAM --file 4 0 "test_cases/${distribution}.txt" "DrunkInsertionSort/output_${drunkenness}_${distribution}.txt" $drunkenness $ITERATIONS 2>&1 | tee -a $LOG_FILE
        done
    done
}

# Study 1 for ShellSort
run_study_1_shell() {
    for gaps in "${GAPS1[@]}"; do
        echo "Running ShellSort with gaps=${gaps}" | tee -a $LOG_FILE
        $PROGRAM --test 3 0 10000 "ShellSort_with_gaps/output_shell_${gaps}.txt" $gaps $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done

    for gaps in "${GAPS2[@]}"; do
        echo "Running ShellSort with gaps=${gaps}" | tee -a $LOG_FILE
        $PROGRAM --test 3 0 10000 "ShellSort_with_gaps/output_shell_${gaps}.txt" $gaps $ITERATIONS 2>&1 | tee -a $LOG_FILE
    done
}

# Study 1 for QuickSort
run_study_1_quick() {
    for pivot in 0 1 2 3; do
        for size in "${SIZES[@]}"; do
            echo "Running QuickSort with pivot=${pivot}, size=${size}" | tee -a $LOG_FILE
            $PROGRAM --test 2 0 ${size} "QuickSort_with_pivot/output_quick_${pivot}_${size}.txt" $pivot $ITERATIONS 2>&1 | tee -a $LOG_FILE
        done
    done
}

# Run studies
cleanup
run_study_1
run_study_1_sh
run_study_2
run_study_2_sh
run_study_3
run_study_1_drunk
run_study_1_shell
run_study_1_quick
run_study_2_drunk

echo "All studies completed." | tee -a $LOG_FILE

