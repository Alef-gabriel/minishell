/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:57:51 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:24:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_mini;

// verificar >>> init_term();
int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*s;

	(void)argc;
	(void)argv;
	init_vars();
	g_mini.env_table = env_to_hash(envp);
	while (1)
	{
		input = takeinput();
		if (!ft_strncmp("exit", input, 4))
			exit(0);
		s = ft_strtrim(input, " ");
		if (s[0] != '\0')
			parse_input(s, envp);
		free(s);
		free(input);
		g_mini.pipes = 0;
	}
	return (0);
}
