#include <criterion/criterion.h>

Test(test_memcpy, cpy_no_bits_if_byte_number_is_zero) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	res_exp[1];
	size_t	n = 0;

	ft_memcpy(dest, src, n);
	memcpy(res_exp, src, n);

	cr_assert_arr_eq(dest, res_exp, 1 * sizeof(char));
}

Test(test_memcpy, returns_pointer) {
	char 	src[] = {69};
	char 	dest[] = {0};
	size_t	n = 0;

	char 	*own_ptr = ft_memcpy(&dest, src, n);
	char 	*orig_ptr = memcpy(&dest, src, n);

	cr_assert_eq(*own_ptr, *orig_ptr);
}

Test(test_memcpy, cpy_one_byte) {
	char 	src[] = {69};
	char 	dest[] = {0};
	char 	res_exp[1];
	size_t	n = 1;

	ft_memcpy(dest, src, n);
	memcpy(res_exp, src, n);

	cr_assert_arr_eq(dest, res_exp, 1 * sizeof(char));
}

Test(test_memcpy, set_two_bytes) {
	char 	src[] = {69, 68};
	char 	dest[] = {0, 0};
	char 	res_exp[2];
	size_t	n = 2;

	ft_memcpy(dest, src, n);
	memcpy(res_exp, src, n);

	cr_assert_arr_eq(dest, res_exp, 2 * sizeof(char));
}

Test(test_memcpy, do_nothing_if_source_is_null, .disabled=true) {
	ft_memcpy(((void*)0), ((void*)0), 3);
	//memcpy(((void*)0), ((void*)0), 3);
	/*
	char 	*src = NULL;
	char 	*dest = NULL;
	char 	*res_exp = NULL;
	size_t	n = 3;

	ft_memcpy(dest, src, n);
	memcpy(res_exp, src, n);

	cr_assert_arr_eq(dest, res_exp, 1 * sizeof(char));*/
}

#ifdef own_source


#endif

// what else !?