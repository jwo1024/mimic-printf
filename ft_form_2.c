/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:39:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/17 20:12:25 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	xX_rm_zero(char **str);
static void	xX_strupper(char **str);

int	ft_form_p(va_list *ap, char **str)
{
	size_t	n;
	void	*p;
	char	*tmp;	

	p = va_arg(*ap, void *);
	n = (size_t)p;
	tmp = ft_conv_dec(n, 16);
	if (tmp)
	{
		*str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (*str == NULL)
		return (0);
	return (1);
}

int	ft_form_u(va_list *ap, char **str)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	*str = ft_conv_dec(n, 10);
	if (*str == NULL)
		return (0);
	return (1);
}

int	ft_form_xX(va_list *ap, char **str, char c)
{
	int	str_len;

	*str = ft_conv_dec((size_t)va_arg(*ap, size_t), 16);
	if (*str)
	{
		str_len = ft_strlen(*str);
		if (str_len > 8)
			xX_rm_zero(str);
		if (c == 'X')
			xX_strupper(str);
		return (1);
	}	
	return (0);
}

static void	xX_rm_zero(char **str)
{
	char	*tmp;
	int		tmp_len;
	int		n;

	tmp = *str;
	tmp_len = ft_strlen(tmp);
	*str = ft_substr(tmp, tmp_len - 8, tmp_len + 1);
	free(tmp);
	if (ft_strncmp(*str, "00000000", 8) == 0)
	{
		free(*str);
		*str = ft_substr("0", 0, 2);
	}
	else
	{
		n = 0;
		while ((*str)[n] == '0')
			n++;
		tmp = *str;
		*str = ft_substr(tmp, n, ft_strlen(tmp));
		free(tmp);
	}
}

static void	xX_strupper(char **str)
{
	size_t	n;

	n = 0;
	while ((*str)[n])
	{
		(*str)[n] = ft_toupper((*str)[n]);
		n++;
	}
}
