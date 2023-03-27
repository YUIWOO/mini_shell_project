#include "../include/main.h"

static int is_valid_quoto(char *line)
{
	int i = -1;
	while(line[++i])
	{
		if(line[i] == 34) //34
		{
			while(line[++i] != 34)
			{
				if(line[i] == '\0')
					return 0;
			}
		}
		if(line[i] == 39) //39
		{
			while(line[++i] != 39)
			{
				if(line[i] == '\0')
					return 0;
			}
		}
	}
	return 1;
}

static int is_valid_pipe(char *line)
{
	int flag = 0;
	int i = -1;
	while(line[++i])
	{
		if(line[i] == 34)
		{
			while(line[i] != 34)
				i ++;
		}
		if(line[i] == '|')
		{
			if(flag == 0)
				return 0;
			while(line[++i] == ' ')
				i ++;
			if(line[i] == '\0')
				return 0;
		}
		if(line[i] != ' ')
			flag = 1;
	}
	return 1;
}

static int is_valid_redirect(char *line)
{
	return 1;
}

int is_valid_line(char *line)
{
	// //quoto 짝 맞는지
	// if(!is_valid_quoto(line))
	// 	return 0;
	// //파이프 앞뒤로 적절한 값 있는지
	// if(!is_valid_pipe(line))
	//  	return 0;
	// //redirect뒤에 정상적으로 값 있다고 기대
	// if(!is_valid_redirect(line))
	// 	return 0;
	return 1;
}