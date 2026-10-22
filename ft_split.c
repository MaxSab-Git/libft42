/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:59:49 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/20 17:15:41 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned int	split_count(char const *s, char c)
{
	unsigned int	strcount;
	const char		*start;
	const char		*end;

	start = s;
	end = s;
	strcount = 0;
	while (end && *end != '\0')
	{
		end = ft_strchr(start, c);
		if (end != start)
			strcount++;
		start = end + 1;
	}
	return (strcount);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	strcount;
	const char		*st;
	const char		*end;
	char			**splitted;

	st = s;
	end = s;
	splitted = malloc((split_count(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	strcount = 0;
	while (end && *end != '\0')
	{
		end = ft_strchr(st, c);
		if (!end)
			end = st + ft_strlen(st);
		if (end != st)
		{
			splitted[strcount] = malloc((size_t)(end - st + 1) * sizeof(char));
			ft_strlcpy(splitted[strcount++], st, (size_t)(end - st) + 1);
		}
		st = end + 1;
	}
	splitted[strcount] = NULL;
	return (splitted);
}
