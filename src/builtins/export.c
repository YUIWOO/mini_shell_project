/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:33:04 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 12:54:25 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int export(char *arg, char ***envp)
{
    char    *arg_copy;
    char    *key;
    char    *value;
    char    *temp;

    if (!arg || !(*envp))
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