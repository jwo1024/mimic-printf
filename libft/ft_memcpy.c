/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:24:50 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:24:54 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d_temp;
	const unsigned char	*s_temp;

	d_temp = dst;
	s_temp = src;
	i = 0;
	while (i < n && dst != src)
	{
		d_temp[i] = s_temp[i];
		i++;
	}
	return (dst);
}
