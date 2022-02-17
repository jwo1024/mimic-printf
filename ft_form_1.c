#include    "ft_printf.h"

int	ft_form_c(va_list *ap, char **str, char c)
{
	*str = (char *)malloc(sizeof(char) * 2);
	if (*str)
	{
		if (c == '%')
			(*str)[0] = '%';
		else if (c == 'c')
			(*str)[0] = va_arg(*ap, int);
		(*str)[1] = '\0';
		return (1);
	}
	return (0);
}

int	ft_form_s(va_list *ap, char **str)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		*str = ft_strjoin("(null)", "");
	else if (s)
		*str = ft_substr(s, 0, ft_strlen(s) + 1);
	if (*str)
		return (1);
	return (0);
}

int	ft_form_di(va_list *ap, char **str)
{
	int		n;
	char	*tmp;

	n = va_arg(*ap, int);
	if (n == -2147483648)
		*str = ft_substr("-2147483648", 0, 12);
	else if (n < 0)
	{
		n *= -1;
		tmp = ft_conv_dec(n, 10);
		if (tmp)
		{
			*str = ft_strjoin("-", tmp);
			free(tmp);
		}
	}
	else
		*str = ft_conv_dec(n, 10);
	if (*str == NULL)
		return (0);
	return (1);
}
