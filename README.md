# gtest-oct-bosch-2024

StringCalculatorSpecs.cpp : Defines the entry point for the console application.


string_calculator_add

	when_passed_a_single_number
		returns_0_for_empty_string
		returns_0_for_zero
    returns_1_for_one
  
  when_passed_two_comma_delimited_numbers
		returns_their_sum
  
	when_passed_multiple_comma_delimited_numbers
		returns_their_sum
  
	when_delimited_with_newline_and_comma
		returns_their_sum
  
	when_passed_a_delimiter
		returns_the_sum_based_on_that_delimiter

	when_passed_negative_numbers
		throws_an_exception_listing_invalid_values
  
	when_passed_numbers_over_1000
		ignores_them
  
	when_passed_multicharacter_delimiter
		uses_that_delimiter_to_sum_values
  
	when_passed_multiple_delimiters
		sums_on_each_delimiter

	when_passed_multiple_multicharacter_delimiters
		sums_on_each_delimiter
