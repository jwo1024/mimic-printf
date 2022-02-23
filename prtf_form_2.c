/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_form_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:39:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/23 16:04:20 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	prtf_form_p(va_list *ap, t_string *str)
{
	char	*tmp;
	void	*a;

	a = va_arg(*ap, void *);
	tmp = prtf_conv_base((size_t)a, 16, "0123456789abcdef");
	if (tmp)
	{
		str->s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if ((str->s) == NULL)
		return (0);
	str->s_len += ft_strlen(str->s);
	return (1);
}

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
	size_t	a;
	size_t	l;
	char	*nbr;

	l = 0;
	a = n;
	while (a || (l == 0 && n == 0))
	{
		a = a / base;
		l++;
	}
	nbr = (char *)malloc(sizeof(char) * (l + 1));
	a = 0;
	while (nbr && a < l)
	{
		nbr[l - a - 1] = idx[n % base];
		n = n / base;
		a++;
	}
	if (nbr)
		nbr[a] = '\0';
	return (nbr);
}
