#include <criterion/criterion.h>
#include "test_utils.h"

void	*func_add_one_to_int(void *old_content)
{
	int	*result;

	result = malloc(sizeof(old_content));
	*result = *(int *) old_content + 1;
	return (result);
}

void	*return_incrementing_number(void *content)
{
	static	int i = -1;
	int *tmp = malloc(sizeof(int));
	i++;
	*tmp = i;
	return tmp;
	(void) content;
}

void	*return_input(void *content)
{
	return (content);
}

Test(test_lstmap, a_function_that_does_noting_returns_a_copy)
{
	t_list *in = generate_list_of_n_zeros(3);

	t_list *cpy = ft_lstmap(in, return_input, del);

	cr_assert_eq(*(int *)cpy->content, 0, "act: %d", *(int *)cpy->content);
	cpy = cpy->next;
	cr_assert_eq(*(int *)cpy->content, 0, "act: %d", *(int *)cpy->content);
	//*/
}

Test(test_lstmap, a_function_that_adds_one_more_creates_ascending_counter)
{
	t_list *in = generate_list_of_n_zeros(7);

	t_list *cpy = ft_lstmap(in, return_incrementing_number, del);

	cr_assert_eq(*(int *)cpy->content, 0, "act: %d", *(int *)cpy->content);
	cpy = cpy->next;
	cr_assert_eq(*(int *)cpy->content, 1, "act: %d", *(int *)cpy->content);
	cpy = cpy->next;
	cr_assert_eq(*(int *)cpy->content, 2, "act: %d", *(int *)cpy->content);
}

// how to make these tests less redundant?