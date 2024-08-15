/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_console_one_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:32:46 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 12:32:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_print_pawn_info(int index, t_pawn_movement *pawn)
{
	ft_printf("Pawn %d Initial Position (%d, %d) \
		Target [%d, %d] in %s Direction with %u Steps.\n", index, \
		pawn->initial_position.x, \
		pawn->initial_position.y, \
		pawn->target_position.x, \
		pawn->target_position.y, \
		pawn->direction, \
		pawn->steps_need);
}
