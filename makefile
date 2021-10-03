prog:save.o background.o hero.o input.o menu.o rotozoom.o game.o button.o enemy.o entity.o aEnigmes.o jEnigme.o Enigmes.o Enigme.o main.o
	gcc save.o background.o hero.o input.o menu.o rotozoom.o game.o button.o enemy.o entity.o aEnigmes.o jEnigme.o Enigmes.o Enigme.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx
main.o:main.c
	gcc -c main.c
save.o:save.c
	gcc -c save.c
background.o:background.c
	gcc -c background.c
hero.o:hero.c
	gcc -c hero.c
input.o:input.c
	gcc -c input.c
menu.o:menu.c
	gcc -c menu.c
button.o:button.c
	gcc -c button.c
game.o:game.c
	gcc -c game.c
rotozoom.o:rotozoom.c
	gcc -c rotozoom.c
entity.o:entity.c
	gcc -c entity.c
enemy.o:enemy.c
	gcc -c enemy.c
aEnigmes.o:aEnigmes.c
	gcc -c aEnigmes.c
jEnigme.o:jEnigme.c
	gcc -c jEnigme.c
Enigmes.o:Enigmes.c
	gcc -c Enigmes.c
Enigme.o:Enigme.c
	gcc -c Enigme.c
