# ft_printf

The goal of this project is to recode the function printf in C language.

### Instructions
* You have to recode the libc’s printf function.
* Your function will be called ft_printf and will be prototyped similarly to printf.
* You won’t do the buffer management in the printf function.
* You have to manage the following conversions: csp
* You have to manage the following conversions: diouxX with the following flags: hh, h, l and ll.
* You have to manage the following conversion: f with the following flags: l and L.
* You must manage %%
* You must manage the flags #0-+ and space
* You must manage the minimum field-width
* You must manage the precision

### Bonus
I added as a bonus to this project:
* Conversions %j, %z and %t.
* The non existing %b conversion for binary numbers.
* The * flag in order to give precision and field-width as arguments.

### What I learned
* The use of variable argument lists with va_start, va_arg...
* The use of a 'dispatcher' function via the use of an array of function's pointers.
* Structuring the codebase in order to make adding new functionalities easier.