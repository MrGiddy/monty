#/bin/bash

run_test() {
	    echo "Running test: $1"
	        ./monty "$1"
	}

# Test Case 1: Pop from an empty stack
echo "pop" > test1.m
run_test test1.m
rm test1.m

# Test Case 2: Pop from an initially empty stack
echo "push 42" > test2.m
echo "pop" >> test2.m
run_test test2.m
rm test2.m

# Test Case 3: Pop from a non-empty stack
echo "push 10" > test3.m
echo "push 20" >> test3.m
echo "push 30" >> test3.m
echo "pop" >> test3.m
echo "pall">>test3.m
run_test test3.m
rm test3.m

# Test Case 4: Pop multiple elements from the stack
echo "push 10" > test4.m
echo "push 20" >> test4.m
echo "push 30" >> test4.m
echo "pop" >> test4.m
echo "pop" >> test4.m
echo "pop" >> test4.m
run_test test4.m
rm test4.m

# Test Case 5: Alternating push and pop operations
echo "push 1" > test5.m
echo "pop" >> test5.m
echo "push 2" >> test5.m
echo "pop" >> test5.m
echo "push 3" >> test5.m
echo "pop" >> test5.m
run_test test5.m
rm test5.m

# Test Case 6: Pop from an initially non-empty stack
echo "push 100" > test6.m
echo "push 200" >> test6.m
run_test test6.m
rm test6.m

# Test Case 7: Pop all elements from the stack
echo "push 5" > test7.m
echo "push 10" >> test7.m
echo "push 15" >> test7.m
echo "pall" >> test7.m
echo "pop" >> test7.m
echo "pop" >> test7.m
echo "pop" >> test7.m
echo "pall" >> test7.m
run_test test7.m
rm test7.m

echo "Testing complete."
