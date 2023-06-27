#include "./inc/libasm.h"

void    strlen_check(size_t (*f1)(const char *s), size_t (*f2)(const char *s), const char *str)
{
    size_t  r1, r2;

    r1 = f1(str);
    r2 = f2(str);

    // compare return
    if (r1 == r2)
        printf("%sOK%s\n", GREEN, DEFAULT);
    else
        printf("%sKO%s\n", RED, DEFAULT);
}

void    strcpy_check(char *(f1)(char *, const char *), char *(f2)(char *, const char *), const char *str, const char *str2) {
    char *res1, *res2;

    char dest1[12] = "********";
    char dest2[12] = "********";

    res1 = f1(dest1, str);
    res2 = f2(dest2, str2);

    // compare return | original str | target str
    if (!strcmp(res1, res2) && !strcmp(str, str2) && *res1 == *dest1 && *res2 == *dest2)
        printf("%sOK%s\n", GREEN, DEFAULT);
    else
    {
        printf("%sKO%s\n", RED, DEFAULT);
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
    
    // compare return
    if (r1 == r2)
        printf("%sOK%s\n", GREEN, DEFAULT);
    else
    {
        printf("%sKO%s\n", RED, DEFAULT);
        printf("ft = %d | or = %d\n", r1, r2);
    }
}

void    write_check(int fd, const void *buf, size_t count)
{
    ssize_t r1, r2;
    char    str1[100], str2[100];
    int     p1[2];
    int     p2[2];
    int     tmperrno;

    pipe(p1);
    pipe(p2);
    if (fd == -1)
    {
        close(p1[1]);
        close(p2[1]);
        r2 = ft_write(fd, buf, count);
        tmperrno = errno;
        r1 = write(fd, buf, count);
    }
    else
    {
        r2 = ft_write(p2[1], buf, count);
        tmperrno = errno;
        r1 = write(p1[1], buf, count);
    }

    // check errno
    // return
    // output if no error

    // printf("%zd == %zd | %d == %d\n", r1, r2, errno, tmperrno);
    if (r1 == r2 && errno == tmperrno)
    {
        if (r2 != -1 && r1 != -1) // check output
        {
            r1 = read(p1[0], str1, count);
            r2 = read(p2[0], str2, count);
            if (r1 == r2 && !strcmp(str1, str2))
                printf("%sOK%s\n", GREEN, DEFAULT);
            else
                printf("%sKO write%s\n", RED, DEFAULT);
        }
        else
            printf("%sOK on error write%s\n", GREEN, DEFAULT);
    }
    else
        printf("%sKO ERRNO or return%s\n", RED, DEFAULT);

}

void    read_check(int fd, size_t count)
{
    ssize_t r1, r2;
    char    str1[1000], str2[1000];
    int     p1[2];
    int     p2[2];
    int     tmperrno;

    if (fd == -1)
    {
        r2 = write(fd, str2, count);
        tmperrno = errno;
        r1 = write(fd, str1, count);
    }
    else
    {
        pipe(p1);
        pipe(p2);

        write(p2[1], "abcdefghijklmnopqrstuvwxyz 0123456798 42 est vraiment sympa\n", count);
        write(p1[1], "abcdefghijklmnopqrstuvwxyz 0123456798 42 est vraiment sympa\n", count);

        r2 = ft_read(p2[0], str2, count);
        str2[count] = 0;
        tmperrno = errno;
        r1 = read(p1[0], str1, count);
        str1[count] = 0;
    }

    // check erro
    // check return
    // check buff
    if (errno == tmperrno && r1 == r2 && !strcmp(str1, str2))
        printf("%sOK%s\n", GREEN, DEFAULT);
    else
        printf("%sKO : %d-%d | %zd-%zd | %d %s\n", RED, errno, tmperrno, r1, r2, strcmp(str1, str2), DEFAULT);
}

void    strdup_check(const char *str)
{
    char    *s1, *s2;

    s1 = strdup(str);
    s2 = ft_strdup(str);

    if (!strcmp(s1, s2) && s1 != s2 && s2 != str)
        printf("%sOK%s\n", GREEN, DEFAULT);
    else
        printf("%sKO%s\n", RED, DEFAULT);

    free(s1);
    free(s2);
}

// ****************************

void    strlen_tester()
{
    printf("%s*** STRLEN TESTER ***%s\n", YELLOW, DEFAULT);

    char test[4] = "0123";
    strlen_check(ft_strlen, strlen, "test");
    strlen_check(ft_strlen, strlen, "test\n");
    strlen_check(ft_strlen, strlen, test);
    strlen_check(ft_strlen, strlen, "");
}

void    strcpy_tester()
{
    printf("%s*** STRCPY TESTER ***%s\n", YELLOW, DEFAULT);

    strcpy_check(ft_strcpy, strcpy, "012345678", "012345678");
    strcpy_check(ft_strcpy, strcpy, "***", "***");

    strcpy_check(ft_strcpy, strcpy, "", "");
    strcpy_check(ft_strcpy, strcpy, "\0", "\0");
}

void    strcmp_tester()
{
    printf("%s*** STRCMP TESTER ***%s\n", YELLOW, DEFAULT);

    strcmp_check(ft_strcmp, strcmp, "a", "");
    strcmp_check(ft_strcmp, strcmp, "", "a");

    strcmp_check(ft_strcmp, strcmp, "asd", "ASD");
    strcmp_check(ft_strcmp, strcmp, "ASD", "asd");

    strcmp_check(ft_strcmp, strcmp, "", "");
    strcmp_check(ft_strcmp, strcmp, "***", "***");

    strcmp_check(ft_strcmp, strcmp, "abc", "abc");
    strcmp_check(ft_strcmp, strcmp, "\0", "\0");
}

void    write_tester()
{
    printf("%s*** WRITE TESTER ***%s\n", YELLOW, DEFAULT);

    write_check(1, "012345678\n", 11);
    write_check(1, "012345678\n\0", 50);
    write_check(1, "012345678", 5);
    write_check(1, "", 0);
    write_check(1, "abcd\n", 15);
    write_check(-1, "abcd\n", 15);
    write_check(1, "abcd\n", -1);

}

void    read_tester()
{
    printf("%s*** READ TESTER ***%s\n", YELLOW, DEFAULT);
    read_check(0, 42);
    read_check(0, 1);
    read_check(0, 0);
    read_check(0, 280);
    read_check(0, -1);
    read_check(-1, 42);
}

void    strdup_tester()
{
    printf("%s*** STRDUP TESTER ***%s\n", YELLOW, DEFAULT);
    strdup_check("");
    strdup_check("42");
    strdup_check("012345679");
    strdup_check("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vel nunc nulla. Proin ornare augue id lorem vestibulum, nec interdum.");
}

int main()
{
    printf("BEGIN TEST\n");
    strlen_tester();
    strcpy_tester();
    strcmp_tester();
    write_tester();
    read_tester();
    strdup_tester();

    return (0);
}