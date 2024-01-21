/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:46:10 by deordone          #+#    #+#             */
/*   Updated: 2024/01/21 14:20:52 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;
char					*get_next_line(int fd);
void					ft_attach(t_gnl_list **lst, char *buf);
char					*ft_newline(t_gnl_list **lst, char *line, int l_line);
void					ft_clear(t_gnl_list **lst);
void					ft_lstnew(t_gnl_list **lst, int fd);
t_gnl_list				*ft_lastnode(t_gnl_list **lst);
int						found_newline(t_gnl_list *lst);
int						ft_contsize(t_gnl_list *temp);
int						ft_cpylst(t_gnl_list *temp, char *line, int displacer);
void					ft_del(t_gnl_list **lst);

#endif
