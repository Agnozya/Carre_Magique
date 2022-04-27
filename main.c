#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5


//Procédures
void IniTab(int n_Tab2d[TAILLE][TAILLE]);
void Placement(int n_Tab2d[TAILLE][TAILLE]);
void Affichage(int N_tab2d[TAILLE][TAILLE]);




int main()
{
   int n_Tab2d[TAILLE][TAILLE]; //Création du tableau à deux dimensions qui sera utilisé pour créer et afficher le carré magique

   IniTab(n_Tab2d);             //Execution de la procédure qui permet d'initialiser le tableau à deux dimensions
   Placement(n_Tab2d);          //Execution de la procédure qui rempli de le tableau
   Affichage(n_Tab2d);          //Execution de la procédure qui affiche le tableau à l'écran

    return 0;
}

/*******************************************************************************
BUT: Initialiser le tableau à deux dimensions

ENTREE: Le tableau à deux dimensions non initialisé

SORTIE: Le tableau à deux dimensions initialiser

Description: Cette procédure permet d'initialiser un tableau à deux dimensions en le remplissant avec des zéros
*******************************************************************************/

void IniTab (int n_Tab2d[TAILLE][TAILLE]){

    int n_i=0, n_j=0;       //Variables afin d'initialiser la matrice

    for(n_i=0;n_i<TAILLE;n_i++){  //Double bloucle pour remplacer chaques cellules de la matrice par un zéro
        for(n_j=0;n_j<TAILLE;n_j++){
            n_Tab2d[n_i][n_j]=0;
        }
    }
}

/*******************************************************************************
BUT: Remplire le tableau pour en faire un carré magique

ENTREE: Le tableau à deux dimensions initialisé avec des zéros

SORTIE: Le tableau à deux dimensions rempli pour en faire un carré magique

Description: Cette procédure rempli le tableau selon on ordre précis et un placement en fonction de la constante
*******************************************************************************/

void Placement (int n_Tab2d[TAILLE][TAILLE]){

    int n_nb=1, n_l=((TAILLE/2)-1), n_c=(TAILLE/2);     //Variables du nombres à mettre dans la cellule, de la ligne et de la colonne. Valeurs de n_l et de n_c pour etre un peu au dessus du milieu du tableau
    n_Tab2d[n_l][n_c]=n_nb;                             //Mise en place du premier nombre dans le tableau (1)
    do{                                                 //Boucle principal qui s'arrete lorsque le dernier chiffre est rentré (TAILLE²)
        n_nb++;                                         //Augmentation du nombre à placer
        n_l--;                                          //Reduction de ligne et augmentation de la colonne afin d'avancer à la case en haut à droite
        n_c++;
        if(n_l<0 || n_c==(TAILLE) || n_c<0){            //Permet d'avoir un tableau sphérique en modifiant la ligne ou la colonne
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


        while(n_Tab2d[n_l][n_c]!=0){                    //Boucle de vérification permettant de se déplacer en haut à droite si la case à déjà était modifié
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
BUT: Afficher le carré magique

ENTREE: Le tableau à deux dimensions complété

SORTIE: Affichage du tableau à l'écran

Description: Cette procédure permet d'afficher le carré magique à l'écran
*******************************************************************************/

void Affichage (int n_Tab2d[TAILLE][TAILLE]){

    int n_i=0, n_j=0;                   //Variables pour la double boucle afin de parcourir l'integralité du tableau

    for(n_i=0;n_i<TAILLE;n_i++){
        printf("\n");                   //Retour à la ligne après avoir afin toute une ligne du tableau
        for(n_j=0;n_j<TAILLE;n_j++){
            if(n_Tab2d[n_i][n_j]<10){   //Mise en place d'un espace pour les chiffres afin qu'ils soient alignés
                printf(" ");
            }
            printf("%d ",n_Tab2d[n_i][n_j]); //Affichage de la cellule avec un espace à la fin pour ne pas avoir les chiffres collés ensembles
        }
    }
}
