parametrosCompilacao = -Wall -g -Wextra
nomePrograma = trab220231953
fontes = main.c ordenacao.c pilha.c
objetos = main.o ordenacao.o pilha.o

all: $(nomePrograma)

$(nomePrograma): $(objetos)
	gcc -o $(nomePrograma) $(objetos) $(parametrosCompilacao)

main.o: main.c ordenacao.h pilha.h
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.c ordenacao.h pilha.h
	gcc -c ordenacao.c $(parametrosCompilacao)

pilha.o: pilha.c pilha.h
	gcc -c pilha.c $(parametrosCompilacao)

clean:
	rm -f *.o $(nomePrograma)
