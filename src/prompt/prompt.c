#include "minishell.h"

char	*get_directory(void)
{
	char	*color_string;
	char	*temp;

	temp = (char *)malloc(SIZE * sizeof(char));
	getcwd(temp, SIZE);
	color_string = ft_strtjoin(BOLDGREEN, (ft_strrchr(temp, '/') + 1), RESET);
	free(temp);
	temp = NULL;
	return (color_string);
}

// executar as dups caso necessario (em caso de redirect)
// criar a commat_commands, linkando todos os
// pipes antes de começar com os execs
char	*takeinput(void)
{
	char	*buffer;
	char	*folder;
	char	*temp;

	get_sig();
	folder = get_directory();
	temp = ft_strtjoin(BOLDWHITE, "Minishell", folder);
	buffer = readline(temp);
	free(folder);
	free(temp);
	folder = NULL;
	temp = NULL;
	return (buffer);
}
