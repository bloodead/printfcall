#include <stdlib.h>
#include <unistd.h>

char*   id_getline(int fd);
typedef	struct	s_list 
{
	char*	value;
	char*	token;
	struct	s_list*	next;  
}t_list;

t_list*	add_list(t_list* tmp, char* str, char* str2, int count)
{
	t_list*	begin;
	if (count > 0)
	{
		begin = tmp;
		while (begin->next != 0)
		{
			begin = begin->next;
		}
	}
	if (count == 0)
	{
		tmp = (t_list*)malloc(sizeof(*tmp));
		begin = tmp;
	}
	begin->next = (t_list*)malloc(sizeof(*begin));
	begin->value = str;
	begin->token = str2;
	begin = begin->next;
	begin->next = 0;
	return tmp;
}

t_list*	id_print_list(int fd, int fd2, t_list* tokenlist, int count)
{
	char*	str;
	char*	str2;

	str = id_getline(fd);
	str2 = id_getline(fd2);
	tokenlist = add_list(tokenlist, str, str2, count);
	return(tokenlist);
}
