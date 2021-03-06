#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "base.h"


t_list*	load_rep(t_list* idenlist)
{	
	char*	path;
	int	fd;
	int	fd2;
	int	count;

	count = 0;
	path = "id.id";
	fd = open(path, 0);
	path = "repid.id";
	fd2 = open(path, 0);
	if (fd == -1 || fd2 == -1)
	{
	id_print_str("ERROR TO OPEN");
	return(0);
	}
	while (count != 8)
	{
		idenlist = id_print_list(fd, fd2, idenlist, count);
		count = count + 1;
	}
	return (idenlist);
}

void	check_type(const char* format, va_list a_list, t_list* listype)
{
	int*	pt_count;
	int	count;

	count = 0;
	pt_count = &count;
	while (format[count] != '\0')
	{
		if (format[count] == '%' && format[count + 1] != '%' )
		{
			a_list = check(listype,format,a_list,pt_count);
		}
		else if (format[count] == '%' && format[count + 1] == '%' )
		{
			id_print_char('%');
			count = count + 1;
		}
		else
		 id_print_char(format[count]);
		count = count + 1;
	}
}


void	id_printf(const char* format, ...)
{
	t_list*	listype;
	va_list	a_list;
	listype = 0;
	listype = load_rep(listype);
	va_start(a_list, format);
	check_type(format,a_list, listype);
	va_end(a_list);
	free(listype);
}
