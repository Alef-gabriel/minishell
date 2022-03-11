#include "minishell.h"

t_minishell g_mini;

void	shell_loop(char **envp);

int main(int argc, char **argv, char **envp)
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
	return(0);
}

void	shell_loop(char **envp)
{
	char	*s;
	char	*input;

	while (1)
	{
		g_mini.on_child = FALSE;
		input = takeinput();
		if (input == NULL)
		{
			ft_putendl_fd("exit", 1);
			//verificar o que está alocado e fazer free
			exit(0);
		}
		if (!ft_strncmp("exit", input, 4))
			exit(0);
		add_history(input);
		s = ft_strtrim(input, " ");
		if(s[0] != '\0')
			parse_input(s, envp);
		free(s);
		free(input);
		g_mini.cont_pipe = 0;
	}
	return ;
}
