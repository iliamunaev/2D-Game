/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arr_char_solid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:12:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 15:15:35 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool	ft_is_char_arr_solid(char *arr, char c)
{
	int i;

	i = 0;
	while(arr[i])
	{
		if(arr[i] != c)
			return (false);
		i++;
	}
	return (true);
}

void test_ft_is_char_arr_solid()
{
    // Case 1: All characters match
    assert(ft_is_char_arr_solid("AAA", 'A') == true);

    // Case 2: Contains a different character
    assert(ft_is_char_arr_solid("AAABAA", 'A') == false);

    // Case 3: Empty string (should be considered "solid" as it has no conflicting characters)
    assert(ft_is_char_arr_solid("", 'A') == true);

    // Case 4: String with one matching character
    assert(ft_is_char_arr_solid("A", 'A') == true);

    // Case 5: String with one non-matching character
    assert(ft_is_char_arr_solid("B", 'A') == false);


    printf("All tests passed successfully!\n");
}

int main(void)
{
    test_ft_is_char_arr_solid();
    return 0;
}