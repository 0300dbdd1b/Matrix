
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;33m
WHITE			=	\033[1;37m
NC				=	\033[0m

SRCDIR		=	./srcs/
INCDIR		=	./includes/

SRCNAME		= 	Matrix.cpp		\
				Matrix_operator	\

SRCS		= 	${addprefix ${SRCDIR}, ${SRCNAME}}
OBJS		= 	${SRCS:.c=.o}

CC			= 	g++
CFLAGS 		=	-Wall -Werror -Wextra

.c.o        :
				${CC} ${CFLAGS} -I ./includes/ -c $< -o ${<:.c=.o}



NAME		= 	Matrix.a
$(NAME) 	: 	${OBJS}
				ar rvs ${NAME} ${OBJS}


all:		${NAME}					## Cree la base de la Bibliotheque Statique "libft.a

clean:								## Supprime tout les .o inclus dans la bibliotheque "libft.a
			rm -f ${OBJS}

fclean:								## Supprime la Bibliotheque Statique et ses fichiers objet
			rm -f ${OBJS}
			rm -f ${NAME}

re:			fclean all   			## Supprime et recompile la Bibliotheque Smaketatique avec ses fichiers objets



help:								## Liste toutes les comman
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
