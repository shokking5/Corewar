#include "corewar.h"

void	live(t_carriage *carriage, t_corewar *core)
{
	int player_id;
	t_carriage *founded;

	player_id = read_arg_value(core, carriage, 0);
	core->lives_num++;
	carriage->lastlive = core->cycles;
	founded = NULL;
	if (player_id <= -1 && player_id >= -((int) core->players_num))
	{
		founded = find_carriage_by_id(core, ft_abs(player_id) - 1);
		founded->lastlive = core->cycles;
		founded->player->current_lives++;
		core->last_alive = founded->player;
	}
	if (core->flags->verbosity & V_OPERATIONS)
		ft_printf("P %4d | live %d\n", carriage->id, player_id);
	if (core->flags->verbosity & V_LIVES && founded)
		ft_printf("Player %d (%s) is said to be alive\n", player_id,
				  carriage->player->header->name);
}