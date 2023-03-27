#include "../include/main.h"

char *change_env_var(char *token, int start, int end, char ***envp)
{
	printf("%d %d\n", start, end);
	char *left_str = ft_substr(token, 0, start);
	char *key = ft_substr(token, start+1, end - start);
	char *middle_str = get_env_value(*envp, key);
	//middle 밸류 없는경우 고려(널포인터 반환)
	char *right_str = ft_substr(token, end + 1, ft_strlen(token)-end-1);
	
	printf("left : %s\n", left_str);
	printf("key : %s\n", key);
	printf("middle_str : %s\n", middle_str);
	printf("right : %s\n", right_str);
	
	char *tmp_str = ft_strjoin(left_str, middle_str);
	printf("tmp_str : %s\n", tmp_str);
	char *ret_str = ft_strjoin(tmp_str, right_str);
	printf("ret_str : %s\n", ret_str);
	free(left_str);
	free(key);
	free(right_str);
	free(tmp_str);
	free(token);
	return ret_str;
}

char *change_single_quote(char *token, int start, int end)
{
	char *left_str = ft_substr(token, 0, start);
	char *middle_str = ft_substr(token, start+1, end-start-1);
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

char *change_double_quote(char *token, int start, int end)
{
	char *left_str = ft_substr(token, 0, start);
	char *middle_str = ft_substr(token, start+1, end-start-1);
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
		}
		if(token[i] == 34)
		{
			int j = 1;
			
			while(token[i + j] != 34)
				j ++;
			token = change_double_quote(token, i, i+j);
			i = i + j - 2;
		}
		if(token[i] == '$')
		{
			int j = 1;
			if(token[i+j] == ' ' || !token[i+j])
				continue;
			while(token[i+j] && token[i+j] != ' ')
				j ++;
			printf("j : %d\n", j);
			change_env_var(token, i, i+j-1, envp);
		}
	}
	return token;
}
