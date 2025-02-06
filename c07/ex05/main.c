int main() {
    char *str = "abc;def:ghi";
    char *charset = ";:";
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

