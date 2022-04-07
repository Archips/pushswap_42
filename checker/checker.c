/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:46:40 by athirion          #+#    #+#             */
/*   Updated: 2022/04/07 09:39:41 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_init_stacks(t_data *data)
{
	int	i;
	int	*tab_ptr;

	data->stack_b = ft_listnew(0);
	tab_ptr = data->tab;
	data->stack_a = ft_listnew(*(data)->tab++);
	i = 0;
	while (i++ < (int)data->tab_size - 1)
		ft_listadd_back(&data->stack_a, ft_listnew(*(data)->tab++));
	data->tab = tab_ptr;
	data->oplist = ft_char_listnew("init");
}

void	ft_get_operations(t_data *data, char *op)
{
	if ft_strncmp(op, "sa\n", 3) == 0)
		ft_swap(data->stack_a, NULL, NULL);
	else if ft_strncmp(op, "sb\n", 3) == 0)
		ft_swap(data->stack_b, NULL, NULL);	
	else if ft_strncmp(op, "ss\n", 3) == 0)
		ft_ss(data->stack_a, data->stack_b, NULL);
	else if ft_strncmp(op, "pa\n", 3) == 0)
		ft_push(data->stack_a, data->stack_b, NULL, NULL);
	else if ft_strncmp(op, "pb\n", 3) == 0)
		ft_push(data->stack_b, data->stack_a, NULL, NULL);
	else if ft_strncmp(op, "ra\n", 3) == 0)
		ft_rotate(data->stack_a, NULL, NULL);
	else if ft_strncmp(op, "rb\n", 3) == 0)
		ft_rotate(data->stack_b, NULL, NULL);
	else if ft_strncmp(op, "rr\n", 3) == 0)
		ft_rr(data->stack_a, data->stack_b, NULL, NULL);
	else if ft_strncmp(op, "rra\n", 4) == 0)
		ft_reverse_rotate(data->stack_a, NULL, NULL);
	else if ft_strncmp(op, "rrb\n", 4) == 0)
		ft_reverse_rotate(data->stack_b, NULL, NULL);
	else if ft_strncmp(op, "rrr\n", 4) == 0)
		ft_reverse_rotate(data->stack_a, data->stack_b, NULL, NULL);
	else
		exit(EXIT_FAILURE); //TO DO
}

void	ft_read_operation(t_data *data)
{
	char *op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			exit(EXIT_FAILURE); //TO DO
		ft_get_operations(data, op);
		free(op);
	}
	if (ft_listissort(data->stack_a) && ft_set_ids(data->stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	ft_putstr_fd("KO\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_parser(&data, ac, av);
		if (!data.tab)
			return (ft_putstr_fd("Error\n", 2), 1);
		ft_init_stacks(&data);
		if (!ft_listissort(data.stack_a))
			ft_read_operations(&data);
		ft_listclear(&data.stack_a, free);
		ft_listclear(&data.stack_b, free);
		ft_free(data.tab);
	}
	return (0);
}	
