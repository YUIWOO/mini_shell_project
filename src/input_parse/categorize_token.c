#include "../include/main.h"

static void set_exec_count(int *exec_count, char **token_ar)
{
	int i = 0;
	exec_count[0] = 0; //execve ar
	exec_count[1] = 0; //redirect
	while(token_ar[i])
	{
		if(token_ar[i][0] == '>' || token_ar[i][0] == '<')
			exec_count[1] ++;
		else
		{
			exec_count[0] ++;
		}
		i ++;
	}
}

static void alloc_exec_ptr_member(t_execution *exe_ptr, int *exec_count)
{
	exe_ptr->exev_argv = malloc(sizeof(char *) * (exec_count[1] + 1));
	exe_ptr->exev_argv[exec_count[0]] = NULL;
	exe_ptr->redirect_ar = malloc(sizeof(t_redirect) * (exec_count[2] + 1));
	exe_ptr->redirect_ar[exec_count[1]].type = NULL_STATE;
}

static void allign_exec_ptr(t_execution *exe_ptr, char **token_ar)
{
	int i = 0;
	int cmd_count = 0;
	int option_count = 0;
	int redirect_count = 0;

	while(token_ar[i])
	{
		if(token_ar[i][0] == '>' || token_ar[i][0] == '<')
		{
			set_redirect_token(&exe_ptr->redirect_ar[redirect_count++], token_ar[i]);
			// exe_ptr->redirect_ar[redirect_count++].file_name = token_ar[i];
		}
		else
		{
			exe_ptr->exev_argv[option_count++] = token_ar[i];
		}
		i ++;
	}
}

void categorize_token(t_execution *exe_ptr, char **token_ar)
{
	int i = 0;
	int cmd_flag = 0;
	int exec_count[3];

	set_exec_count(exec_count, token_ar);
	alloc_exec_ptr_member(exe_ptr, exec_count);
	allign_exec_ptr(exe_ptr, token_ar);
	free(token_ar);
}