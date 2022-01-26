#include "test_utils.h"

Test(test_isprint, returns_one_if_input_alphabetic) {
	cr_assert_eq(ft_isprint('e'), 1);
}

Test(test_isprint, returns_one_if_input_not_alphabetic) {
	cr_assert_eq(ft_isprint('0'), 1);
}

Test(test_isprint, equals_real_function) {
	for (int i = -256; i < 257; i++)
		cr_assert_eq((isprint(i) == 0), (ft_isprint(i) == 0));
}
