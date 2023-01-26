
NAME	=	so_long
LIBFT	=	libft.a
LDIR	=	libft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm -f

#-fsanitize=address
# Sources are all .c files
SRCS	=	main.c\
			error.c\
			map_ft.c\
			player.c\
			ft_image.c\
			ft_flood.c\
			ft_so_long_utilse.c


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