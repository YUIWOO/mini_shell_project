#include "builtins.h"

t_info	g_info;
// int main(int argc, char **argv, char **envp)
// {
// 	t_info	g_info;

// 	g_info.envp = envp;
// 	env(envp);
// 	pwd();
// 	// system("leaks a.out");
// }

int main(int argc, char **argv, char **envp)
{
	g_info.envp = dptr_dup(envp);
	// cd("..");
	// pwd();
	// env(g_info.envp);
	// env(g_info.envp);
	export("EUI=JIN", &g_info.envp);
	env(g_info.envp);
	system("leaks a.out");
	// env(g_info.envp);
	// int i = 0;
	// while(1)
	// 	if (i == 0)
	// 		pwd();
	// 	i++;
	// 	;
	// return (0);
}