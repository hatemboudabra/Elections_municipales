#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include<gtk/gtk.h>
#include <string.h>
typedef struct
{  char id[20];
char region[50];
int ce;
int no;

} bv;
void ajouterbv( bv b);
void modifierbv(char id[20],bv b1);
int supprimer(char *filename, char id[20]);
bv chercher(char *filename,char id[20]);
void supprimer_bv(char id[20]);
void afficher_bv(GtkWidget* liste);
void chercher_bv(GtkWidget* liste, char ch[20]);


#endif // FONCTION_H_INCLUDED
