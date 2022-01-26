#include "test_utils.h"

Test(test_strchr, reverse_string) {
	char	*in = "abab";

	char	*res_act = ft_strrchr(in, 'a');

	cr_assert_eq(res_act, in + 2);
}

Test(test_strchr, reverse_string_1) {
	char	*in = "abb";

	char	*res_act = ft_strrchr(in, 'a');

	cr_assert_eq(res_act, in);
}