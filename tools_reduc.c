


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
