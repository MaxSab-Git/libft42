/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:58:04 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/21 14:13:41 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**new_last;
	t_list	*new_elem;
	void	*new_content;

	new_list = NULL;
	new_last = &new_list;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->content = new_content;
		*new_last = new_elem;
		new_last = &new_last[0]->next;
		lst = lst->next;
	}
	return (new_list);
}
