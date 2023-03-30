/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:33:04 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/30 22:01:50 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export(char **args, char ***envp)
{
	char	*arg_copy;
	char	*key;
	char	*value;
	char	*temp;

	if (get_dptr_size(args) == 1)
		return export_no_option(*envp);
	while (*(++args))
	{
		if (!(*envp))
			return (1);
		arg_copy = ft_strdup(*args);
		temp = ft_strchr(arg_copy, '=');
		if (temp == NULL)
		{
			if (arg_copy[0] != '_' && !ft_isalpha(arg_copy[0]))
			{
				printf("bash: export: `%s': not a valid identifier\n", arg_copy);
				free(arg_copy);
				continue ;
			}
			else
				value = "";
		}
		else
		{
			*temp = 0;
			key = arg_copy;
			value = temp + 1;
			if (key[0] != '_' && !ft_isalpha(key[0]))
			{
				printf("bash: export: `%s': not a valid identifier\n", key);
				free(arg_copy);
				continue ;
			}
		}
		// export 1=B, A=1 일 경우 첫번째 거는 안되지만 두번째건 됨
		//이경우 에러 메세지도 출력
		set_env_value(envp, arg_copy, value);
		free(arg_copy);
	}
	return (0);
}

int	export_no_option(char **envp)
{
	char	**envp_copy;
	int		i;

	envp_copy = dptr_dup(envp);
	ft_sort_ascii(envp_copy, get_dptr_size(envp_copy));
	i = -1;
	while (envp_copy[++i])
		printf("declare -x %s\n", envp[i]);
	free_dptr(envp_copy, DEFAULT);
	return (0);
}
