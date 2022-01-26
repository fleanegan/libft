#include <criterion/criterion.h>

Test(test_memset, set_no_bits) {
	char 	dest_own[] = {69, 68};
	char 	res_exp[] = {69, 68};
	size_t	bit_count = 0;
	int 	new_content = 3;

	ft_memset(&dest_own, new_content, bit_count);
	memset(&res_exp, new_content, bit_count);

	cr_assert_arr_eq(dest_own, res_exp, 2 * sizeof(char));
}

Test(test_memset, returns_pointer) {
	char 	dest_own[] = {69, 68};
	size_t	bit_count = 0;
	int 	new_content = 3;
	char 	*own_ptr =	ft_memset(&dest_own, new_content, bit_count);
	char 	*orig_ptr =	memset(&dest_own, new_content, bit_count);

	cr_assert_eq(*own_ptr, *orig_ptr);
}

Test(test_memset, set_one_byte) {
	char 	dest_own[] = {0};
	char 	dest_orig[] = {0};
	size_t	bit_count = 1;
	int 	new_content = 3;

	ft_memset(&dest_own, new_content, bit_count);
	memset(&dest_orig, new_content, bit_count);

	cr_assert_eq(dest_own[0], 3);
	cr_assert_eq(dest_own[0], dest_orig[0]);
}

Test(test_memset, set_two_bytes) {
	char 	dest_own[] = {69, 68};
	char 	res_exp[2];
	size_t	bit_count = 2;
	int 	new_content = 3;

	ft_memset(&dest_own, new_content, bit_count);
	memset(&res_exp, new_content, bit_count);

	cr_assert_arr_eq(dest_own, res_exp, 2 * sizeof(char));
}

// what else !?