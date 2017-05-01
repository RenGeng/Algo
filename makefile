
# options de compilation
CC = gcc
CCFLAGS = -Wall 



# fichiers du projet
SRC = commun.c notre_algo.c algo_glouton.c dominantset.c
OBJ = $(SRC:.c=.o)
EXEC = dominantset


# règle initiale
all: $(EXEC)

# dépendance des .h
commun.o: commun.h
notre_algo.o: commun.h notre_algo.h
algo_glouton.o: commun.h algo_glouton.h
dominantset.o: commun.h notre_algo.h algo_glouton.h

# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS)

# règles supplémentaires
clean:
	rm -f *.o
rmproper:
	rm -f $(EXEC) *.o