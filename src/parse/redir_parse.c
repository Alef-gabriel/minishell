#include "minishell.h"

int check_redir(char *cmd_line)
{
	if (!ft_strstr(cmd_line, ">>>"))
		return (-1);
	if (!ft_strstr(cmd_line, ">>"))
		return (1);
	if (!ft_strstr(cmd_line, ">"))
		return (1);
	return (0);
}

int	file_trima(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != REDIRECT && s[i] != REDIRECT_INPUT && s[i] != PIPE && s[i] != SPACECHAR)
		i++;
	return (i);
}

t_files	*files_save(char *s, t_files *anchor, int sig)
{
	t_files *save_f;
	int		i;

	i = file_trima(s);
	save_f = anchor;
	if (anchor == NULL)
	{
		anchor = file_init(ft_substr(s, 0, i));
		anchor->doc_sig = sig;
	}
	else
	{
		while (anchor->next != NULL)
			anchor = anchor->next;
		anchor->next = file_init(ft_substr(s, 0, i));
		anchor->next->doc_sig = sig;
		anchor = save_f;
	}
	return (anchor);
}

t_files	*redirect_input_files(char *s, t_files *anchor, int sig)
{
	t_files *save_f;
	int		i;

	i = file_trima(s);
	if (sig == 1)
	{
		save_f = anchor;
		anchor = file_init(ft_substr(s, 0, i));
		anchor->doc_sig = sig;
		anchor->next = save_f;
	}
	return (anchor);
}
