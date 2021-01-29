/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:41:02 by acyrenna          #+#    #+#             */
/*   Updated: 2021/01/26 21:05:41 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	usage(void)
{
	ft_putendl(
	"Usage: /corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"
 	"-dump nbr_cycles\n"
  		"\tat the end of nbr_cycles of executions, dump the memory\n"
  		"\ton the standard output and quit the game. The memory will\n"
   		"\tbe dumped in the hexadecimal format with32 octets per line\n"
	"-n number\n"
 	"\tsets the number of the next player. If non-existent, the player\n"
   	"\twill have the next available number in the order of the parameters.\n"
	"\tThe last player will have the first process in the order\n"
  	"of execution.");
	exit(1);
}

int		main(int args, char **argv)
{
	t_corewar	*corewar;

	if (args < 2)
		usage();
	corewar = parse(args - 1, argv);
	init_game(corewar);
	print_field(corewar);

	t_player *p = corewar->players;
	t_carriage *c = corewar->carriages;
	for (int i = 0; i < corewar->players_num; i++)
	{
		ft_printf("Player %s: %d; Carriage 1: %d\n", p->header->name, p->id,
			c->id);
		p = p->next;
		c = c->next;
	}

	clean_corewar(corewar);
	return (0);
}
