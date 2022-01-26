#include "test_utils.h"

Test(test_isdigit, returns_zero_if_input_alphabetic) {
	cr_assert_eq(ft_isdigit('e'), 0);
}

Test(test_isdigit, returns_one_if_input_digit) {
	cr_assert_eq(ft_isdigit('0'), 1);
}

TheoryDataPoints(theory_isdigit, returns_one_if_input_digit) = {
		DataPoints(int, -1, 0, 'A', 'B', 'Z', 'Y', 'a', 'b', 'y', 'z', 95, '0', '1'),
};

Theory((int in), theory_isdigit, returns_one_if_input_digit) {
	cr_assert_eq((isdigit(in) == 0), (ft_isdigit(in) == 0));
}