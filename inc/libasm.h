#ifndef LIBASM_H
# define LIBADM_H

# include "stdio.h"
# include "string.h"
# include <unistd.h>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define YELLOW  "\033[33m"
#define DEFAULT "\033[0m"

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);


int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);


#endif