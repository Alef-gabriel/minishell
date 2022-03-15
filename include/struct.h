/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:26:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/15 02:13:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum	e_bool
{
	false,
	true
};

typedef struct s_node{
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash{
	t_node	**nodes;
	int		size;
}	t_hash;

typedef struct s_files{
	char			*file_name;
	int				fd;
	int				link;
	int				doc_sig;
	struct s_files	*next;
}	t_files;

typedef struct s_limiter{
	char				*name;
	struct s_limiter	*next;
}	t_limiter;

typedef struct s_commands{
	t_limiter			*limiter;
	t_files				*files_redir;
	t_files				*files_input_redir;
	char				**cmd;
	char				*wf_cmd;
	int					fd_in;
	struct s_commands	*next;
}	t_commands;

typedef struct s_minishell{
	int			comand;
	int			open_quotes_sig;
	int			quote_type_sig;
	int			pipes;
	int			on_child;
	int			cont_pipe;
	int			fd_in;
	int			exit_tmp;
	int			exit_code;
	char		*pwd;
	char		*color_folder;
	char		**env;
	t_commands	*commands;
	t_hash		*env_table;
}	t_minishell;

#endif
