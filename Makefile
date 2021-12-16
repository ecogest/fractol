# ================================= PROJECT ================================== #

NAME = fractol

all: $(NAME)

#  =========================== COMPILER AND FLAGS ===========================  #

CC        = clang
CXX       = clang++
CPPFLAGS  = -Iincludes
CPPFLAGS += -Ilibft/includes
CPPFLAGS += -Imlx
CFLAGS    = -Wall -Werror -Wextra
CFLAGS   += -g
LDFLAGS   = -Llibft -lft
LDFLAGS  += -Lmlx -lmlx -lXext -lX11 -lm -lbsd

#  ========================== SOURCES AND OBJECTS ===========================  #

SRCDIR  = src
OBJDIR  = obj
SRCS = src/main_fractol.c \
			 src/hook_keyboard.c \
			 src/win_init_destroy.c \
			 src/f_usage.c \
			 src/hook_mouse_button.c \
			 src/hook_and_loop.c \
			 src/parsing.c \
			 src/main.c \
			 src/iter_algos.c \
			 src/fig_get_palette_and_color.c \
			 src/hook_mouse_moves.c \
			 src/img_px_put.c \
			 src/palettes.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

#  ============================ LINK EXECUTABLE =============================  #

$(NAME): libft/libft.a mlx/libmlx.a $(OBJDIR) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@printf "✨ $(BOLD)$(GREEN)%s$(NC)$(GREEN) has been successfully linked.\n$(NC)" $@

#  ============================== COMPILE LIBS ==============================  #

libft/libft.a: libft
libft:
	@$(MAKE) --silent -C libft $(filter $(MAKECMDGOALS),clean fclean re)

mlx/libmlx.a: mlx
mlx:
	@$(MAKE) --silent -C mlx $(filter $(MAKECMDGOALS),clean fclean re)

#  ============================ COMPILE OBJECTS =============================  #

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "$(YELLOW)Compiling: %s\n$(NC)" $<
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# ================================= CLEANING ================================= #

clean: libft mlx
	@printf "$(MAGENTA)Cleaning objects.\n$(NC)"
	@rm -rf $(OBJDIR)

fclean: clean libft mlx
	@printf "$(MAGENTA)Removing binary: $(BOLD)%s\n$(NC)" $(NAME)
	@rm -f $(NAME) $(NAME_TEST)

re: fclean all libft mlx

clean-no-lib:
	@printf "$(MAGENTA)Cleaning objects.\n$(NC)"
	@rm -rf $(OBJDIR)
fclean-no-lib: clean-no-lib
	@printf "$(MAGENTA)Removing binary: $(BOLD)%s\n$(NC)" $(NAME)
	@rm -f $(NAME) $(NAME_TEST)
r: fclean-no-lib all

#  ================================= Bonus ==================================  #

# No forbidden functions used, bonuses are the same as regular sources
bonus: all

#  ================================= .PHONY =================================  #

.PHONY: all link clean fclean re libft mlx bonus

#  ================================= COLORS =================================  #

CYAN    = "\\e[36m"
GREEN   = "\\e[32m"
MAGENTA = "\\e[35m"
GRAY    = "\\e[37m"
YELLOW  = "\\e[33m"

BOLD    = "\\e[1m"
NC      = "\\e[0m"
