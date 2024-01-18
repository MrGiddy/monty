#!/bin/bash
# Monty Test Suite

# Function to run a test case
run_test() {
	    echo "Running test: $1"
	        ./monty "$1"
	}

# Test Case 1: Push integers onto the stack and print
echo "push 10" > test1.m
echo "push 20" >> test1.m
echo "push 30" >> test1.m
echo "pall" >> test1.m
run_test test1.m
rm test1.m

# Test Case 2: Push a non-integer value (should print an error)
echo "push abc" > test2.m
run_test test2.m
rm test2.m

# Test Case 3: Push without an argument (should print an error)
echo "push" > test3.m
run_test test3.m
rm test3.m

# Test Case 4: Push integers and print with an empty stack
echo "push 5" > test4.m
echo "push 15" >> test4.m
echo "pall" >> test4.m
run_test test4.m
rm test4.m

# Test Case 5: Push, pop, and print (verify pop functionality)
echo "push 42" > test5.m
echo "pop" >> test5.m
echo "pall" >> test5.m
run_test test5.m
rm test5.m

# Test Case 6: Push multiple integers and print
echo "push 1" > test6.m
echo "push 2" >> test6.m
echo "push 3" >> test6.m
echo "push 4" >> test6.m
echo "push 5" >> test6.m
echo "pall" >> test6.m
run_test test6.m
rm test6.m

# Add more test cases based on the specified instructions

echo "All test cases executed successfully."
