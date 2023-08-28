#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "fonction.c"
#include "fonction.h"
#include "fonctions.c"
#include "observateur.h"
#include "observateur.c"
#include "election.h"
#include "election.c"
utilisateur ut;
char tyy[20]="homme";
char tyy1[20]="homme";
char cin[20];
char cinn[20];
int ci;
int x = 1 ;
int y = 1 ; 
int check = 0 ; 
void
on_button36_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button37_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Utilisateur;
Utilisateur=lookup_widget(button,"Utilisateur");
gtk_widget_destroy(Utilisateur);
GtkWidget *supprimer;
supprimer = create_supprimer ();
  gtk_widget_show (supprimer);


}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *Utilisateur;
Utilisateur=lookup_widget(button,"Utilisateur");
gtk_widget_destroy(Utilisateur);
utilisateur u;
FILE *f;
f=fopen("user.txt","r");
GtkWidget *modifieruser;
modifieruser = create_modifieruser ();
  gtk_widget_show (modifieruser);
GtkWidget *nomHatem2;
nomHatem2 = lookup_widget (modifieruser ,"nomHatem2");
GtkWidget *prenomHatem2;
prenomHatem2 = lookup_widget (modifieruser ,"prenomHatem2");
GtkWidget *cinHate2;
cinHate2 = lookup_widget (modifieruser ,"cinHate2");

while(fscanf(f,"%d %s %s %s %s %s %s %d \n",&u.CIN,u.nom,u.prenom,u.date_de_naissance,u.sexe,u.type,u.region,&u.bureau)!=-1){
 if (u.CIN==ut.CIN){
char ci[20];
sprintf(ci,"%d",u.CIN);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifieruser,"cinHate2")),ci);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifieruser,"nomHatem2")),u.nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifieruser,"prenomHatem2")),u.prenom);

}}
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];

GtkWidget *treeview1;
GtkWidget *Utilisateur;
Utilisateur=lookup_widget(button,"Utilisateur");
treeview1=lookup_widget(Utilisateur,"treeview1");
cherch = lookup_widget (button ,"cinrech");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
int r=atoi(ch);

 chercher_user(treeview1,r);


}





void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}






void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
printf(cin);
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *date_de_naissance;
GtkWidget *sexe;
GtkWidget *CIN;
GtkWidget *type;

GtkWidget *region;
GtkWidget *bureau;
GtkWidget *modifieruser;


utilisateur u;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;
nom = lookup_widget (button ,"nomHatem2");
prenom = lookup_widget (button ,"prenomHatem2");
CIN = lookup_widget (button ,"cinHate2");
type = lookup_widget (button ,"typeHatem");
region = lookup_widget (button ,"combo3");
sexe = lookup_widget (button ,"radiobutton6");
bureau = lookup_widget (button ,"spinbutton12");


GtkWidget *calendar;
calendar=lookup_widget(button,"calendar3");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;


u.bureau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(bureau));

strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(cinn, gtk_entry_get_text(GTK_ENTRY(CIN)));
u.CIN=atoi(cinn);
strcpy(u.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(u.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"/");strcat(y,b);strcat(y,"/");strcat(y,c);


strcpy(u.date_de_naissance,y);
strcpy(u.sexe,tyy1);

modifier_usr(ut.CIN,u);
gtk_widget_destroy(modifieruser);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);

}


void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifieruser;
modifieruser=lookup_widget(button,"modifieruser");
gtk_widget_destroy(modifieruser);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"homme");
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy1,"femme");
}




void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Utilisateur;
Utilisateur=lookup_widget(button,"Utilisateur");
gtk_widget_destroy(Utilisateur);
GtkWidget *ajouteruser;
ajouteruser = create_ajouteruser ();
  gtk_widget_show (ajouteruser);
}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *utilisateur;
utilisateur=lookup_widget(button,"Utilisateur");
gtk_widget_destroy(utilisateur);
GtkWidget *connexion;
connexion = create_Connexion ();
  gtk_widget_show (connexion);
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton15_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button31_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button32_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button48_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button53_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
supprimer=lookup_widget(button,"supprimer");
gtk_widget_destroy(supprimer);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);
}


