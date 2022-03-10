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

	pwd = getcwd(folder, sizeof(folder));
	pwd = ft_strjoin(pwd, "\n");
	write(fd, pwd, ft_strlen(pwd));
	return (0);
}
