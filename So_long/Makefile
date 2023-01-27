RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RESET	=	"\x1B[0m"
ORG		=	"\x1b[38;5;202m"
PIK		=	"\x1b[38;5;176m"
CLE 	=	\e[1;1H\e[2J

NAME	=	so_long
LIBFT	=	libft.a
LDIR	=	libft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm	-f

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

USER = $(shell whoami)

all: $(NAME)
	@ cat logo.txt
	@ echo "\n\n			correction is made by $(USER)\n\n"
# Generates output file
$(NAME): $(OBJS)
	@ $(MAKE) -C $(LDIR)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit $(LDIR)$(LIBFT) -o $(NAME) -D NAME=\"$(USER)\"

# Removes objects
clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o
	@ echo $(shell clear) $(GRN) clean *.o$(RESET)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)
	@ echo $(shell clear) $(GRN) clean all$(RESET)


# Removes objects and executables and remakes
re: fclean all