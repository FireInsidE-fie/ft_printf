/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:58 by estettle          #+#    #+#             */
/*   Updated: 2024/10/23 10:51:37 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	ft_printf("[!] - Beginning basic tests...\n\n");
	ft_printf("");
	ft_printf("wow wow\n");
	ft_printf("wow\t\twow\n");

	ft_printf("[!] - c conversion tests...\n\n");
	ft_printf("Printing c : %c\n", 'c');
	ft_printf("Printing a null character : %c\n", '\0');
	ft_printf("Printing 9 : %c\n", '9');
}
