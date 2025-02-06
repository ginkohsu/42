//ex 00

#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int main(int ac, char **av)
{
    char *mock;
    char *real;

    if(ac == 2)
    {
        mock = ft_strdup(av[1]);
        real = strdup(av[1]);
        printf("%s\n%s\n", mock, real);
    }
    return (0);
}




//ex01

int main (int ac, char **argv)
{
    int min;
    int max;
    int *result;
    int i;

    if (ac != 3)
        return (0);
    min = atoi(argv[1]);
    max = atoi(argv[2]);
    result = ft_range(min, max);
    i = 0;
    while (i < (max - min))
    {
        printf("%i\n", result[i]);
        i++;
    }
    free(result);
    return 0;
}

/*mistake:
while (result[i])
  {
  printf("%i\n", result[i]);
  i++;
 }
 for integer array, it is different from char array,
 there is no null terminator, and result[i] is saying
 it will terminate when it encounters a 0, which can lead to error.
 */



//ex02

int main (int ac, char **argv)
{
    int min;
    int max;
    int result;
    int *arr;

    if (ac != 3)
        return (0);
    min = atoi(argv[1]);
    max = atoi(argv[2]);
    result = ft_ultimate_range(&arr, min, max); //wow "&range" is a pointer to the pointer range!
        printf("%i\n", result);
    free(arr);
    return 0;
}

