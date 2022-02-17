/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:38:45 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/17 17:38:47 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

char	*ft_conv_dec(size_t n, size_t to)
{
	size_t	a;
	size_t	l;
	char	idx[17];
	char	*nbr;

	ft_strlcpy(idx, "0123456789abcdef", 17);
	l = 0;
	a = n;
	while (a || (l == 0 && n == 0))
	{
		a = a / to;
		l++;
	}
	nbr = (char *)malloc(sizeof(char) * (l + 1));
	a = 0;
	while (nbr && a < l)
	{
		nbr[l - a - 1] = idx[n % to];
		n = n / to;
		a++;
	}
	if (nbr)
		nbr[a] = '\0';
	return (nbr);
}
