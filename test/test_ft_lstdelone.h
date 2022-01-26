#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/libft.h"
#include "test_utils.h"

Test(test_lstdelone, passing_a_delete_function_which_prints_content_prints_1_when_deleting_correctly)
{
	char	*dummy_content_string = "1";
	char	*content = ft_strdup(dummy_content_string);
	t_list *lst = ft_lstnew(content);
	cr_expect_str_eq(lst->content, dummy_content_string);

	cr_redirect_stdout();

	ft_lstdelone(lst, del);

	cr_assert_stdout_eq_str(dummy_content_string);
}