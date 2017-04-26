#include<stdio.h>
#include<stdlib.h>


// Définition à la main du graphe (voir le document word pour avoir une image)


#define TAILLE_MAX 6
int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 1

						{0,1,0,1,0,1},
						{1,0,1,0,1,0},
						{0,1,0,0,1,0},
						{1,0,0,0,1,0},
						{0,1,1,1,0,1},
						{1,0,0,0,1,0},
				   					 
				   					 };


/*
#define TAILLE_MAX 7
int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 2 marche pas

						{0,1,0,0,0,0,0},
						{1,0,1,1,0,0,0},
						{0,1,0,0,0,0,1},
						{0,1,0,0,1,0,1},
						{0,0,0,1,0,1,0},
						{0,0,0,0,1,0,1},
				   		{0,0,1,1,0,1,0},
				   					 };
*/

//fonction qui calcule le nb d'arc (ie. le nb de voisin) d'un noeud
int calcul_nb_arc(int graphe[][TAILLE_MAX],int numero_noeud)
{
	int i;
	int res=0;
	for (i=0;i<TAILLE_MAX;i++)
	{
		res += graphe[numero_noeud][i];
	}

	return res;
}

//fonction qui renvoie un tableau contenant la la position des voisins
int* voisin(int graphe[][TAILLE_MAX],int numero_noeud)
{
	int i,j=0;
	int *tableau_voinsin = (int*)malloc(calcul_nb_arc(graphe,numero_noeud)*sizeof(int));
	for (i = 0; i < TAILLE_MAX; i++)
	{
		if(graphe[numero_noeud][i]==1)
		{
			tableau_voinsin[j++] = i;
		}
	}

	return tableau_voinsin;
}

//fonction pour savoir si une valeur est dans un tableau
int in_tableau(int val,int tab[]) // Parcourir un tableau sans savoir sa taille..??
{
	int i;
	for(i=0;i<TAILLE_MAX;i++)
	{
		if (val == tab[i]) return 1;
	}
	return 0;
}

//fonction pour avoir le noeud qui a le plus de voisin
int max_voisin(int graphe[][TAILLE_MAX])
{
	int i,nb_max = -1,nb_voisin,noeud;
	for(i=0;i<TAILLE_MAX;i++)
	{
		nb_voisin = calcul_nb_arc(graphe,i);
		if(nb_voisin>nb_max)
		{
			nb_max = nb_voisin;
			noeud = i;
		}
	}
	return noeud;
}

void main(void)
{

	int i,j,k=1,nb_voisin,cond_dedans,noeud_max_voisin; //cond_dedans vaut 1 si aucun élément de liste_voisin est dans dominant_set, 0 sinon
	int *liste_voisin;
	int dominant_set[TAILLE_MAX-1];
	for (i = 0; i < TAILLE_MAX; i++) // pour initialiser le tableau à -1 et avoir un point avec un nb de voisin élévé
	{
		dominant_set[i] = -1;
	}
	noeud_max_voisin = max_voisin(graphe);
	dominant_set[0] = noeud_max_voisin;

	printf("INIT\n");
	for (int i = 0; i < TAILLE_MAX; ++i)
	{
		printf("%d\n",dominant_set[i]);
	}


	for(i=0;i<TAILLE_MAX;i++)
	{
		liste_voisin = voisin(graphe,i);
		nb_voisin = calcul_nb_arc(graphe,i);
		if (i==dominant_set[0]) continue;
		for(j=0;j<nb_voisin;j++)
		{
			if(!in_tableau(liste_voisin[j],dominant_set)) cond_dedans = 1;
			else cond_dedans = 0;
		}
		if(cond_dedans) dominant_set[k++] = i;
	}



	/*
	printf("%d\n",graphe[0][0]); // = 0
	printf("%d\n",graphe[0][3]); // = 1
	printf("%d\n",graphe[1][0]); // = 0
	printf("%d\n",graphe[4][4]); // = 0
	int a = calcul_nb_arc(graphe,0);
	printf("%d\n",a);
	printf("\n\n\n\n\n");
	int *b = voisin(graphe,0); 
	*/
	printf("AFTER\n");
	for (int i = 0; i < TAILLE_MAX; ++i)
	{
		printf("%d\n",dominant_set[i]);
	}
/*
	int *liste = voisin(graphe,1);

	printf("VOISIN de 4\n");
	printf("nb de voisin =%d\n",calcul_nb_arc(graphe,1));
	for (int i = 0; i < calcul_nb_arc(graphe,1); ++i)
	{
		printf("%d\n",liste[i]);
	}

*/	
}