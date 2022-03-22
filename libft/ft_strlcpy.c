/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:41:51 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:41:53 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize < 1)
		return (len);
	idx = 0;
	while (src[idx] != '\0' && idx + 1 < dstsize)
	{
		dst[idx] = (char)src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (len);
}
