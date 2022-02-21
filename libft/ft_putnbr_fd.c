/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:59:06 by jiwolee           #+#    #+#             */
/*   Updated: 2022/01/22 01:57:19 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	write_num(int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	min;
	int	max;

	min = -2147483648;
	max = 2147483647;
	if (fd < 0)
		return ;
	if (n == min)
		write(fd, "-2147483648", 11);
	else
	{
		 if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		write_num(n, fd);
	}
}

static void	write_num(int nb, int fd)
{
	int	a;
	int	num;
	int	result;

	num = nb;
	a = 1;
	while (num >= 10)
	{
		a = a * 10;
		num = num / 10;
	}
	while (a >= 1)
	{
		result = nb / a % 10;
		result += 48;
		write(fd, &result, 1);
		a = a / 10;
	}
}