void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button38__clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobuttonf_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"femme");
}


void
on_radiobuttonh_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tyy,"homme");
}


void
on_buttonajouterUsHatem_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *date_de_naissance;
GtkWidget *sexe;
GtkWidget *CIN;
GtkWidget *type;
GtkWidget *dialog;
GtkWidget *region;
GtkWidget *bureau;
GtkWidget *ajouteruser;


utilisateur u;
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int o=0;
nom = lookup_widget (button ,"NomHatem");
prenom = lookup_widget (button ,"PrenomHatem");
CIN = lookup_widget (button ,"CinHatem");
type = lookup_widget (button ,"combobox1_typeHatem");
region = lookup_widget (button ,"regionHatem");
sexe = lookup_widget (button ,"radiobuttonh");
bureau = lookup_widget (button ,"spinbutton1bur_ut");






GtkWidget *calendar;
calendar=lookup_widget(button,"calendar1_hatem");
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);
mm=mm+1;

if(strlen(gtk_entry_get_text(GTK_ENTRY(CIN)))==8 && strlen(gtk_entry_get_text(GTK_ENTRY(nom)))>=1 && strlen(gtk_entry_get_text(GTK_ENTRY(prenom)))>=1)
{
u.bureau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(bureau));

strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(CIN)));
u.CIN=atoi(cin);
strcpy(u.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(u.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"/");strcat(y,b);strcat(y,"/");strcat(y,c);


strcpy(u.date_de_naissance,y);
strcpy(u.sexe,tyy);


ajouter_usr(u);
ajouteruser=lookup_widget(button,"ajouteruser");
gtk_widget_destroy(ajouteruser);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);
}

		else{
			dialog=gtk_message_dialog_new(GTK_WINDOW(dialog),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_OK,
			"Verefier votre donnes STP !!");
			gtk_window_set_title(GTK_WINDOW(dialog),"Alerte");
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
		}


}


void
on_buttonRetourHatem_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouteruser;
ajouteruser=lookup_widget(button,"ajouteruser");
gtk_widget_destroy(ajouteruser);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);
}


void
on_ActualiserUser_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *Utilisateur;
Utilisateur=lookup_widget(button,"Utilisateur");
treeview1=lookup_widget(Utilisateur,"treeview1");

afficher_us(treeview1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* CIN;
	gchar* nom;
	gchar* prenom;
	gchar* date_de_naissance;
	gchar* sexe;
	gchar* type;
	gchar* region;
        gchar* bureau;


	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&CIN,1,&nom,2,&prenom,3,&date_de_naissance,4,&sexe,5,&type,6,&region,7,&bureau,-1);
strcpy(cin,CIN);
printf(cin);
ut.CIN=atoi(cin);

	}
}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_us(ut.CIN);
GtkWidget *supprimer;
supprimer=lookup_widget(button,"supprimer");
gtk_widget_destroy(supprimer);
GtkWidget *Utilisateur;
Utilisateur = create_Utilisateur ();
  gtk_widget_show (Utilisateur);
}



void
on_toAffLE_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_afficher_liste_electorale ();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toAddLE_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_ajout_liste ();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toModLE_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_modifier_liste ();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toSupprimerListe_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_supprimer_liste();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toVote_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ;
	window1 = create_vote();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_toStats_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2 ; 
	
	window1 = create_stats ();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourSupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"supprimer_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourStats_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"stats");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourVote_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"vote");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"modifier_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_button67_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"afficher_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_retourAJ_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"ajout_liste");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_RefrechListe_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeview9");
		
	afficher_election(treeview,"election.txt");
}


void
on_radiobuttonAG_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		x=1;
	}
}


void
on_radiobuttonAC_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_radiobuttonAD_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		x=3;
	}
}


