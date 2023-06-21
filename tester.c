#include "./inc/libasm.h"

void    strcpy_check(char *(f1)(char *, const char *), char *(f2)(char *, const char *), const char *str, const char *str2) {
    char *res1, *res2;

    char dest1[12] = "********";
    char dest2[12] = "********";

    (void)f1;

    res1 = f1(dest1, str);
    // res1 = f2(dest1, str);
    res2 = f2(dest2, str2);

    if (!strcmp(res1, res2) && !strcmp(str, str2) && *res1 == *dest1 && *res2 == *dest2)
        printf("OK\n");
    else
    {
        printf("KO\n");
        printf("ft_res = %s\nOr_res = %s\n", res1, res2);
        printf("ft_src = %s\nOr_src = %s\n", str, str2);
        printf("ft_des = %s\nOr_des = %s\n", dest1, dest2);
        printf("*res1 == *dest1: %d\n", *res1 == *dest1);
        printf("*res2 == *dest2: %d\n", *res2 == *dest2);
    }


}

void    strlen_tester()
{
    char test[4] = "0123";
    printf("ft: %ld | or: %ld\n", ft_strlen("test"), strlen("test"));
    printf("ft: %ld | or: %ld\n", ft_strlen("test\n"), strlen("test\n"));
    printf("ft: %ld | or: %ld\n", ft_strlen(test), strlen(test));
    printf("ft: %ld | or: %ld\n", ft_strlen(""), strlen(""));
}

void    strcpy_tester()
{
    strcpy_check(ft_strcpy, strcpy, "012345678", "012345678");
    strcpy_check(ft_strcpy, strcpy, "***", "***");

    strcpy_check(ft_strcpy, strcpy, "", "");
    strcpy_check(ft_strcpy, strcpy, "\0", "\0");
}

int main()
{
    printf("BEGIN TEST\n");
    // strlen_tester();
    strcpy_tester();
    return (0);
}