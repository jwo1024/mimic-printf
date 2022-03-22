/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:25:14 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dststr;
	unsigned char	*srcstr;
	size_t			i;

	if (len == 0 || dst == src)
		return (dst);
	dststr = (unsigned char *)dst;
	srcstr = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (dst < src)
			dststr[i] = srcstr[i];
		else
			dststr[len - i - 1] = srcstr[len - i - 1];
		i++;
	}
	return (dst);
}
