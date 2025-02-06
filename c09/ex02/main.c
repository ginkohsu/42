#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int main() {
    char *str = "sde:;e:sdf";
    char *charset = ":';";
    char **result = ft_split(str, charset);

    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word: %s\n", result[i]);
            free(result[i]);
        }
        free(result);
    }

    return 0;
}

