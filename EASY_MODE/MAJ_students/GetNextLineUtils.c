/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetNextLineUtils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:14:59 by sel-hano          #+#    #+#             */
/*   Updated: 2023/08/20 02:06:46 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Students.h"

char	*_line_reader(char *all)
{
	t_get_line	gl;

	gl.newline = _search(all, '\n');
	if (gl.newline)
	{
		gl.len = gl.newline - all;
		gl.line = malloc(gl.len + 1);
		if (!gl.line)
			return (NULL);
		_ncopy(gl.line, all, gl.len);
	}
	else
	{
		gl.len = _strlen(all);
		gl.line = malloc(gl.len + 1);
		if (!gl.line)
			return (NULL);
		_ncopy(gl.line, all, gl.len + 1);
	}
	return (gl.line);
}

char	*_rest(char *s)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	rest = (char *)malloc(sizeof(char) * (_strlen(s) - i + 1));
	j = 0;
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = '\0';
	return (free(s), rest);
}

char	*_join(char *s1, char *s2)
{
	t_join	join;

	join.size1 = _strlen(s1);
	join.size2 = _strlen(s2);
	join.size = join.size1 + join.size2;
	if (!s1 && join.size2)
		s1 = _duplicate("");
	if (!s1 || !s2)
		return (NULL);
	join.new_str = malloc((join.size + 1));
	if (!join.new_str)
		return (NULL);
	_ncopy(join.new_str, s1, join.size1);
	_ncopy(join.new_str + join.size1, s2, join.size2);
	return (free(s1), join.new_str);
}

char	*_file_reader(int fd, char *stc_buffer)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(buffer), NULL);
		buffer[ret] = '\0';
		stc_buffer = _join(stc_buffer, buffer);
		if (_search(stc_buffer, '\n'))
			break ;
	}
	return (free(buffer), stc_buffer);
}

char	*get_next_line(int fd)
{
	static char	*reader;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = _file_reader(fd, reader);
	if (reader && !*reader)
	{
		free(reader);
		reader = NULL;
	}
	if (reader)
	{
		line = _line_reader(reader);
		reader = _rest(reader);
		return (line);
	}
	return (NULL);
}