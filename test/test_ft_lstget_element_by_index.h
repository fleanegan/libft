#include "test_utils.h"

Test(test_ft_lstget_element_by_index, get_element_zero)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*res_act = ft_lstget_element_by_index(first, 0);
	cr_assert_eq(res_act, first);
}

Test(test_ft_lstget_element_by_index, get_element_one)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	t_list	*res_act = ft_lstget_element_by_index(first, 1);
	cr_assert_eq(res_act, second);
}

Test(test_ft_lstget_element_by_index, if_id_out_of_range_return_NULL)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*res_act = ft_lstget_element_by_index(first, 1);
	cr_assert_null(res_act);
}

int	where_content_equals(void *content, int in)
{
	if (content && *(int *)content == in)
		return (1);
	return (0);
}

Test(test_ft_lstget_element_by_attribute, if_not_found_return_NULL)
{
	t_list	*first = ft_lstnew(NULL);

	t_list	*res_act = ft_lstget_element_by_function(first,
													   where_content_equals, 1);
	cr_assert_null(res_act);
}

Test(test_ft_lstget_element_by_attribute, return_element_for_which_compare_function_returns_true)
{
	t_list	*first = ft_lstnew(malloc_int(1));

	t_list	*res_act = ft_lstget_element_by_function(first,
													   where_content_equals, 1);
	cr_assert_eq(res_act, first);
}

Test(test_ft_lstget_element_by_attribute, test_with_longer_list)
{
	t_list	*first = ft_lstnew(malloc_int(1));
	t_list	*searched_item = ft_lstnew(malloc_int(0));
	ft_lstadd_back(&first, ft_lstnew(malloc_int(1)));
	ft_lstadd_back(&first, ft_lstnew(malloc_int(1)));
	ft_lstadd_back(&first, ft_lstnew(malloc_int(1)));
	ft_lstadd_back(&first, ft_lstnew(malloc_int(1)));
	ft_lstadd_back(&first, searched_item);

	t_list	*res_act = ft_lstget_element_by_function(first,
													   where_content_equals, 0);
	cr_assert_eq(res_act, searched_item);
}