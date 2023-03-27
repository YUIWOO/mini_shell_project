#cc src/builtins/minishell_utils.c src/builtins/minishell_utils2.c src/libft/*.c src/signal/*.c src/execute/*.c src/get_input/*.c src/input_parse/*.c src/print/*.c -lreadline -L/Users/youngwch/.brew/opt/readline/lib -I/Users/youngwch/.brew/opt/readline/include

cc -g3 -fsanitize=address src/builtins/minishell_utils.c src/builtins/minishell_utils2.c src/libft/*.c src/signal/*.c src/execute/*.c src/get_input/*.c src/input_parse/*.c src/print/*.c -lreadline -L/Users/youngwch/.brew/opt/readline/lib -I/Users/youngwch/.brew/opt/readline/include
