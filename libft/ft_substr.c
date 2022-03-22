/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:27:35 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:27:38 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || (unsigned int)s_len <= start)
	{
		str = (char *)malloc(sizeof(char));
		if (str)
			*str = '\0';
		return (str);
	}
	if (s_len < len)
		len = s_len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
