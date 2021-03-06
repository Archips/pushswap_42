/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:31 by athirion          #+#    #+#             */
/*   Updated: 2022/04/14 14:20:33 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Set the Stack Elements IDs.
 ** Return the Stack len.
 */

int	ft_set_ids(t_lst *stack)
{
	int		i;
	t_lst	*temp;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp && temp->next)
	{
		temp->id = i++;
		temp = temp->next;
	}
	temp->id = i;
	return (i + 1);
}
