/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:26:47 by lclerc            #+#    #+#             */
/*   Updated: 2023/03/17 10:29:00 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The get_next_line() let a text file be read by the file descriptor (standard
 * input and file), one line at a time in a loop.
 * 
 * The function returns the line that was read, unless there is nothing else to
 * read or if an error occur, in which case NULL is returned.
 * 
 * Returned line should include '\n' except if the end of file was reached and
 * does not end with a '\n'.
 *
 * External functions allowed: read, malloc, free.
 *
 * All helper functions must be included into get_next_line_utils.c
 *
 * Static variables are recommended to be used.
 *
 * Compiler call must use '-D BUFFER_SIZE=n' in order to define the buffer size
 * for read(). The project must be able to compile with and without '-D
 * BUFFER_SIZE' option with a default value of your choice.
 *
 * Example: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c 
 * 
 * BUFFER_SIZE is defined in get_next_line.h. If the -D flag is used at compile
 * time, it will override this value.
 *
 * The read() returns the number of bytes read and placed in the buffer. '0' is
 * returned when EOF is reached and '-1' in case of error.
 *
 * Undefined behaviours happen:
 * 	- if the file pointed to by fd changed since the last call whereas read()
 * 	didnt reach EOF.
 *	- if reading a binary file. 
 *
 * From man getline(3), an entire line is read from stream, storing the address
 * of the buffer containing the text into a *line_pointer. The buffer is
 * null-terminated and includes the newline character if present.
 *
 * LIMITATIONS:
 * BUF_SIZE must be at least 1.
 * fd is limited to 1024 (or as defined by FD_SETIZE) else it will result in
 * undefined behaviour.
 */

#include "get_next_line.h"

static char	*malloc_and_null_me(int size, int zeroed)
{
	char	*new_string;

	new_string = (char *)malloc(size * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[zeroed] = '\0';
	return (new_string);
}

/*
 * stash_remain() is backing up the part of the buffer after the new line has
 * been extracted. 
 *
 * If there is no new line, it is consequently the last string in the file. The 
 * updated_buffer is freed and NULL is returned.
 */

static char	*stash_remain(char *line_buffer)
{
	char	*updated_buffer;
	size_t	buffer_len;
	int		i;

	i = 0;
	buffer_len = gnl_ft_strlen(line_buffer);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
	{
		free(line_buffer);
		return (NULL);
	}
	updated_buffer = malloc_and_null_me(buffer_len - i + 2, buffer_len - i);
	if (!updated_buffer)
		return (NULL);
	updated_buffer[buffer_len - i + 1] = '\0';
	gnl_ft_strlcpy(updated_buffer, line_buffer + i + 1, buffer_len - i + 1);
	free(line_buffer);
	return (updated_buffer);
}

/*
 * extract_line() is copying the first string in the line buffer to new_line
 */

static char	*extract_line(char *line_buffer)
{
	char	*new_line;
	size_t	buffer_len;
	size_t	i;

	i = 0;
	if (!line_buffer)
		return (NULL);
	buffer_len = gnl_ft_strlen(line_buffer);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	new_line = malloc_and_null_me(i + 1, i);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
	{
		new_line[i] = line_buffer[i];
		i++;
	}
	if (line_buffer[i] && line_buffer[i] == '\n')
		new_line[i++] = '\n';
	return (new_line);
}

static char	*read_line(int fd, char *line_buffer, int read_bytes, size_t s2_len)
{
	char		*buffer;
	char		*temp;

	if (!line_buffer)
		line_buffer = malloc_and_null_me(1, 0);
	buffer = malloc_and_null_me(BUFFER_SIZE + 1, BUFFER_SIZE);
	if (!buffer || !line_buffer)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		temp = gnl_ft_strjoin(line_buffer, buffer, s2_len);
		if (!temp)
			return (NULL);
		free(line_buffer);
		line_buffer = temp;
		if (gnl_ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line_buffer);
}

char	*get_next_line(int fd)
{
	static char	*line_buffer[OPEN_MAX];
	char		*new_line;
	int			read_bytes;
	size_t		s2_len;

	s2_len = 0;
	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line_buffer[fd] = read_line(fd, line_buffer[fd], read_bytes, s2_len);
	if (!line_buffer[fd])
		return (NULL);
	new_line = extract_line(line_buffer[fd]);
	line_buffer[fd] = stash_remain(line_buffer[fd]);
	return (new_line);
}
