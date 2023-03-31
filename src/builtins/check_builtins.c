/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:09:00 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/31 12:49:25 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_same_str(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	if (ft_strncmp(str1, str2, ft_strlen(str1)) != 0)
		return (0);
	return (1);
}

int	check_builtins(char **args, char ***envp)
{
	if (!args || !*args)
		return (-1);
	if (is_same_str(args[0], "echo"))
		return (echo(args));
	if (is_same_str(args[0], "pwd"))
		return (pwd());
	if (is_same_str(args[0], "cd"))
		return (cd(args[1], envp));
	if (is_same_str(args[0], "export"))
		return (export(args, envp));
	if (is_same_str(args[0], "unset"))
		return (unset(args, *envp));
	if (is_same_str(args[0], "exit"))
		ms_exit(args);
	if (is_same_str(args[0], "env"))
		return (env(args, *envp));
	return (-1);
}
