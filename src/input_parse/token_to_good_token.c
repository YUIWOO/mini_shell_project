#include "../include/main.h"

int is_env_var(char *str)
{
	int i = -1;
	if(str[++i] != '$')
		return 0;
	while(str[++i])
	{
		if(ft_isalpha(str[i]) || str[i] == '_')
			return 1;
	}
	return 0;
}
int get_env_var_length(char *str) //is env var 통과 후 달러위치에서 주면 됨
{
	int i = 1;
	while(ft_isalpha(str[++i]) || ft_isdigit(str[i]) || str[i] == '_')
	{
		// continue;
	}
	return i - 1;
}

char *change_env_var(char *token, int start, int end, char ***envp)
{
	//printf("%d %d\n", start, end);
	char *left_str = ft_substr(token, 0, start);
	char *key = ft_substr(token, start+1, end - start);
	char *middle_str = get_env_value(*envp, key);
	if(!middle_str)
		middle_str = "";
	//middle 밸류 없는경우 고려(널포인터 반환)
	char *right_str = ft_substr(token, end + 1, ft_strlen(token)-end-1);
	
	// printf("left : %s\n", left_str);
	// printf("key : %s\n", key);
	// printf("middle_str : %s\n", middle_str);
	// printf("right : %s\n", right_str);
	
	char *tmp_str = ft_strjoin(left_str, middle_str);
	//printf("tmp_str : %s\n", tmp_str);
	char *ret_str = ft_strjoin(tmp_str, right_str);
	//printf("ret_str : %s\n", ret_str);
	free(left_str);
	free(key);
	free(right_str);
	free(tmp_str);
	free(token);
	return ret_str;
}

char *change_single_quote(char *token, int start, int end)
{
	//printf("%d %d\n", start, end);
	char *left_str = ft_substr(token, 0, start);
	char *middle_str = ft_substr(token, start+1, end-start-1);
	//printf("mid : %s\n", middle_str);
	char *right_str = ft_substr(token, end + 1, ft_strlen(token)-end-1);

	char *tmp_str = ft_strjoin(left_str, middle_str);
	char *ret_str = ft_strjoin(tmp_str, right_str);
	//printf("ret : %s\n", ret_str);
	free(left_str);
	free(middle_str);
	free(right_str);
	free(tmp_str);
	free(token);
	return ret_str;
}

char *change_double_quote(char *token, int *start, int end, char ***envp)
{
	//printf("%d %d\n", *start, end);
	char *left_str = ft_substr(token, 0, *start);
	char *middle_str = ft_substr(token, *start+1, end-*start-1);
	int i = -1;
	while(middle_str[++i])
	{
		if(middle_str[i] == '$')
		{
			if(is_env_var(middle_str + i))
			{
				middle_str = change_env_var(middle_str, i, i + get_env_var_length(middle_str + i) , envp);
				i --;
			}
		}
	}
	*start += (ft_strlen(middle_str) - 1);
	char *right_str = ft_substr(token, end + 1, ft_strlen(token)-end-1);
	char *tmp_str = ft_strjoin(left_str, middle_str);
	char *ret_str = ft_strjoin(tmp_str, right_str);

	free(left_str);
	free(middle_str);
	free(right_str);
	free(tmp_str);
	free(token);

	return ret_str;
}

char *token_to_good_token(char *token, char ***envp)
{
	if(!token)
		return NULL;
	int i = -1;
	while(token[++i])
	{
		if(token[i] == 39)
		{
			int j = 1;
			while(token[i + j] != 39)
				j ++;
			token = change_single_quote(token, i, i+j);
			i = i + j - 2;
			if(i == -1)
				continue;
			if(!token[i])
				return token;
			continue;
		}
		if(token[i] == 34)
		{
			int j = 1;
			while(token[i + j] != 34)
				j ++;
			token = change_double_quote(token, &i, i+j, envp);
			if(i == -1)
				continue;
			if(!token[i])
				return token;
			continue;
		}
		if(token[i] == '$')
		{
			if(is_env_var(token + i))
			{
				token = change_env_var(token, i, i + get_env_var_length(token + i) , envp);
				i --;
			}
			if(i == -1)
				continue;
			if(!token[i])
				return token;
			continue;
		}
	}
	return token;
}
