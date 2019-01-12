NAME		:= 21sh
DEBUG		:="yes"
# **************************************************************************** #
#								PATH                                           #
# **************************************************************************** #

#			In

PWD			:= $(shell pwd)
NO_ERROR	:= 2> /dev/null

#			PATH

LIB_PATH	:= $(PWD)/libft
INC_PATH	:= $(PWD)/include
SRC_PATH	:= $(PWD)/src
OBJ_PATH	:= $(PWD)/obj


#			Ext

CC			:= /usr/bin/clang
CMD_NORME	:= norminette

export CMD_NORME

# **************************************************************************** #
#								NAME LST                                       #
# **************************************************************************** #

LIB_NAME	:= libft
LIB_SYS		:= -lncurses
INC_LST		:=\
	include/lexer.h				\
	include/parser.h			\
	include/shell.h				\
	include/utils.h				\
	libft/include/libft.h		\
	libft/include/ft/io.h		\
	libft/include/ft/std.h		\
	libft/include/ft/strconv.h	\
	libft/include/ft/string.h	\
	libft/include/ft/type.h


#	on this block we make to var used in ompilation:
#
#	SUB_LST	containe list of all subdir in $(SRC_PATH). this var is used to 
#			create same architectue in $(OBJ_PATH)
#
#	SRC_LST	containe list of all C file of this project. containe exempel:
#			/full/path/of/toto.c /full/path/of/tata.c
#
#	for make the to var we have this paterne:
#	you need ony to writing contente of TMP_NAME and TMP_LST
#
#	TMP_NAME	:= name of dir containe C file
#	TMP_LST		:= list of all C file inside $(TMP_NAME)/
#
#	TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
#	SUB_LST		:= $(SUB_LST) $(TMP_NAME)
#	SRC_LST		:= $(SRC_LST) $(TMP_SRC_SRC)
#
#	tips OSx for writing contente of dir_name_LST man pbcopy

#			Main

MAIN_LST	:= main.c utils.c

SRC_LST		:= $(MAIN_LST)

#			Builtins

TMP_NAME	:= builtins
TMP_LST		:=

TMP_SRC		:= $(addprefix $(TMP_NAME)/,$(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			Lexer

TMP_NAME	:= lexer

TMP_LST		:=  lexer_addtoken.c lexer_cleanup.c lexer_create.c lexer_deltoken.c lexer_destroy.c lexer_tokenize.c utils.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			Parser

TMP_NAME	:= parser

TMP_LST		:= command_create.c command_destroy.c command_parse.c node_create.c node_destroy.c node_insert.c parser_cleanup.c parser_create.c parser_destroy.c parser_expandword.c parser_parse.c redirection_create.c redirection_destroy.c utils.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/,$(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			Process

TMP_NAME	:= process

TMP_LST		:=

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			Shell

TMP_NAME	:= shell

TMP_LST		:= shell_envinit.c shell_create.c shell_destroy.c shell_getenv.c shell_gethome.c shell_setenv.c shell_unsetenv.c history.c shell_actiondispatcher.c shell_processline.c shell_start.c utils.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			Action

TMP_NAME	:= shell/action

TMP_LST		:= action_arrowup.c action_basic.c action_return.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)


# **************************************************************************** #
#								VAR                                            #
# **************************************************************************** #

LIB_SRC			:= $(addprefix $(LIB_PATH)/, libft.a)

OBJ_LST			:= $(SRC_LST:.c=.o)

INC				:= -I $(INC_PATH) -I $(LIB_PATH)/include/
SRC				:= $(addprefix $(SRC_PATH)/, $(SRC_LST))
OBJ				:= $(addprefix $(OBJ_PATH)/, $(OBJ_LST))


# **************************************************************************** #
#								SHELL                                          #
# **************************************************************************** #

#			Compilation
ifndef CC
	CC		:= /usr/bin/gcc
endif

#			Link
ifndef LN
	LN		:= /bin/ln
endif

#			Remove
ifndef RM
	RM		:= /bin/rm
endif

#			Export

export		CC
export		LN
export		RM


# **************************************************************************** #
#								FLAGS                                          #
# **************************************************************************** #

#						DEFAULTS VALUE

#			Compilation
ifndef CC_FLAGS
	CC_FLAGS			= -Wall -Werror -Wextra
	ifeq ($(DEBUG),"yes")
		CC_FLAGS		+= -g -fsanitize=address # -ferror-limit=-1
	else
		CC_FLAGS		+= -Ofast
	endif
endif

#			Link
ifndef LN_FLAGS
	LN_FLAGS	= -f
endif

#			Remove
ifndef RM_FLAGS
	RM_FLAGS	= -rf
endif

#			Export

export		CC_FLAGS
export		LN_FLAGS
export		RM_FLAGS

# **************************************************************************** #
#								COLOR                                          #
# **************************************************************************** #

START		:=\033[0;32mStart\033[0m\n
END			:=\033[0;32mEnd\033[0;0m\n
OK			:=\033[0;33mOK\033[0;0m\n

# **************************************************************************** #
#								RULES                                          #
# **************************************************************************** #

.PHONY: all

all: lib $(NAME)

$(NAME): $(LIB_SRC) $(OBJ_PATH) $(OBJ)
	@printf "$(NAME): "
	@$(CC) $(CC_FLAGS) $(INC) $(OBJ) $(LIB_SRC) $(LIB_SYS) -o $(NAME)
	@printf "$(OK)"

#			RULES FOR LIB

.PHONY: lib clean_lib fclean_lib

lib:
	@printf "$(LIB_NAME).a: $(START)"
	@$(MAKE) --silent --directory=$(LIB_PATH) all
	@printf "$(LIB_NAME).a: $(END)"

clean_lib:
	@$(MAKE) --silent --directory= $(LIB_PATH) clean

fclean_lib:
	@$(MAKE) --silent --directory=$(LIB_PATH) fclean


#			RULES FOR OBJ

$(OBJ_PATH):
	@printf "obj directory: "
	@mkdir -p $(OBJ_PATH) $(NO_ERROR)
	@mkdir -p $(addprefix $(OBJ_PATH)/, $(SUB_LST)) $(NO_ERROR)
	@mkdir -p obj/shell/action $(NO_ERROR)
	@printf "$(OK)"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(INC_LST)
	@printf "$(notdir $<) => $(notdir $@): "
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@printf "done\n"

#		RULES CLEAN

.PHONY: clean fclean re

clean: clean_lib
	@printf "Delete obj:"
	@$(RM) $(RM_FLAGS) $(OBJ_PATH)
	@printf " done\n"

fclean: fclean_lib
	@printf "Delete obj:"
	@$(RM) $(RM_FLAGS) $(OBJ_PATH)
	@printf " done\n"
	@printf "Delete $(NAME):"
	@$(RM) $(RM_FLAGS) $(NAME)
	@printf " done\n"

re: fclean all

#		Rules for debuging Makefile

.PHONY: source_list full_list

source_list:
	@printf "<SUB_LST>\n$(SUB_LST)\n</SUB_LST>\n"
	@printf "<SRC_LST>\n$(SRC_LST)\n</SRC_LST>\n"

full_list:
	@printf "<SUB_LST>\n$(SUB_LST)\n</SUB_LST>\n"
	@printf "<INC>\n$(INC_LST)\n</INC>\n"
	@printf "<SRC>\n$(SRC)\n</SRC>\n"


#		Rules norme

norme: norme_header norme_src

norme_header:
	@$(NORME_CHECK) $(INC_PATH)

norme_src:
	@$(NORME_CHECK) $(SRC)