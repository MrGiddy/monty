!/bin/bash
run_monty() {
	echo "Running test: $1"
	./monty "$1"
	echo "Finished test: $1"
}

# Test Case 1: Swap with an empty stack
echo "swap" > test1.m
run_monty test1.m
rm test1.m

# Test Case 2: Swap with fewer than two elements
echo "push 42" > test2.m
echo "swap" >> test2.m
run_monty test2.m
rm test2.m

# Test Case 3: Swap with exactly two elements
echo "push 10" > test3.m
echo "push 20" >> test3.m
echo "swap" >> test3.m
echo "pall" >> test3.m
run_monty test3.m
rm test3.m

# Test Case 4: Swap with more than two elements
echo "push 1" > test4.m
echo "push 2" >> test4.m
echo "push 3" >> test4.m
echo "swap" >> test4.m
echo "pall" >> test4.m
run_monty test4.m
rm test4.m

# Test Case 5: Multiple swap operations
echo "push 1" > test5.m
echo "push 2" >> test5.m
echo "push 3" >> test5.m
echo "swap" >> test5.m
echo "swap" >> test5.m
echo "pall" >> test5.m
run_monty test5.m
rm test5.m

echo "Testing complete."
