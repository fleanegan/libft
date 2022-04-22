#include "test_utils.h"

int cpy_str(void *content, void **result)
{
	(*result) = ft_strdup((char *)content);
	if (*result == NULL)
		return (1);
	return (0);
}

Test(test_to_array, empty_list_returns_empty_nullterminated_2darray)
{
	t_list	*in = NULL;

	void	**result = to_array(in, NULL);
	cr_assert_not_null(result);
	cr_assert_null(result[0]);
}

Test(test_to_array, one_element_list_returns_as_nullterminated_2darray)
{
	t_list	*in = ft_lstnew(ft_strdup("test me"));

	void	**result = to_array(in, cpy_str);
	cr_assert_not_null(result);
	cr_expect_str_eq(result[0], "test me");
}

Test(test_to_array, three_element_list_returns_as_nullterminated_2darray)
{
	t_list	*in = ft_lstnew(ft_strdup("test"));
	ft_lstadd_back(&in, ft_lstnew(ft_strdup("me")));
	ft_lstadd_back(&in,ft_lstnew(ft_strdup("now")));

	void	**result = to_array(in, cpy_str);
	cr_assert_not_null(result);
	cr_expect_str_eq(result[0], "test");
	cr_expect_str_eq(result[1], "me");
	cr_expect_str_eq(result[2], "now");
}

Test(test_to_array, null_element_in_list_is_ignored_if_not_last)
{
	t_list	*in = ft_lstnew(ft_strdup("test"));
	ft_lstadd_back(&in, ft_lstnew(NULL));
	ft_lstadd_back(&in,ft_lstnew(ft_strdup("now")));

	void	**result = to_array(in, cpy_str);
	cr_assert_not_null(result);
	cr_expect_str_eq(result[0], "test");
	cr_expect_str_eq(result[1], "now");
}