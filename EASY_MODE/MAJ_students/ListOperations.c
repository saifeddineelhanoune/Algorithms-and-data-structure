/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListOperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:29:00 by sel-hano          #+#    #+#             */
/*   Updated: 2023/08/19 22:50:04 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Students.h"

int	ListSize(t_StudentsInfo *info)
{
	int i = 0;
	while (info)
	{
		i++;
		info = info->next;
	}
	return i;
}