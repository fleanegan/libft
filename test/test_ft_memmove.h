#include <criterion/criterion.h>

Test(test_memmove, cpy_no_bits_if_byte_number_is_zero) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	res_exp[] = {0};
	size_t	n = 0;

	ft_memmove(dest, src, n);

	cr_assert_arr_eq(dest, res_exp, 1 * sizeof(char));
}

Test(test_memmove, returns_pointer) {
	char 	src[] = {69};
	char 	dest[] = {0};
	size_t	n = 0;

	char 	*dest_ptr = ft_memmove(&dest, src, n);

	cr_assert_eq(dest_ptr, (const char *) &dest);
}

Test(test_memmove, cpy_one_byte) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	res_exp[] = {69};
	size_t	n = 1;

	ft_memmove(dest, src, n);

	cr_assert_arr_eq(dest, res_exp, 1 * sizeof(char));
}

Test(test_memmove, set_two_bytes) {
	char 	src[] = {69, 68};
	char 	dest[] = {0, 0};
	char 	res_exp[] = {69, 68};
	size_t	n = 2;

	ft_memmove(dest, src, n);

	cr_assert_arr_eq(dest, res_exp, 2 * sizeof(char));
}

Test(test_memmove, set_overlapping_memories) {
	char 	src[] = {69, 68};
	char 	res_exp[] = {69};
	char 	*dest = (src + 1);
	size_t	n = 1;

	ft_memmove(dest, src, n);

	cr_assert_arr_eq(dest, res_exp, sizeof(char));
}

Test(test_memmove, comparison_with_original_implementation_normal_case) {
	char	src_non_empty[] = "abc";
	char	*dest_own = (char *) malloc(sizeof(char) * 3);
	char	*dest_orig = (char *) malloc(sizeof(char) * 3);

	char 	*ptr_own = ft_memmove(dest_own, src_non_empty, 3);
	char	*ptr_orig = memmove(dest_orig, src_non_empty, 3);

	cr_assert_arr_eq(dest_own, dest_orig, sizeof(char) * 3);
	cr_assert_eq(*ptr_own, *ptr_orig);
}

Test(test_memmove, comparison_with_original_implementation_dest_too_short) {
	char	src_non_empty[] = "abc";
	char	*dest_own = (char *) malloc(sizeof(char) * 2);
	char	*dest_orig = (char *) malloc(sizeof(char) * 2);

	ft_memmove(dest_own, src_non_empty, 3);
	memmove(dest_orig, src_non_empty, 3);

	cr_assert_arr_eq(dest_own, dest_orig, sizeof(char) * 2);
}

Test(test_memmove, comparison_with_original_implementation_empty_length) {
	char	src_non_empty[] = "abc";
	char	*dest_own = (char *) malloc(sizeof(char) * 3);
	char	*dest_orig = (char *) malloc(sizeof(char) * 3);

	ft_memmove(dest_own, src_non_empty, 0);
	memmove(dest_orig, src_non_empty, 0);

	cr_assert_arr_eq(dest_own, dest_orig, sizeof(char) * 2);
}
// what else !?