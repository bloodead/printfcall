#include <stdarg.h>
#include <stdlib.h>
#include "base.h"


int	size_nbr(int numb)
{
	int	size;

	size = 0;
	while (numb != 0)
	{
		numb = numb / 10;
		size = size + 1;
	}
	return size;
}


void	print_zero(int zero, int size)
{
	zero = zero - size;
	while (zero != 0)
	{
		id_print_char('0');
		zero = zero - 1;
	}
}

void	print_point(int numb, char* str)
{
	int count;

	count = 0;
	while (count != numb)
	{
		id_print_char(str[count]);
		count = count + 1;
	}
}


