#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct
{
	int j;
	int m ;
	int a ;
}date ;
typedef struct
{
    char id[20];
    char nom[20];
    char orientation[30];
    char munic[30];
    char nomCT[30];
    char cinT[20];
    char nomC1[30];
    char cinC1[20];
    char nomC2[30];
    char cinC2[20];
    char nomC3[30];
    char cinC3[20];
    int nbrVote ;
    date d ;
}election;



void ajouter_elec(election e);
void supprimer_elec(char id[]);
void modifier_election(election el);
void afficher_election(GtkWidget *liste,char *fname);
void afficher_electionVote(GtkWidget *liste);

int rechercher_election(char id[]);

election recherche_election(char id[]);

int trierLE(GtkWidget *liste,char *fname);

#endif // ELECTION_H_INCLUDED

