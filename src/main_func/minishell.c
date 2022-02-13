/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:57:51 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/13 13:46:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_mini;

// verificar >>> init_term() mensagem inicial;
int	main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **envp)
{
	char	*input;
	char	*s;

	init_vars();
	pwd_build(); // < teste do pwd
	g_mini.env_table = env_to_hash(envp);
	ft_putstr_fd("teste\n", 1);
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
