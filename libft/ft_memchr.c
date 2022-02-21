/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:58:53 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/19 21:58:53 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		cc;

	cc = (unsigned char)c;
	i = 0;
	str = s;
	while (i < n)
	{
		if (*str == cc)
			return ((void *)str);
		str++;
		i++;
	}
	return (0);
}
