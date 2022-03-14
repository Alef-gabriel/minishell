#include "minishell.h"

t_minishell	g_mini;

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
		if (!init_inspect(input))
			parse_input(input, envp);
		free(input);
		g_mini.cont_pipe = 0;
	}
	return ;
}
