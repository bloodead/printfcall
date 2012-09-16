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
}


void	convert_bin_to_hexa(char* dec, char c)
{
	char bin[2];
	int count;
	int calc;

	if (c == 'x')
		c = 'a';
	else
		c = 'A';
	count = 0;
	calc = 0;
	while (count != 8)
	{
		if(dec[count] == '1')
		{
			if (count == 0 || count == 4)
				calc = calc + 8;
			else if (count == 1 || count == 5)
				calc = calc + 4;
			else if (count == 2 || count == 6)
				calc = calc + 2;
			else if (count == 3 || count == 7)
				calc = calc + 1;
		}

		if (count == 3)
		{
			if (calc >= 10)
			{
				calc = calc - 10;
				bin[0] = c + calc;
			}
			else
				bin[0] = '0' + calc;

			calc = 0;
			id_print_char(bin[0]);
		}

		if (count == 7)
		{
			if (calc >= 10)
			{
				calc = calc - 10;
				bin[1] = c + calc;
			}
			else
				bin[1] = '0' + calc;
			calc = 0;
			id_print_char(bin[1]);
		}
		count = count + 1;
	}
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
