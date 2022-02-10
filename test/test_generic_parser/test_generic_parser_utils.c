//
// Created by fschlute on 2/10/22.
//

#include "test_generic_parser_utils.h"

#define INVALID_LINE line_no == 3

void *generate_dummy_struct(const char *file_name)
{
	return (ft_calloc(1, sizeof (t_dummy_struct)));
	(void) file_name;
}

void *generate_dummy_struct_broken(const char *file_name)
{
	return (NULL);
	(void) file_name;
}

int fill_dummy_struct_line_wise(const char *line, void *s_struct, int line_no)
{
	if (INVALID_LINE)
		return (1);
	((t_dummy_struct *) s_struct)->content[line_no] = ft_atoi(line);
	return (0);
}

int fill_dummy_struct_grid_wise(const char *str, void *s_struct, int line_no,
								int column_no)
{
	((t_dummy_struct *) s_struct)->content[column_no] = ft_atoi(str);
	return (0);
	(void) line_no;
}

void clean_up_non_allocated(void *in)
{
	(void) in;
}

void assert_struct_filled_correctly(const t_dummy_struct *res)
{
	for (int i = 0; i < 3; i++)
		cr_expect_eq(res->content[i], i, "act %d, exp: %d", res->content[i], i);
}
