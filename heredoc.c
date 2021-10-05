#include "minishell.h"


int get_delimeter(char *str)
{
    int flag;
    int i;
    int mode;

    i = 0;
    mode = 0;
    flag = 0;
    while(str[i])
    {
        if (!flag && (str[i] == 39 || str[i] == 34))
        {
            flag = remove_char(str, i, flag);;
            mode = 1;  
        }
        else if (flag && str[i] == flag)
            flag = remove_char(str, i, flag);
        else
            i++;
    }
    if (flag)
        return (-1);
    return mode;
}

void expand_line(char **line)
{
    int i;

    i = 0;
    while((*line)[i])
    {
        if((*line)[i] == '$')
            expand_env(line,i);
        else
            i++;
    }
}

int input_to_file(int fd, char *delimeter, int mode)
{
    char *line;
    
    while(1)
    {
        line = readline(">");
        if(!ft_strncmp(line,delimeter,ft_strlen(line)))
            return 0;
        if(!mode)
            expand_line(&line);
        write(fd, line,ft_strlen(line));
        write(fd, "\n",1);
    }
}

int here_doc(char *str)
{
    int mode;
    int fd;

    mode = get_delimeter(str);
    //printf("%d -> %s\n", mode, str);
    if(mode == -1)
    {
        printf("Error : Multiline\n");
        return (mode);
    }
    fd = open("test", O_TMPFILE | O_WRONLY, 0777);
    input_to_file(fd, str, mode);
}