#include "test_utils.h"

Test(test_add_element_at_index, add_element_to_list_with_one_element)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*new = ft_lstnew(NULL);

    ft_lstadd_element_at_index(&first, new, 1);

	cr_assert_eq(first->next, new);
}

Test(test_add_element_at_index, adding_an_element_does_not_break_connection_to_last)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*last = ft_lstnew(NULL);
	t_list	*new = ft_lstnew(NULL);
	ft_lstadd_back(&first, last);

    ft_lstadd_element_at_index(&first, new, 1);

	cr_expect_eq(first->next, new);
	cr_expect_eq(new->next, last);
}

Test(test_add_element_at_index, adding_an_element_at_specific_index)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	t_list	*new = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

    ft_lstadd_element_at_index(&first, new, 2);

	cr_expect_eq(second->next, new);
}

Test(test_add_element_at_index, if_element_exceeds_index_return_minus_one)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*new = ft_lstnew(NULL);

	int	res_act = ft_lstadd_element_at_index(&first, new, 2);

	cr_expect_eq(res_act, -1);
}

Test(test_add_element_at_index, prev_node_is_set_correctly)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);
	t_list	*new = ft_lstnew(NULL);

	ft_lstadd_element_at_index(&first, new, 1);

	cr_expect_eq(second->prev, new);
	cr_expect_eq(new->prev, first);
}

Test(test_add_element_at_index, setting_prev_on_first_element)
{
	t_list	*first = ft_lstnew(NULL);
	t_list	*new = ft_lstnew(NULL);
	t_list	*lst = first;

	ft_lstadd_element_at_index(&lst, new, 0);

	cr_expect_eq(first->prev, new);
	cr_expect_eq(new->prev, NULL);
}