void
on_ajouterLE_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nomLE, *idLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 , *output,*j,*m,*a  ;
GtkWidget *munic ; 
	
	election e;
	char message[200];
	
	
	
	
	idLE=lookup_widget(button,"idLE");
	nomLE=lookup_widget(button,"nomLE");

	munic = lookup_widget(button,"comboboxMunic");

	nomCT=lookup_widget(button,"nomCT");
	cinCT=lookup_widget(button,"cinT");

	nomC1=lookup_widget(button,"nomC1");
	cinC1=lookup_widget(button,"cinC1");

	nomC2=lookup_widget(button,"nomC2");
	cinC2=lookup_widget(button,"cinC2");

	nomC3=lookup_widget(button,"nomC3");
	cinC3=lookup_widget(button,"cinC3");

	j = lookup_widget(button,"spinJA");
	m = lookup_widget(button,"spinMA");
	a = lookup_widget(button,"spinAA");

	output = lookup_widget(button,"outputLE");



	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

	strcpy(e.munic,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));

	strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
	strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

	strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
	strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

	strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
	strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

	strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
	strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



	if(x==1){
		strcpy(e.orientation,"gauche");	
	}
	else if(x == 2){
		strcpy(e.orientation,"center");
	}
	else{
		strcpy(e.orientation,"droite");
	}

	

	e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

	e.nbrVote = 0 ;
	 
	if(rechercher_election(e.id)){
		sprintf(message,"ID EXISTANT ! \n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		ajouter_elec(e);		
		sprintf(message,"AJOUT AVEC SUCCÉE ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
	}
	
}


void
on_consulterLE_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
	GtkWidget *j , *m , *a ;
	GtkWidget * munic ; 
	
	GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(button,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(button,"outputLEE");	
	

	if(!rechercher_election(id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
		election e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_election(id).nom);
		strcpy(e.orientation,recherche_election(id).orientation);

		strcpy(e.nomCT,recherche_election(id).nomCT);
		strcpy(e.cinT,recherche_election(id).cinT);

		strcpy(e.nomC1,recherche_election(id).nomC1);
		strcpy(e.cinC1,recherche_election(id).cinC1);

		strcpy(e.nomC2,recherche_election(id).nomC2);
		strcpy(e.cinC2,recherche_election(id).cinC2);

		strcpy(e.nomC3,recherche_election(id).nomC3);
		strcpy(e.cinC3,recherche_election(id).cinC3);
		strcpy(e.munic,recherche_election(id).munic);

		int comboValue = 0 ;
		

		if(strcmp(e.munic,"sahline") == 0){
			comboValue = 1 ;
		}
		else if(strcmp(e.munic,"wardanine") == 0){
			comboValue = 2 ;
		}
		else if(strcmp(e.munic,"masjedaissaa") == 0){
			comboValue = 3 ;
		}
		else if(strcmp(e.munic,"jamel") == 0){
			comboValue = 4;
		}
		else if(strcmp(e.munic,"monastire") == 0){
			comboValue = 5 ;
		}		
		munic = lookup_widget(button,"combobox2");

		gtk_combo_box_set_active(munic,comboValue);

		


					
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		

		nomLE=lookup_widget(button,"nomLEE");
    		gtk_entry_set_text(GTK_ENTRY(nomLE),e.nom);

		nomCT=lookup_widget(button,"nomCTE");
		gtk_entry_set_text(GTK_ENTRY(nomCT),e.nomCT);

		cinCT=lookup_widget(button,"cinTE");
		gtk_entry_set_text(GTK_ENTRY(cinCT),e.cinT);

		nomC1=lookup_widget(button,"nomCE1");
		gtk_entry_set_text(GTK_ENTRY(nomC1),e.nomC1);

		cinC1=lookup_widget(button,"cinCE1");
		gtk_entry_set_text(GTK_ENTRY(cinC1),e.cinC1);

		nomC2=lookup_widget(button,"nomCE2");
		gtk_entry_set_text(GTK_ENTRY(nomC2),e.nomC2);

		cinC2=lookup_widget(button,"cinCE2");
		gtk_entry_set_text(GTK_ENTRY(cinC2),e.cinC2);


		nomC3=lookup_widget(button,"nomCE3");
		gtk_entry_set_text(GTK_ENTRY(nomC3),e.nomC3);

		cinC3=lookup_widget(button,"cinCE3");
		gtk_entry_set_text(GTK_ENTRY(cinC3),e.cinC3);

		j = lookup_widget(button,"spinJM");
		gtk_spin_button_set_value(j,recherche_election(id).d.j);


		m = lookup_widget(button,"spinMM");
		gtk_spin_button_set_value(m,recherche_election(id).d.m);

		a = lookup_widget(button,"spinAM");
		gtk_spin_button_set_value(a,recherche_election(id).d.a);

		
	}

}


void
on_radiobuttonGE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		y=1;
	}
}


