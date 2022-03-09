/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 01:01:38 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:47:00 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//verificar se o "echo $?" retorna 0
int	pwd_build(int fd)
{
	char	folder[PATH_MAX];
	char	*pwd;

	if (fd != 1)
		fd = open("temp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	pwd = getcwd(folder, sizeof(folder));
	write(fd, pwd, ft_strlen(pwd));
	write(fd, "\n", 1);
	if (fd != 1)
	{
		close(fd);
		return (open("temp", O_RDONLY, 0644));
	}
	return (1);
}
