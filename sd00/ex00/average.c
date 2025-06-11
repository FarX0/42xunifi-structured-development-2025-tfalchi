/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:07:36 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/11 12:10:19 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"
float average(const int *arr, int size)
{
	int i = 0;
	float average = 0;
	int correct_nbr = 0;
	
	while (i < size)
	{
		if(arr[i] >= 0 && arr[i] <= 100)
		{
			average = average + arr[i];
			correct_nbr++;
		}
		i++;
	}
	average = average / correct_nbr;
	return (average);
}

/*
int main(void)
{
	// Test case 1: Mix of valid and invalid elements
	int arr1[] = {50, 75, -10, 90, 150, 25, 0, 100};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	float avg1 = average(arr1, size1);
	printf("Test case 1: Result: %.2f\n", avg1);
	
	// Test case 2: All valid elements
	int arr2[] = {10, 20, 30, 40, 50};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	float avg2 = average(arr2, size2);
	printf("Test case 2: Result: %.2f\n", avg2);
	
	// Test case 3: All invalid elements
	int arr3[] = {-5, -10, 101, 200, -50};
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	float avg3 = average(arr3, size3);
	printf("Test case 3: Result: %.2f\n", avg3);
	
	// Test case 4: Empty array
	int arr4[1];
	int size4 = 0;
	float avg4 = average(arr4, size4);
	printf("Test case 4: Result: %.2f\n", avg4);
	
	return 0;
} */