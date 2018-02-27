juego : command.o game.o game_loop.o graphic_engine.o screen.o space.o object.o player.o gamereader.o set.o
	gcc -o juego command.o game.o game_loop.o graphic_engine.o screen.o space.o object.o player.o gamereader.o set.o
command.o: command.c command.h
	gcc -c command.c
game.o:  game.c game.h player.c object.c
	gcc -c game.c
game_loop.o: game_loop.c graphic_engine.h
	gcc -c game_loop.c
graphic_engine.o: graphic_engine.c screen.h graphic_engine.h
	gcc -c graphic_engine.c
screen.o: screen.c screen.h
	gcc -c screen.c
space.o: space.c space.h
	gcc -c space.c
object.o: object.c object.h
	gcc -c object.c
player.o: player.c player.h
	gcc -c player.c
gamereader.o: gamereader.c gamereader.h
	gcc -c gamereader.c
set.o: set.c set.h
	gcc -c set.c




clean:
	rm -rf *.o oca
