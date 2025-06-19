#ifndef EX00_H
# define EX00_H

# include <stdlib.h>
# include <unistd.h>

typedef struct file {
	char	*name;
	int		number;
	char	*author;
	bool	warning;
} file;

#endif
