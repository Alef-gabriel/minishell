/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:32:59 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/11 02:35:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_signal(void)
{
	ft_putendl_fd("exit", 1);
	rl_clear_history();
	//fazer free nas funções de hash table caso do ctrl + d
	exit(0);
}
