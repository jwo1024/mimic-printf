#include    "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		len;
	int		rtn;

	va_start(ap, c);
	len = 1;
    rtn = 0;
	while (*c != '\0')
	{
		if (*c == '%')
			len = ft_prtf_form(&c, &ap);
		else
			len = ft_prtf_justr(&c);
		if (len == -1)
		{
			rtn = len;
			break;
		}
		rtn += len;
	}
	va_end(ap);
	return (rtn);
}

int ft_prtf_justr(const char **cptr)
{
	int	len;

	len = 0;
	while ((*cptr)[len] != '\0' && (*cptr)[len] != '%')
	{
		ft_putchar_fd((*cptr)[len], 1);
		len++;
	}
	*cptr += len;
	return (len);
}

int	ft_prtf_form(const char **cptr, va_list *ap)
{
	int		i;
	int		rtn;
	char	a;
	char	*str;

	i = 0;
	rtn = 0;
	(*cptr)++;
	while (1)
	{
		a = (*cptr)[i];
		i++;
		rtn = ft_form(a, ap, &str);
		if (rtn == 1)
			break;
		else if(a == '\0' || rtn == -1)
		{
			rtn = -1;
			break;
		}
	}
	if (rtn != -1)
		rtn = ft_wrtfre_str(**cptr, str);
	*cptr += i;
	return (rtn); // 연결부분 수정필요 길이를 반환하던지 그래야함
}

int	ft_wrtfre_str(char	c, char *str) //str malloc free 위치; 
{
	int	rtn;

	rtn = ft_strlen(str);
	if (str == NULL)
		ft_putstr_fd("(NULL)", 1);
	else
	{
		if (*str == '\0' && c == 'c')
		{
			ft_putchar_fd(*str, 1);
			rtn++;
		}
		else
			ft_putstr_fd(str, 1);
		free(str);
	}
	return (rtn);
}

int ft_form(char c, va_list *ap, char **nbr)
{
	int	rtn;

	rtn = 0;
	if (c == '%'|| c == 'c')
		rtn = ft_form_c(ap, nbr, c);
	else if (c == 's')
		rtn = ft_form_s(ap, nbr);
	else if (c == 'd' || c == 'i')
		rtn = ft_form_di(ap, nbr);
	else if (c == 'p')
		rtn = ft_form_p(ap, nbr);
	else if (c == 'u')
		rtn = ft_form_u(ap, nbr);
	else if (c == 'x' || c == 'X')
		rtn = ft_form_xX(ap, nbr, c);
	return (rtn);
}
