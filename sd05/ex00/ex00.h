#ifndef EX00_H
# define EX00_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "libft/libft.h"

typedef struct book
{
	char	*title;
	char	*author;
	int		number;
	bool	warning;
}	t_book;

#endif