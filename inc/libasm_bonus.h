#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <errno.h>
# include <stdlib.h>

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

int ft_atoi_base(char *str, char *base);

// ft_list_push_front (like the one in the piscine)
// ft_list_size (like the one in the piscine)
// ft_list_sort (like the one in the piscine)
// ft_list_remove_if (like the one in the piscine)

#endif