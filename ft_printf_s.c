/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:51:18 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 14:00:37 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_string(char *str, int *count)
{
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
