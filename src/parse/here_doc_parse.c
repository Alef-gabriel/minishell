#include "minishell.h"


int check_here_doc(char *cmd)
{
	if (!ft_strstr(cmd, "<<<"))
		return(-1);
	if (!ft_strstr(cmd, "<<"))
		return(1);
	if (!ft_strstr(cmd, "<"))
		return(1);
	return (0);
}

