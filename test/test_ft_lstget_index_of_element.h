#include "test_utils.h"

Test(test_lstget_index_of_element, return_negative_if_not_found)
{
	t_list	*lst = NULL;

	int	index = ft_lstget_index_of_element(lst, lst);

	cr_assert_lt(index, 0);
}

Test(test_lstget_index_of_element, return_zero_if_first_item)
{
	t_list	*lst = ft_lstnew(NULL);

	int	index = ft_lstget_index_of_element(lst, lst);

	cr_assert_eq(index, 0);
}

Test(test_lstget_index_of_element, return_index_if_found)
{
	t_list	*lst = ft_lstnew(NULL);
	t_list	*b = ft_lstnew(NULL);
	t_list	*c = ft_lstnew(NULL);
	ft_lstadd_back(&lst, b);
	ft_lstadd_back(&lst, c);

	int	index = ft_lstget_index_of_element(lst, c);

	cr_assert_eq(index, 2);
}