#include "test_utils.h"

Test(test_isalpha, returns_one_if_input_alphabetic) {
	cr_assert_eq(ft_isalpha('e'), 1);
}

Test(test_isalpha, returns_zero_if_input_not_alphabetic) {
	cr_assert_eq(ft_isalpha('0'), 0);
}

TheoryDataPoints(theory_isalpha, returns_one_if_input_alphabetic) = {
		DataPoints(int, -1, 0, 'A', 'B', 'Z', 'Y', 'a', 'b', 'y', 'z', 95),
};

Theory((int in), theory_isalpha, returns_one_if_input_alphabetic) {
	cr_assert_eq((isalpha(in) == 0), (ft_isalpha(in) == 0));
}