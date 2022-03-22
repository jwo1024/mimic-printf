/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:44 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:17:45 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		if (c == 32)
			return (64);
		else if (ft_isalnum(c))
			return (ft_isalnum(c));
		return (16);
	}
	return (0);
}
