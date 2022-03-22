/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:41:14 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:41:17 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_substr(s, 0, ft_strlen(s));
	if (str)
	{
		i = 0;
		while (str[i])
		{
			str[i] = f(i, str[i]);
			i++;
		}
	}
	return (str);
}
