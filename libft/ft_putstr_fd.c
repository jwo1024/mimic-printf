/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:59:05 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 14:46:53 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (fd >= 0)
	{
		while (s && s[len])
			len++;
		write(fd, s, len);
	}
}
