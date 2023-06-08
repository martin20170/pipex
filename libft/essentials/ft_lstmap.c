/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:15:14 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:15:38 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essentials.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*element;

	if (lst == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	element = new_list;
	while (lst->next)
	{
		lst = lst->next;
		element->next = ft_lstnew((*f)(lst->content));
		if (element == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		element = element->next;
	}
	return (new_list);
}
