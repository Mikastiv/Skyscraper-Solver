/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:37:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/20 11:00:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define N 4

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_valid_num(char c)
{
	if (c >= '1' && c < '1' + N)
		return (1);
	else
		return (0);
}

int	ft_input_is_valid(char *input)
{
	int	count;
	int	prev_is_num;

	prev_is_num = 0;
	count = 0;
	while (*input != '\0' && count != 4 * N)
	{
		if (!prev_is_num && ft_is_valid_num(*input))
			count++;
		else if (prev_is_num && ft_is_space(*input))
		{
		}
		else
			return (0);
		prev_is_num = !prev_is_num;
		input++;
	}
	if (count == 4 * N && *input == '\0')
		return (1);
	return (0);
}

void	ft_parse_input(int viewers[4][N], char *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (*input != '\0' && j < N)
		{
			if (*input != ' ')
			{
				viewers[i][j] = *input - '0';
				j++;
			}
			input++;
		}
		i++;
	}
}

void	ft_print_array(int viewers[4][N])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < N)
		{
			printf("%d ", viewers[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	viewers[4][N];

	if (argc != 2 || !ft_input_is_valid(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_parse_input(viewers, argv[1]);
	ft_print_array(viewers);
}
