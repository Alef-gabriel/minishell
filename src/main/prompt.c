/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:12 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/18 01:33:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_directory(void);

char	*takeinput(void)
{
	char	*buffer;
	char	*folder;
	char	*temp;

	get_sig();
	folder = get_directory();
	temp = ft_strtjoin(BOLDWHITE, "Minishell", folder);
	buffer = readline(temp);
	free(folder);
	free(temp);
	folder = NULL;
	temp = NULL;
	return (buffer);
}

static char	*get_directory(void)
{
	char	*color_string;
	char	*temp;

	temp = (char *)malloc(SIZE * sizeof(char));
	getcwd(temp, SIZE);
	color_string = ft_strtjoin(BOLDGREEN, (ft_strrchr(temp, '/') + 1), RESET);
	free(temp);
	temp = NULL;
	return (color_string);
}
