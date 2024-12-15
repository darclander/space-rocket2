
OBJS = ./src/*.cpp

CC=g++

OPTIMIZATION= #-O3

STATIC= -static -static-libgcc -static-libstdc++ 

# https://www.reddit.com/r/gamedev/comments/5pl8vs/sdl2_staticlly_link/
LINKER_FLAGS= -static
LINKER_FLAGS += `pkg-config --libs --static SDL2`
LINKER_FLAGS += `pkg-config --libs --static SDL2_ttf`
LINKER_FLAGS += `pkg-config --libs --static SDL2_Image`
LINKER_FLAGS += `pkg-config --libs --static SDL2_Mixer`
LINKER_FLAGS += -lbrotlicommon -lsharpyuv


LIBS= -lmingw32 -lws2_32 -lSDL2main -lSDL2 -lSDL2_Image -lSDL2_TTF -lSDL2_Mixer
CFLAGS= -I$(IDIR) $(LIBS) $(EXTRA_LIBS) 

IDIR = ./src/headers
_DEPS = Game.hpp Gui.hpp Controller.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = ./obj
_OBJ = main.o Game.o Gui.o Controller.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: space-rocket

./obj/%.o: ./src/%.cpp $(DEPS)
	$(CC) -c $(OPTIMIZATION) -o $@ $< -I./src/headers

space-rocket: $(OBJ)
	$(CC) $(OPTIMIZATION) -o ./debug/$@ $^ $(CFLAGS) 

static: $(OBJ)
	$(CC) $(OPTIMIZATION) -o ./debug/$@ $^ $(CFLAGS) $(LINKER_FLAGS) -mconsole

run: space-rocket
	./debug/snake

clean: remove space-rocket

remove:
	./remove.py

