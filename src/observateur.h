#ifndef OBS_H_INCLUDED
#define OBS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{
	int id;
	char nom[20];
	char prenom[20];
	char profession[20];
	char nationality[20];
	char genre[20];
	int numB;	
}observateur;


void ajouter_observateur(observateur o);
void supprimer_observateur(int id);
void modifier_observateur(observateur o);

void afficher_observateur(GtkWidget *liste,char *fname);

int rechercher_observateur(int id);

observateur observateur_data(int id);

void trierObs();
int nbTotal(char *filename);
#endif // OBS_H_INCLUDED
