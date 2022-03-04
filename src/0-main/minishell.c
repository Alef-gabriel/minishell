#include "minishell.h"

t_minishell g_mini;

void	shell_loop(char **envp);

int	main(int argc __attribute__((unused)),
	char **argv __attribute__((unused)), char **envp)
{
	init_vars();
	g_mini.env_table = env_to_hash(envp);
	shell_loop(envp);
	return (0);
}

void	shell_loop(char **envp)
{
	char	*s;
	char	*input;

	while (true)
	{
		input = takeinput();
		if (!ft_strcmp("exit", input))
		{
			//adicionar funções de free
			exit(0);
		}
		s = ft_strtrim(input, " ");
		if(s[0] != '\0')
			parse_input(s, envp);
		free(s);
		free(input);
		g_mini.cont_pipe = 0;
	}
	return ;
}
