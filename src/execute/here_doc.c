#include "../include/main.h"

static int ft_find_number_figure(unsigned long long n1, unsigned long long base_len)
{
	int i;

	i = 0;
	while (1)
	{
		i++;
		if (n1 / base_len == 0)
			return (i);
		n1 = n1 / base_len;
	}
	return (0);
}

static void	ft_write_base(unsigned long long num, int count, char *base, char *answer)
{
    int base_len;

    base_len = ft_strlen(base);
	if (count != 0)
	{
		ft_write_base(num / base_len, count - 1, base, answer);
		answer[count] = base[num % base_len];
	}		
}

static char    *get_ptr_str(char *ptr)
{
    char                *answer;
    unsigned long long  temp;
    int                 len;

    temp = (unsigned long long)ptr;
    len = ft_find_number_figure(temp, 16);
    answer = malloc(sizeof(char) * (len + 2));
    answer[0] = '.';
    ft_write_base(temp, len, "0123456789abcdef", answer);
    answer[len + 1] = 0;
    return (answer);
}

int open_here_doc(char *limiter, char **temp_file)// 일단 수정할 필요 있음
{
	int		temp_file_fd;
	char	*ptr;
    char    *line;
	char	*temp_file_name;

    ptr = malloc(sizeof(char) * 2);
	*temp_file_name = get_ptr_str(ptr);
	temp_file_fd = open(*temp_file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line || (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0
				&& ft_strlen(line) == ft_strlen(limiter) + 1))
			break ;
		write(temp_file_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
    free(ptr);
	close(temp_file_fd);
    return (temp_file_fd);
}

void	remove_temp_file(t_execution *execution)
{
	int	i = -1;
	while ((execution->redirect_ar)[++i].type != NULL_STATE)
	{
		if ((execution->redirect_ar)[i].temp_file)
		{
			unlink((execution->redirect_ar)[i].temp_file);
			free((execution->redirect_ar)[i].temp_file);
		}
	}
}

int main()
{
    char *str = "euijin";;
    printf("%s\n",get_ptr_str(str));
    system("leaks a.out");

    for (int i = 0; i < 1 ; i++)
        open_here_doc("LIMITER");
}
