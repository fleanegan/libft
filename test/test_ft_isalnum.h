#include "test_utils.h"

Test(test_isalnum, returns_one_if_input_alphabetic) {
	cr_assert_eq(ft_isalnum('e'), 1);
}

Test(test_isalnum, returns_one_if_input_digit) {
	cr_assert_eq(ft_isalnum('0'), 1);
}

TheoryDataPoints(theory_isalnum, returns_one_if_input_alphanumeric_else_zero) = {
		DataPoints(int, -1, 0, 'A', 'B', 'Z', 'Y', 'a', 'b', 'y', 'z', 95, '0', '1', 24),
};

Theory((int in), theory_isalnum, returns_one_if_input_alphanumeric_else_zero) {
	cr_assert_eq((isalnum(in) == 0), (ft_isalnum(in) == 0));
}