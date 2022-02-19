NAME	:= libftprintf.a
SRCS	:= src
SRC		:= $(wildcard $(SRCS)/*.c)

OBJDIR	:= objects
LIBFT	:= $(OBJDIR)/libft.a
OBJ		:= $(SRC:$(SRCS)/%.c=$(OBJDIR)/%.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -I ./include -g

all: dirs $(NAME)

test:
	@mv $(OBJDIR)/libftprintf.a .
	@make -C printfTester/ m

$(NAME): $(LIBFT) $(OBJ)
	@mv $(OBJDIR)/libft.a $(OBJDIR)/libftprintf.a
	@ar -rcs $(OBJDIR)/$(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

dirs:
	@mkdir -p objects

clean:
	rm -f $(OBJDIR)/*.o
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@rm -r libftprintf.a
	@make -C libft fclean

.PHONY: all libft dirs clean fclean
