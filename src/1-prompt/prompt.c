#include "minishell.h"

void	get_directory(void)
{
	getcwd(g_mini.pwd, SIZE);
	g_mini.color_folder = ft_strtjoin(BOLDMAGENTA, g_mini.pwd, RESET);
}
