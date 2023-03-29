#include "../include/main.h"

static void make_execution(t_execution *exe_ptr, char *str_ar, char ***envp, int exit_code)
{
	char **token_ar = make_token(str_ar); //tap 처리 필요
	categorize_token(exe_ptr, token_ar, envp, exit_code);
	exe_ptr->is_terminated = NOT_NULL_STATE;
}

static t_execution *make_execution_ar(char** str_ar, char ***envp, int exit_code)
{
	t_execution *ret_ar;
	int i = 0;
	while(str_ar[i])
		i ++;
	ret_ar = malloc(sizeof(t_execution) * (i + 1));
	ret_ar[i].is_terminated = NULL_STATE;
	i = 0;
	while(str_ar[i])
	{
		make_execution(ret_ar + i, str_ar[i], envp, exit_code);
		free(str_ar[i]);
		i ++;
	}
	free(str_ar);
	return ret_ar;
}

t_execution *str_to_execution(char *line, char ***envp, int exit_code)
{
	t_execution *execution_ar;

	char **str_ar = pipe_split(line, '|');
	execution_ar = make_execution_ar(str_ar, envp, exit_code);
	return execution_ar;
}