#include "test_utils.h"

Test(test_isascii, returns_one_if_input_alphabetic) {
	cr_assert_eq(ft_isascii('e'), 1);
}

Test(test_isascii, returns_one_if_input_digit) {
	cr_assert_eq(ft_isascii('0'), 1);
}

Test(test_isascii, equals_real_function) {
	for (int i = -256; i < 257; i++)
		cr_assert_eq((isascii(i) == 0), (ft_isascii(i) == 0));
}