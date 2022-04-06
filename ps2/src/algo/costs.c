#include "push_swap.h"

/*
 ** Find a distance
 **
 ** Find the distance between two nodes both stacks included.
 */

static int	ft_dist(int size, int id)
{
	int	dist;

	dist = 1;
	if (size % 2 == 0)
	{
		if (id > size / 2)
			dist = size - id + 1;
		else
			dist = id + 1;
	}
	else
	{
		if (id > size / 2)
			dist = size - id + 1;
		else if (id == size / 2)
			dist = size - id;
		else
			dist = id + 1;
	}
	return (dist);
}

/*
 ** Compare two nodes locations
 **
 ** Check if the two given nodes are located in the same part of
 ** their respective stack.
 */

static int	ft_comp(int id_a, int id_b, int size_a, int size_b)
{
	if ((id_a > size_a / 2 && id_b > size_b / 2)
		|| (id_a <= size_a / 2 && id_b <= size_b / 2))
		return (1);
	return (0);
}

/*
 ** Find a cost
 */

static int	ft_cost(int id_a, int id_b, int size_a, int size_b)
{
	int	cost;

	if (ft_comp(id_a, id_b, size_a, size_b))
	{
		if (ft_dist(size_a, id_a) > ft_dist(size_b, id_b))
			cost = ft_dist(size_a, id_a);
		else
			cost = ft_dist(size_b, id_b);
	}
	else
		cost = ft_dist(size_a, id_a) + ft_dist(size_b, id_b) - 1;
	return (cost);
}

/*
 ** Set Costs
 **
 ** Cost = distance to perform to put a stack_b element in the
 ** right location of the stack_a.
 */

void	ft_set_cost(t_data *data)
{
	t_lst	*temp_a;
	t_lst	*temp_b;

	temp_b = data->stack_b;
	while (temp_b)
	{
		temp_a = data->stack_a;
		while (temp_a)
		{
			if (temp_a->content == temp_b->senpai)
				temp_b->cost = ft_cost
					(temp_a->id, temp_b->id, data->size_a, data->size_b);
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}
