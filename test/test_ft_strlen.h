#include <criterion/criterion.h>

Test(test_strlen, empty_string_has_len_zero) {
	char	in[] = "";
	size_t 	res_exp = 0;
	size_t 	res_calc = ft_strlen((const char *) &in);

	cr_assert_eq(res_exp, res_calc);
}

Test(test_strlen, one_char_has_len_one) {
	char	in[] = "d";
	size_t 	res_exp = 1;
	size_t 	res_calc = ft_strlen((const char *) &in);

	cr_assert_eq(res_exp, res_calc);
}

Test(test_strlen, two_chars_have_len_two) {
	char	in[] = "dd";
	size_t 	res_exp = 2;
	size_t 	res_calc = ft_strlen((const char *) &in);

	cr_assert_eq(res_exp, res_calc);
}
