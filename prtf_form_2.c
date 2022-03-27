/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_form_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:38:13 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/28 02:21:37 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	prtf_form_u(va_list *ap, t_string *str)
{
	unsigned int	a;

	a = va_arg(*ap, unsigned int);
	str->s = prtf_conv_base((size_t)a, 10, "0123456789");
	if ((str->s) == NULL)
		return (0);
	str->s_len += ft_strlen(str->s);
	return (1);
}

int	prtf_form_x(va_list *ap, t_string *str, char c)
{
	unsigned int	a;

	a = va_arg(*ap, unsigned int);
	if (c == 'x')
		str->s = prtf_conv_base((size_t)a, 16, "0123456789abcdef");
	else
		str->s = prtf_conv_base((size_t)a, 16, "0123456789ABCDEF");
	if (str->s)
	{
		str->s_len = ft_strlen(str->s);
		if (str->s_len > 8)
			prtf_x_rmzero(str);
		return (1);
	}
	return (0);
}

void	prtf_x_rmzero(t_string *str)
{
	char	*tmp;
	int		n;

	tmp = str->s;
	str->s = ft_substr(tmp, str->s_len - 8, str->s_len + 1);
	free(tmp);
	if (ft_strncmp(str->s, "00000000", 8) == 0)
	{
		free(str->s);
		str->s = ft_strdup("0");
	}
	else
	{
		n = 0;
		while ((str->s)[n] == '0')
			n++;
		tmp = str->s;
		str->s = ft_substr(tmp, n, ft_strlen(tmp));
		str->s_len = ft_strlen(str->s);
		free(tmp);
	}
}

char	*prtf_conv_base(size_t n, size_t base, char *idx)
{
	size_t	div;
	size_t	i;
	size_t	len;
	char	*nbr;

	len = 0;
	div = n;
	while (div || (len == 0 && n == 0))
	{
		div = div / base;
		len++;
	}
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (nbr && i < len)
	{
		nbr[len - i - 1] = idx[n % base];
		n = n / base;
		i++;
	}
	if (nbr)
		nbr[i] = '\0';
	return (nbr);
}
