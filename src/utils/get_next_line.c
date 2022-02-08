/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:37:32 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/30 00:08:21 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cont_until_new_line(char *buff)
{
	int		i;

	i = 0;
	if (buff)
	{
		while (buff[i])
		{
			if (buff[i] == '\n')
			{
				i++;
				break ;
			}
			i++;
		}
	}
	return (i);
}

static int	cut_line_for_new_line(char *line, char *new_line)
{
	int		i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;
		}
		ft_delete(&line);
	}
	return (i);
}

static char	*buf_organizer(char *buf)
{
	int		save_stance;
	int		len_buf;
	char	*save;
	int		buf_stance;

	buf_stance = cont_until_new_line(buf);
	len_buf = buf_stance;
	save_stance = 0;
	while (buf[len_buf])
		len_buf++;
	if (len_buf - buf_stance == 0)
	{
		ft_delete(&buf);
		return (0);
	}
	save = (char *)ft_calloc(sizeof(char), (len_buf - buf_stance) + 1);
	while (buf[buf_stance])
		save[save_stance++] = buf[buf_stance++];
	ft_delete(&buf);
	return (save);
}

static char	*make_new_line(char *line, char *buf, char *next_line_bool)
{
	char	*new_line;
	int		new_line_stance;
	int		buf_stance;

	new_line = (char *)ft_calloc(1, cont_until_new_line(line)
			+ cont_until_new_line(buf) + 1);
	new_line_stance = cut_line_for_new_line(line, new_line);
	buf_stance = 0;
	while (buf[buf_stance])
	{
		new_line[new_line_stance++] = buf[buf_stance];
		if (buf[buf_stance] == '\n')
		{
			*next_line_bool = 0;
			break ;
		}
		buf_stance++;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	char		*next_line_bool;
	int			size_read;

	next_line_bool = (char *)ft_calloc(sizeof(char), 2);
	*next_line_bool = '1';
	line = NULL;
	while (*next_line_bool)
	{
		if (!buf)
			buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		size_read = read(fd, buf, BUFFER_SIZE - ft_buf_verify(buf));
		if (!(*buf) && (size_read == 0 || size_read == -1))
		{
			ft_delete(&buf);
			ft_delete(&next_line_bool);
			return (line);
		}
		line = make_new_line(line, buf, next_line_bool);
		buf = buf_organizer(buf);
	}
	ft_delete(&next_line_bool);
	return (line);
}
