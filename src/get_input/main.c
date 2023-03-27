#include "../include/main.h"

int main(int argc, char **argv, char **envp)
{
    int ret;
    char *line;
	t_execution *execution_ar;
    signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
    while (1)
    {
        line = readline("r o u ghshell $ ");
        if (line)
        {
			execution_ar = str_to_execution(line);
			add_history(line);
            free(line);
            line = NULL;
			if(execution_ar)
			{
				//print_all_execution(execution_ar);
				int exit_code = execute_all(execution_ar, envp); //종료값을 $?코드로 바꿀생각 해야할듯 ?
				printf("exit : %d\n", exit_code);
				free_execution_ar(execution_ar);
			}
			//system("leaks a.out");
        }
        else
        {
            //printf("ctrl + d\n");
			exit(0);
        }
    }
    return (0);
}
