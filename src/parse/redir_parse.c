#include "minishell.h"

int	check_redir(char *cmd_line)
{
	if (!ft_strstr(cmd_line, ">>>"))
		return (-1);
	if (!ft_strstr(cmd_line, ">>"))
		return (1);
	if (!ft_strstr(cmd_line, ">"))
		return (1);
	return (0);
}

t_files	*files_save(char *s, t_files *anchor, int finish, int sig)
{
	t_files	*save_f;

	save_f = anchor;
	if (anchor == NULL)
	{
		anchor = file_init(ft_substr(s, 0, finish));
		anchor->doc_sig = sig;
	}
	else
	{
		while (anchor->next != NULL)
			anchor = anchor->next;
		anchor->next = file_init(ft_substr(s, 0, finish));
		anchor->next->doc_sig = sig;
		anchor = save_f;
	}
	return (anchor);
}
