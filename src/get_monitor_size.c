/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_monitor_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:09:54 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 20:18:28 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_monitor	*get_monitor_size(void)
{
	t_monitor	*monitor;
	int	prime_monitor;

	prime_monitor = 0;
	monitor = malloc(sizeof(t_monitor));
	if(!monitor)
		return(NULL);
	mlx_get_monitor_size(prime_monitor, monitor->width, monitor->height);
}
