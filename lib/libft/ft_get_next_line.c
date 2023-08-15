/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:32:05 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 10:44:15 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*new_backup(char *backup)
{
	char	*line;
	size_t	len;

	len = 0;
	while (backup[len] && backup[len] != '\n')
		len++;
	if (!backup[len])
	{
		free (backup);
		backup = NULL;
		return (NULL);
	}
	line = (char *) malloc((ft_strlen(backup) - len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup + (len + 1), ft_strlen(backup) - len + 1);
	free(backup);
	backup = NULL;
	return (line);
}

static	char	*get_line(char *backup)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!backup[len])
		return (NULL);
	while (backup[len] && backup[len] != '\n')
		len++;
	line = (char *) malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, len + 2);
	return (line);
}

static	char	*read_file(int fd, char *backup, char **buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(backup, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*buffer);
			*buffer = NULL;
			free(backup);
			return (NULL);
		}
		(*buffer)[bytes_read] = '\0';
		tmp = backup;
		backup = ft_strjoin(tmp, *buffer);
		free(tmp);
		tmp = NULL;
	}
	free(*buffer);
	*buffer = NULL;
	return (backup);
}

char	*gnl(int fd)
{
	static char	*backup = NULL;
	char		*line_return;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	backup = read_file(fd, backup, &buffer);
	if (!backup)
		return (NULL);
	line_return = get_line(backup);
	backup = new_backup(backup);
	return (line_return);
}
