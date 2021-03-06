/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:15:39 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 16:24:28 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			round_address(int address)
{
	address %= MEM_SIZE;
	if (address < 0)
		address += MEM_SIZE;
	return (address);
}

int			need_idx_mod(int op_id)
{
	if (op_id == 13 || op_id == 14 || op_id == 15)
		return (0);
	return (1);
}

int			read_indirect(t_corewar *core, t_carriage *carriage, int shift,
					int manual_address)
{
	int	address;
	int	value;

	address = manual_address ? manual_address : read_int(core,
										carriage->pc + shift, IND_SIZE);
	address = need_idx_mod(carriage->op->id) ? address % IDX_MOD : address;
	value = read_int(core, carriage->pc + address, DIR_SIZE);
	return (value);
}

int			read_direct(t_corewar *core, t_carriage *carriage, int shift)
{
	return (read_int(core, carriage->pc + shift, carriage->op->dir_size));
}

int			read_arg_value(t_corewar *core, t_carriage *carriage, int arg_index)
{
	int	shift;

	shift = get_shift_to_arg(carriage, arg_index);
	if (carriage->types[arg_index] == T_IND)
		return (read_indirect(core, carriage, shift, 0));
	else if (carriage->types[arg_index] == T_DIR)
		return (read_direct(core, carriage, shift));
	else if (carriage->types[arg_index] == T_REG)
		return (read_byte(core, carriage, shift));
	return (0);
}
