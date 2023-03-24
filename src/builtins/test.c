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
	// printf("%s", g_info.envp[0]);
	// char **cmds = ft_split("eui/jin/jjang", '/');
	// char *str = str_total_join(cmds, "/");
	// printf("%s",str);
	// char *str2 = get_env_value(g_info.envp, "HOME");
	// printf("%s", str2);
	cd("~/Desktop");
	pwd();
	// cd("~/Desktop");
	// pwd();
	system("leaks a.out");
	
	// int i = 0;
	// while(1)
	// 	if (i == 0)
	// 		pwd();
	// 	i++;
	// 	;
	// return (0);
}