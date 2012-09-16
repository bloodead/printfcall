NAME	=	id_print.a
SRCS	=	check.c		\
		func_type.c	\
		id_getline.c	\
		id.id		\
		id_printf.c	\
		id_print_list.c	\
		print_final.c	\
		repid.id	\
		id_print_char.c	\
		id_print_str.c	\
		id_print_nbr.c	\
		tools_reduc.c	\
		tools.c
OBJS	=	$(SRCS:.c=.o)
CC	=	gcc
CFLAGS	=	-W -Wall -Werror
LDFLAGS	=
AR	=	ar
RANLIB	=	ranlib

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) r $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	rm -f *.o

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all
