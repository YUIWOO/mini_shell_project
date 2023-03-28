#include "../include/main.h"

int execute_iterate(t_execution *execution_ar, char ***envp, int **pipe_ar)
{
	int i = -1;
	int input_fd;
	int output_fd;
	int p_count = 0;
	int pid;
	while(execution_ar[p_count].is_terminated != NULL_STATE)
		p_count ++;
	//pid_buffer = malloc(sizeof(int) * p_count); //fork함수에 free 필요 ?
	int last_pid;
	while(++i <= p_count)
	{
		//waitpid(-1, NULL, 0);
		//전체 프로세스 종료 확인 후 리턴
		//여기서 모두 기다리면 될듯 //ls | lll 같은경우 불안정 -> execute 문제인듯 ?
		//wait(NULL);
		if(i == p_count)
		{		
			int exit_status;
			while (1)
			{
				int status;
				int child_id = wait(&status);
				if(child_id <= 0)
					break ;
				if(child_id == pid)
				{
					//printf("catch\n");
					exit_status = status;
				}
			}
			return exit_status;
		}
		pid = fork();
		if(pid == 0)
			break ;
		else
		{
			//wait(NULL); //추후 수정 일단 동작 확인 용 //yes와 같은 끝나지 않는 동작 병렬적으로 처리되게 하면 됨
			if(i != 0)
			{
				close(pipe_ar[i-1][0]);
			}
			if(pipe_ar[i] != NULL)
			{
				close(pipe_ar[i][1]);
			}
		}
	}
	execute(execution_ar+i, envp, pipe_ar, i);
	return 0;
}

void free_pipe(int **pipe_ar)
{
	int i = -1;
	while(pipe_ar[++i])
		free(pipe_ar[i]);
	free(pipe_ar);
}

int execute_all(t_execution *execution_ar, char ***envp)
{
	int **pipe_ar;
	int p_count = 0;
	while(execution_ar[p_count].is_terminated != NULL_STATE)
		p_count ++;
	if(p_count)
	{
		pipe_ar = malloc(sizeof(int *) * (p_count));
		pipe_ar[p_count - 1] = NULL;	
	}
	else //1개 || 0개
	{
		pipe_ar = malloc(sizeof(int *) * 1);
		pipe_ar[0] = NULL;
	}
	int i = -1;
	while(++i < p_count - 1)
	{
		pipe_ar[i] = malloc(sizeof(int) * 2);
		pipe(pipe_ar[i]);
	}
	int exit_status = execute_iterate(execution_ar, envp, pipe_ar);
	free_pipe(pipe_ar);
	return exit_status;
}
