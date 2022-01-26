#include "test_utils.h"

Test(test_lstiter, iterating_over_one_element_which_stores_a_zero_turns_this_into_a_one)
{
	int		content = 0;
	t_list	*lst = ft_lstnew(&content);

	ft_lstiter(lst, &test_lst_intcontent_add_one);

	cr_assert_eq(*(int *) lst->content, 1);
}

Test(test_lstiter, iterating_over_three_elements_which_store_a_zero_turns_them_into_ones)
{
	int		content_of_first = 0;
	int		content_of_second = 0;
	int		content_of_third = 0;
	t_list	*first = ft_lstnew(&content_of_first);
	t_list	*second = ft_lstnew(&content_of_second);
	t_list	*third = ft_lstnew(&content_of_third);
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);

	ft_lstiter(first, &test_lst_intcontent_add_one);

	cr_assert_eq(*(int *) first->content, 1);
	cr_assert_eq(*(int *) second->content, 1);
	cr_assert_eq(*(int *) third->content, 1);
}

// how to make these tests less redundant?