void
on_radiobuttonCE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}
}


void
on_radiobuttonDE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		y=3;
	}
}


void
on_checkModif_activate                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (togglebutton)){
		check = 1 ;
	}
	else{
		check = 0 ;
	}
}


void
on_saveChangesLE_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nomLE , *nomCT , *cinCT , *nomC1 , *cinC1 , *nomC2 ,*cinC2 ,*nomC3 , *cinC3 ;
GtkWidget *munic ; 

	GtkWidget *idLE , *output;
	char message[200];
	char id[20];
	election e;

	idLE = lookup_widget(button,"idLEE");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	output = lookup_widget(button,"outputLEE");

	if(check == 0 ){
		sprintf(message,"Veuillez confirmer votre choix! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		if(rechercher_election(id)){
		nomLE=lookup_widget(button,"nomLEE");
		nomCT=lookup_widget(button,"nomCTE");
		cinCT=lookup_widget(button,"cinTE");

		nomC1=lookup_widget(button,"nomCE1");
		cinC1=lookup_widget(button,"cinCE1");

		nomC2=lookup_widget(button,"nomCE2");
		cinC2=lookup_widget(button,"cinCE2");

		nomC3=lookup_widget(button,"nomCE3");
		cinC3=lookup_widget(button,"cinCE3");

		munic = lookup_widget(button,"combobox2");

		strcpy(e.munic,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));

		strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(idLE)));
		strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nomLE)));

		strcpy(e.nomCT,gtk_entry_get_text(GTK_ENTRY(nomCT)));
		strcpy(e.cinT,gtk_entry_get_text(GTK_ENTRY(cinCT)));

		strcpy(e.nomC1,gtk_entry_get_text(GTK_ENTRY(nomC1)));
		strcpy(e.cinC1,gtk_entry_get_text(GTK_ENTRY(cinC1)));

		strcpy(e.nomC2,gtk_entry_get_text(GTK_ENTRY(nomC2)));
		strcpy(e.cinC2,gtk_entry_get_text(GTK_ENTRY(cinC2)));

		strcpy(e.nomC3,gtk_entry_get_text(GTK_ENTRY(nomC3)));
		strcpy(e.cinC3,gtk_entry_get_text(GTK_ENTRY(cinC3)));



		if(y==1){
			strcpy(e.orientation,"gauche");	
		}
		else if(y == 2){
			strcpy(e.orientation,"center");
		}
		else{
			strcpy(e.orientation,"droite");
		}


		GtkWidget *j,*m,*a; 
		j = lookup_widget(button,"spinJM");
		m = lookup_widget(button,"spinMM");
		a = lookup_widget(button,"spinAM");
	

		e.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
		e.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
		e.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

		e.nbrVote = recherche_election(id).nbrVote ; 

		sprintf(message,"MODIFICATION AFFECTÉE ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_election(e);
		
	}
	else{
		sprintf(message,"ID NON TROUVABLE! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}

	}
}


