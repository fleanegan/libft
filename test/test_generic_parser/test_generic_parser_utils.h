#ifndef LIBFT_TEST_GENERIC_PARSER_UTILS_H
#define LIBFT_TEST_GENERIC_PARSER_UTILS_H
#include "../test_utils.h"

typedef struct	s_dummy_struct
{
	int content[3];
} t_dummy_struct;

void	*generate_dummy_struct(const char *file_name);
void	*generate_dummy_struct_broken(const char *file_name);
int		fill_dummy_struct_line_wise(const char *line, void * s_struct, int line_no);
int		fill_dummy_struct_grid_wise(const char *str, void * s_struct, int line_no, int column_no);
void	clean_up_non_allocated(void *in);
void assert_struct_filled_correctly(const t_dummy_struct *res);

#endif //LIBFT_TEST_GENERIC_PARSER_UTILS_H
