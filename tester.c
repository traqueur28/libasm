#include "./inc/libasm.h"

void    strlen_tester()
{
    char test[4] = "0123";
    printf("ft: %ld | or: %ld\n", ft_strlen("test"), strlen("test"));
    printf("ft: %ld | or: %ld\n", ft_strlen("test\n"), strlen("test\n"));
    printf("ft: %ld | or: %ld\n", ft_strlen(test), strlen(test));
    printf("ft: %ld | or: %ld\n", ft_strlen(""), strlen(""));


}

int main()
{
    printf("BEGIN TEST\n");
    // ft_strlen("test");
    strlen_tester();
    return (0);
}