void
on_voter_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idLE , *output ; 
	char id[30];
	char message[100] ;  

	idLE = lookup_widget(button,"idVote");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));
	
	output = lookup_widget(button,"outputVote");

	if(rechercher_election(id)){
		election e;

		strcpy(e.id,id);		
		strcpy(e.nom,recherche_election(id).nom);
		strcpy(e.orientation,recherche_election(id).orientation);

		strcpy(e.nomCT,recherche_election(id).nomCT);
		strcpy(e.cinT,recherche_election(id).cinT);

		strcpy(e.nomC1,recherche_election(id).nomC1);
		strcpy(e.cinC1,recherche_election(id).cinC1);

		strcpy(e.nomC2,recherche_election(id).nomC2);
		strcpy(e.cinC2,recherche_election(id).cinC2);

		strcpy(e.nomC3,recherche_election(id).nomC3);
		strcpy(e.cinC3,recherche_election(id).cinC3);
		strcpy(e.munic,recherche_election(id).munic);

		e.d.j = recherche_election(id).d.j ;
		e.d.m = recherche_election(id).d.m ;
		e.d.a = recherche_election(id).d.a ;

		e.nbrVote = recherche_election(id).nbrVote + 1 ; 
		modifier_election(e);
		sprintf(message,"Vote ajouté avec succés  ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}


void
on_refreshTreeView_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeviewVote");
		
	afficher_election(treeview,"election.txt");
}


void
on_refreshStat2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeviewStat2");
	trierLE(treeview,"election.txt");
}


void
on_refreshStat1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeviewStat1");
		
	afficher_electionVote(treeview);
}


void
on_supListe_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(button,"idSupp");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));


	output = lookup_widget(button,"outputSupp");

	if(rechercher_election(id)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
		
	supprimer_elec(id);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}


void
on_GestionListe_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_menu_liste_electorale ();
	window2 = lookup_widget(button,"Admin");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}



void
on_Retourlisteele_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;
	window1 = create_Admin ();
	window2 = lookup_widget(button,"menu_liste_electorale");
  	gtk_widget_show (window1);
	gtk_widget_destroy(window2);
}


void
on_refreshData_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeviewObs");
		
	afficher_observateur(treeview,"observateur.txt");
}


void
on_triData_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
trierObs();
	GtkWidget *treeview;	
	treeview = lookup_widget(button,"treeviewObs");
		
	afficher_observateur(treeview,"triobs.txt");
	remove("triobs.txt");
}


void
on_suppObs_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"gesObs");
	window2 = create_suppObs_window ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_modifierObs_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"gesObs");
	window2 = create_modifObs () ;
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_ajouterObs_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"gesObs");
	window2 = create_ajoutObs_window ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_retourAjObs_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"ajoutObs_window");
	window2 = create_gesObs ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_addObs_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idO, *nom , *prenom , *profession , *natio , *genre , *numB , *output;
	
	char message[200];
	char id[20];


	observateur o;

	idO=lookup_widget(button,"obs1");
	nom=lookup_widget(button,"obs2");

	prenom=lookup_widget(button,"obs3");
	profession=lookup_widget(button,"obs4");
	
	natio = lookup_widget(button,"comboboxN");
	numB = lookup_widget(button,"spinNB");


	output = lookup_widget(button,"outputAdd");



	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idO)));
	o.id = atoi(id);


	strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(o.profession,gtk_entry_get_text(GTK_ENTRY(profession)));

	strcpy(o.nationality,gtk_combo_box_get_active_text(GTK_COMBO_BOX(natio)));

	if(x==1){
		strcpy(o.genre,"Homme");	
	}
	else{
		strcpy(o.genre,"Femme");
	}

	o.numB = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numB));


	sprintf(message,"Votre ajout a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
	ajouter_observateur(o);
}


void
on_radiobuttonHA_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		x=1;
	}
}


