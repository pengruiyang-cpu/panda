C_FLAGS =  -Wall -Werror -O6
OBJECTS = main.o 


panda: $(OBJECTS)
	gcc $(OBJECTS) -o panda


%.o: %.c
	gcc -c $*.c $(C_FLAGS)


clear:
	rm *.o panda

