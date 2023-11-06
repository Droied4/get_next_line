/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:42:24 by deordone          #+#    #+#             */
/*   Updated: 2023/11/06 18:39:34 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*lastnod;
	t_list	*cleanod;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	cleanod = malloc(sizeof(t_list));
	if (NULL == cleanod || NULL == buf)
	{
		ft_lastnode(*lst, 1);
		lst = NULL;
		free(buf);
		return ;
	}
	lastnod = ft_lastnode(*lst, 2);
	i = 0;
	k = 0;
	while (lastnod->content[i] != '\0' && lastnod->content[i] != '\n')
		++i;
	while (lastnod->content[i] != '\0' && lastnod->content[++i])
		buf[k++] = lastnod->content[i];
	buf[k] = '\0';
	cleanod->content = buf;
	cleanod->next = NULL;
	ft_del(lst, cleanod, buf);
}

void	ft_attach(t_list **lst, char *buf)
{
	t_list	*new_node;
	t_list	*lastnod;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	lastnod = ft_lastnode(*lst, 2);
	if (!lastnod)
		*lst = new_node;
	else
		lastnod->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

char	*ft_newline(t_list **lst, char *line, int l_line)
{
	t_list	*temp;
	int		displacer;

	temp = *lst;
	displacer = 0;
	l_line += ft_contsize(temp);
	line = malloc(1 * (l_line + 1));
	if (!line)
		return (NULL);
	temp = *lst;
	while (temp->next != NULL)
	{
		displacer = ft_cpylst(temp, line, displacer);
		temp = temp->next;
	}
	displacer = ft_cpylst(temp, line, displacer);
	line[l_line] = '\0';
	return (line);
}

void	ft_lstnew(t_list **lst, int fd)
{
	int		char_read;
	char	*buf;

	char_read = 0;
	while (!found_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_attach(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	int				l_line;

	line = NULL;
	l_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		ft_lastnode(lst, 1);
		lst = NULL;
		return (NULL);
	}
	ft_lstnew(&lst, fd);
	if (lst == NULL)
	{
		ft_lastnode(lst, 1);
		lst = NULL;
		return (NULL);
	}
	line = ft_newline(&lst, line, l_line);
	ft_lstclear(&lst);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*rslt;

	fd = open("file.txt", O_RDONLY);
	rslt = get_next_line(fd);
	printf("line -> %s", rslt);
	return (0);
}

int	main(void)
{
	int fd;
	char *putito;

	fd = open("file.txt", O_RDONLY);
	if (!fd)
		return (-1);
	int i = 0;
	while (i++ < 5)
	{
		(putito = get_next_line(fd));
		printf ("%s", putito);
		free(putito);
	}
	close(fd);
	return (0);
}*/
