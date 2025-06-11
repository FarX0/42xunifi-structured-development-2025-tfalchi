/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:38:26 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/10 18:23:50 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
    int i = 0;
	int k = 0;
	int result = 0;
    
	if (arr[i] != -1 && size > 0)
	{
        k++;
		i++;
	}
	while (i < size)
	{
        while (arr[i] != -1 && i < size)
		{
            if(arr[i] > arr[i - 1])
            k++;
			i++;
		}
		if(k >= 3)
        result++;
		k = 0;
		if (i < size)
        i++;
	}
	return (result);
}
/*
int main(void)
{
    // Test case 1: Empty array
    int arr1[] = {};
    int size1 = 0;
    printf("Test case 1 (Empty array): %d\n", count_segments(arr1, size1));
    
    // Test case 2: Array with only -1 values
    int arr2[] = {-1, -1, -1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test case 2 (Only -1s): %d\n", count_segments(arr2, size2));
    
    // Test case 3: Array with no -1 values (single segment)
    int arr3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Test case 3 (Single segment, increasing): %d\n", count_segments(arr3, size3));
    
    // Test case 4: Array with non-increasing single segment
    int arr4[] = {5, 4, 3, 2, 1};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Test case 4 (Single segment, non-increasing): %d\n", count_segments(arr4, size4));
    
    // Test case 5: Multiple segments with increasing values
    int arr5[] = {1, 2, 3, -1, 4, 5, 6, -1, 7, 8};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test case 5 (Multiple segments, all increasing): %d\n", count_segments(arr5, size5));
    
    // Test case 6: Multiple segments with mixed patterns
    int arr6[] = {1, 0, 3, -1, 4, 2, 6, -1, 7, 7, 9};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Test case 6 (Multiple segments, mixed patterns): %d\n", count_segments(arr6, size6));
    
    // Test case 7: Array starting with -1
    int arr7[] = {-1, 1, 2, 3, -1, 4, 5};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("Test case 7 (Starting with -1): %d\n", count_segments(arr7, size7));
    
    // Test case 8: Array ending with -1
    int arr8[] = {1, 2, 3, -1, 4, 5, -1};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    printf("Test case 8 (Ending with -1): %d\n", count_segments(arr8, size8));
    
    // Test case 9: Single element, not -1
    int arr9[] = {5};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    printf("Test case 9 (Single element, not -1): %d\n", count_segments(arr9, size9));
    
    // Test case 10: Single element, -1
    int arr10[] = {-1};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    printf("Test case 10 (Single element, -1): %d\n", count_segments(arr10, size10));
    
    return 0;
}
 */