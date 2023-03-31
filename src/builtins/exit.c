/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:49:23 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/31 12:42:27 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static	int	check_digit(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

static int	is_valid(char *num_str)
{
	int	i;
	int	space_idx;

	i = 0;
	while (num_str[i])
	{
		if (num_str[i] != ' ')
			break ;
		i++;
	}
	if (num_str[i] == '+' || num_str[i] == '-')
		i++;
	while (num_str[i])
	{
		if (ft_isdigit(num_str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long long	get_exit_status(const char *str)
{
	unsigned long long	num;
	int					i;
	long long			sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (check_digit(str[i]))
	{
		if (sign == 1 && num > 9223372036854775807ULL)
			return (-1);
		if (sign == -1 && num > 9223372036854775808ULL)
			return (-1);
		num = (str[i] - '0') + num * 10;
		i++;
	}
	return (sign * (long long)num % 256);
}

static void	print_exit_error_message(char *str)
{
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

void	ms_exit(char **arg)
{
	if (get_dptr_size(arg) == 1)
		exit(0);
	if (!is_valid(arg[1]))
	{
		print_exit_error_message(arg[1]);
		exit(255);
	}
	if (get_exit_status(arg[1]) == -1)
	{
		print_exit_error_message(arg[1]);
		exit(255);
	}
	exit((int)ft_atoll(arg[1]) % 256);
}
