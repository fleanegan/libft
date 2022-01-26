#include "test_utils.h"

int	dummy_compare_ascending(void *in, void *comp)
{
	return (*(char *)in <= *(char *)comp);
}

int	dummy_compare_print_on_call(void *in, void *comp)
{
	write(1, "1", 1);
	return (1);
	(void) in;
	(void) comp;
}

Test(test_lstsort, sorting_NULL_does_nothing)
{
	t_list *lst = NULL;

	ft_lstsort(&lst, dummy_compare_ascending);
}

Test(test_lstsort, sorting_one_element_does_nothing)
{
	t_list *lst = ft_lstnew("\1");

	ft_lstsort(&lst, dummy_compare_ascending);
}

Test(test_lstsort, sorting_two_unordered_elements_swaps_them)
{
	t_list *a = ft_lstnew("a");
	t_list *b = ft_lstnew("b");
	t_list *lst = b;
	ft_lstadd_back(&lst, a);

	ft_lstsort(&lst, dummy_compare_ascending);

	cr_assert_eq(*(char *)lst->content, 'a');
}

Test(test_lstsort, sorting_two_ordered_elements_does_nothing)
{
	t_list *a = ft_lstnew("a");
	t_list *b = ft_lstnew("b");
	t_list *lst = a;
	ft_lstadd_back(&lst, b);

	ft_lstsort(&lst, dummy_compare_ascending);

	cr_assert_eq(ft_lstget_element_by_index(lst, 0), a, "is: %s", (char *) ft_lstget_element_by_index(lst, 0)->content);
	cr_assert_eq(ft_lstget_element_by_index(lst, 1), b, "is: %s", (char *) ft_lstget_element_by_index(lst, 1)->content);
}

Test(test_lstsort, sorting_three_unordered_elements_gets_them_sorted)
{
	int da = 1;
	int db = 2;
	int dc = 0;
	t_list *a = ft_lstnew(&da);
	t_list *b = ft_lstnew(&db);
	t_list *c = ft_lstnew(&dc);
	t_list *lst = a;
	ft_lstadd_back(&lst, b);
	ft_lstadd_back(&lst, c);

	ft_lstsort(&lst, dummy_compare_ascending);

	cr_assert_eq(*(int *)lst->content, 0);
	cr_assert_eq(*(int *)lst->next->content, 1);
	cr_assert_eq(*(int *)lst->next->next->content, 2);
}

Test(test_lstsort, sorting_with_repeated_of_three)
{
	int da = 1;
	int db = 1;
	int dc = 0;
	t_list *a = ft_lstnew(&da);
	t_list *b = ft_lstnew(&db);
	t_list *c = ft_lstnew(&dc);
	t_list *lst = a;
	ft_lstadd_back(&lst, b);
	ft_lstadd_back(&lst, c);

	ft_lstsort(&lst, dummy_compare_ascending);

	cr_assert_eq(*(int *)lst->content, 0);
	cr_assert_eq(*(int *)lst->next->content, 1);
	cr_assert_eq(*(int *)lst->next->next->content, 1);
}
//*/
Test(test_lstsort, long_unordered_list)
{
	t_list	*stack = ft_lstnew(malloc_int(30));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(2)));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(-2)));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(4)));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(3)));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(0)));
	ft_lstadd_back(&stack, ft_lstnew(malloc_int(31)));

	ft_lstsort(&stack, dummy_compare_ascending);
	cr_assert_eq(* (int *)stack->content, -2);
	cr_assert_eq(* (int *) ft_lstlast(stack)->content, 31);
}

