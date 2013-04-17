#include "Creature.h"
#include "Player.h"

void Player::move(HysVec2f diff_pos)
{
	Creature::move(diff_pos);

	//camera follow player.
	//TODO: redefine HysVec2f operator = !
	GameEngine::get_instance()->camera.pos = pos;
}