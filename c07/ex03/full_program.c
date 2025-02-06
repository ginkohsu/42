
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main(int ac, char **av)
{
    char *result;
    char *sep;

    if (ac == 1)
        return (0);
    sep = " ";
    result = ft_strjoin(ac - 1, av + 1, sep);
    if (result != NULL)
    {
        printf("%s\n", result);
        free(result);
    }
    return (0);
}

