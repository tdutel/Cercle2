/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:24 by tdutel            #+#    #+#             */
/*   Updated: 2023/01/04 17:45:57 by tdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_list	*ft_lstnew_secure(void *content, void (*del)(void *))
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
	{
		del(content);
		return (NULL);
	}
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew_secure((*f)(lst->content), del);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
