/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:23:40 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/20 14:47:00 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*new_elem;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s) + 1;
	new_elem = malloc(slen);
	if (!new_elem)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_elem[i] = s[i];
		i++;
	}
	new_elem[i] = '\0';
	return (new_elem);
}
