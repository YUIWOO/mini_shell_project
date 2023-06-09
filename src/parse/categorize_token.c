/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:10:04 by youngwch          #+#    #+#             */
/*   Updated: 2023/03/29 20:13:42 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	set_exec_count(int *exec_count, char **token_ar)
{
	int	i;

	i = 0;
	exec_count[0] = 0;
	exec_count[1] = 0;
	while (token_ar[i])
	{
		if (token_ar[i][0] == '>' || token_ar[i][0] == '<')
				exec_count[1]++;
		else
			exec_count[0]++;
		i ++;
	}
}

static void	alloc_exec_ptr_member(t_execution *exe_ptr, int *exec_count)
{
	exe_ptr->exev_argv = malloc(sizeof(char *) * (exec_count[0] + 1));
	exe_ptr->exev_argv[exec_count[0]] = NULL;
	exe_ptr->redirect_ar = malloc(sizeof(t_redirect) * (exec_count[1] + 1));
	exe_ptr->redirect_ar[exec_count[1]].type = NULL_STATE;
}

static void	allign_exec_ptr(t_execution *exe_ptr, char **token_ar, char ***envp)
{
	int	i;
	int	argv_count;
	int	redirect_count;

	i = -1;
	redirect_count = -1;
	argv_count = 0;
	while (token_ar[++i])
	{
		if (token_ar[i][0] == '>' || token_ar[i][0] == '<')
		{
			set_redirect_token(&exe_ptr->redirect_ar[++redirect_count],
				token_ar[i]);
			exe_ptr->redirect_ar[redirect_count].file_name
				= token_to_good_token(
					exe_ptr->redirect_ar[redirect_count].file_name, envp);
		}
		else
			exe_ptr->exev_argv[argv_count++]
				= token_to_good_token(token_ar[i], envp);
	}
}

void	categorize_token(t_execution *exe_ptr, char **token_ar, char ***envp)
{
	int	i;
	int	cmd_flag;
	int	exec_count[2];

	i = 0;
	cmd_flag = 0;
	set_exec_count(exec_count, token_ar);
	alloc_exec_ptr_member(exe_ptr, exec_count);
	allign_exec_ptr(exe_ptr, token_ar, envp);
	free(token_ar);
}
