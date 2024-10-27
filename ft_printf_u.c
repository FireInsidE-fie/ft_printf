/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:40:27 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 15:43:41 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_uns_len(unsigned int nb)
{
	unsigned int	divider;
	int				digit_count;

	divider = 1;
	digit_count = 1;
	while ((nb / divider) >= 10)
	{
		divider *= 10;
		digit_count++;
	}
	return (digit_count);
}

static void	ft_putuns(unsigned int n)
{
	if (n >= 10)
	{
		ft_putuns(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

void	process_uns(unsigned int nb, int *count)
{
	ft_putuns(nb);
	*count += get_uns_len(nb);
}
