/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:39:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/23 15:27:34 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	prtf_form_srch(char c, va_list *ap, t_string *str)
{
	int	rtn;

	rtn = 0;
	str->s_len = 0;
	str->specific = c;
	if (c == '%' || c == 'c')
		rtn = prtf_form_c(ap, str, c);
	else if (c == 's')
		rtn = prtf_form_s(ap, str);
	else if (c == 'd' || c == 'i')
		rtn = prtf_form_di(ap, str);
	else if (c == 'p')
		rtn = prtf_form_p(ap, str);
	else if (c == 'u')
		rtn = prtf_form_u(ap, str);
	else if (c == 'x' || c == 'X')
		rtn = prtf_form_xX(ap, str, c);
	return (rtn);
}

int	prtf_form_c(va_list *ap, t_string *str, char c)
{
	str->s = (char *)malloc(sizeof(char) * 2);
	if (str->s)
	{
		if (c == '%')
			str->s[0] = '%';
		else if (c == 'c')
			str->s[0] = va_arg(*ap, int);
		str->s[1] = '\0';
		str->s_len += 1;
		return (1);
	}
	return (0);
}

int	prtf_form_s(va_list *ap, t_string *str)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		str->s = ft_strdup("(null)");
	else if (s)
		str->s = ft_strdup(s);
	if (!(str->s))
		return (0);
	str->s_len += ft_strlen(str->s);
	return (1);
}

int	prtf_form_di(va_list *ap, t_string *str)
{
	int		n;
	char	*tmp;

	n = va_arg(*ap, int);
	if (n == -2147483648)
		str->s = ft_strdup("-2147483648");
	else if (n < 0)
	{
		n *= -1;
		tmp = prtf_conv_base(n, 10, "0123456789");
		if (tmp)
		{
			str->s = ft_strjoin("-", tmp);
			free(tmp);
		}
	}
	else
		str->s = prtf_conv_base(n, 10, "0123456789");
	if ((str->s) == NULL)
		return (0);
	str->s_len += ft_strlen(str->s);
	return (1);
}
