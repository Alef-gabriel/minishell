#include "minishell.h"

t_minishell	g_mini;

void	shell_loop(char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv != NULL)
	{
		printf("Minishell is an interactive shell\n");
		exit (EXIT_SUCCESS);
	}
	init_vars();
	g_mini.env_table = env_to_hash(envp);
	shell_loop(envp);
	rl_clear_history();
	return (0);
}

void	shell_loop(char **envp)
{
	char	*input;

	while (true)
	{
		g_mini.on_child = FALSE;
		input = takeinput();
		if (input == NULL)
		{
			//adicionar free nas funções de hash na função exit_signal;
			exit_signal();
		}
		if (!ft_strncmp("exit", input, 4))
		{
			//fazer free nas funções de hash table caso do ctrl + d
			exit(0);
		}
		add_history(input);
		parse_input(input, envp);
		free(input);
		g_mini.cont_pipe = 0;
	}
	return ;
}
