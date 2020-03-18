This function prints on a simple way similar to printf with a few exceptions like:

- %% : This exception prints a "%"
- \" : This exception prints a "
- \' : This exception prints a '
- \\ : This exception prints a \

The way that it compiles is with gcc -Wall -Werror -Wextra -pedantic *.c* that takes all .c files present on the directory.
The program start with a main function that receive all the parameters that we gonna print, like numbers, strings or characters, calls the function _printf that receive all that string like _printf("%s", "hola holberton"), that line prints literraly hola holberton.
The way to do that is "walking" on that string position by position and when on the position are a "%" and in the next position are a valid case like "s, d, i, c, b" it's enter on a part of the function that categorizes if that the argument after the , is a number/character or a string. And when we know what it is, it enter on two different functions, one for the strings, and the other for the numbers and characters. If we enter on the string function, it verificated that the string that we are receiving is not null and if not null we write position by position of that string and returns the number of characters printed. On the other hand we have the functions that print numbers and characters on the way that it ask if is a character and then print the character or a number and then he receives the number on a function to change int to string so we can print it on the format of a string.

Some examples are:

_printf("%") - That prints nothing and return a -1

_printf("%d", 1) - That prints the number 1

_printf("%d%s", 1, " hola") - That prints the number 1 followed by hola like this "1 hola"

_printf("%%%d%c", 1, 'p') - Prints % followed by 1 and p like this "%1p"

_printf("\\%%%i%s%d", 1, "Holberton", 2) - Prints "\%1Holberton2" 


By Norman Isaza and Santiago Arboleda
