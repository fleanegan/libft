#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_ft_lstlast, list_with_one_element_returns_this_element)
{
	t_list *lst = ft_lstnew(NULL);

	t_list *res_act = ft_lstlast(lst);

	cr_assert_eq(lst, res_act);
}

Test(test_ft_lstlast, list_with_two_element_returns_second_elements)
{
	t_list *first = ft_lstnew(NULL);
	t_list *second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	t_list *res_act = ft_lstlast(first);

	cr_assert_eq(res_act, second);
}

Test(test_ft_lstlast, if_null_passed_return_null)
{
	t_list	*l;
	t_list	*expected;
	t_list	*actual;

	l = NULL;
	expected = NULL;
	actual = ft_lstlast(l);

	cr_assert_eq(expected, actual);
}

