#!/bin/bash
# Define a test function
run_test() {
  # Run the program with an input and save the output
  program_output=$(./s21_cat "$1")
  # Compare the output with the expected one
  if [ "$program_output" == "$2" ]; then
    echo "Test passed!"
  else
    echo "Test failed."
  fi
}

# Call the test function with different inputs
run_test "input1" "expected_output1"
run_test "input2" "expected_output2"
