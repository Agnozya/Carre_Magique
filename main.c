#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5


//Proc�dures
void IniTab(int n_Tab2d[TAILLE][TAILLE]);
void Placement(int n_Tab2d[TAILLE][TAILLE]);
void Affichage(int N_tab2d[TAILLE][TAILLE]);




int main()
{
   int n_Tab2d[TAILLE][TAILLE]; //Cr�ation du tableau � deux dimensions qui sera utilis� pour cr�er et afficher le carr� magique

   IniTab(n_Tab2d);             //Execution de la proc�dure qui permet d'initialiser le tableau � deux dimensions
   Placement(n_Tab2d);          //Execution de la proc�dure qui rempli de le tableau
   Affichage(n_Tab2d);          //Execution de la proc�dure qui affiche le tableau � l'�cran

    return 0;
}

/*******************************************************************************
BUT: Initialiser le tableau � deux dimensions

ENTREE: Le tableau � deux dimensions non initialis�

SORTIE: Le tableau � deux dimensions initialiser

Description: Cette proc�dure permet d'initialiser un tableau � deux dimensions en le remplissant avec des z�ros
*******************************************************************************/

void IniTab (int n_Tab2d[TAILLE][TAILLE]){

    int n_i=0, n_j=0;       //Variables afin d'initialiser la matrice

    for(n_i=0;n_i<TAILLE;n_i++){  //Double bloucle pour remplacer chaques cellules de la matrice par un z�ro
        for(n_j=0;n_j<TAILLE;n_j++){
            n_Tab2d[n_i][n_j]=0;
        }
    }
}

/*******************************************************************************
BUT: Remplire le tableau pour en faire un carr� magique

ENTREE: Le tableau � deux dimensions initialis� avec des z�ros

SORTIE: Le tableau � deux dimensions rempli pour en faire un carr� magique

Description: Cette proc�dure rempli le tableau selon on ordre pr�cis et un placement en fonction de la constante
*******************************************************************************/

void Placement (int n_Tab2d[TAILLE][TAILLE]){

    int n_nb=1, n_l=((TAILLE/2)-1), n_c=(TAILLE/2);     //Variables du nombres � mettre dans la cellule, de la ligne et de la colonne. Valeurs de n_l et de n_c pour etre un peu au dessus du milieu du tableau
    n_Tab2d[n_l][n_c]=n_nb;                             //Mise en place du premier nombre dans le tableau (1)
    do{                                                 //Boucle principal qui s'arrete lorsque le dernier chiffre est rentr� (TAILLE�)
        n_nb++;                                         //Augmentation du nombre � placer
        n_l--;                                          //Reduction de ligne et augmentation de la colonne afin d'avancer � la case en haut � droite
        n_c++;
        if(n_l<0 || n_c==(TAILLE) || n_c<0){            //Permet d'avoir un tableau sph�rique en modifiant la ligne ou la colonne
            if(n_l<0){
                n_l=(TAILLE-1);
            }
            if(n_c<0){
                    n_c=(TAILLE-1);
            }
            if(n_c==TAILLE){
                    n_c=0;
            }
        }


        while(n_Tab2d[n_l][n_c]!=0){                    //Boucle de v�rification permettant de se d�placer en haut � droite si la case � d�j� �tait modifi�
            n_l--;
            n_c--;
            if(n_l<0 || n_c==(TAILLE) || n_c<0){
                if(n_l<0){
                    n_l=(TAILLE-1);
                }
                if(n_c<0){
                        n_c=(TAILLE-1);
                }
                if(n_c==TAILLE){
                        n_c=0;
                }
            }
        }
        n_Tab2d[n_l][n_c]=n_nb;                         //Mise en place de du nombre dans la case disponible
    }while(n_nb != (TAILLE*TAILLE));                    //Fin de la boucle principale
}

/*******************************************************************************
BUT: Afficher le carr� magique

ENTREE: Le tableau � deux dimensions compl�t�

SORTIE: Affichage du tableau � l'�cran

Description: Cette proc�dure permet d'afficher le carr� magique � l'�cran
*******************************************************************************/

void Affichage (int n_Tab2d[TAILLE][TAILLE]){

    int n_i=0, n_j=0;                   //Variables pour la double boucle afin de parcourir l'integralit� du tableau

    for(n_i=0;n_i<TAILLE;n_i++){
        printf("\n");                   //Retour � la ligne apr�s avoir afin toute une ligne du tableau
        for(n_j=0;n_j<TAILLE;n_j++){
            if(n_Tab2d[n_i][n_j]<10){   //Mise en place d'un espace pour les chiffres afin qu'ils soient align�s
                printf(" ");
            }
            printf("%d ",n_Tab2d[n_i][n_j]); //Affichage de la cellule avec un espace � la fin pour ne pas avoir les chiffres coll�s ensembles
        }
    }
}
