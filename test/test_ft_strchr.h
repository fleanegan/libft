#include <criterion/criterion.h>
#include <unistd.h>
#include "../src/libft.h"

Test(test_strchr, does_not_find_anything_in_empty_string) {
	char	in[] = "";
	int		search = 3;

	char	*res_own = ft_strchr(in, search);
	char	*res_orig = strchr(in, search);

	cr_assert_eq(res_own, NULL);
	cr_assert_eq(res_orig, res_own);
}

Test(test_strchr, does_not_find_returns_NULL) {
	char	in[] = "itest";
	int		search = 'a';

	char	*res_own = ft_strchr(in, search);
	char	*res_orig = strchr(in, search);

	cr_assert_eq(res_own, NULL);
	cr_assert_eq(res_orig, res_own);
}

Test(test_strchr, finds_terminating_char_in_empty_string) {
	char	in[] = "";
	int		search = 0;

	char	*res_own = ft_strchr(in, search);
	char	*res_orig = strchr(in, search);

	cr_assert_not_null(res_own);
	cr_assert_eq(res_orig, res_own);
}

Test(test_strchr, finds_first_char) {
	char	in[] = "iicaa";
	int		search = 'i';

	char	*res_own = ft_strchr(in, search);
	char	*res_orig = strchr(in, search);

	cr_assert_eq(*res_own, 'i');
	cr_assert_eq(res_orig, res_own);
}

Test(test_strchr, finds_second_char) {
	char	in[] = "iicaa";
	int		search = 'c';

	char	*res_own = ft_strchr(in, search);
	char	*res_orig = strchr(in, search);

	cr_assert_eq(*res_own, search);
	cr_assert_eq(res_orig, res_own);
}

/* how do we test something we WANT to crash ?
Test(test_strchr, given_a_trash_pointer_return_NULL) {
	char	*trash = 0;
	int		search = 'c';

	(void) ft_strchr(trash, search);
	cr_assert_fail("original function fails so we expect it here too");
	(void) strchr(trash , search);

}
*/