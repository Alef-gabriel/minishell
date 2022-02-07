/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 01:01:38 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/07 01:11:13 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//verificar se o "echo $?" retorna 0
void	pwd_build(void)
{
	char	*folder;

	folder = getcwd(NULL, 0);
	ft_putendl(folder, 1);
	free(folder);
}
