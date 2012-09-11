#include <stdarg.h>
#include <stdlib.h>
#include "base.h"


void check_zero(const char* format, int* pt_count,va_list a_list)
{
	int size;
	char* str;
	int	count2;

	count2 = 0;
	*pt_count = *pt_count + 1;
	size = 0;
	while (format[*pt_count] >= '0' && format[*pt_count] <= '9')
	{
		size = size + 1;
		*pt_count = *pt_count + 1;
	}
	if  (format[*pt_count] == 'd')
	{
		str = malloc(sizeof(*str) * size);
		*pt_count = *pt_count - size;
		while (format[*pt_count] != 'd')
		{
			str[count2] = format[*pt_count];
			*pt_count = *pt_count + 1;
			count2 = count2 + 1;
		}
		print_zero(atoi(str), size_nbr(va_arg(a_list,int)));
		
	}
}


va_list check_point(const char* format,va_list a_list,int* pt_count)
{
	int	size;
	char*	str;
	int	count2;

	count2 = 0;
	*pt_count = *pt_count + 2;
	size = 0;
	while (format[*pt_count] >= '0' && format[*pt_count] <= '9')
	{
		size = size + 1;
		*pt_count = *pt_count + 1;
	}
	if  (format[*pt_count] == 's')
	{
		str = malloc(sizeof(*str) * size);
		*pt_count = *pt_count - size;
		while (format[*pt_count] != 's')
		{
			str[count2] = format[*pt_count];
			*pt_count = *pt_count + 1;
			count2 = count2 + 1;
		}
		
		print_point(atoi(str), va_arg(a_list,char*));
	}
	*pt_count = *pt_count + 1;
	return a_list;
}



va_list func_type_d(va_list a_list)
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

va_list  search_func_type(va_list a_list,t_list* begin)
{
		if (begin->value[0] == 'd')
			a_list = func_type_d(a_list);
		else if(begin->value[0] == 's')
			 a_list = func_type_s(a_list);
		else if(begin->value[0] == 'x')
			a_list = func_type_x(a_list, begin->value[0]);
		else if(begin->value[0] == 'X')
			a_list = func_type_x(a_list, begin->value[0]);
		else if(begin->value[0] == 'o')
			 a_list = func_type_o(a_list);

	return a_list;
}


va_list	check(t_list* begin, const char* format,va_list a_list,int* pt_count)
{
	while (begin->next != 0)
	{
		if (format[*pt_count + 1] == begin->value[0])
		{
			*pt_count = *pt_count + 1;
			a_list = search_func_type(a_list,begin);
			return a_list;
		}
		begin = begin->next;
	}
	if (format[*pt_count + 1] == '0')
	{
		 	check_zero(format,pt_count,a_list);
			id_print_nbr(va_arg(a_list,int));
	}
	if (format[*pt_count + 1] == '.')
		a_list = check_point(format,a_list,pt_count);
			return a_list;
}
