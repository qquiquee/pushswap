#include "libft.h"

static int	ft_nbytes(ssize_t *nbytes, char **getline)
{
	if (*nbytes < 0)
	{
		if (*getline != NULL)
		{
			free(*getline);
			*getline = NULL;
		}
		return (-1);
	}
	return (0);
}

static int	ft_line_strdup(char **line)
{
	*line = ft_strdup("");
	return (0);
}

static int	ft_gnl_n(ssize_t ret, char **getline, char **line)
{
	char		*tmp;
	char		*tmp2;

	if (ft_nbytes(&ret, getline))
		return (-1);
	if (!ret && !*getline)
		return (ft_line_strdup(line));
	tmp = ft_strchr(*getline, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*getline);
		tmp2 = ft_strdup(tmp + 1);
		free(*getline);
		*getline = tmp2;
		return (1);
	}
	if (ft_strchr(*getline, '\0'))
	{
		*line = ft_strdup(*getline);
		free(*getline);
		*getline = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	static char	*getline[4096];
	char		*buffer;

	ret = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0
		|| !buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!getline[fd])
			getline[fd] = ft_strdup(buffer);
		else
			getline[fd] = ft_strjoin(getline[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	buffer = NULL;
	return (ft_gnl_n(ret, &getline[fd], &*line));
}
