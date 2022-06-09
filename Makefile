##
## EPITECH PROJECT, 2022
## nm_objdump
## File description:
## Makefile
##

all:
	make -C ./nm
	make -C ./objdump

nm:
	make -C ./nm

objdump:
	make -C ./objdump

clean:
	make clean -C ./nm
	make clean -C ./objdump
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore*

fclean: clean
	make fclean -C ./nm
	make fclean -C ./objdump
	rm -f my_nm
	rm -f my_objdump
re: fclean all
