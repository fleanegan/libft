#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <time.h>
# include <malloc.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../src/libft.h"
# include "bsd/string.h"
# include "../src/libft_auxilliar.h"
# include <criterion/criterion.h>
# include <criterion/theories.h>
# include <ctype.h>
# include <string.h>
# include <criterion/redirect.h>
//# include "test_generic_parser/"

typedef struct strcat_obj
{
	char 	*src;
	char 	*dst_own;
	char 	*dst_orig;
	size_t	size_parameter;
} *strcat_obj_ptr;

char			*generate_random_string(size_t len);
void			zero_array(char *arr, size_t size);
void			ft_putstr(char *str);
strcat_obj_ptr	generate_test_strings(size_t max_length);
void			del(void *content);
void			cr_bugfix_assert_str_stdout(char *compare_string);
void			cr_bugfix_assert_str_stderr(char *compare_string);
int				replacement_for_broken_criterion_stdout_matcher(char *compare_string, FILE *f_stream);
void			test_lst_intcontent_add_one(void *content);
t_list			*generate_list_of_n_zeros(size_t n);
void			*cpy_lstcontent_int(void *content);

#endif	 // TEST_UTILS_H
