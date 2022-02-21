/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:59:46 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/21 23:25:02 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	isset(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fro;
	size_t	bac;
	char	*str;

	str = NULL;
	if (s1)
	{
		fro = 0;
		bac = ft_strlen(s1) - 1;
		while (isset(set, s1[fro]))
			fro++;
		if (fro >= bac)
		{
			str = (char *)malloc(sizeof(char) * 1);
			if (str)
				*str = '\0';
			return (str);
		}
		while (isset(set, s1[bac]))
			bac--;
		str = ft_substr(s1, fro, bac - fro + 1);
	}	
	return (str);
}

static int	isset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
