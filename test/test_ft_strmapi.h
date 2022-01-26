#include "test_utils.h"

char	test_map_function(unsigned int param, char to_be_mapped)
{
	return (1 + to_be_mapped);
	(void) param;
}

Test(test_strmapi, apply_add_one_to_string)
{
	char	*in = "abc";

	char	*res_act = ft_strmapi(in, test_map_function);

	cr_assert_str_eq(res_act, "bcd");
}