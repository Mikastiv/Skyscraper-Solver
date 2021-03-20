/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:37:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/20 19:46:28 by mleblanc         ###   ########.fr       */
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

void	ft_print_array(int array[][N], int is_result)
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
			printf("%d ", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_init_result_array(int array[][N])
{
	int i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			array[i][j] = 0;
			j++;
		}
		i++;	
	}
}

int	ft_dup_in_col(int result[][N], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (result[j][col] != 0 && result[i][col] != 0)
			{
				if (result[i][col] == result[j][col])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_colup_valid(int result[][N], int col_height, int col)
{
	int	box_count;
	int visible_boxes;
	int height;
	int i;

	box_count = 0;
	i = 0;
	visible_boxes = 0;
	height = 0;
	if (ft_dup_in_col(result, col))
		return (0);
	while (i < N)
	{
		if (result[i][col] > height)
		{
			height = result[i][col];
			visible_boxes++;
		}
		if (result[i][col] != 0)
			box_count++;
		i++;
	}
	if (box_count == N && visible_boxes != col_height)
		return (0);
	if (box_count < N && visible_boxes > col_height)
		return (0);
	return (1);
}

int	ft_is_coldown_valid(int result[][N], int col_height, int col)
{
	int	box_count;
	int visible_boxes;
	int height;
	int i;

	box_count = 0;
	i = N - 1;
	visible_boxes = 0;
	height = 0;
	while (i >= 0)
	{
		if (result[i][col] > height)
		{
			height = result[i][col];
			visible_boxes++;
		}
		if (result[i][col] != 0)
			box_count++;
		i--;
	}
	if (box_count == N && visible_boxes != col_height)
		return (0);
	if (box_count < N && visible_boxes > col_height)
		return (0);
	return (1);
}

int	ft_dup_in_row(int result[][N], int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (result[row][i] != 0 && result[row][j] != 0)
			{
				if (result[row][i] == result[row][j])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_rowleft_valid(int result[][N], int clue, int row)
{
	int	box_count;
	int visible_boxes;
	int height;
	int j;

	box_count = 0;
	j = 0;
	visible_boxes = 0;
	height = 0;
	if (ft_dup_in_row(result, row))
		return (0);
	while (j < N)
	{
		if (result[row][j] > height)
		{
			height = result[row][j];
			visible_boxes++;
		}
		if (result[row][j] != 0)
			box_count++;
		j++;
	}
	if (box_count == N && visible_boxes != clue)
		return (0);
	if (box_count < N && visible_boxes > clue)
		return (0);
	return (1);
}

int	ft_is_rowright_valid(int result[][N], int clue, int row)
{
	int	box_count;
	int visible_boxes;
	int height;
	int j;

	box_count = 0;
	j = N - 1;
	visible_boxes = 0;
	height = 0;
	while (j >= 0)
	{
		if (result[row][j] > height)
		{
			height = result[row][j];
			visible_boxes++;
		}
		if (result[row][j] != 0)
			box_count++;
		j--;
	}
	if (box_count == N && visible_boxes != clue)
		return (0);
	if (box_count < N && visible_boxes > clue)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	viewers[4][N];
	int res[N][N];

	if (argc != 2 || !ft_input_is_valid(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_parse_input(viewers, argv[1]);
	ft_print_array(viewers, 0);
	ft_init_result_array(res);

	res[0][0] = 3;
	res[0][1] = 2;
	res[0][2] = 1;
	res[0][3] = 4;
	ft_print_array(res, 1);

	int clue = 4;
	int row = 0;
	printf("Duplicate?: %d\n", ft_dup_in_row(res, row));
	printf("Valid?: %d\n", ft_is_rowright_valid(res, clue, 0));
}
