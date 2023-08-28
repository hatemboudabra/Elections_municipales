#include<stdio.h>
#include"fonction.h"
#include<stdlib.h>
#include <string.h>
void ajouterbv(bv b)
{
    FILE *f=NULL;
f=fopen("bureau.txt","a+");
        fprintf(f,"%s %s %d %d \n",b.id,b.region,b.ce,b.no);
        fclose(f);
    
}

void modifierbv(char id[20],bv b1)
{
FILE*f=NULL;
FILE*f1=NULL;
bv b ;
f=fopen("bureau.txt","r");

f1=fopen("ancien.txt","w+");

if ((f!=NULL)&&(f1!=NULL))
while(fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=-1){
if(strcmp(b.id,b1.id)==0)
{
fprintf(f1,"%s %s %d %d \n",b1.id,b1.region,b1.ce,b1.no);
}
else
{
fprintf(f1,"%s %s %d %d \n",b.id,b.region,b.ce,b.no);
}
}
fclose(f);
fclose(f1);
remove("bureau.txt");
rename("ancien.txt","bureau.txt");

}
int supprimer(char *filename, char id[20])
 {

    bv b;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=EOF)
        {
            if(strcasecmp(b.id,id)==0)
                return 1;
            else
           fprintf(f2,"%s %s %d %d \n",b.id,b.region,b.ce,b.no);
	            return 0;
	}
    }

 }
void supprimer_bv(char id[20])
{

FILE*f=NULL;
FILE*f1=NULL;
bv b ;
f=fopen("bureau.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=-1){
if(strcasecmp(id,b.id)!=0)
    fprintf(f1,"%s %s %d %d \n",b.id,b.region,b.ce,b.no);
}
fclose(f);
fclose(f1);
remove("bureau.txt");
rename("ancien.txt","bureau.txt");

}

bv chercher(char *filename, char id[20])
{
   bv b;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=EOF)
        {
            if(strcasecmp(b.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        b.id[0]="-1";
    return b;

}
enum
{
	EIDF,
	EREGIONF,
	ECE,
	ENO,
	COLUMNSF
};
char a[50];
char b1[50];
char c[50];
char id[20];
char region[50];
int ce;
int no;

void afficher_bv(GtkWidget* liste)
{
                GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
             bv b;

	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Identifiant",renderer ,"text",EIDF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Region",renderer ,"text",EREGIONF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
            
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Capacite electoral",renderer ,"text",ECE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("Nombre observateur",renderer ,"text",ENO, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    



}
	    store=gtk_list_store_new (COLUMNSF, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("bureau.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  

			while(fscanf(f,"%s %s %d %d\n",id,region,&ce,&no)!=EOF)
			{

sprintf(b1,"%d",ce);
sprintf(c,"%d",no);
				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EIDF,id,EREGIONF,region,ECE,b1,ENO,c, -1);
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
}
void chercher_bv(GtkWidget* liste, char ch[20])
{
                   GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column;
 	    GtkTreeIter iter;
	    GtkListStore *store;
             bv b;
char a[50];
char b1[50];
char c[50];
char id[20];
char region[50];
int ce;
int no;
	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("id",renderer ,"text",EIDF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("region",renderer ,"text",EREGIONF, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
            
            renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("ce",renderer ,"text",ECE, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	    renderer = gtk_cell_renderer_text_new ();
	    column = gtk_tree_view_column_new_with_attributes("no",renderer ,"text",ENO, NULL);
	    gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	    
	   



}
	    store=gtk_list_store_new (COLUMNSF, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	    f=fopen("bureau.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {

                              while(fscanf(f,"%s %s %d %d\n",id,region,&ce,&no)!=EOF)
			{if (strcasecmp(id,ch)==0){

sprintf(b1,"%d",ce);
sprintf(c,"%d",no);

				gtk_list_store_append (store, &iter);
				gtk_list_store_set(store,&iter,EIDF,id,EREGIONF,region,ECE,b1,ENO,c, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);  
			
	    }
}

/*
void cherche_bv(char cins[23]){
FILE*f=NULL;
 bv b;
f=fopen("bureau.txt","r");
while(fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=-1){
if(b.id=cins)
     printf("%s %s %d %d \n",b.id,b.region,b.ce,b.no);
}
fclose(f);

}*/
