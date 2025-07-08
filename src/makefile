UNAME = $(shell uname)

OBJS = main.o ReadWriteFile.o Simulation.o MyGlut.o Time/Timer.o Time/TimerClass.o Actors/Actor.o Actors/World.o Objects/ComponentObject.o Objects/RenderObject.o Managers/RenderManager.o Managers/ComponentManager.o Objects/WorldRenderObject.o Actors/Objects.o Objects/ObjectRenderObject.o Objects/ObjectComponentObject.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pthread
LFLAGS = -Wall $(DEBUG) -lm

SOURCES = main.cpp Simulation.cpp ReadWriteFile.cpp MyGlut.cpp Time/Timer.cpp Time/TimerClass.cpp Actors/Actor.cpp Actors/World.cpp Objects/ComponentObject.cpp Objects/RenderObject.cpp Managers/RenderManager.cpp Managers/ComponentManager.cpp Objects/WorldRenderObject.cpp  Actors/Objects.cpp Objects/ObjectRenderObject.cpp Objects/ObjectComponentObject.cpp

HEADERS = Simulation.h ReadWriteFile.h MyGlut.h Time/Timer.h Time/TimerClass.h Actors/Actor.h Actors/World.h Objects/ComponentObject.h Objects/RenderObject.h Managers/RenderManager.h Managers/ComponentManager.h Objects/WorldRenderObject.h Actors/Objects.h Objects/ObjectRenderObject.h Objects/ObjectComponentObject.h

# OS X Does things a bit different
ifeq ($(UNAME), Darwin)
	LFLAGS += -framework GLUT -framework OpenGL
else
	LFLAGS += -lglut -lGL -lGLU 
endif

all: gorobot

gorobot: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o gorobot

main.o : main.cpp Simulation.cpp
	$(CC) $(CFLAGS)  main.cpp -o main.o

Simulation.o : Simulation.cpp
	$(CC) $(CFLAGS) Simulation.cpp -o Simulation.o

ReadWriteFile.o : ReadWriteFile.cpp
	$(CC) $(CFLAGS) ReadWriteFile.cpp -o ReadWriteFile.o

MyGlut.o : MyGlut.cpp
	$(CC) $(CFLAGS) MyGlut.cpp -o MyGlut.o

Timer.o : Time/Timer.cpp
	$(CC) $(CFLAGS) Time/Timer.cpp -o Time/Timer.o

TimerClass.o : Time/TimerClass.cpp
	$(CC) $(CFLAGS) Time/TimerClass.cpp -o Time/TimerClass.o

Actor.o : Actors/Actor.cpp Objects/RenderObject.cpp
	$(CC) $(CFLAGS) Actors/Actor.cpp -o Actors/Actor.o

World.o : Actors/World.cpp Actors/Actors.cpp Objects/WorldRenderObject.cpp Managers/RenderManager.cpp
	$(CC) $(CFLAGS) Actors/World.cpp -o Actors/World.o

ComponentObject.o : Objects/ComponentObject.cpp
	$(CC) $(CFLAGS) ComponentObject.cpp -o ComponentObject.o

RenderObject.o : Objects/RenderObject.cpp
	$(CC) $(CFLAGS) Objects/RenderObject.cpp -o Objects/RenderObject.o

RenderManager.o : Managers/RenderManager.cpp
	$(CC) $(CFLAGS) Managers/RenderManager.cpp -o Managers/RenderManager.o

ComponentManager.o : Managers/ComponentManager.cpp
	$(CC) $(CFLAGS) ComponentManager.cpp -o ComponentManager.o

WorldRenderObject.o : Objects/WorldRenderObject.cpp main.cpp
	$(CC) $(CFLAGS) Objects/WorldRenderObject.cpp -o Objects/WorldRenderObject.o

Objects.o : Actors/Objects.cpp
	$(CC) $(CFLAGS) Objects.cpp -o Objects.o

ObjectRenderObject.o : Objects/ObjectRenderObject.cpp
	$(CC) $(CFLAGS) ObjectRenderObject.cpp -o ObjectRenderObject.o

ObjectComponentObject.o : Objects/ObjectComponentObject.cpp
	$(CC) $(CFLAGS) ObjectComponentObject.cpp -o ObjectComponentObject.o

clean: 
	\rm -f $(OBJS) gorobot Project.tar *.o

rebuild:
	clear
	make clean
	make	

tar:
	tar cfv Project.tar makefile $(HEADERS) $(SOURCES)

