/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinxu <jinxu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:18:51 by jinxu             #+#    #+#             */
/*   Updated: 2025/02/03 14:19:03 by jinxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct Point
{
	int	x;
	int	y;
}	t_point;

#endif
/*
syntax typedef:
typedef existing_type new_type_name;

syntax struct:
struct struct_name 
{
data_type member1;
date_type member2;
....
};

!!!!!
if we use struct t_point{ ... }
we have to use 'struct t_point' to refer
to this structure type in main.

but for typedef struct{ ...} t_point,
t_point is an alias,
we can directly use alias in code.

*/
