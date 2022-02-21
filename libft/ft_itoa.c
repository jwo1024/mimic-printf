/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:52:30 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/19 21:58:38 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	cntdigit(int n);
static void	put_nbr(char *result, int nbr, int cnt);

char	*ft_itoa(int n)
{
	char	*result;
	int		cnt;

	cnt = cntdigit(n);
	if (n < 0)
		cnt++;
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	if (result)
		put_nbr(result, n, cnt);
	return (result);
}

static void	put_nbr(char *result, int nbr, int cnt)
{
	result[cnt--] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		while (cnt > 0)
		{
			result[cnt] = (-(nbr % 10) + '0');
			nbr = nbr / 10;
			cnt--;
		}
	}
	else
	{
		while (cnt >= 0)
		{
			result[cnt] = (nbr % 10) + '0';
			nbr = nbr / 10;
			cnt--;
		}
	}
}

static int	cntdigit(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}
