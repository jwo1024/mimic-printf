/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:16:07 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:16:23 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c))
		return (ft_isalpha(c));
	else if (ft_isdigit(c))
		return (ft_isdigit(c));
	return (0);
}
