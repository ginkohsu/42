#include <unistd.h>
#include <stdio.h>

int ft_str_is_alpha(char *str);

int ft_str_is_alpha(char *str)
{
    while (*str)
    {   
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
        {   
            return (0);
        }   
        str ++; 
    }   
    return (1);
}

int main( )
{
    char *string = "Hello world";
    int result = ft_str_is_alpha(string);
    printf("%d\n", result);
    return (0);
}
~      
