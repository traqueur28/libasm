#include "./inc/libasm.h"

void    strcpy_check(char *(f1)(char *, const char *), char *(f2)(char *, const char *), const char *str, const char *str2) {
    char *res1, *res2;

    char dest1[12] = "********";
    char dest2[12] = "********";

    (void)f1;

    res1 = f1(dest1, str);
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

void    strcmp_check(int(f1)(const char *, const char *), int(f2)(const char *, const char *), const char *s1, const char *s2) {
    int r1, r2;

    r1 = f1(s1, s2);
    r2 = f2(s1, s2);

    if (r2 < 0)
        r2 = -1;
    if (r2 > 0)
        r2 = 1;
    
    if (r1 == r2)
        printf("OK\n");
    else
    {
        printf("KO\n");
        printf("ft = %d | or = %d\n", r1, r2);
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

void    strcmp_tester()
{
    strcmp_check(ft_strcmp, strcmp, "a", "");
    strcmp_check(ft_strcmp, strcmp, "", "a");

    strcmp_check(ft_strcmp, strcmp, "asd", "ASD");
    strcmp_check(ft_strcmp, strcmp, "ASD", "asd");

    strcmp_check(ft_strcmp, strcmp, "", "");
    strcmp_check(ft_strcmp, strcmp, "***", "***");

    strcmp_check(ft_strcmp, strcmp, "abc", "abc");
    strcmp_check(ft_strcmp, strcmp, "\0", "\0");
}

int main()
{
    printf("BEGIN TEST\n");
    // strlen_tester();
    // strcpy_tester();
    strcmp_tester();
    return (0);
}