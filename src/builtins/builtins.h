/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:07 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/24 20:38:08 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "/Users/yuikim/MiniShell/libft/libft.h"//상대 경로로 표시할 필요 있음
int		env(char **envp);
int		pwd(void);
int		cd(char *path);

//utils
void	show_error(char *cmd);
char	*get_env_value(char **envp, char *key);
char	*set_env_value(char **envp, char *key, char *value);
void	free_dptr(char **dptr);
char	*str_total_join(char **words, char *operator);
int		get_dptr_size(char **dptr);
char	**dptr_dup(char **dptr);



//type
typedef struct s_info{
	char	**envp;
}	t_info;

#endif
