/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:57:15 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/21 13:01:16 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_free;

	while (*lst != NULL)
	{
		to_free = *lst;
		*lst = lst[0]->next;
		ft_lstdelone(to_free, del);
	}
}
