/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:58:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/19 21:58:36 by jiwolee          ###   ########seoul.kr  */
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
