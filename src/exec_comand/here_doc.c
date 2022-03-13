#include "minishell.h"

void	heredoc(t_limiter *limiters, int fd)
{
	char	*input;

	while (limiters)
	{
		while(1)
		{
			input = readline("heredoc> ");
			if(ft_strncmp(limiters->name, input, ft_strlen(limiters->name)) != 0)
			{
				write(fd, input, ft_strlen(input));
				write(fd, "\n", 1);
			}
			else
				break ;
		}
		limiters = limiters->next;
	}
	return ;
}
