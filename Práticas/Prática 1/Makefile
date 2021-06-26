# Compila programas do curso de Computação Gráfica no ambiente Windows ou Linux


#INSERIR EM CAMINHO O CAMINHO DAS BIBLIOTECAS GLUT/FREEGLUT

CAMINHO = D:/ProgramFiles/CommonFiles/MinGW/glut
INCPATH = -I$(CAMINHO)/include
LIBPATH = -L$(CAMINHO)/lib
LIBS = -lglu32 -lopengl32 -lglut32
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets  
main: main.o desenha.o
	g++ main.o -o main desenha.o $(LFLAGS)
	./main
	rm main.o
	rm desenha.o
	rm main.exe

desenha.o:	desenha.c	desenha.h
	g++ -c desenha.c  $(CFLAGS)

# Source targets
main.o: main.c
	g++ -c main.c $(CFLAGS)