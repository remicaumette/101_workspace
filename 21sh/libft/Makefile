# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/12 18:55:30 by timfuzea     #+#   ##    ##    #+#        #
#    Updated: 2019/01/17 16:08:58 by rcaumett    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		:= libft.a

#DEBUG		:="no" uncomtant this line to force status
# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

#		IN

PWD			:= $(shell pwd)
NO_ERROR	:= 2> /dev/null

#		PATH

INC_PATH	:= $(PWD)/include
SRC_PATH	:= $(PWD)/src
OBJ_PATH	:= $(PWD)/obj

# **************************************************************************** #
#									NAME LST                                   #
# **************************************************************************** #

#			Header

INC_LST		:= $(addprefix $(INC_PATH)/, libft.h)


#			Ft

TMP_NAME	:= ft

TMP_LST		:= io.h std.h strconv.h string.h type.h

TMP_SRC		:= $(addprefix ft/, $(TMP_LST))
SUB_INC		:= $(SUB_INC) $(addprefix $(INC_PATH)/, $(TMP_NAME))
INC_LST		:= $(INC_LST) $(addprefix $(INC_PATH)/, $(TMP_SRC))


# to add othe block just copy past
##			
#
#TMP_NAME	:=
#
#TMP_LST		:=
#
#TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
#SUB_LST		:= $(SUB_LST) $(TMP_NAME)
#SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			IO

TMP_NAME	:= io

TMP_LST		:= ft_print_memory.c ft_print_memory_fd.c ft_putchar.c \
				ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
				ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c get_next_line.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

#			std

TMP_NAME	:= std

TMP_LST		:= ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)


#			strconv

TMP_NAME	:= strconv

TMP_LST		:= ft_atoi.c ft_atol.c ft_atoll.c ft_itoa.c ft_lltoa.c ft_ltoa.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)


#			string

TMP_NAME	:= string

TMP_LST		:= ft_strarr_add.c ft_strarr_clone.c ft_strarr_del.c \
				ft_strarr_len.c ft_strarr_join.c \
				ft_strarr_sort.c ft_strcat.c ft_strchr.c ft_strclr.c \
				ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
				ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
				ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
				ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
				ft_strtrim.c ft_strndup.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)


#			type

TMP_NAME	:= type

TMP_LST		:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_tolower.c ft_toupper.c

TMP_SRC		:= $(addprefix $(TMP_NAME)/, $(TMP_LST))
SUB_LST		:= $(SUB_LST) $(TMP_NAME)
SRC_LST		:= $(SRC_LST) $(TMP_SRC)

# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

OBJ_LST			:= $(SRC_LST:.c=.o)

INC				:= -I $(INC_PATH) $(addprefix -I , $(SUB_INC))
SRC				:= $(addprefix $(SRC_PATH)/, $(SRC_LST))
OBJ				:= $(addprefix $(OBJ_PATH)/, $(OBJ_LST))


# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

ifndef DEBUG
	DEBUG	:= "no"
endif

#			Compilator

ifndef CC
	CC		:= /usr/bin/clang
endif

#			Link

ifndef LN
	LN		:= /bin/ln
endif

#			Remove

ifndef RM
	RM		:= /bin/rm
endif

#			

ifndef AR
	AR		:= /bin/ar
endif

# **************************************************************************** #
#									FLAG                                       #
# **************************************************************************** #

#				DEFAULTS VALUE

ifndef CC_FLAGS
	CC_FLAGS			= -Wall -Werror -Wextra
	ifeq ($(DEBUG), "yes")
		CC_FLAGS		+= -g -fsanitize=address# -ferror-limit=-1
	else
		CC_FLAGS		+= -Ofast
	endif
endif

ifndef LN_FLAGS
	LN_FLAGS	= -sf
endif

ifndef RM_FLAG
	RM_FLAG		= -rf
endif

ifndef AR_FLAG
	AR_FLAG		= rcs
endif

# **************************************************************************** #
#									STR IN COLOR                               #
# **************************************************************************** #

START			:="\033[0;32mStart\033[0m\n"
END				:="\033[0;32mEnd\033[0;0m\n\n"
OK				:="\033[0;33mOK\033[0;0m\n"

# **************************************************************************** #
#									REGLES                                     #
# **************************************************************************** #

.PHONY: all

all: $(NAME)

#				Rule lib

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "$(NAME) => "
	@$(AR) $(AR_FLAG) $(NAME) $(OBJ)
	@printf $(OK)

#				Rule obj

$(OBJ_PATH):
	@printf "mkdir obj/:"
	@mkdir -p $(addprefix $(OBJ_PATH)/,$(SUB_LST)) $(NO_ERROR)
	@printf $(OK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_LST)
	@printf "$(basename $(NAME)) => $(notdir $@):"
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@printf " done\n"

#				Rule clean

clean:
	@printf "Delete obj:"
	@$(RM) -f $(OBJ)
	@$(RM) -rf $(OBJ_PATH)
	@printf " done\n"

fclean: clean
	@printf "Delete $(NAME):"
	@$(RM) -f $(NAME)
	@printf " done\n"

re: fclean all

#			Rules for debuging Makefile

source_list:
	@printf "<SUB_LST>\n$(SUB_LST)\n</SUB_LST>\n"
	@printf "<INC_LST>\n$(INC_LST)\n</INC_LST>\n"
	@printf "<SRC_LST>\n$(SRC_LST)\n</SRC_LST>\n"

full_list:
	@printf "<SUB_LST>\n$(SUB_LST)\n</SUB_LST>\n"
	@printf "<INC>\n$(INC)\n</INC>\n"
	@printf "<SRC>\n$(SRC)\n</SRC>\n"

#				Rule norme

norme:
	@printf "\tNorme de $(SRC_LST)\n"
	@norminette $(SRC)
	@printf "\tNorme de $(INC_LST)\n"
	@norminette $(INC_LST)