void
on_radiobuttonFA_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_nombreTotal_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog;
	dialog = create_dialogNObs ();
	gtk_widget_show(dialog);

	GtkWidget *output ;
	char message[200];

	output = lookup_widget(dialog,"nbObs");
	sprintf(message,"Le nombre total des observateurs\n\t\t\t\t est %d",nbTotal("observateur.txt"));

	gtk_label_set_text(GTK_LABEL(output),message);
}


void
on_deleteObs_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idLE , *output;
	char message[200];
	char id[20];

	idLE = lookup_widget(button,"idSupp");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idLE)));

	int idO = atoi(id);


	output = lookup_widget(button,"outputDel");

	if(rechercher_observateur(idO)){
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
		supprimer_observateur(idO);
	}
	else{
		sprintf(message,"Identifiant non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	
	}
}


void
on_retourDelObs_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"suppObs_window");
	window2 = create_gesObs ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_closePopup_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog ; 

	dialog = lookup_widget(button,"dialogNObs");
	gtk_widget_destroy(dialog);
}


void
on_ToGestionObs_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Admin");
	window2 = create_gesObs () ;
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_retourEditObs_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"modifObs");
	window2 = create_gesObs ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_saveChanges_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idO, *nom , *prenom , *profession , *natio , *genre , *numB , *output;
	
	char message[200];
	char id[20];


	observateur o;

	idO=lookup_widget(button,"obs5");
	nom=lookup_widget(button,"obs6");

	prenom=lookup_widget(button,"obs7");
	profession=lookup_widget(button,"obs8");
	
	natio = lookup_widget(button,"comboboxNE");
	numB = lookup_widget(button,"spinNBE");


	output = lookup_widget(button,"outputEdit");



	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idO)));
	o.id = atoi(id);


	strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(o.profession,gtk_entry_get_text(GTK_ENTRY(profession)));

	strcpy(o.nationality,gtk_combo_box_get_active_text(GTK_COMBO_BOX(natio)));

	if(y==1){
		strcpy(o.genre,"Homme");	
	}
	else{
		strcpy(o.genre,"Femme");
	}

	o.numB = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numB));
	
	if(rechercher_observateur(o.id)){
		
		sprintf(message,"Votre modification a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_observateur(o);
	}
	else{
		sprintf(message,"Id Non existant ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}


void
on_rechercheObs_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idO, *nom , *prenom , *profession , *natio , *genre , *numB , *radioF, *output;
	
	char message[200];
	char id[20];


	observateur o;

	idO=lookup_widget(button,"obs5");
	nom=lookup_widget(button,"obs6");

	prenom=lookup_widget(button,"obs7");
	profession=lookup_widget(button,"obs8");
	
	natio = lookup_widget(button,"comboboxNE");
	numB = lookup_widget(button,"spinNBE");

	radioF = lookup_widget(button,"radiobuttonFE");


	output = lookup_widget(button,"outputEdit");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(idO)));
	o.id = atoi(id);

	if(!rechercher_observateur(o.id)){
		sprintf(message,"ID NON EXISTANT\n");
		
    		gtk_label_set_text(GTK_LABEL(output),message);	
	}
	else{
				
		strcpy(o.nom,observateur_data(o.id).nom);

		strcpy(o.prenom,observateur_data(o.id).prenom);

		strcpy(o.profession,observateur_data(o.id).profession);

		strcpy(o.nationality,observateur_data(o.id).nationality);

		o.numB = observateur_data(o.id).numB;
			
		sprintf(message,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		gtk_label_set_text(GTK_LABEL(output),message);	
		

    		gtk_entry_set_text(GTK_ENTRY(nom),o.nom);

		gtk_entry_set_text(GTK_ENTRY(prenom),o.prenom);

		gtk_entry_set_text(GTK_ENTRY(profession),o.profession);

		int comboValue = 1;
		if(strcmp(o.nationality,"Tunisienne") == 0 ){
			comboValue = 0;
		}
		gtk_combo_box_set_active(natio,comboValue);

		gtk_spin_button_set_value(numB,o.numB);



	}
}


void
on_radiobuttonHE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		y=1;
	}
}


