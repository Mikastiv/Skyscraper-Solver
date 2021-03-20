/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:37:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/20 16:42:16 by sleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 4
#include <unistd.h>
#include <stdio.h>
#include "input_validation.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_2d_to_1d(int row, int col)
{	
	return (row * N + col);
}

void	ft_print_array(int array[], int is_result)
{
	int i;
	int j;
	int k;

	i = 0;
	if (is_result)
		k = N;
	else
		k = 4;		
	while (i < k)
	{
		j = 0;
		while (j < N)
		{
			printf("%d ", array[ft_2d_to_1d(i, j)]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_init_result_array(int array[])
{
	int index;

	index = 0;
	while (index < N * N)
	{
		array[index] = 0;
		index++;	
	}
}

int	ft_firstrow_index(int index)
{
	while (index > N)
	{
		index -= N;
	}
	return (index);
}

int	ft_is_calup_valid(int result[], int col_height, int index, int num)
{
	int	box_count;
	int count;
	int height;
	int i;

	box_count = 0;
	i = ft_firstrow_index(index);
	count = 0;
	height = 0;
	while (i < index)
	{
		if (num == result[i])
			return (0);
		if (result[i] > height)
		{
			height = result[i];
			count++;
		}
		i += N;
		box_count++;
	}
	if (count == col_height && num > height)
		return (0);
	if (num < height && box_count == N - 1)
		return (0);
	return (1);
}


int	main(int argc, char *argv[])
{
	int	viewers[4 * N];
	int res[N * N];

	if (argc != 2 || !ft_input_is_valid(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_parse_input(viewers, argv[1]);
	ft_print_array(viewers, 0);
	ft_init_result_array(res);
	ft_print_array(res, 1);
}
