#include    "./libft/libft.h"
#include    <stdarg.h>
#include	<stdio.h>

int ft_printf(const char *c, ...);

char    *ft_conv_dec(size_t n, size_t to);
int     ft_prtf_justr(const char **cptr);
int     ft_prtf_form(const char **cptr, va_list *ap);
int     ft_form(char c, va_list *ap, char **nbr);
int     ft_form_c(va_list *ap, char **str, char c);
int     ft_form_s(va_list *ap, char **str);
int     ft_form_di(va_list *ap, char **str);
int     ft_form_p(va_list *ap, char **str);
int     ft_form_u(va_list *ap, char **str);
int     ft_form_xX(va_list *ap, char **str, char c);

int main(void)
{
    int i = -392;
	int	k = 99;
	char c = 'a';
	char *a = "9!";
	int	rtn;

    rtn = ft_printf("123\n%x\n%u\n%i\n", i, i, i);
	printf("rtn = %d\n", rtn);
    return (0);
}