#include "minishell.h"

void	get_directory(void)
{
	getcwd(g_mini.pwd, SIZE);
	g_mini.color_folder = ft_strtjoin(BOLDMAGENTA, g_mini.pwd, RESET);
}

char	*takeinput(void)
{
	char	*input;

	input = readline(g_mini.color_folder);
	add_history(input);
	if (!ft_strcmp("exit", input))
	{
		free(input);
		exit(0);
	}
	return (input);
}
