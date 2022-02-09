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
void	pwd_build(void)
{
	char	folder[PATH_MAX];

	getcwd(folder, sizeof(folder));
	ft_putendl_fd(folder, STDOUT_FILENO);
	//free(folder);
}
