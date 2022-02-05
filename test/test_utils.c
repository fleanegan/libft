#include <stddef.h>
#include "test_utils.h"

char	*generate_random_string(size_t len)
{
	char	*result;
	char 	*possible_chars;

	possible_chars = "qwertyuiopasdfghjklzxcvbnm0123456789 \n\t";
	result = (char *) malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	//srand(time(NULL));
	while (len-- > 0)
	{
		result[len] = possible_chars[rand() % 37];
	}
	return result;
}

void zero_array(char *arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

int calc_dst_memory(size_t src_len_var, size_t dst_len_var) {
	return (int) src_len_var + (int) dst_len_var + SPACE_NULLTERMIN;
}

void allocate_test_object_memory(size_t src_len_var, size_t dst_len_var, strcat_obj_ptr result) {
	result->src = (char *) malloc(sizeof(char) * src_len_var);
	result->dst_orig = (char *) malloc(sizeof(char) * calc_dst_memory(src_len_var, dst_len_var));
	result->dst_own = (char *) malloc(sizeof(char) * calc_dst_memory(src_len_var, dst_len_var));
}

void zero_init_test_object_memory(size_t src_len_var, size_t dst_len_var, strcat_obj_ptr result) {
	zero_array(result->dst_own, calc_dst_memory(src_len_var, dst_len_var));
	zero_array(result->dst_orig, calc_dst_memory(src_len_var, dst_len_var));
	zero_array(result->src, src_len_var);
}

void fill_test_object_data(const char *rand_string_dst, const char *rand_string_src, size_t src_len_var,
						   size_t dst_len_var, size_t size_var, strcat_obj_ptr result) {
	result->size_parameter = size_var;
	strlcpy(result->src, rand_string_src, src_len_var + SPACE_NULLTERMIN);
	strlcpy(result->dst_own, rand_string_dst, dst_len_var + SPACE_NULLTERMIN);
	strlcpy(result->dst_orig, rand_string_dst, dst_len_var + SPACE_NULLTERMIN);
}

strcat_obj_ptr populate_one_test_object(const char *rand_string_dst, const char *rand_string_src,
										size_t src_len_var, size_t dst_len_var, size_t size_var) {
	strcat_obj_ptr result = (strcat_obj_ptr) malloc(sizeof(struct strcat_obj));
	allocate_test_object_memory(src_len_var, dst_len_var, result);
	zero_init_test_object_memory(src_len_var, dst_len_var, result);
	fill_test_object_data(rand_string_dst, rand_string_src, src_len_var, dst_len_var, size_var, result);
	return result;
}

strcat_obj_ptr generate_test_strings(size_t max_length)
{
	size_t	dst_max_length = max_length * 2 + SPACE_NULLTERMIN;
	char 	*rand_string_dst = generate_random_string(max_length);
	char 	*rand_string_src = generate_random_string(max_length);
	int 	ctr = 0;
	int 	test_permutation_count = (int) ((max_length + SPACE_NULLTERMIN) *
										   (max_length + SPACE_NULLTERMIN) *
										   (dst_max_length + 2) + SPACE_NULLTERMIN);
	strcat_obj_ptr result = (strcat_obj_ptr) malloc(sizeof(struct strcat_obj) * test_permutation_count);

	for (size_t src_len_var = 0; src_len_var < max_length + SPACE_NULLTERMIN; src_len_var++) {
		for (size_t dst_len_var = 0; dst_len_var < max_length + SPACE_NULLTERMIN; dst_len_var++) {
			for (size_t size_var = 0; size_var < dst_max_length + SPACE_NULLTERMIN + 1; size_var++) {
				result[ctr] = *populate_one_test_object(rand_string_dst, rand_string_src, src_len_var, dst_len_var, size_var);
				ctr++;
			}
		}
		result[ctr].src = NULL;
	}
	return result;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

		int replacement_for_broken_criterion_stdout_matcher(char *compare_string, FILE *f_stream) {
			size_t read;
			char buf[1];
			size_t len = strlen(compare_string);
			size_t	ctr = 0;
			int matches = 1;

			while ((read = fread(buf, 1, sizeof(char), f_stream)) > 0) {
				ctr++;
				if (!compare_string || *buf != *compare_string++)
					matches = 0;
			}
			if (read)
				while (fread(buf, 1, sizeof (buf), f_stream) > 0) ctr++;
			if (len != ctr)
				matches = 0;
			return (matches);
		}

void cr_bugfix_assert_str_stdout(char *compare_string)
{
	cr_assert(replacement_for_broken_criterion_stdout_matcher(compare_string, cr_get_redirected_stdout()));
}

void cr_bugfix_assert_str_stderr(char *compare_string)
{
	cr_assert(replacement_for_broken_criterion_stdout_matcher(compare_string, cr_get_redirected_stderr()));
}

void	del(void *content)
{
	if (content)
		// do not use printf as it writes to buffer
		write(1, ((char *) content), ft_strlen(content));
	free(content);
}

void	test_lst_intcontent_add_one(void *content)
{
	*((int *) content) += 1;
}

void *cpy_lstcontent_int(void *content)
{
	int	*copied_content = malloc(sizeof(int));
	*(int *)(copied_content) = *(int *)content;
	return (copied_content);
}

t_list *generate_list_of_n_zeros(size_t n)
{
	int		*tmp_content;
	t_list	*result;
	t_list	*tmp;

	result = NULL;
	for (size_t i = 0; i < n; i++)
	{
		tmp_content = malloc(sizeof(int));
		*tmp_content = 0;
		tmp = ft_lstnew(tmp_content);
		if (!result)
			result = tmp;
		else
			ft_lstadd_back(&result, tmp);
	}
	return (result);
}