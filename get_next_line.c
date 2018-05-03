#include "get_next_line.h"

t_list         *ft_get_file(int fd, t_list *list)
{
    t_list      *current;

    current = list;
    while (current != NULL)
    {
        if (current->content_size == fd)
            return (current);
        current = current->next;
    }
    if (!(current = ft_lstnew("\0", fd)))
        return (NULL);
    return (current);
}

char	*ft_strjoinfree(char *s1, char *s2, int mask)
{
	char	*strjoin;

	if (!s1)
		return (NULL);
	strjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!strjoin)
		return (NULL);
	ft_strcpy(strjoin, s1);
	ft_strcat(strjoin, s2);
	if (mask == 1)
        free(s1);
    else if (mask == 2)
        free(s2);
    else if (mask == 3)
    {
        free(s1);
        free(s2);
    }
    return (strjoin);
}

int			get_next_line(const int fd, char **line)
{
    static t_list      *save;
    t_list             *current;
    char               buff[BUFF_SIZE + 1];
    int                len;
    int                i;
    
    if (fd < 0)
        return (-1);
    i = 0;
    if (!(current = ft_get_file(fd, save)))
        return (-1);
    if (ft_strchr(current->content, SEP) == NULL)
    {
        while ((len = read(current->content_size, buff, BUFF_SIZE)))
        {
            buff[BUFF_SIZE] = '\0';
            if (!(current->content = ft_strjoinfree(current->content, buff, 1)))
                return (-1);
            if (ft_strchr(current->content, SEP) != NULL)
                break ;
        }
    }
    while (((char *)current->content)[i] != '\n')
        i++;
    if (line && *line)
        free(*line);
    return ((len == 0) ? 0 : 1);
}