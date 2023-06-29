#ifndef LIBASM_H
# define LIBASM_H

# include "stdio.h"
# include "string.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define YELLOW  "\033[33m"
#define DEFAULT "\033[0m"

size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

/*  ***** BONUS ***** */

int ft_atoi_base(char *str, char *base);

// ft_list_push_front (like the one in the piscine)
// ft_list_size (like the one in the piscine)
// ft_list_sort (like the one in the piscine)
// ft_list_remove_if (like the one in the piscine)

#endif