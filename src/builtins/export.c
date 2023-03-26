#include "builtins.h"

int export(char *arg, char **envp)
{
    char    **arg_arr;
    char    *key;
    char    *value;
    char    *temp;

    if (!arg || !envp)
        return (1);
    if (ft_strchr(arg, '=') == NULL)
        return (1);
    temp = ft_strchr(arg, '=');
    *temp = 0;
    key = arg_arr;
    value = temp + 1;
    return (0);
}