NAME = gnl
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.

SRC = main.c \
			get_next_line.c \
			get_next_line_utils.c

BSRC = main_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
BOBJS = $(addprefix $(OBJDIR)/, $(BSRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	gcc -g $(CFLAGS) $^ $(INCLUDES) -o $@

bonus: $(BOBJS)
	gcc -g $(CFLAGS) $^ $(INCLUDES) -o $@


$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	gcc -g $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean:
	$(RM) $(NAME)
	$(RM) -r $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
