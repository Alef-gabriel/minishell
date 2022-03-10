#include "minishell.h"

// executar as dups caso necessario (em caso de redirect)
// criar a commat_commands, linkando todos os pipes antes de começar com os execs

int	count_cmd_len(char *s, int init)
{
	int	ret;

	ret = 0;
	while (s[init] != '|' && s[init])
	{
		ret++;
		init++;
	}
	return (ret);
}

void	separate_in_pipes(char *s)
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
		while (s[j] != '|' && s[j])
		{
			j++;
		}
		if (s[j] == '\0' || s[j] == '|')
		{
			if(s[j] == '|')
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
	char	*temp;

	if (!ft_strcmp("exit", input) || input == NULL)
	{
		//adicionar funções de free
		exit(0);
	}
	temp = ft_strtrim(input, " ");
	if(input[0] != '\0')
	{
		if (check_sintax(temp) == -1)
		{
			printf ("minishell: syntax error near unexpected token `<token>'\n");
			return ;
		}
		if (readline_output_parser(temp) == -1)
			return ;
	}
	free(temp);
	return ;
}
