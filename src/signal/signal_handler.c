#include "../include/main.h"

void signal_handler(int signum)
{
    if (signum == SIGINT)
	{
		printf("\n");
    	rl_on_new_line();
    	rl_replace_line("", 1);
    	rl_redisplay();
		return;
	}
	if (signum == SIGQUIT) 
	{
		return ;
	}
}
