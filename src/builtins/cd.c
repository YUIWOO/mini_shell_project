#include "builtins.h"

static int	change_pwd_env(char *new_path, char ***envp)
{
	char	*buffer;

	if (chdir(new_path) == -1)
	{
		show_error("cd");
		return (1);
	}
	buffer = get_pwd();
	set_env_value(envp, "PWD", buffer);
	free(buffer);
	return (0);
}


int	cd(char *path, char ***envp)
{
	char	**path_info;
	char	*new_path;
	char	*buffer;

	buffer = get_pwd();
	set_env_value(envp, "OLDPWD", buffer);
	free(buffer);
	return (change_pwd_env(path, envp));
}
