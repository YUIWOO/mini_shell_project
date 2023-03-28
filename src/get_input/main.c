#include "../include/main.h"

int exit_code;
char **g_envp;

int main(int argc, char **argv, char **envp)
{
    int ret;
    char *line;
	t_execution *execution_ar;
	struct termios term;
	static char **s_envp;
	//s_envp = dptr_dup(envp);
	envp = dptr_dup(envp);

	input_handler(&term);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGQUIT, signal_handler);

	//char *str = ft_strdup("YE=/"12");
	//export(str, &envp);
	exit_code = 0;
    while (1)
    {
        line = readline("bash $ ");
        if (line)
        {
			add_history(line);
			if(!is_valid_line(line))
			{
				printf("syntax error\n");
				free(line);
				continue;
			}
			execution_ar = str_to_execution(line, &s_envp);
			add_history(line);
            free(line);
            line = NULL;
			if(execution_ar)
			{
				//print_all_execution(execution_ar);
				exit_code = execute_all(execution_ar, &s_envp); //종료값을 $?코드로 바꿀생각 해야할듯 ?
				free_execution_ar(execution_ar);
			}
			//system("leaks a.out");
        }
        else
        {
			print_eof();
			exit(0);
        }
    }
    return (0);
}
