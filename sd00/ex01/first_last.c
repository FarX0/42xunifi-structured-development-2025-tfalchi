/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:19:41 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/10 18:24:05 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int i = 0;

	first[0] = -1;
	last[0] = -1;
	while (i < size)
	{
		if(arr[i] == target)
		{
			if (first[0] == -1)
				first[0] = i;
			last[0] = i;
		}
		i++;
	}
}
/*
int main(void)
{
    int first, last;
    
    // Test case 1: Target appears multiple times
    int arr1[] = {5, 7, 7, 8, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 8;
    
    first_last(arr1, size1, target1, &first, &last);
    printf("Test case 1: Target = %d, First = %d, Last = %d\n", target1, first, last);
    
    // Test case 2: Target appears once
    int arr2[] = {5, 7, 7, 9, 10, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 9;
    
    first_last(arr2, size2, target2, &first, &last);
    printf("Test case 2: Target = %d, First = %d, Last = %d\n", target2, first, last);
    
    // Test case 3: Target doesn't exist
    int arr3[] = {5, 7, 7, 9, 10, 10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 8;
    
    first_last(arr3, size3, target3, &first, &last);
    printf("Test case 3: Target = %d, First = %d, Last = %d\n", target3, first, last);
    
    // Test case 4: Empty array
    int arr4[0];
    int size4 = 0;
    int target4 = 5;
    
    first_last(arr4, size4, target4, &first, &last);
    printf("Test case 4: Target = %d, First = %d, Last = %d\n", target4, first, last);
    
    return 0;
} */