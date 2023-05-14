#include "main.h"
int main(int argc, char **argv)
{
    char *prompt = "(Shell) $";
    char *lineptr;
    char *lineptr_copy = NULL;
    const char *delim = " \n";
    size_t n = 0;
    __ssize_t nchars_read;
    (void)argc;
    (void)argv;

    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        if (nchars_read == -1)
        {
            printf("Exiting shell ....\n");
            return (-1);
        }
        printf("%s", lineptr);
        free(lineptr);
    }
    lineptr_copy = malloc(sizeof(char) * nchars_read);
    if (lineptr_copy == NULL)
    {
        perror("tsh: memory allocation eroor");
        return (-1);
    }
    stcpy(lineptr_copy, lineptr);
    return (0);
}