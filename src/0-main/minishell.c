#include "minishell.h"

t_minishell g_mini;

void	shell_loop(char **envp);

void	signal_handler(int	signumber)
{
	if (signumber == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		errno = 130;
	}
	if (signumber == SIGQUIT)
	{
		write(1, "\b TESTE\b", 3);;
		errno = 131;
	}

}

void	start_sigaction(void)
{
	struct sigaction	marks;

	marks.sa_handler = signal_handler;
	marks.sa_flags = SA_NODEFER;
	sigemptyset(&marks.sa_mask);
	sigaction(SIGINT, &marks, 0);
	sigaction(SIGQUIT, &marks, 0);
	return ;
}

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
