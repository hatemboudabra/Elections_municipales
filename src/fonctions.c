#include<stdio.h>
#include"fonctions.h"
#include<stdlib.h>
#include <string.h>
void ajouter_usr(utilisateur u)
{
    FILE *f=NULL;
f=fopen("user.txt","a+");
        fprintf(f,"%d %s %s %s %s %s %s %d \n",u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,u.bureau);
        fclose(f);
    
}
/*
void modifier( char * filename, int CIN, utilisateur nouv )
{

   utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");

    if (f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %s %s %d  \n",u.nom,u.prenom,u.date_de_naissance,u.sexe,&u.CIN,u.type,u.region,&u.bureau)!=EOF)
        {
            if(u.CIN== CIN)
            {
                fprintf(f2,"%s %s %s %s %d %s %s %d  \n",nouv.nom,nouv.prenom,nouv.date_de_naissance,nouv.sexe,nouv.CIN,nouv.type,nouv.region,nouv.bureau);

            }
            else
                fprintf(f2,"%s %s %s %s %d %s %s %d \n",u.nom,u.prenom,u.date_de_naissance,u.sexe,u.CIN,u.type,u.region,u.bureau);
}

        }

   fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
   
}*/
void modifier_usr(int cin,utilisateur r){
FILE*f=NULL;
FILE*f1=NULL;
utilisateur u ;
f=fopen("user.txt","r");

f1=fopen("ancien.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,&u.bureau)!=-1){
if(cin==r.CIN)
{
fprintf(f1,"%d %s %s %s %s %s %s %d \n",r.CIN,r.nom,r.prenom,r.date_de_naissance,r.sexe,r.type,r.region,r.bureau);
}
else
{
fprintf(f1,"%d %s %s %s %s %s %s %d \n",u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,u.bureau);
}
}
fclose(f);
fclose(f1);
remove("user.txt");
rename("ancien.txt","user.txt");

}

void supprimer_us(int cin){

FILE*f=NULL;
FILE*f1=NULL;
utilisateur u ;
f=fopen("user.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,&u.bureau)!=-1){
if(cin!=u.CIN)
    fprintf(f1,"%d %s %s %s %s %s %s %d \n",u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,u.bureau);
}
fclose(f);
fclose(f1);
remove("user.txt");
rename("ancien.txt","user.txt");

}
utilisateur chercher_usr(char * filename, int CIN)
{
   utilisateur u;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %s %s %d \n",u.nom,u.prenom,u.date_de_naissance,u.sexe,&u.CIN,u.type,u.region,&u.bureau)!=EOF)
        {
            if(u.CIN== CIN)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.CIN=-1;
    return u;

}
enum
{
	ECIN,
	ENOM,
	EPRENOM,
	EDATE,
	ESEXE,
	ETYPE,
	EREGION,
        EBUREAU,
	COLUMNS
};
int CIN;
char a[50];
char b[50];    
char nom[50];
char prenom[50];
char date_de_naissance[50];
char sexe[50];
char type[50];
char region[50];
int bureau;

void afficher_us(GtkWidget *liste)
{
                GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
             utilisateur u;

	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("cin",renderer ,"text",ECIN, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
            
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("preom",renderer ,"text",EPRENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("date de naissance",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("sexe",renderer ,"text",ESEXE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Region",renderer ,"text",EREGION, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Bureau",renderer ,"text",EBUREAU, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



}
	    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("user.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  

			while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&CIN,nom,prenom,date_de_naissance,sexe,type,region,&bureau)!=EOF)
			{
sprintf(a,"%d",CIN);
sprintf(b,"%d",bureau);
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,ECIN,a,ENOM,nom,EPRENOM,prenom,EDATE,date_de_naissance,ESEXE,sexe,ETYPE,type,EREGION,region,EBUREAU,b, -1);
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}
void chercher_user(GtkWidget *liste, int ch)
{
                   GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
             utilisateur u;
int CIN;
char a[50];
char b[50];    
char nom[50];
char prenom[50];
char date_de_naissance[50];
char sexe[50];
char type[50];
char region[50];
int bureau;
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("cin",renderer ,"text",ECIN, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nom",renderer ,"text",ENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
            
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("preom",renderer ,"text",EPRENOM, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("date de naissance",renderer ,"text",EDATE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("sexe",renderer ,"text",ESEXE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Type",renderer ,"text",ETYPE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Region",renderer ,"text",EREGION, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Bureau",renderer ,"text",EBUREAU, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



}
	    store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("user.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {

                              while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&CIN,nom,prenom,date_de_naissance,sexe,type,region,&bureau)!=EOF)
			{if (CIN==ch){
sprintf(a,"%d",CIN);
sprintf(b,"%d",bureau);

				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,ECIN,a,ENOM,nom,EPRENOM,prenom,EDATE,date_de_naissance,ESEXE,sexe,ETYPE,type,EREGION,region,EBUREAU,b, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);  
			
	    }
}


void cherche_user(int cins){
FILE*f=NULL;
 utilisateur u;
f=fopen("user.txt","r");
while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&CIN,nom,prenom,date_de_naissance,sexe,type,region,&bureau)!=-1){
if(u.CIN=cins)
     printf("%d %s %s %s %s %s %s %d \n",u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,u.bureau);
}
fclose(f);

}
float Tauxhommes()
{
    utilisateur u;
    float nbr_home=0;
    float nbr_fme=0;
float taux_home=0;
float taux_fme=0;
    FILE *f=fopen("user.txt","r");
 if (f!=NULL)
  {
     while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,&u.bureau)!=EOF)
      {

         if(strcmp(u.sexe,"homme")==0){
          
            nbr_home++;}
        
         else {
            nbr_fme++;
      }}}
  

taux_home=(nbr_home/(nbr_home+nbr_fme))*100;
taux_fme=(nbr_fme/(nbr_home+nbr_fme))*100;
fclose(f);
return taux_home;
}

float Tauxfemmes()
{
    utilisateur u;
    float nbr_home=0;
    float nbr_fme=0;
float taux_home=0;
float taux_fme=0;
    FILE *f=fopen("user.txt","r");
 if (f!=NULL)
  {
     while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,&u.bureau)!=EOF)
      {

         if(strcmp(u.sexe,"femme")==0){
          
            nbr_fme++;}
        
         else {
        
            nbr_home++;
}
      }}
  

taux_home=(nbr_home/(nbr_home+nbr_fme))*100;
taux_fme=(nbr_fme/(nbr_home+nbr_fme))*100;
fclose(f);
return taux_fme;
}
float agemoyen()
{
utilisateur u;
int a=0;
float na=0;
int nb=0;
int dayf,monthf,yearf;
float ma=0.0;
    FILE *f=fopen("user.txt","r");
	if(f!=NULL)

	{
	     while(fscanf(f,"%d %s %s %d/%d/%d %s %s %s %d \n",&u.CIN,u.nom,u.prenom,&dayf,&monthf,&yearf,u.sexe,u.type,u.region,&u.bureau)!=EOF)
		{
   

                  a = 2022-yearf;
                  na=na+a;
                  nb++;

	    }

	}
ma=(float)na/nb;
	fclose(f);
	return (ma);
}

