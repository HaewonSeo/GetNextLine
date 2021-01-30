/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:10:34 by haseo             #+#    #+#             */
/*   Updated: 2021/01/30 03:56:06 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	split_backup(char **backup, char **line, int idx_nl)
{
	char *tmp;

	(*backup)[idx_nl] = '\0';								// split the backup
	*line = ft_strdup(*backup);							// get a line
	tmp = ft_strdup(&(*backup)[idx_nl + 1]);
	free(*backup);
	*backup = NULL;
	*backup = tmp;
}

int		nl_in_backup(const char *backup)
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

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char 	*backup;
	ssize_t			read_size;
	int				idx_nl;

	if ((fd < 0) || (fd > OPEN_MAX) || (!line) || (BUFFER_SIZE < 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';				//BUFFER_SIZE를 초과하는 값을 담지 않기 위함.
		backup = ft_strjoin(backup, buf);
	}
	if ((idx_nl = nl_in_backup(backup)) >= 0)
	{
		split_backup(&backup, line, idx_nl);
		return (1);
	}
	else
	{
		*line = backup;
		return (0);
	}
}
