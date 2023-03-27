/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:39:16 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 19:36:47 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_slash_char(char *str, char target)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	while (str[++i])
	{
		if (str[i] != target)
			return (0);
	}
	return (1);
}

int	echo(char **arg)
{
	int	new_line;
	int	i;

	new_line = 1;
	i = -1;
	while (arg[++i])
	{
		if (is_slash_char(arg[i], 'n'))
			new_line = 0;
		else
			break ;
	}
	if (new_line)
		i = 0;
	printf("%s", arg[i]);
	while (arg[++i])
		printf(" %s", arg[i]);
	if (new_line)
		printf("\n");
	return (0);
}
