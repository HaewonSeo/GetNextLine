/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:31:25 by haseo             #+#    #+#             */
/*   Updated: 2021/02/02 16:00:14 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		nl_in_backup(const char *backup)
{
	int		i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void		split_backup(char **backup, char **line, int idx_nl)
{
	char *tmp;

	(*backup)[idx_nl] = '\0';							// split the backup
	*line = ft_strdup(*backup);							// get a line
	tmp = ft_strdup(&(*backup)[idx_nl + 1]);
	free(*backup);
	*backup = tmp;
}

static int		 split_remainder(char **backup, char **line)
{
	int idx_nl;

	if(!(*backup))
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((idx_nl = nl_in_backup(*backup)) >= 0)
	{
		split_backup(backup, line, idx_nl);
		return (1);
	}
	*line = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char 	*backup[OPEN_MAX];
	ssize_t			read_size;
	int				idx_nl;

	if ((fd < 0) || (fd > OPEN_MAX) || (!line) || (BUFFER_SIZE < 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';				//BUFFER_SIZE를 초과하는 값을 담지 않기 위함.
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((idx_nl = nl_in_backup(backup[fd])) >= 0)
		{
			split_backup(&backup[fd], line, idx_nl);
			return (1);
		}
	}
	return(split_remainder(&backup[fd], line));
}
