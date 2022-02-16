#include	"ft_printf.h"

int ft_form_p(va_list *ap, char **str)
{
	size_t	n;
	void	*p;
	char	*tmp;	

	p = va_arg(*ap, void *);
	n = (size_t)p;
	tmp = ft_conv_dec(n, 16);
	if(tmp)
	{
		*str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (*str == NULL)
		return (0);
	return (1);
}

int ft_form_u(va_list *ap, char **str)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	*str = ft_conv_dec(n, 10);
	if (*str == NULL)
		return(0);
	return (1);
}

int ft_form_xX(va_list *ap, char **str, char c)
{
	char	*tmp;
	int		tmp_len;

	tmp = ft_conv_dec((size_t)va_arg(*ap, size_t), 16);
	if (tmp)
	{
		tmp_len = ft_strlen(tmp);
		if (tmp_len > 8)
		{
			*str = ft_substr(tmp, tmp_len - 8, tmp_len + 1);
			free(tmp);
			if (ft_strncmp(*str, "00000000", 8) == 0)
			{
				tmp = *str;
				*str = ft_substr("0", 0, 2); 
				free(tmp);
			}
		}
		else
			*str = tmp;
	}
	if (!*str)
		return (0);
	if (c == 'X')
		ft_form_X(str);
	return (1);
}

void	ft_form_X(char **str)
{
	size_t	n;

	n = 0;
	while ((*str)[n])
	{
		(*str)[n] = ft_toupper((*str)[n]);
		n++;
	}
}