void
on_radiobuttonFE_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		y=2;
	}
}


void
on_RetourOBSLISTE_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"gesObs");
	window2 = create_Admin ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_ToStat_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Utilisateur");
	window2 = create_StatHatem ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_AfficherStatHatem_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	
	char msg1[100];
	char msg2[100];
	char msg3[100];


        GtkWidget *output3;
	GtkWidget *output2;
	GtkWidget *output1;
	GtkWidget *label3hatem;
	GtkWidget *label4hatem;
	GtkWidget *label5hatem;
	GtkWidget *Stat;

	output1=lookup_widget(button,"label3hatem");
	gtk_label_set_text(GTK_LABEL(output1),"outHatem1");
	sprintf(msg1," %.2f  ./.",Tauxhommes());
	gtk_label_set_text(GTK_LABEL(output1),msg1);
	output2=lookup_widget(button,"label4hatem");
	gtk_label_set_text(GTK_LABEL(output2),"outHatem2");
	sprintf(msg2," %.2f  ./.",Tauxfemmes());
	gtk_label_set_text(GTK_LABEL(output2),msg2);

output3=lookup_widget(button,"label5hatem");
	gtk_label_set_text(GTK_LABEL(output3),"outHatem3");
	sprintf(msg3," %.2f ",agemoyen());
	gtk_label_set_text(GTK_LABEL(output3),msg3);
}


void
on_RetourStatToAff_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"StatHatem");
	window2 = create_Utilisateur ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_ToBureau_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"Admin");
	window2 = create_principal ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}

bv b11;
//char tyy1[20];
int valid;
int ok;

void
on_pbtact_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *principal;
principal=lookup_widget(button,"principal");
treeview1=lookup_widget(principal,"treeviewf");

afficher_bv(treeview1);
}


void
on_pbta_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *principal;
principal=lookup_widget(button,"principal");
gtk_widget_destroy(principal);
GtkWidget *ajouter;
ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
}


void
on_pbtm_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(button,"treeviewf");;
        
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);}
           


GtkWidget *principal;
principal=lookup_widget(button,"principal");
gtk_widget_destroy(principal);
bv b;
FILE *f;
f=fopen("bureau.txt","r");
GtkWidget *modifier;
modifier = create_modifier ();
  gtk_widget_show (modifier);
GtkWidget *mentry;
mentry = lookup_widget (modifier ,"mentry");

while(fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no)!=-1){
 if (strcasecmp(b.id,b11.id)==0){

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"mentry")),b.id);

}}
fclose(f);
f=fopen("bureau.txt","r");
GtkWidget *output2,*output4, *output5,*output8 ;

if(f!=NULL)
{
while (fscanf(f,"%s %s %d %d \n",b.id,b.region,&b.ce,&b.no) != EOF)
{
if (strcmp (b.id,id) == 0){

output8 = lookup_widget(modifier, "mentry");
	gtk_entry_set_text(GTK_ENTRY(output8), b.id);

	output2 = lookup_widget(modifier, "mcb");
	gtk_entry_set_text(GTK_ENTRY(output2), b.region);

	output4 = lookup_widget(modifier, "msb1");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), b.ce);


	output5 = lookup_widget(modifier, "msb2");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), b.no);

}}

fclose(f);

}
}


void
on_pbts_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(button,"treeviewf");;
        
        gchar *id;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

            supprimer_bv(id);
	    supprimer("bureau.txt", id);}
/*GtkWidget *principal;
principal=lookup_widget(button,"principal");
gtk_widget_destroy(principal);
GtkWidget *supprimer;
supprimer = create_supprimer_bu ();
  gtk_widget_show (supprimer);*/
}



void
on_pbtstat_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *principal;
principal=lookup_widget(button,"principal");
gtk_widget_destroy(principal);
GtkWidget *statistique;
statistique = create_stat ();
  gtk_widget_show (statistique);
}


