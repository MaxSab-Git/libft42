/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:40:00 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/20 15:50:39 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	trimsize;
	char	*trimmed;

	trimsize = 1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			trimsize++;
		i++;
	}
	trimmed = malloc(trimsize);
	if (!trimmed)
		return (NULL);
	trimsize = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			trimmed[trimsize++] = s1[i];
		i++;
	}
	trimmed[trimsize] = '\0';
	return (trimmed);
}
