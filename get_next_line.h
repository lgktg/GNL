/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgelu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:29:04 by tgelu             #+#    #+#             */
/*   Updated: 2018/06/02 20:08:59 by piliegeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 1
# define SEP '\n'

# define MALCHK(x) if(x) return (-1);

int			get_next_line(const int fd, char **line);
#endif
