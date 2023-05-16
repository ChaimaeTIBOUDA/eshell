#include "main.h"
int main(void)
{
    char *full_command;
    char *copy_command = NULL;
    const char *delim = " \n";
    size_t n = 0;
    __ssize_t nchars_read;
    //(void)argc;
    int n_token = 0;
    char *token;
    int i;
    char **argv;

    printf("$ ");
    nchars_read = getline(&full_command, &n, stdin);
    printf("%s", full_command);
    copy_command = malloc(sizeof(char) * nchars_read);
    if (copy_command == NULL)
    {
        perror("tsh: memory allocation eroor");
        return (-1);
    }
    stpcpy(copy_command, full_command);
    if (nchars_read == -1)
    {
        printf("Exiting shell ....\n");
        return (-1);
    }
    else
    {
        token = strtok(full_command, delim);
        while (token != NULL)
        {
            n_token++;
            token = strtok(NULL, delim);
        }
        n_token++;
        argv = malloc(sizeof(char *) * n_token);
        token = strtok(copy_command, delim);
        for ( i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char *) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        } 
        argv[i] = NULL;
        free(argv);
        free(full_command);
        free(copy_command);

    }
    return (0);
}