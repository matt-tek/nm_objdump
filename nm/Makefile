##
## EPITECH PROJECT, 2020
## B-CPE-100-RUN-1-1-cpoolday11-mathieu.muty
## File description:
## Makefile
##

SRC	=	main.c \

SRC_TEST=

OBJ	=	$(SRC:.c=.o)

NAME	=	my_nm

NAME_TEST=	unit_test

IFLAG	=	-I ./include/

WFLAG	=	-W -Wall -Wextra -Werror

CRIFLAG	=	-l criterion --coverage

GDBFLAG	=	-g -g3

CFLAGS	=	$(WFLAG) $(GDBFLAG) $(IFLAG) $(LFLAG)

all: $(OBJ)
	gcc $(OBJ) -o $(NAME) $(IFLAG) $(WFLAG) $(GDBFLAG)
	mv $(NAME) ../

gcc_test: 
	gcc $(SRC_TEST) -o $(NAME_TEST) $(IFLAG) $(WFLAG) $(CRIFLAG)
	./$(NAME_TEST) --verbose

clean:
	rm -f *~
	rm -f *#
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore*
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

tests_run: fclean gcc_test

re: fclean all
