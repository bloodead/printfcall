


int	bin_octal(int count, int calc)
{
	if (count == 7 || count == 4 || count == 1)
		calc = calc + 1;
	else if (count == 6 || count == 3 || count == 0)
		calc = calc + 2;
	else if (count == 5 || count == 2)
		calc = calc + 4;
	return calc;
}

char*	bin_octal_s(int count, char* bin, int calc)
{
	if (count == 5)
		bin[2] = '0' + calc;
	if (count == 2)
		bin[1] = '0' + calc;
	if (count == 0)
		bin[0] = '0' + calc;

	return bin;
}


int	bin_hexa(int count, int calc)
{
	if (count == 0 || count == 4)
		calc = calc + 8;
	else if (count == 1 || count == 5)
		calc = calc + 4;
	else if (count == 2 || count == 6)
		calc = calc + 2;
	else if (count == 3 || count == 7)
		calc = calc + 1;
	return calc;\
}

char*	bin_hexa_s(int count, int calc, char* bin, char c)
{
	if (count == 3)
	{
		if (calc >= 10)
		{
			calc = calc - 10;
			bin[0] = c + calc;
		}
		else
			bin[0] = '0' + calc;
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
	}
	return bin;
}
