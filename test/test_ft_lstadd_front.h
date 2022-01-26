#include "test_utils.h"

Test(test_lstadd_front, next_of_new_is_old)
{
	t_list *old = ft_lstnew(NULL);
	t_list *lst_pointer = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst_pointer, new);

	cr_assert_eq(new->next, old);
}

Test(test_lstadd_front, old_is_second_after_add_front)
{
	t_list *old = ft_lstnew(NULL);
	t_list *lst_pointer = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst_pointer, new);

	cr_assert_eq(new, lst_pointer);
}

Test(test_lstadd_front, prev_is_set)
{
	t_list *old = ft_lstnew(NULL);
	t_list *lst = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst, new);

	cr_assert_eq(old->prev, new);
}

Test(test_lstadd_front, prev_is_not_set_on_empty_lists)
{
	t_list *old = NULL;
	t_list *lst = old;
	t_list *new = ft_lstnew(NULL);

	ft_lstadd_front(&lst, new);

	cr_assert_null(new->next);
}

Test(test_lstadd_front, new_element_has_prev_set_to_null)
{
	t_list *old = NULL;
	t_list *lst = old;
	t_list *new = ft_lstnew(NULL);
	new->prev = (t_list *)1;

	ft_lstadd_front(&lst, new);

	cr_assert_null(new->prev);
}
