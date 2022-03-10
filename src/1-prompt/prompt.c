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


char	*takeinput(void)
{
	char	*buffer;
	char	*folder;

	get_sig();
	folder = get_directory();
	buffer = readline(folder);
	free(folder);
	folder = NULL;
	return (buffer);
}
