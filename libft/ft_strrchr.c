/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:28:02 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:28:04 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	a;

	a = (char)c;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (s[l] == a)
			return ((char *)&s[l]);
		l--;
	}
	return (NULL);
}
