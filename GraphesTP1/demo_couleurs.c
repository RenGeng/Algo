#include <stdlib.h>
#include <stdio.h>
#include "graphaux.h"
#include "graphes.h"

#define USAGE "lit un graphe dans le fichier <filename> et genere une figure en PostScript dans <filename>.eps"

int main(int argc, char **argv)
{
  graphe *g;
  char buf[256];

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s <filename>\n%s\n", argv[0], USAGE);
    exit(0);
  }

  g = ReadGraphe(argv[1]);         /* lit le graphe a partir du fichier */
  PlongementCirculaire(g, 150);    /* plonge le graphe dans le plan */
  sprintf(buf, "%s.eps", argv[1]); /* construit le nom du fichier PostScript */
  EPSGraphe(g,                     /* genere une figure en PostScript */
	    buf, // nom fichier
	    10,  // rayon sommets
	    5,   // taille fleches
	    60,  // marge
	    1,   // noms sommets
	    0,   // valeurs sommets
	    1,   // couleurs sommets
	    0    // valeurs arcs
	    );

  TermineGraphe(g);

  return 0;
} /* main() */
