/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:09:00 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 20:51:43 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_builtins(char **args, char ***envp)
{
	if (!args)
		return (-1);
	if (ft_strncmp(args[0], "echo", ft_strlen("echo")) == 0)
		return (echo(args));
	if (get_dptr_size(args) == 0)
	{
		if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
			return (cd("~", envp));
		if (ft_strncmp(args[0], "env", ft_strlen("env")) == 0)
			return (env(*envp));
		if (ft_strncmp(args[0], "exit", ft_strlen("exit")) == 0)
			ms_exit(args);
		if (ft_strncmp(args[0], "pwd", ft_strlen("pwd")) == 0)
			return (pwd());
	}
	if (get_dptr_size(args) == 1)
	{
		if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
			return (cd(args[0], envp));
		if (ft_strncmp(args[0], "export", ft_strlen("export")) == 0)
			return (export(args[0], envp));
		if (ft_strncmp(args[0], "unset", ft_strlen("unset")) == 0)
			return (unset(args[0], envp));
	}
	return (-1);
}
