/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:40:37 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:40:40 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && i < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
