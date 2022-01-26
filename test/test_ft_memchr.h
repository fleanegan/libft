#include "test_utils.h"

Test(test_memchr, does_not_find_anything_in_empty_string) {
	char	in[] = "";
	int		search = 3;

	char	*res_own = ft_memchr(in, search, ft_strlen(in));
	char	*res_orig = memchr(in, search, ft_strlen(in));

	cr_assert_null(res_own);
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, does_not_find_returns_NULL) {
	char	in[] = "itest";
	int		search = 'a';

	char	*res_own = ft_memchr(in, search, ft_strlen(in));
	char	*res_orig = memchr(in, search, ft_strlen(in));

	cr_assert_null(res_own);
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, finds_terminating_char_in_empty_string) {
	char	in[] = "";
	int		search = 0;

	char	*res_own = ft_memchr(in, search, 1);
	char	*res_orig = memchr(in, search, 1);

	cr_assert_eq(*res_own, 0);
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, finds_first_char) {
	char	in[] = "iicaa";
	int		search = 'i';

	char	*res_own = ft_memchr(in, search, ft_strlen(in));
	char	*res_orig = memchr(in, search, ft_strlen(in));

	cr_assert_eq(*res_own, 'i');
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, finds_second_char) {
	char	in[] = "iicaa";
	int		search = 'c';

	char	*res_own = ft_memchr(in, search, ft_strlen(in));
	char	*res_orig = memchr(in, search, ft_strlen(in));

	cr_assert_eq(*res_own, search);
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, finds_char_after_terminating_char) {
	char	in[] = "c\0a";
	int		search = 'a';

	char	*res_own = ft_memchr(in, search, 3);
	char	*res_orig = memchr(in, search, 3);

	cr_assert_eq(*res_own, search);
	cr_assert_eq(res_orig, res_own);
}

Test(test_memchr, stops_after_n) {
	char	in[] = "ab";
	int		search = 'b';

	char	*res_own = ft_memchr(in, search, 1);
	char	*res_orig = memchr(in, search, 1);

	cr_assert_null(res_orig);
	cr_assert_null(res_own);
	cr_assert_eq(res_orig, res_own);
	(void) res_orig;
}

Test(test_memchr, does_it_cast_both_input_to_unsigned) {
	char	*src = "/|\x12\xff\x09\x42\2002\42|\\";
	int		size = 10;

	char	*res_orig = memchr(src, '\200', size);
	char	*res_own = ft_memchr(src, '\200', size);

	cr_assert_eq(res_orig, res_own);
}