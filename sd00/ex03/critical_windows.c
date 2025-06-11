/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:16:52 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/10 18:23:18 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

bool is_critical(const int *readings)
{
	int i = 0;
	int flag = 0;
	float average = 0;
	
	while (i != 5)
	{
		if (readings[i] >= 70)
		{
			if (readings[i] > 150)
				return(0);
			flag++;
		}
		average = average + readings[i];
		i++;
	}
	average = average / 5;
	if(average >= 90 && flag >= 3)
		return (1);
	return(0);
}

int count_critical_windows(const int *readings, int size)
{
	int i = 0;
	int result = 0;

	while (i < size - 4)
	{
		result = result + is_critical(&readings[i]);
		i++;
	}
	return (result);
}

/*
int main(void)
{
    printf("Testing critical windows detection:\n");
    
    // Test case 1: Empty array (edge case)
    int arr1[] = {};
    int size1 = 0;
    printf("Test case 1 (Empty array): %d\n", count_critical_windows(arr1, size1));
    
    // Test case 2: Array with fewer than 5 elements (edge case)
    int arr2[] = {80, 100, 90, 75};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test case 2 (Less than 5 elements): %d\n", count_critical_windows(arr2, size2));
    
    // Test case 3: Exactly 5 elements, is critical
    int arr3[] = {70, 95, 110, 100, 90}; // 3 >= 70, avg = 93, all <= 150
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Test case 3 (Exactly 5 elements, critical): %d\n", count_critical_windows(arr3, size3));
    
    // Test case 4: Exactly 5 elements, not critical (average too low)
    int arr4[] = {70, 95, 110, 60, 60}; // 3 >= 70, avg = 79, all <= 150
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Test case 4 (5 elements, avg too low): %d\n", count_critical_windows(arr4, size4));
    
    // Test case 5: Exactly 5 elements, not critical (too few high readings)
    int arr5[] = {100, 30, 60, 60, 150}; // 2 >= 70, avg = 94, all <= 150
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test case 5 (5 elements, too few high readings): %d\n", count_critical_windows(arr5, size5));
    
    // Test case 6: Exactly 5 elements, not critical (reading too high)
    int arr6[] = {90, 95, 151, 100, 90}; // 4 >= 70, avg = 105.2, one > 150
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Test case 6 (5 elements, one reading too high): %d\n", count_critical_windows(arr6, size6));
    
    // Test case 7: Longer array with multiple windows
    int arr7[] = {60, 70, 80, 90, 100, 110, 120, 130, 60};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("Test case 7 (Multiple windows): %d\n", count_critical_windows(arr7, size7));
    
    // Test case 8: Edge case - exactly 3 readings >= 70 and avg exactly 90
    int arr8[] = {70, 70, 70, 110, 130}; // 3 >= 70, avg = 90
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    printf("Test case 8 (Edge case - 3 readings >= 70, avg = 90): %d\n", count_critical_windows(arr8, size8));
    
    // Test case 9: Edge case - readings exactly 150 (should be valid)
    int arr9[] = {150, 150, 150, 0, 0}; // 3 >= 70, avg = 90, none > 150
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    printf("Test case 9 (Edge case - readings exactly 150): %d\n", count_critical_windows(arr9, size9));
    
    return 0;
} */