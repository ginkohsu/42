int main( )
{       
        char dest[50];
        char *src =  "She isn't a kitty";
        char *newstr = ft_strncpy(dest, src, 9);
        printf("%s\n", newstr);
}

