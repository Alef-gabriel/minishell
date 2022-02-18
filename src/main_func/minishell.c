/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:57:51 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/18 00:55:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_mini;

void	shell_loop(void)
{
	char	*input;
	char	*s;

	while (true)
	{
		get_directory();
		get_sig();
		input = takeinput();
		parse_input(s);
		g_mini.pipes = 0;
	}
}

int	main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **envp)
{
	init_vars();
	g_mini.env_table = env_to_hash(envp);
	shell_loop();
	rl_clear_history();
	return (0);
}
