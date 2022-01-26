#include "test_utils.h"

Test(test_bzero, set_no_bits_if_n_is_zero) {
	char 	dest_own[] = {69, 68};
	char 	res_exp[] = {69, 68};
	size_t	bit_count = 0;

	ft_bzero(&dest_own, bit_count);

	cr_assert_arr_eq(dest_own, res_exp, 2 * sizeof(char));
}

Test(test_bzero, set_one_byte) {
	char 	dest_own[] = {2};
	size_t	bit_count = 1;

	ft_bzero(&dest_own, bit_count);

	cr_assert_eq(dest_own[0], 0);
}

Test(test_bzero, set_two_bytes) {
	char 	dest_own[] = {69, 68};
	char 	res_exp[] = {0, 0};
	size_t	bit_count = 2;

	ft_bzero(&dest_own, bit_count);

	cr_assert_arr_eq(dest_own, res_exp, 2 * sizeof(char));
}

// what else !?