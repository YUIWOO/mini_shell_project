#include "builtins.h"

int export(char *arg, char **envp)
{
    char    *arg_copy;
    char    *key;
    char    *value;
    char    *temp;

    if (!arg || !envp)
        return (1);
    if (ft_strchr(arg, '=') == NULL)
        return (1);
    arg_copy = ft_strdup(arg);
    temp = ft_strchr(arg_copy, '=');
    *temp = 0;
    key = arg_copy;
    value = temp + 1;
    set_env_value(envp, key, value);
    free(key);
    return (0);
}