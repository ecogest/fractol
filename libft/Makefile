# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 18:35:15 by mjacq             #+#    #+#              #
#    Updated: 2021/11/29 11:17:11 by mjacq            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = libft.a
CC       = clang
CFLAGS   = -Wall -Werror -Wextra $(INCLUDES)
INCLUDES = -Iincludes

#  ================================ Sources =================================  #

# SRC = $(wildcard ft_*.c)

# SRC_FT :=
# $(eval SRC = $(addprefix libft_original/,$(SRC_FT)))

# ft_is
SRC_FT_IS := ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isnumber.c \
	ft_isint.c
$(eval SRC += $(addprefix ft_is/,$(SRC_FT_IS)))

# ft_lst
SRC_FT_LST := ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c
$(eval SRC += $(addprefix ft_lst/,$(SRC_FT_LST)))

# ft_mem
SRC_FT_MEM := ft_bzero.c \
	ft_calloc.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c
$(eval SRC += $(addprefix ft_mem/,$(SRC_FT_MEM)))

# ft_mem
SRC_FT_PUT := ft_putchar.c \
	ft_putchar_fd.c \
	ft_putchar_err.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putendl_err.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putnbr_err.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putstr_err.c \
	ft_putwchar.c \
	ft_putwchar_fd.c
$(eval SRC += $(addprefix ft_put/,$(SRC_FT_PUT)))

# ft_str
SRC_FT_STR := ft_split.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_stris.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_strnjoin.c \
	ft_strappend.c \
	ft_strnappend.c
$(eval SRC += $(addprefix ft_str/,$(SRC_FT_STR)))

# ft_to
SRC_FT_TO := ft_atoi.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_wctomb.c
$(eval SRC += $(addprefix ft_to/,$(SRC_FT_TO)))

# ft_math
SRC_FT_MATH := ft_min_max_abs.c
$(eval SRC += $(addprefix ft_math/,$(SRC_FT_MATH)))

# gnl
SRC_GNL := get_next_line.c \
	gnl_buf_to_tok.c \
	gnl_join_tokens.c \
	gnl_read.c \
	gnl_run.c
$(eval SRC += $(addprefix gnl/,$(SRC_GNL)))

# # ft_printf
# SRC_FT_PRINTF := core_functions.c \
# 	flag_checking.c \
# 	ft_lst.c \
# 	ft_printf.c \
# 	misc.c \
# 	padding.c \
# 	precision.c
# $(eval SRC += $(addprefix ft_printf/,$(SRC_FT_PRINTF)))

#  ================================ Objects =================================  #

OBJ = $(SRC:.c=.o)

# BONUS_OBJ = $(BONUS:.c=.o)

#  ================================= Rules ==================================  #

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[38;5;2mArchive rebuilt (ar rc).\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "Object created : $@"

# bonus: $(OBJ) $(BONUS_OBJ)
# 	@ar rc $(NAME) $^
# 	@ranlib $(NAME)
# 	@echo "\033[38;5;2mArchive (with bonus) rebuilt (ar rc).\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[38;5;202mObjects removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;202m$(NAME) removed.\033[0m"

re: fclean all
