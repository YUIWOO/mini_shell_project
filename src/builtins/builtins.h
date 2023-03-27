/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:07 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/27 20:57:25 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"//상대 경로로 표시할 필요 있음
//define
# define HOME 1
# define DEFAULT 0

//builtin
int		env(char **envp);
int		pwd(void);
int		cd(char *path, char ***envp);
char	*get_pwd(void);
int		export(char *arg, char ***envp);
int		unset(char *key, char **envp);
int		echo(char **arg);
void	ms_exit(char **arg);

//utils
void	show_error(char *cmd);
char	*get_env_value(char **envp, char *key);
char	*set_env_value(char ***envp, char *key, char *value);
void	free_dptr(char **dptr, int opt);
char	*str_total_join(char **words, char *operator);
int		get_dptr_size(char **dptr);
char	**dptr_dup(char **dptr);
void	append_dptr(char ***dptr, char *statement);
void	set_env_statement(char **env_addr, char *key, char *value);
void	make_env_statement(char ***envp_ptr, char *key, char *value);

//type
typedef struct s_info{
	char	**envp;
}	t_info;

#endif
