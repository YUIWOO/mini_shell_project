/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:22:29 by youngwch          #+#    #+#             */
/*   Updated: 2023/03/29 20:22:29 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

extern int	g_exit_code;

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_code = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		return ;
	}
	if (signum == SIGTERM)
	{
		printf(" exit\n");
		exit(-1);
	}
	if (signum == SIGQUIT)
	{
		return ;
	}
}

void	input_handler(struct termios *term_ptr)
{
	tcgetattr(STDIN_FILENO, term_ptr);
	term_ptr->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, term_ptr);
}

void	print_eof(void)
{
	printf("\033[1A");
	printf("\033[6C");
	printf(" exit\n");
	exit(0);
}
