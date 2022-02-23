/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:58:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/02/23 15:57:20 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*temp;

	if (lst && *lst)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = temp->next;
			ft_lstdelone(temp, del);
		}
	}
}
