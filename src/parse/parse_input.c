#include "minishell.h"

int count_cmd_len(char *s, int init)
{
	int ret;

	ret = 0;

	while (s[init] != PIPE && s[init])
	{
		ret++;
		init++;
	}
	return (ret);
}

void separate_in_pipes(char *s)
{
	int			i;
	int			j;
	int			len;
	t_commands	*save_init;

	i = 0;
	j = 0;
	len = 0;
	save_init = g_mini.commands;
	while (s[i])
	{
		j = i;
		while (s[j] != PIPE && s[j])
		{
			j++;
		}
		if (s[j] == '\0' || s[j] == PIPE)
		{
			if(s[j] == PIPE)
				g_mini.cont_pipe++;
			len = count_cmd_len(s, i);
			g_mini.commands->wf_cmd = ft_substr(s, i, len);
			if (g_mini.commands->next == NULL)
			{
				g_mini.commands->next = init_comands();
			}
			g_mini.commands = g_mini.commands->next;
		}
		i = j + 1;
		if (i >= ft_strlen(s))
			break ;
	}
	g_mini.commands = save_init;
}

void	parse_input(char *input, char **env)
{
	char	*s;

	s = ft_strtrim(input, " ");
	if(s[0] == '\0')
	{
		return ;
	}
	if (check_sintax(s) == -1)
	{
		printf("minishell: syntax error near unexpected token `<token>'\n");
		return ;
	}
	if (readline_output_parser(s) == -1)
	{
		return ;
	}
}
