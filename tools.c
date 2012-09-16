#include <stdarg.h>
#include <stdlib.h>
#include "base.h"
#include "reduc.h"

void	convert_bin_to_octal(char* dec)
{
	char*	bin;
	int	count;
	int	calc;

	bin = malloc(sizeof(*bin) * 3);
	calc = 0;
	count = 7;
	while (count >= 0)
	{
		if(dec[count] == '1')
			calc = bin_octal(count, calc);
		if (count == 5 || count == 2 || count == 0)
		{
			bin = bin_octal_s(count, bin, calc);
			calc = 0;
		}
		count = count - 1;
	}
	id_print_str(bin);
	free(bin);
}


void	convert_bin_to_hexa(char* dec, char c)
{
	char* bin;
	int count;
	int calc;

	bin = malloc(sizeof(*bin) * 2);
	if (c == 'x')
		c = 'a';
	else
		c = 'A';
	count = 0;
	calc = 0;
	while (count != 8)
	{
		if(dec[count] == '1')
			calc = bin_hexa(count, calc);
		if (count == 3 || count == 7)
		{
			bin = bin_hexa_s(count, calc, bin, c);
			calc = 0;
		}
		count = count + 1;
	}
		id_print_str(bin);
		free(bin);
}

void	convert_dec_to_bin(int dec, char c)
{
	char	bin[8];
	int	count;
	int	calc1;
	count = 7;
	calc1 = 0;
	
	while (count >= 0)
	{	
		calc1 = dec % 2;
		dec = dec / 2;
		bin[count] = '0' + calc1;
		count = count - 1;
	}
	if (c == 'x' || c == 'X')
		convert_bin_to_hexa(bin,c);
	else if (c == 'o')
		convert_bin_to_octal(bin);
}
