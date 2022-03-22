/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:35:53 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 14:58:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			len = prtf_form(&c, &ap);
		else
			len = prtf_justr(&c);
		if (len == -1)
		{
			rtn = len;
			break ;
		}
		rtn += len;
	}
	va_end(ap);
	return (rtn);
}

int	prtf_justr(const char **cptr)
{
	int	len;

	len = 0;
	while ((*cptr)[len] != '\0' && (*cptr)[len] != '%')
		len++;
	write(1, *cptr, len);
	*cptr += len;
	return (len);
}

int	prtf_form(const char **cptr, va_list *ap)
{
	t_string	str;
	t_flags		flgs;

	ft_memset(&str, 0, sizeof(str));
	ft_memset(&flgs, 0, sizeof(t_flags));
	(*cptr)++;
	while (1)
	{
		if (prtf_form_srch(**cptr, ap, &str))
			break ;
		else
			if (prtf_flags(cptr, &str, &flgs) == 0 || **cptr == '\0')
				return (-1);
	}
	prtf_valid_flgs(&str, &flgs);
	prtf_apply_flgs(&str, &flgs);
	write(1, str.s, str.s_len);
	free(str.s);
	(*cptr)++;
	return (str.s_len);
}

int	prtf_flags(const char **cptr, t_string *str, t_flags *flgs)
{
	str->specific = 'd';
	if (**cptr == '+')
		flgs->plus = 1;
	else if (**cptr == '-')
		flgs->minus = 1;
	else if (**cptr == ' ')
		flgs->blank = 1;
	else if (**cptr == '#')
		flgs->sharp = 1;
	else if (**cptr == '0')
		flgs->zero = 1;
	else if (ft_isdigit(**cptr) || **cptr == '.')
	{
		prtf_dot_width(flgs, **cptr, cptr);
		return (1);
	}
	else
		return (0);
	(*cptr)++;
	return (1);
}

void	prtf_dot_width(t_flags *flgs, char c, const char **cptr)
{
	int		i;
	size_t	*dest;

	i = 0;
	if (c == '.')
	{
		flgs->dot = 1;
		dest = &(flgs->len_dot);
		if ((*cptr)++ && !ft_isdigit(**cptr))
			return ;
	}
	else
	{
		flgs->width = 1;
		dest = &(flgs->len_width);
	}
	while (ft_isdigit((*cptr)[i]))
	{
		if (*dest)
			*dest *= 10;
		*dest += ((*cptr)[i] - '0');
		i++;
	}
	*cptr += i;
}
