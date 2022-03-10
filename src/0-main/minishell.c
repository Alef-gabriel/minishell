#include "minishell.h"

t_minishell g_mini;

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
	char	*s;
	char	*input;

	while (true)
	{
		input = takeinput();
		add_history(input);
		if (!ft_strcmp("exit", input) || input == NULL)
		{
			//adicionar funções de free
			exit(0);
		}
		s = ft_strtrim(input, " ");
		if(input[0] != '\0')
			parse_input(s, envp);
		free(s);
		free(input);
		g_mini.cont_pipe = 0;
	}
	return ;
}
