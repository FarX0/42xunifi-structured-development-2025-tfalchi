/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/19 16:55:22 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size > 1)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else if (size == 1)
		dst[i] = '\0';
	return (len);
}

/*int	main(void)
{
    char 	dest[20];
   // const char *source = "1234567890";
   // size_t size = 10;

	printf("  %ld  ",ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
   // size_t result = ft_strlcpy(des, source, size);

   // printf("Result: %zu\n", result);
   // printf("Destination: %s\n", destination);
   // return 0;
}*/
