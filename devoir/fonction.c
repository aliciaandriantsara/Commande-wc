#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "declaration.h"

void fonction(int argc, char *argv[])
{
	FILE *pfile=NULL;
	int n1=0;
	int n2=0;
	int n3=0;
	int *max=NULL;
	int i;
	int Max=0;
	char caractere=0;
	if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--bytes") == 0)
	{
		pfile=fopen(argv[2], "r+");
		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			rewind(pfile);
			n1=octet(pfile);
			printf("%d %s\n", n1, argv[2]);
			fclose(pfile);
		}
	}
	else if(strcmp(argv[1],  "-m") == 0 || strcmp(argv[1], "--chars") == 0)
	{

		pfile=fopen(argv[2], "r+");
		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			rewind(pfile);
			n1=octet(pfile);
			printf("%d %s\n", n1, argv[2]);
			fclose(pfile);
		}
	}
	else if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--lines") == 0)
	{
		pfile=fopen(argv[2], "r+");
		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			rewind(pfile);
			n2=ligne(pfile);
			printf("%d %s\n", n2, argv[2]);
			fclose(pfile);
		}
	}
	else if(strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--words") == 0)
	{
		pfile=fopen(argv[2], "r+");
		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			rewind(pfile);
			n3=mot(pfile);
			printf("%d %s\n", n3, argv[2]);
			fclose(pfile);
		}
	}
	else if(strcmp(argv[1], "--version") == 0)
	{
		printf("wc (GNU coreutils) 8.32\nCopyright © 2020 Free Software Foundation, Inc.\nLicense GPLv3+ : GNU GPL version 3 ou ultérieure <https://gnu.org/licenses/gpl.html>\nCeci est un logiciel libre. Vous etes libre de le modifier et de le redistribuer.\nCe logiciel n'est accompagne d'ABSOLUMENT AUCUNE GARANTIE, dans les limites permises par la loi.\n\nEcrit par Paul Rubin et David MacKenzie.\n");
	}
	else if(strcmp(argv[1], "--help") == 0)
	{
		printf("Utilisation : wc [OPTION]... [FICHIER]... \n\tou : wc [OPTION]... --files0-from=F \n Afficher le nombre de sauts de ligne, de mots et d'octets pour chaque FICHIER et une ligne totale si plus d'un fichier est specifie. Un mot est une sequence de taille non nulle de caracteres delimites par une espace. \n\nSans FICHIER ou quand FICHIER est -, lire l'entree standard. \n\nLes option ci-dessous permettent de selectionner les compteurs a afficher,qui sont toujours utilises dans l'ordre suivant : saut de ligne, mot, caractere,octet, longueur de ligne maximale. \n-c, --bytes\tafficher le nombre d'octets \n-m, --chars\tafficher le nombre de caracteres \n-l, --lines\tafficher le nombre de sauts de lignes \n\t--files0-from=F\tlire l'entree depuis les fichiers indiques par\t\tdes noms terminant par NUL dans le fichier F \n-L, --max-line-length\tafficher la largeur maximale d'affichage \n-w, --words\tafficher le nombre de mots \n\t--help     afficher l'aide et quitter\t--version  afficher des informations de version et quitter \n\nAide en ligne de GNU coreutils : <https://www.gnu.org/software/coreutils/> \nSignalez les problemes de traduction a : <traduc@traduc.org> \nDocumentation complete <https://www.gnu.org/software/coreutils/wc> \nou disponible localement via: info '(coreutils) wc invocation' \n ");
	}
	else if(strcmp(argv[1], "-L") == 0 || strcmp(argv[1], "--max-line-length") == 0)
	{
		pfile=fopen(argv[2], "r+");
		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			n2=ligne(pfile);
			max=(int*)malloc(n2*sizeof(int));
			rewind(pfile);
			while((caractere=fgetc(pfile)) != EOF)
			{
				max[i]++;
				if(caractere == '\n' && i<n2)
				{
					i++;
				}
			}
			Max=max[0];
			for(i=1;i<n2;i++)
			{
				if(Max<max[i])
				{
					Max=max[i];
				}

			}
			Max = Max - 1;
			printf("%d %s\n", Max, argv[2]);

			

		}

	}
	else
	{
		pfile=fopen(argv[1], "r+");

		if(pfile == NULL)
		{
			printf("Erreur d'ouverture\n");
		}
		else
		{
			n1=octet(pfile);
			rewind(pfile);
			n2=ligne(pfile);
			rewind(pfile);
			n3=mot(pfile);
			printf("%d  %d  %d  %s\n", n2, n3, n1, argv[1]);
			fclose(pfile);
		}
	}
}

int ligne(FILE *pfile)
{
	int nbligne=1;
	while(fgetc(pfile) != EOF)
	{
		if(fgetc(pfile) == '\n' || fgetc(pfile) == '\0')
			nbligne++;
	}
	return (nbligne);
}

int octet(FILE *pfile)
{
	int nboctet=0;
	while(fgetc(pfile) != EOF)
	{
		nboctet++;
	}
	return (nboctet);
}


int mot(FILE *pfile)
{
	int nbmots=0;
	char caractere=0;
	while((caractere=fgetc(pfile)) != EOF)
	{
		if(caractere == ' ')
			nbmots++;
		else if(caractere == '\n')
			nbmots++;
	}
	nbmots = nbmots - 1;
	return (nbmots);
}
