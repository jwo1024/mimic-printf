/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:57:54 by marvin            #+#    #+#             */
/*   Updated: 2022/01/21 22:30:07 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	rtn_ll(const char *str, unsigned long long result, int i);

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;

	result = 0;
	i = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			i *= -1;
	}
	return (rtn_ll(str, result, i));
}

static int	rtn_ll(const char *str, unsigned long long result, int i)
{
	unsigned long long	mul;
	int					idx;

	mul = 1;
	idx = 0;
	while ('0' <= str[idx] && str[idx] <= '9')
		idx++;
	while (0 < idx--)
	{
		result += (str[idx] - '0') * mul;
		if (mul == 1000000000000000000)
		{
			if ((result > 9223372036854775808ULL && i == -1)
				|| (0 < idx && i == -1))
				return (0);
			else if ((result > 9223372036854775807 && i == 1)
				|| (0 < idx && i == 1))
				return (-1);
			else
				break ;
		}
		mul *= 10;
	}
	return (result * i);
}
