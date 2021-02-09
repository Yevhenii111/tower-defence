LIBS = -lsfml-graphics -lsfml-window -lsfml-system
LIBS1 = -lgamedll
LDFLAGS = -L/KPI/prog2/SFML-2.5.1/lib
LDFLAGS1 = -L/KPI/prog2/tower_defence
CPPFLAGS = -I/KPI/prog2/SFML-2.5.1/include
main = obj/main.o
map = obj/map.o
way = obj/way.o
enemy = obj/enemy.o
menu = obj/menu.o
levels = obj/levels.o
data = obj/data.o
towers = obj/towers.o
healthbar = obj/healthbar.o
BG = obj/BG.o

all: dll main

dll: $(map) $(way) $(enemy) $(menu) $(levels) $(data) $(towers) $(healthbar) $(BG)
	g++ -shared -o gamedll.dll $(map) $(way) $(enemy) $(menu) $(levels) $(data) $(towers) $(healthbar) $(BG) $(LIBS) $(LDFLAGS)
	
main: $(main)
	g++ -o main.exe $(main) $(LIBS) $(LIBS1) $(LDFLAGS) $(LDFLAGS1)

$(main): main.cpp
	g++ -c main.cpp $(CPPFLAGS) -o $(main)
$(map): map.cpp
	g++ -c map.cpp $(CPPFLAGS) -o $(map)
$(way): way.cpp
	g++ -c way.cpp $(CPPFLAGS) -o $(way)
$(enemy): enemy.cpp
	g++ -c enemy.cpp $(CPPFLAGS) -o $(enemy)
$(menu): menu.cpp
	g++ -c menu.cpp $(CPPFLAGS) -o $(menu)
$(levels): levels.cpp
	g++ -c levels.cpp $(CPPFLAGS) -o $(levels)
$(data): data.cpp
	g++ -c data.cpp $(CPPFLAGS) -o $(data)
$(towers): towers.cpp
	g++ -c towers.cpp $(CPPFLAGS) -o $(towers)
$(healthbar): healthbar.cpp
	g++ -c healthbar.cpp $(CPPFLAGS) -o $(healthbar)
$(BG): BG.cpp
	g++ -c BG.cpp $(CPPFLAGS) -o $(BG)