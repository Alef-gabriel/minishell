#include "minishell.h"

void	heredoc(t_limiter *limiters)
{
	char	*input;
	int		fd;

	fd = open ("heredoc", O_CREAT | O_RDONLY | O_WRONLY | O_APPEND, 0777);
	while (limiters)
	{
		while(1)
		{
			input = readline("heredoc> ");
			if(ft_strncmp(limiters->name, input, ft_strlen(limiters->name)) != 0)
			{
				write(fd, input, ft_strlen(input) - 1);
				write(fd, "\n", 1);
			}
			else
				break ;
		}
		limiters = limiters->next;
	}
	return ;
}
