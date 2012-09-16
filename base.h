#ifndef _base_h_
#define _base_h_

void	id_print_char(char c);
void	id_print_str(char* str);
void	id_print_nbr(int n);
void	id_print_str(char* str);
void	id_print_char(char c);
void	convert_dec_to_bin(int dec, char c);
typedef	struct	s_list
{
	char*	value;
	char*	token;
	struct	s_list* next;
}t_list;
va_list	func_type_d(va_list a_list);
va_list	func_type_s(va_list a_list);
va_list	func_type_x(va_list a_list, char c);
va_list	func_type_o(va_list a_list);
va_list	check(t_list* listype, const char* format, va_list a_list, int* pt_count);
int	size_nbr(int numb);
void	print_zero(int zero, int size);
void	print_point(int numb, char* str);
char*	id_getline(int fd);
t_list*	id_print_list(int fd, int fd2, t_list* tokenlist, int count);
char*	id_getline(int fd);
#endif
