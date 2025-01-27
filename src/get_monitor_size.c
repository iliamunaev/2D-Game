/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_monitor_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:09:54 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 18:29:06 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_monitor	*get_monitor_size(void)
{
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if(!monitor)
	{
		ft_putstr_fd("Error: memory allocation for monitor failed\n", 2);
		return(NULL);
	}
	monitor->height = 0;
	monitor->width = 0;

	mlx_get_monitor_size(0, &monitor->width, &monitor->height);
	
	printf("get_monitor_size() monitor hight: %d\n", monitor->height); // test
	printf("get_monitor_size() monitor wigth: %d\n", monitor->width); // test
	return (monitor); 
}
