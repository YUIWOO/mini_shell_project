#include "../include/main.h"

static int is_valid_quoto(char *line)
{
	int i = -1;
	while(line[++i])
	{
		if(line[i] == 34)
		{
			while(line[++i] != 34)
			{
				if(line[i] == '\0')
					return 0;
			}
		}
		if(line[i] == 39)
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
		if(line[i] == '|')
		{
			if(flag == 0)
				return 0;
			while(line[++i] == ' ')
				i ++;
			if(line[i] == '\0')
				return 0;
			i --;
		}
		if(line[i] != ' ')
			flag = 1;
		if(line[i] == 34)
		{
			while(line[++i] != 34)
			{

			}
		}
		if(line[i] == 39)
		{
			while(line[++i] != 39)
			{

			}
		}
	}
	return 1;
}

static int is_valid_redirect(char *line)
{
	int i = -1;
	while(line[++i])
	{
		if(line[i] == 34)
		{
			while(line[++i] != 34)
			{

			}
		}
		if(line[i] == 39)
		{
			while(line[++i] != 39)
			{

			}
		}
		if(line[i] == '<')
		{
			i ++;
			if(line[i] == '<')
				i ++;
			while(1)
			{
				if(line[i] == ' ')
				{
					i ++;
					continue;
				}
				if(line[i] == '>' || line[i] == '<' || line[i] == '|' || line[i] == '\0')
				{
					return 0;
				}
				else
					break;
				i ++;
			}
			i --;
		}
		if(line[i] == '>')
		{
			i ++;
			if(line[i] == '>')
				i ++;
			while(1)
			{
				if(line[i] == ' ')
				{
					i ++;
					continue;
				}
				if(line[i] == '>' || line[i] == '<' || line[i] == '|' || line[i] == '\0')
				{
					return 0;
				}
				else
					break;
				i ++;
			}
			i --;
		}
	}
	return 1;
}

int is_valid_line(char *line)
{
	if(!is_valid_quoto(line))
		return 0;
	if(!is_valid_pipe(line))
	 	return 0;
	if(!is_valid_redirect(line))
		return 0;
	return 1;
}