# Compila programas do curso de OpenGL no ambiente Linux
# Substitua nome_do_programa pelo nome do programa ...
# ...que se está trabalhando
#
# Antes das linhas que contém "gcc...", não pode haver espaço em
# branco e sim uma marca de tabulação
#
# Prof. Marco Antonio
#       
# Variables
MESA = D:/ProgramFiles/CommonFiles/MinGW/freeglut
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS = -lglu32 -lopengl32 -lglut32
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets  
main: main.o
	g++ -o main main.o $(LFLAGS)
	./main

# Source targets
main.o: main.c
	g++ -c main.c $(CFLAGS)