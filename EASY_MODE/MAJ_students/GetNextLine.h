#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	*_search(char *s, char c);

size_t	_strlen(char *str);

char	*_file_reader(int fd, char *str);

char	*_line_reader(char *str);

char	*get_next_line(int fd);

char	*_join(char *str, char *buff);

char	*_rest(char *str);

char *_ncopy(char *dest,char *src, size_t n);

char *_duplicate(char *s);

typedef struct s_get_line
{
    char *line;
    char *newline;
    size_t len;
} t_get_line;

typedef struct s_join
{
    char	*new_str;
	int		size1;
	int		size2;
	int		size;
} t_join;

#endif