void
on_pbtc_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];

GtkWidget *treeview1;
GtkWidget *principal;
principal=lookup_widget(button,"principal");
treeview1=lookup_widget(principal,"treeviewf");
cherch = lookup_widget (button ,"pentry");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));


 chercher_bv(treeview1,ch);
}


void
on_pbtr_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(button,"principal");
	window2 = create_Admin ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_srd1_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
//supprimer_bv(b11.id);
supprimer("bureau.txt",b11.id);
GtkWidget *supprimer;
supprimer=lookup_widget(button,"supprimer_bu");
gtk_widget_destroy(supprimer);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);
}


void
on_srd2_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
supprimer=lookup_widget(button,"supprimer_bu");
gtk_widget_destroy(supprimer);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);
}


void
on_arb1_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{ok=1;
}
}


void
on_arb1__toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{ok=0;
}
}


void
on_abtc_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *region;
GtkWidget *ce;
GtkWidget *no;

GtkWidget *ajouter;


bv b;
char id1[10];
id = lookup_widget (button ,"aentry");
region = lookup_widget (button ,"acb");
ce = lookup_widget (button ,"asb1");
no = lookup_widget (button ,"asb2");

b.ce=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ce));
b.no=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(no));

strcpy(b.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(b.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));


ajouterbv(b);
ajouter=lookup_widget(button,"ajouter");
gtk_widget_destroy(ajouter);
GtkWidget *principal;
principal = create_principal ();
gtk_widget_show (principal);

}


void
on_abtr_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
ajouter=lookup_widget(button,"ajouter");
gtk_widget_destroy(ajouter);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);
}


void
on_mcheck_activate                     (GtkButton       *button,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (button)){
		valid = 1 ;
	}
}


void
on_mbtc_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *region;
GtkWidget *ce;
GtkWidget *no;

GtkWidget *modifier;


bv b;
char id1[10];
id = lookup_widget (button ,"mentry");
region = lookup_widget (button ,"mcb");
ce = lookup_widget (button ,"msb1");
no = lookup_widget (button ,"msb2");

b.ce=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ce));
b.no=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(no));

strcpy(b.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(b.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));




 if(valid==0){
modifierbv(id,b);
modifier=lookup_widget(button,"modifier");
gtk_widget_destroy(modifier);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);}


}


void
on_mbtr_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
modifier=lookup_widget(button,"modifier");
gtk_widget_destroy(modifier);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);
}


void
on_sbtact_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sbtr_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *statistique;
statistique=lookup_widget(button,"stat");
gtk_widget_destroy(statistique);
GtkWidget *principal;
principal = create_principal ();
  gtk_widget_show (principal);
}


void
on_treeviewf_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* region;
        gchar* ce;
	gchar* no;
	char ID[10];
	char a[10],b[10];


	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ sprintf(a,"%d",b11.ce); sprintf(b,"%d",b11.no);
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&region,2,&a,3,&b,-1);
strcpy(id,ID);
printf(id);
strcpy(b11.id,ID);

	}
}


void
on_button7Dec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin;
admin=lookup_widget(button,"Admin");
gtk_widget_destroy(admin);
GtkWidget *connexion;
connexion = create_Connexion ();
  gtk_widget_show (connexion);
}


void
on_Conn_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
char id[10],id1[10];
GtkWidget *cin,*mot_pass;
	cin=lookup_widget(button,"cinL");
	mot_pass=lookup_widget(button,"mdpL");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(mot_pass)));
	GtkWidget *window1,*window2,*window3;
	window1=lookup_widget(button,"Connexion");
		if (strcmp(id,"admin")==0 & strcmp(id1,"admin")==0)
{
			window2=create_Utilisateur();
			gtk_widget_show(window2);
			gtk_widget_destroy(window1);
		}
		
	
else{
window3=create_Admin();
		gtk_widget_show(window3);
		gtk_widget_destroy(window1);
}
}

