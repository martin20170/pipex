/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:39:44 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/23 16:39:52 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	if (*lst)
	{
		while (ptr->next)
		{
			next = ptr->next;
			ft_lstdelone(ptr, *del);
			ptr = next;
		}
		ft_lstdelone(ptr, *del);
		*lst = NULL;
	}
}
