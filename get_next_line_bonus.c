/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:43:43 by deordone          #+#    #+#             */
/*   Updated: 2024/09/24 19:32:04 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstclear(t_gnl_list **lst)
{
	t_gnl_list	*lastnod;
	int			i;
	int			k;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_del(lst));
	lastnod = ft_lastnode(lst);
	i = 0;
	k = 0;
	while (lastnod->content[i] != '\0' && lastnod->content[i] != '\n')
		++i;
	while (lastnod->content[i] != '\0' && lastnod->content[++i])
		buf[k++] = lastnod->content[i];
	buf[k] = '\0';
	ft_del(lst);
	ft_attach(lst, buf);
}

void	ft_attach(t_gnl_list **lst, char *buf)
{
	t_gnl_list	*new_node;
	t_gnl_list	*lastnod;

	if (!buf[0])
		return (free(buf));
	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
	{
		free(buf);
		return (ft_del(lst));
	}
	lastnod = ft_lastnode(lst);
	if (!lastnod)
		*lst = new_node;
	else
		lastnod->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

char	*ft_newline(t_gnl_list **lst, char *line, int l_line)
{
	t_gnl_list	*temp;
	int			displacer;

	temp = *lst;
	displacer = 0;
	l_line += ft_contsize(temp);
	line = (char *)malloc(sizeof(char) * (l_line + 1));
	if (!line)
	{
		ft_del(lst);
		return (NULL);
	}
	displacer = ft_cpylst(temp, line, displacer);
	line[l_line] = '\0';
	return (line);
}

void	ft_lstnew(t_gnl_list **lst, int fd)
{
	int		char_read;
	char	*buf;

	char_read = 0;
	while (!found_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return (ft_del(lst));
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
	static t_gnl_list	*lst[FOPEN_MAX];
	char				*line;
	int					l_line;

	line = NULL;
	l_line = 0;
	if (read(fd, &line, 0) < 0)
	{
		ft_del(&lst[fd]);
		return (NULL);
	}
	if (fd < 0 || fd > FOPEN_MAX - 1 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_lstnew(&lst[fd], fd);
	if (lst[fd] == NULL)
		return (NULL);
	line = ft_newline(&lst[fd], line, l_line);
	if (lst[fd] == NULL)
		return (NULL);
	ft_lstclear(&lst[fd]);
	return (line);
}

// t_gnl_list** <- todas las funciones que quieras modificar o
// controlar la lista tiene que tener este doble puntero
// 1 -> crea la lista
// 2 -> obtiene la line a de la lista
// 3 -> limpia la lista y obtiene el cachito
// 4 -> limpiar la lista
// 5 -> meter un nodo
// 6 -> fijarte si en los nodos hay un \n
// 7 -> cuenta hasta el \n
//
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
	int		fd;
	char	*putito;

	fd = open("test.txt", O_RDONLY);
	putito = get_next_line(fd);
	while (putito)
	{
		printf("%s", putito);
		free(putito);
		putito = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
