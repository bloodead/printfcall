#include <stdarg.h>
#include <stdlib.h>
#include "base.h"



va_list	func_type_d(va_list a_list)
{
	id_print_nbr(va_arg(a_list, int));
	return a_list;
}


va_list func_type_s(va_list a_list)
{
	id_print_str(va_arg(a_list, char*));
	return a_list;
}


va_list func_type_x(va_list a_list, char c)
{
	int numb;

	numb = va_arg(a_list, int);
	convert_dec_to_bin(numb,c);
	return a_list;
}

va_list func_type_o(va_list a_list)
{
	int numb;

	numb = va_arg(a_list, int);
	convert_dec_to_bin(numb,'o');
	return a_list;
}


