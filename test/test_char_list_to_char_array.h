#include "test_utils.h"

Test(test_char_list_to_char_array, do_nothing_if_input_is_empty_list)
{
t_list	*lst = NULL;

char	*res = char_list_to_char_array(lst);

cr_assert_null(res);
}

Test(test_char_list_to_char_array, return_char_if_size_is_one)
{
t_list	*lst = ft_lstnew(strdup("a"));

char	*res = char_list_to_char_array(lst);

cr_assert_eq(*res, 'a');
free(res);
}

Test(test_char_list_to_char_array, return_zeroterminating_string_if_has_more)
{
t_list	*lst = ft_lstnew(strdup("a"));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));

char	*res = char_list_to_char_array(lst);

cr_assert_str_eq(res, "abc");
free(res);
}

Test(test_char_list_to_char_array, stop_if_content_is_zeroterminating)
{
t_list	*lst = ft_lstnew(strdup("a"));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("\0")));
ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));

char	*res = char_list_to_char_array(lst);

cr_assert_str_eq(res, "ab");
cr_assert_neq(res[3], 'c');
free(res);
}