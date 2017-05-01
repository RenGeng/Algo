
#include "notre_algo.h"
#include "algo_glouton.h"
#include "commun.h"
#include <time.h>
/*

Pensez à changer TAILLE_MAX dans le fichier commun.h

*/
int main(void)
{

	
	// Définition à la main du graphe (voir le document word pour avoir une image)

	/*
	int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 1

							{0,1,0,1,0,1},
							{1,0,1,0,1,0},
							{0,1,0,0,1,0},
							{1,0,0,0,1,0},
							{0,1,1,1,0,1},
							{1,0,0,0,1,0},
					   					 
					   					 };
	*/

	
	int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 2
							{0,1,0,0,0,0,0},
							{1,0,1,1,0,0,0},
							{0,1,0,0,0,0,1},
							{0,1,0,0,1,0,1},
							{0,0,0,1,0,1,0},
							{0,0,0,0,1,0,1},
					   		{0,0,1,1,0,1,0},

					   					 };
	

	/*
	int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 3

							{0,1,0,0,0},
							{1,0,1,1,1},
							{0,1,0,1,0},
							{0,1,1,0,1},
							{0,1,0,1,0},

					   					 };
	*/

	/*
	int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 4

							{0,1,0,0,1,0},
							{1,0,1,0,1,0},
							{0,1,0,1,0,1},
							{0,0,1,0,0,0},
							{1,1,0,0,0,1},
							{0,0,1,0,1,0},

					   					 };
	*/

	/*
	int graphe[TAILLE_MAX][TAILLE_MAX] = { // graphe 5

							{0,1,0,0,0,1},
							{1,0,1,0,0,0},
							{0,1,0,1,0,0},
							{0,0,1,0,1,0},
							{0,0,0,1,0,1},
							{1,0,0,0,1,0},

					   					 };
	*/
	int** generation_graphe()
	{
		int i; j;
		srand(time(NULL));
		int taille = rand()%20 // max de la taille de notre graphe à 20
		int** graphe = malloc(taille*sizeof(int*));
		for(i=0:i<taille;i++)
			graphe[i]=malloc(taille*sizeof(int));
		for(i=0;i<taille;i++)
		{
			for(j=i;j<taille;j++)
			{
				if(rand%10<3 && i!=j) // 1/3 des cases à 1
				{
					graphe[i][j]=1;
					graphe[j][i]=1;
				}
				else
				{
					graphe[i][j]=1;
					graphe[j][i]=1;
				}
			}
		}
		return graphe;
	}
	int i;

	int* notre = notre_algo(graphe);

	printf("--------------------Dominant set de notre Algo--------------------\n");
	for(i=0;i<TAILLE_MAX;i++)
	{
		if(notre[i]==-1) break;
		printf("%d\n",notre[i]);
	}

	int* glouton = algorithme_glouton(graphe);

	printf("--------------------Dominant set d'algo glouton--------------------\n");
		for(i=0;i<TAILLE_MAX;i++)
	{
		if(glouton[i]==-1) break;
		printf("%d\n",glouton[i]);
	}
}
