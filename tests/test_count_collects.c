/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_collects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:37:31 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 14:43:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

int ft_parse_char_arr(char *arr, char c)
{
	int i;
    int count;

	i = 0;
	count = 0;
	if (!arr)
		return (-1);
    while (arr[i])
    {
        if (arr[i] == c)
            count++;
        i++;
    }
    return count;
}

int ft_parse_char_2Darr(char **arr, char c)
{
	int i;
    int count;

	i = 0;
	count = 0;
	if (!arr)
		return (-1);		
    while (arr[i])
    {
        count += ft_parse_char_arr(arr[i], c);
        i++;
    }
    return count;
}

int test_count_collects(char **arr)
{
    return ft_parse_char_2Darr(arr, 'C');  // Fix function name
}

int main(void)
{
    char *arr[] = {
        "111111111111111111",
        "1P0000C00000000C01",
        "100011000111000001",
        "100000000000000001",
        "111101111011110111",
        "100000C00000000001",
        "101110001111000111",
        "1000000000000000E1",
        "111111111111111111",
        NULL
    };

    int result = 0;
	
	result = test_count_collects(arr);
    printf("Total 'C': 3 = %d\n", result);
    assert(result == 3);

	result = ft_parse_char_2Darr(arr, 'P');	
    printf("Total 'P': 1 = %d\n", result);
    assert(result == 1);
	
	result = ft_parse_char_2Darr(arr, 'X');	
    printf("Total 'X': 0 = %d\n", result);
    assert(result == 0);
    return 0;
}
