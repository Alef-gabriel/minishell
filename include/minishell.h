/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:00:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 18:36:12 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/libft.h"
# include "./struct.h"

# define TRUE 1
# define FALSE 0
# define PATH_MAX 4096

# define SIZE 255
# define BOLDGREEN		"\033[1m\033[32m ["
# define BOLDWHITE		"\033[1m\033[37m"
# define RESET			"]$ \033[0m"
# define SPACECHAR 2
# define PIPE 3
# define REDIRECT 5
# define REDIRECT_INPUT 4

extern t_minishell	g_mini;

// Main

void			init_vars(void);
void			shell_loop(void);
char			*takeinput(void);
t_files			*file_init(char *filename);
t_commands		*init_commands(void);
void			get_sig(void);

// Buildin

void			ft_echo(char **cmd, int fd);
int				cd_dir(char **cmd);
int				print_table(t_node **nodes, int fd);
int				exit_shell(char *cmd);
int				export(t_hash *data, char *cmd);
int				pwd_build(int fd);
int				unset(t_hash *data, char *key);

// Inspect

int				init_inspect(char *input);
int				inspect_quotation(char *input);
int				inspect_redirection(char *input);
int				inspect_pipe(char *input, int index);
int				start_with_pipe(char *input);

// Utils

void			free_matrix(char **matrix);
int				ft_strstr(const char *str, const char *tofind);

// Exit

int				file_error(char *s);
int				print_quote(int status);
void			print_error(char *err_msg_f, char *err_msg_s, int status);
void			print_redir(int status);
void			free_to_exit(void);
void			exit_signal(void);

// Hash Table

t_node			*nodelast(t_node *node);
void			addlast(t_node **node, t_node *new);
t_hash			*env_to_hash(char **env);
t_node			*hash_search(t_node **nodes, char *key, int len);
t_node			*create_new_node(char *key, char *value);
t_hash			*create_hash(int size);
unsigned int	hash(char *str, unsigned int len);
void			atribute_node(char *key, char *value, t_hash *hash, int index);

// Parse

t_commands	*commads_reconect(t_commands *save, t_commands *current);
char			*expansion(char *str);
char	**path_cmds(char **path_comand, char **cmd);
void			parse_input(char *input);
void			creat_commands(char *s);
char			*join_matrix(char **split);
char			*treat_quotes(char *str);

char			**append_in_matrix(char **array, char *str);
char			**hash_to_env(t_node **nodes);

/*here_doc and redirect*/

t_files			*redirect_input_files(char *s, t_files *anchor, int sig);
int				input_to_exec(t_files *files, int *piper, \
t_limiter *heredoc_limiter);
int				have_pipe(char *input);
int				is_redir(char *cmd);
int				check_redir(char *cmd_line);
int				check_here_doc(char *cmd);
int				file_trima(char *s);
void			heredoc(t_limiter *limiters, int fd);
t_limiter		*heredoc_limiter(void);

/*readline parser*/

void				readline_output_parser(char *s);
int				exec_commands(t_commands *commands_struct);
void			delete_commands(t_commands *commands_struct);

t_files			*parser(char iten, \
	t_files *(*save)(char *, t_files *anchor, int sig));

char			*remove_item_in_str(char *w_cmd, int after_cnt, int before_cnt);

/*pipe parsing*/

char			*ft_conect(char	*first, char *mid, char *end);
char			**cmd_parser(char *cmd, t_node *path);
t_files			*files_save(char *s, t_files *anchor, int sig);

/* Exec */
int				ft_exec(t_commands *cmds);
void			redir_exec(t_commands *commands);
void			ft_filecmp(int destination_fd, int fd);
int				exec_builtins(char **cmd, t_files *redirect, int *piper);

int				signal_type(char *s);
int				fd_to_fd(int fd_in, t_files *fd_out);

#endif