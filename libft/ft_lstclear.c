/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:18:53 by jiwolee           #+#    #+#             */
/*   Updated: 2022/03/22 15:18:57 by jiwolee          ###   ########.fr       */
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
