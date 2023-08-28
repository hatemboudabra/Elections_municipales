#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "observateur.h"
#include <gtk/gtk.h>

enum{
	EIDW,
	ENOMW,
	EPRENOMW,
	EPROFESSION,
	EGENRE,
	ENATION,
	ENBVOTE,
	ECOLUMNSW,
};


void ajouter_observateur(observateur o){

	FILE *f;
	f = fopen("observateur.txt","a");
        if(f!= NULL){
        	fprintf(f,"%d %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.profession,o.nationality,o.genre,o.numB);
    	}
    	fclose(f);
}

void supprimer_observateur(int id){
	observateur o;
FILE *f, *g;
f=fopen("observateur.txt","r");
g=fopen("temp.txt","a");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(o.id),o.nom,o.prenom,o.profession,o.nationality,o.genre,&(o.numB))!=EOF)
	{
		if(o.id != id)
			fprintf(g,"%d %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.profession,o.nationality,o.genre,o.numB);
	}
	
	fclose(f);
	fclose(g);
	
	remove("observateur.txt");
	rename("temp.txt","observateur.txt");
	}
}

void modifier_observateur(observateur o){
	observateur y;
	FILE *f, *g;
	f=fopen("observateur.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%d %s %s %s %s %s %d\n",&(y.id),y.nom,y.prenom,y.profession,y.nationality,y.genre,&(y.numB))!=EOF)
		{
			if(o.id == y.id)
				fprintf(g,"%d %s %s %s %s %s %d\n",o.id,o.nom,o.prenom,o.profession,o.nationality,o.genre,o.numB);
			else
				fprintf(g,"%d %s %s %s %s %s %d\n",y.id,y.nom,y.prenom,y.profession,y.nationality,y.genre,y.numB);
		}
	
		fclose(f);
		fclose(g);
		
		remove("observateur.txt");
		rename("temp.txt","observateur.txt");
	}
}

void afficher_observateur(GtkWidget *liste,char *fname){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    observateur y ;
    char ido[20];
    char numBV[40];
    char name[50];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EIDW,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOMW,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prénom",renderer,"text",EPRENOMW,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Profession",renderer,"text",EPROFESSION,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nationalité",renderer,"text",ENATION,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre",renderer,"text",EGENRE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NumB",renderer,"text",ENBVOTE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNSW,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(y.id),y.nom,y.prenom,y.profession,y.nationality,y.genre,&(y.numB))!=EOF){
			sprintf(ido,"%d",y.id);
			sprintf(numBV,"%d",y.numB);

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EIDW,ido,ENOMW,y.nom,EPRENOMW,y.prenom,EPROFESSION,y.profession,ENATION,y.nationality,EGENRE,y.genre,ENBVOTE,numBV,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}

int rechercher_observateur(int id){
	observateur y ;	
	FILE *f;
	f = fopen("observateur.txt","r");
	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(y.id),y.nom,y.prenom,y.profession,y.nationality,y.genre,&(y.numB))!=EOF)
		{
			if(y.id == id){
				return 1 ; 
			}

		}
	return 0;
	
}

observateur observateur_data(int id){
	observateur y ;	
	FILE *f;
	f = fopen("observateur.txt","r");
	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(y.id),y.nom,y.prenom,y.profession,y.nationality,y.genre,&(y.numB))!=EOF)
		{
			if(y.id == id){
				return y ; 
			}

		}
	return;
}

void trierObs(){

	observateur o;
	observateur data[1000];
    	FILE *f;

	int count = 0; 
   	f = fopen("observateur.txt","r");

    	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(o.id),o.nom,o.prenom,o.profession,o.nationality,o.genre,&(o.numB))!=EOF){
	    data[count] = o ;
		count++ ; 
    	}
    	fclose(f);

	int i,j;
	observateur temp;

	for (i = 0; i < count; i++) {
	    for (j = 0; j < count; j++){
	      if (strcmp(data[i].nom, data[j].nom) < 0)
		{
		  temp = data[i];
		  data[i] = data[j];
		  data[j] = temp;
		}
	  }
	}

	FILE *g;
	g = fopen("triobs.txt","a");
	for (i = 0; i < count; i++) {
		fprintf(g,"%d %s %s %s %s %s %d\n",data[i].id,data[i].nom,data[i].prenom,data[i].profession,data[i].nationality,data[i].genre,data[i].numB);
	}

	fclose(g);
}

int nbTotal(char *filename){
	FILE *f ; 
	observateur o; 
	int count = 0 ; 
	f = fopen("observateur.txt","r");
	while(fscanf(f,"%d %s %s %s %s %s %d\n",&(o.id),o.nom,o.prenom,o.profession,o.nationality,o.genre,&(o.numB))!=EOF){
		count = count + 1 ; 
	
	}

	fclose(f);
	return count ; 
}

