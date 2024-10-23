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
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("\n[!] - Beginning basic tests...\n\n");
	ft_printf("");
	ft_printf("%");
	ft_printf("\n% \n");
	ft_printf("wow wow\n");
	ft_printf("wow\t\twow\n");
	ft_printf("%%\n");

	ft_printf("\n[!] - c conversion tests...\n\n");
	ft_printf("Printing c : %c\n", 'c');
	ft_printf("Printing a null character : %c\n", '\0');
	ft_printf("Printing 9 : %c\n", '9');

	ft_printf("\n[!] - s conversion tests...\n\n");
	ft_printf("String 1 : %s\n", "");
	ft_printf("String 2 : %s\n", "\nwow\nwow\n");
	ft_printf("String 3 : %s\n", "Without the Lord, all is in vain.");
	ft_printf("String 4 : %s\n", "Time to mix drinks and change lives.");
	ft_printf("String 5 : %s\n", "\n\t\b\t\n");
	ft_printf("String 6 : %s\n", "%s");

	ft_printf("\n[!] - d conversion tests...\n\n");
	ft_printf("Printing 0 : %d\n", 0);
	ft_printf("Printing NULL : %d\n", NULL);
	ft_printf("Printing 99 : %d\n", 99);
	ft_printf("Printing -99 : %d\n", -99);
	ft_printf("Printing INT_MAX : %d\n", INT_MAX);
	ft_printf("Printing INT_MIN : %d\n", INT_MIN);

	ft_printf("\n[!] - i conversion tests...\n\n");
	ft_printf("Printing 0 : %i\n", 0);
	ft_printf("Printing NULL : %i\n", NULL);
	ft_printf("Printing 99 : %i\n", 99);
	ft_printf("Printing -99 : %i\n", -99);
	ft_printf("Printing INT_MAX : %i\n", INT_MAX);
	ft_printf("Printing INT_MIN : %i\n", INT_MIN);

	ft_printf("\n[!] - u conversion tests...\n\n");
	ft_printf("Printing 0 : %u\n", 0);
	ft_printf("Printing NULL : %u\n", NULL);
	ft_printf("Printing 99 : %u\n", 99);
	ft_printf("Printing -99 : %u\n", -99);
	ft_printf("Printing INT_MAX : %u\n", INT_MAX);
	ft_printf("Printing INT_MIN : %u\n", INT_MIN);
}
