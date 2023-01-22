
NAME	=	so_long
LIBFT	=	libft.a
LDIR	=	libft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm -f

# Sources are all .c files
SRCS	=	main.c\
			error.c\
			map_ft.c\
			ft_image.c\
			player.c


OBJS	=	$(SRCS:.c=.o)
all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ $(MAKE) -C $(LDIR)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit $(LDIR)$(LIBFT) -o $(NAME)

# Removes objects
clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)

# Removes objects and executables and remakes
re: fclean all