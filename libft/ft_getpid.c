/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:17:43 by bmota-si          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:43 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	get_number_from_line(char *line)
{
	int	i;
	int	number;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	number = ft_atoi(&line[i]);
	return (number);
}

int	ft_getpid(void)
{
	int		fd;
	char	*line;
	int		pid;

	fd = open("/proc/self/status", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line && ft_strncmp(line, "Pid:", 4))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		close(fd);
		return (-1);
	}
	pid = get_number_from_line(line);
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (pid);
}
