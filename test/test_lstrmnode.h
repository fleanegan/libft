#include "test_utils.h"

Test(test_lstrmnode, NULL_input_does_not_do_anything)
{
	ft_lstrmnode(NULL, NULL, free);
}

Test(test_lstrmnode, removing_node_from_list_with_with_entry_sets_list_to_NULL)
{
	t_list	*node_to_delete = ft_lstnew(NULL);

	ft_lstrmnode(&node_to_delete, node_to_delete, free);

	cr_assert_null(node_to_delete);
}

Test(test_lstrmnode, removing_from_begin_of_list_with_two_nodes_sets_lst_to_remaining_node)
{
	t_list	*node_to_delete = ft_lstnew(NULL);
	t_list	*lst = ft_lstnew(NULL);
	t_list	*node_to_stay = lst;
	ft_lstadd_front(&lst, node_to_delete);

	ft_lstrmnode(&lst, node_to_delete, free);
	node_to_delete = NULL;

	cr_assert_eq(lst, node_to_stay);
	cr_assert_null(lst->prev);
}

Test(test_lstrmnode, removing_end_of_list_with_two_nodes_sets_lst_to_remaining_node)
{
	t_list	*node_to_delete = ft_lstnew(NULL);
	t_list	*lst = ft_lstnew(NULL);
	t_list	*node_to_stay = lst;
	ft_lstadd_back(&lst, node_to_delete);

	ft_lstrmnode(&lst, node_to_delete, free);
	node_to_delete = NULL;

	cr_assert_eq(lst, node_to_stay);
	cr_assert_null(lst->next);
}

Test(test_lstrmnode, removing_from_list_with_three_nodes_links_next_and_previous)
{
	t_list	*lst = generate_list_of_n_zeros(3);
	t_list	*node_to_delete = lst->next;
	t_list	*node_before = node_to_delete->prev;
	t_list	*node_after = node_to_delete->next;

	ft_lstrmnode(&lst, node_to_delete, free);
	node_to_delete = NULL;

	cr_assert_null(node_before->prev);
	cr_assert_eq(node_before->next, node_after);
	cr_assert_eq(node_after->prev, node_before);
	ft_lstclear(&lst, free);
}