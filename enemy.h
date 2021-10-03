#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "entity.h"
#include "hero.h"

typedef enum STATE STATE;
enum STATE {RETURN, FOLLOWING};

typedef struct
{
    entity e;
    int frame,vitesse,max,min,blocked;
    char Edirection;
    STATE state;
    int positionini;
} Enemy;
typedef struct
{
    Enemy enemy[3];
    int nombre;
} Enemies;

Enemy init_enemy(int v,int x,int y);
void aff_enemies(Enemies *enemies);
void free_enemy(Enemies *enemies);
void Deplacer(Enemies *enemies);
void collision_ennemy(Enemies *enemies,Hero *hero);
void Animation_Enemy(Enemies *enemies);
void update_ennemy(Enemies *enemies, Hero *hero);
#endif 
