/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:10:45 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/21 12:23:30 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nstr[11];
	size_t	i;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = 10;
	while (1)
	{
		nstr[i--] = (n % 10) * sign + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (sign == -1)
		nstr[i] = '-';
	else
		i++;
	write(fd, nstr + i, 11 - i);
}
