#ifndef CRITICAL_WINDOWS_H
# define CRITICAL_WINDOWS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>

int		count_critical_windows(const int *readings, int size);
bool	is_critical(const int *readings);

#endif