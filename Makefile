NAME = minishell

CC = gcc

CFLAGS	= -Wall -Wextra -Werror
LIBFT 	= -L ./libft -lft

RM = rm -rf

INCLUDE = -I ./include/
HEADER = ./include/minishell.h

PATH_SRC = ./src/
PATH_UTILS = $(PATH_SRC)utils/
PATH_HASH = $(PATH_SRC)hash_table/
PATH_MAIN = $(PATH_SRC)main/
PATH_PARSE = $(PATH_SRC)parse/
PATH_EXEC = $(PATH_SRC)exec_comand/
PATH_BUILTINS = $(PATH_SRC)builtins/
PATH_INSPECT = $(PATH_SRC)inspect/
PATH_EXIT = $(PATH_SRC)exit/

PATH_OBJS = ./objs/

SRCS = $(PATH_MAIN)minishell.c $(PATH_MAIN)initial_func.c $(PATH_MAIN)signal.c \
		$(PATH_MAIN)prompt.c $(PATH_MAIN)signal_heredoc.c \
		$(PATH_PARSE)is_comand.c $(PATH_PARSE)verify_what.c\
		$(PATH_PARSE)parse_input.c $(PATH_PARSE)readline_parser.c \
		$(PATH_PARSE)redir_parse.c $(PATH_PARSE)utils.c \
		$(PATH_PARSE)here_doc_parse.c $(PATH_PARSE)quotes_treat.c \
		$(PATH_EXEC)here_doc.c $(PATH_BUILTINS)echo.c\
		$(PATH_EXEC)exec_cmd.c $(PATH_EXEC)exec_redir.c $(PATH_EXEC)fd_to_fd.c \
		$(PATH_HASH)hash.c $(PATH_HASH)create_env.c $(PATH_HASH)hash_search.c\
		$(PATH_UTILS)free_matrix.c $(PATH_UTILS)ft_strstr.c \
		$(PATH_BUILTINS)export.c $(PATH_BUILTINS)unset.c \
		$(PATH_BUILTINS)pwd.c $(PATH_BUILTINS)exit.c \
		$(PATH_PARSE)expansion.c \
		$(PATH_BUILTINS)chdir.c $(PATH_BUILTINS)env.c \
		$(PATH_INSPECT)inspect_pipe.c $(PATH_INSPECT)inspect_quotation.c \
		$(PATH_INSPECT)inspect_redir.c $(PATH_INSPECT)inspect.c \
		$(PATH_INSPECT)inspect_spaces.c \
		$(PATH_EXIT)exit_clear.c $(PATH_EXIT)error_print.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	rm -rf $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*/*.o $(LIBFT) -lreadline -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)exec_comand/
	@mkdir -p $(PATH_OBJS)hash_table/
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)messages/
	@mkdir -p $(PATH_OBJS)parse/
	@mkdir -p $(PATH_OBJS)builtins/
	@mkdir -p $(PATH_OBJS)utils/
	@mkdir -p $(PATH_OBJS)exit/
	@mkdir -p $(PATH_OBJS)inspect/
	$(CC) $(CFLAGS) $(INCLUDE) -lreadline -I. -c $< -o $@

clean:
	@echo "\033[1;33mCleaning objects\033[0m"
	make clean -C ./libft
	@$(RM) $(PATH_OBJS)
	@echo "\033[1;32mDone!\033[0m"

fclean: clean
	make fclean -C ./libft
	@$(RM) minishell
	@echo  "\033[1;33mCleaning all\033[0m"

re: fclean all

.PHONY: all clean fclean re push