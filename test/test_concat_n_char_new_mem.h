#include "test_utils.h"

Test(test_append_buf_until_nl, if_nl_is_at_pos_zero_only_append_nl)
{
char	*res = ft_strdup("test");
char 	*buf	= "\n";
int		chars_to_append = 5;

char *res_act = concat_n_char_new_mem(res, buf,
									  chars_to_append + SPACE_FOR_NEWLINE);

cr_assert_str_eq(res_act, "test\n");
free(res_act);
free(res);
}

Test(test_append_buf_until_nl, append_two_chars_from_buf)
{
char	*res = ft_strdup("test");
char 	*buf	= "a\n";
int		chars_to_append = 6;

char *res_act = concat_n_char_new_mem(res, buf,
									  chars_to_append + SPACE_FOR_NEWLINE);

cr_assert_str_eq(res_act, "testa\n");
free(res_act);
free(res);
}

Test(test_append_buf_until_nl, append_to_NULL_is_like_strdup)
{
char 	*buf	= "a";
int		len = 1;

char *res_act = concat_n_char_new_mem(NULL, buf, len);

cr_assert_str_eq(res_act, "a");
free(res_act);
}

Test(test_append_buf_until_nl, if_buf_is_NULL_return_NULL)
{
char 	*res = ft_strdup("a");
char 	*res_act = concat_n_char_new_mem(res, NULL, 1);

cr_assert_null(res_act);
free(res);
}