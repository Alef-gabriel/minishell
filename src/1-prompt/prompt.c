#include "minishell.h"

void	get_directory(void)
{
	getcwd(g_mini.pwd, SIZE);
	g_mini.color_folder = ft_strtjoin(BOLDMAGENTA, g_mini.pwd, RESET);
}

char	*takeinput(void)
{
	char	*buffer;

	buffer = readline(BOLDGREEN"MINIHELL"RESET);
	if (*buffer == '\0')
	{
		free(buffer);
	}
	add_history(buffer);
	return (buffer);
}
