/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:58 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:05:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Opens the map file for reading.
 *
 * Opens the specified map file in read-only mode. If the file cannot 
 * be opened, an error message is printed.
 *
 * @param map_file Path to the map file.
 * @return The file descriptor on success, or -1 on failure.
 */
int	open_map_file(const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error: failed to open map file.\n", 2);
	return (fd);
}

/**
 * @brief Trims newline characters from a 2D array of strings.
 *
 * Iterates through each row of the 2D array and removes trailing 
 * newline characters, replacing them with null terminators.
 *
 * @param arr Pointer to the 2D array of strings.
 */
void	trim_2d_array(char **arr)
{
	int	i;
	int	len;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 0 && arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		i++;
	}
}
