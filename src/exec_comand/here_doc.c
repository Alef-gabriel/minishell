#include "minishell.h"

static t_limiter	*save_limiter(char *s, t_limiter *anchor, int finish)
{
	t_limiter *save_limiter;

	save_limiter = anchor;
	if (anchor == NULL)
	{
		anchor = (t_limiter *)malloc(sizeof(t_limiter));
		anchor->name = ft_substr(s, 0, finish);
		anchor->next = NULL;
	}
	else
	{
		while (anchor->next != NULL)
			anchor = anchor->next;
		anchor->next = (t_limiter *)malloc(sizeof(t_limiter));
		anchor->next->name = ft_substr(s, 0, finish);
		anchor->next->next = NULL;
		anchor = save_limiter;
	}
	return (anchor);
}

t_limiter *heredoc_limiter(char *s)
{
	int			i;
	int			j;
	int			len;
	t_limiter	*limiter_list;

	i = 0;
	limiter_list = NULL;
	len = ft_strlen(s);
	while (i < len && s[i])
	{
		j = 0;
		if (s[i] == 4 && signal_type(s + i) == 2)
		{
			while (s[i] && (s[i] == 4 || s[i] == 2))
				i++;
			while (s[i + j] && s[i + j] != 4 && s[i + j] != 5 && s[i + j] != 3 && s[i + j] != 2)
				j++;
			limiter_list = save_limiter(s + i, limiter_list, j);
			i = i + j;
		}
		if (j == 0)
			i++;
	}
	return (limiter_list);
}

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