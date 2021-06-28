/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:27:14 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 20:33:29 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct		s_fd
{
	int				fd;
	char			*backup;
	size_t			backup_size;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(int fd, char **line);
int					read_fd(t_fd *save, char **line);
int					buf_to_backup(t_fd *save,
					char *new_buffer, size_t buf_size);
int					to_line(char **line, t_fd *save);
int					if_eof(char **line, t_fd *save);
t_fd				*find_fd(t_fd **start, int fd);
void				del_fd(t_fd **head, t_fd *save);
void				del_all_fd(t_fd **head);
char				*ft_strdup_size(char *arr, size_t size);

#endif
