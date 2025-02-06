/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:59:00 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/03 13:59:09 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(a) (a % 2 == 0)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG ("I have an even number of arguments.\n")
# define ODD_MSG ("I have an odd number of arguments.\n")
# define SUCCESS 0

typedef int	t_bool;

#endif
