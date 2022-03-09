#include "minishell.h"

void	heredoc(char *cmd)
{
	char	*input;
	int		fd;

	fd = open ("heredoc", O_CREAT | O_RDONLY | O_WRONLY | O_APPEND, 0777);
	redir_input_exec(g_mini.commands->files_input_redir);
	while(1)
	{
		input = readline("heredoc> ");
		if(ft_strncmp(cmd, input, ft_strlen(cmd)) != 0)
		{
			write(fd, input, ft_strlen(input) - 1);
			write(fd, "\n", 1);
		}
		else
			break ;
	}
	return ;
}