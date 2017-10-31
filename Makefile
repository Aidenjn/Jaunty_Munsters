jaunty_munsters:

CC = g++
exe_file = jaunty_munsters
$(exe_file): game.o world.o creature.o demon.o balrog.o cyberDemon.o human.o elf.o cat.o driver.o
	$(CC) game.o world.o creature.o demon.o balrog.o cyberDemon.o human.o elf.o cat.o driver.o -o $(exe_file)
game.o: game.cpp
	$(CC) -c game.cpp
world.o: world.cpp
	$(CC) -c world.cpp
creature.o: creature.cpp
	$(CC) -c creature.cpp
demon.o: demon.cpp
	$(CC) -c demon.cpp
balrog.o: balrog.cpp
	$(CC) -c balrog.cpp
cyberDemon.o: cyberDemon.cpp
	$(CC) -c cyberDemon.cpp
human.o: human.cpp
	$(CC) -c human.cpp
elf.o: elf.cpp
	$(CC) -c elf.cpp
cat.o: cat.cpp
	$(CC) -c cat.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
