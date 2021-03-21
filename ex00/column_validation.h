/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_validation.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:23:11 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 11:49:57 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLUMN_VALIDATION_H
# define COLUMN_VALIDATION_H
# include "config.h"

int	ft_dup_in_col(int result[][N], int col);
int	ft_is_colup_valid(int result[][N], int clues, int col);
int	ft_is_coldown_valid(int result[][N], int clues, int col);

#endif
