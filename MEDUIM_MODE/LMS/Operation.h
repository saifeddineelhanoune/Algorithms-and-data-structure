/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 04:33:16 by sel-hano          #+#    #+#             */
/*   Updated: 2023/08/19 06:00:17 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
#define OPERATION_H

#include <libc.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct s_personal_details
{
	char *full_name;
	int	age;
	int identity;
	bool is_available;
	
}t_personal_details;

typedef struct s_student
{
	t_personal_details *details;
	int		final_mark;
	int		rank;
	int		attendance;
	struct s_student *next;
}t_student;

#endif