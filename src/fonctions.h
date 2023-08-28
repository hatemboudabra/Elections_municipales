#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


typedef struct
{  char nom[50];
char prenom[50];
char date_de_naissance[50];
char sexe[50];
int CIN;
char type[50];
char region[50];
int bureau;

} utilisateur;
void ajouter_usr( utilisateur u );
void modifier_usr(int CIN, utilisateur u);
void supprimer_usr(char *filename, int CIN);
utilisateur chercher_usr(char *filename, int CIN);
float Tauxhommes();
float Tauxfemmes();
float agemoyen();
#endif // FONCTIONS_H_INCLUDED
