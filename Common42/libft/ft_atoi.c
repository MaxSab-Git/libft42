/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 13:29:06 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/20 13:58:00 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspace(int c)
{
	return (('\t' <= c && '\r' >= c) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	if (nptr)
	{
		i = 0;
		while (isspace(nptr[i]))
			i++;
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			sign *= -2 * (nptr[i] == '-') + 1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			num = num * 10 + (nptr[i] - '0');
			i++;
		}
	}
	return (num * sign);
}
