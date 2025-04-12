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

# Log file
LOG_FILE="studies.log"

# Clear the log file
> $LOG_FILE

# Function to run study 1
run_study_1() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for size in "${SIZES[@]}"; do
            echo "Running study 1: Algorithm=${ALGORITHMS[$algorithm]}, Size=$size" | tee -a $LOG_FILE
            $PROGRAM --test $algorithm 0 $size "output_${ALGORITHMS[$algorithm]}_${size}.txt" 2>&1 | tee -a $LOG_FILE
        done
    done
}

# Function to run study 2
run_study_2() {
    for algorithm in "${!ALGORITHMS[@]}"; do
        for distribution in "${DISTRIBUTIONS[@]}"; do
            echo "Running study 2: Algorithm=${ALGORITHMS[$algorithm]}, Distribution=$distribution" | tee -a $LOG_FILE
            $PROGRAM --test $algorithm 0 10000 "output_${ALGORITHMS[$algorithm]}_${distribution}.txt" 2>&1 | tee -a $LOG_FILE
        done
    done
}

# Function to run study 3
run_study_3() {
    selected_algorithm=2 # Index for QUICK algorithm
    for type in "${!TYPES[@]}"; do
        echo "Running study 3: Algorithm=${ALGORITHMS[$selected_algorithm]}, Type=${TYPES[$type]}" | tee -a $LOG_FILE
        $PROGRAM --test $selected_algorithm $type 10000 "output_${ALGORITHMS[$selected_algorithm]}_${TYPES[$type]}.txt" 2>&1 | tee -a $LOG_FILE
    done
}

# Additional gaps for ShellSort
GAPS1=(1 4 10)
GAPS2=(1 3 7)

# Pivot types for QuickSort
PIVOTS=("LEFT" "RIGHT" "MIDDLE" "RANDOM")

# Study 1 for DrunkInsertionSort
run_study_1_drunk() {
    for drunkenness in 0 25 50 75 100; do
        echo "Running DrunkInsertionSort with drunkenness=$drunkenness" | tee -a $LOG_FILE
        $PROGRAM --test 4 0 10000 "output_drunk_${drunkenness}.txt" $drunkenness
    done
}

# Study 1 for ShellSort
run_study_1_shell() {
    for gaps in "${GAPS1[@]}" "${GAPS2[@]}"; do
        echo "Running ShellSort with gaps=${gaps}" | tee -a $LOG_FILE
        $PROGRAM --test 3 0 10000 "output_shell_${gaps}.txt" $gaps
    done
}

# Study 1 for QuickSort
run_study_1_quick() {
    for pivot in "${PIVOTS[@]}"; do
        for size in "${SIZES[@]}"; do
            echo "Running QuickSort with pivot=${pivot}, size=${size}" | tee -a $LOG_FILE
            $PROGRAM --test 2 0 ${size} "output_quick_${pivot}_${size}.txt" $pivot
        done
    done
}

# Analysis of results and selection of the best options
best_quick_sort_pivot=""
best_shell_gap=""
min_time_quick_sort=999999
min_time_shell=999999

# Analyze QuickSort results
for pivot in LEFT RIGHT MIDDLE RANDOM; do
    for size in "${SIZES[@]}"; do
        time=$(grep "Average time" "output_quick_${pivot}_${size}.txt" | awk '{print $3}')
        if (( $(echo "$time < $min_time_quick_sort" | bc -l) )); then
            min_time_quick_sort=$time
            best_quick_sort_pivot=$pivot
        fi
    done
done

# Analyze ShellSort results (example for different gaps)
for gap in {1..5}; do
    for size in "${SIZES[@]}"; do
        time=$(grep "Average time" "output_shell_${gap}_${size}.txt" | awk '{print $3}')
        if (( $(echo "$time < $min_time_shell" | bc -l) )); then
            min_time_shell=$time
            best_shell_gap=$gap
        fi
    done
done

echo "Best pivot for QuickSort: $best_quick_sort_pivot"
echo "Best gap for ShellSort: $best_shell_gap"

# Run studies
run_study_1
run_study_2
run_study_3
run_study_1_drunk
run_study_1_shell
run_study_1_quick

echo "All studies completed." | tee -a $LOG_FILE