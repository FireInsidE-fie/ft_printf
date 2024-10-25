/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:51:18 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 15:02:10 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	process_string(char *str, int *count)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
