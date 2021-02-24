#include <stdio.h>



//Définition de la structure Friandise
struct Friandise{
        //3 attributs
        float prix;
        char* libelle;
        int quantite;
};


//Définition de la structure Compartiment 
struct Compartiment{
        //3 attributs
        int numero; //numéro du compartiment
        float valeur; // valeur de la piéce de monnaie
        int nombre; // nombre de piéces de monnaie
};


//tableau contenant les piéces de monnaie autorisées
float piecesAutorisees[6]={2.0,1.0,0.5,0.2,0.1,0.05};

//somme d'argent non rendue au client précedent
float sommeRestante=0;

//Tableau pour contenir la liste des friandises disponibles (à initialiser avec des variable de type Friandise). 
struct Friandise listeFriandise[100];

//pour contenir la liste des compartiments  (à initialiser avec 6 compartiments. Elle doit contenir des variable de type Compartiment)
struct Compartiment ListeCompartiments[6];



//Fonction pour vérifier si un type de friandise est toujours disponible
int estEnstock(struct Friandise f){
if (f.quantite>0)
	return 1;
	return 0;}

//Fonction pour mettre à jour le stock de friandises (dimunier le nombre de friandises
void MiseAjourStock(struct Friandise f){
	f.quantite-=1;}


//Fonction pour vérifier si on peut rendre une piéce de monnaie à partir d'un compartiment
int AutoriserRendrePiece(struct Compartiment c){
        if(c.nombre>0)
		return 1;
		return 0;}

//Fonction pour vérifier si on peut ajouter une piéce de monnaie à un compartiment
int AutoriserAjouterPiece(struct Compartiment c){
        if(c.nombre<50)
		return 1;
		return 0;}

//Fonction pour ajouter une piéce à un compartiment 
 void AjouterPiece(struct  Compartiment c){
            c.nombre+=1;}

//Fonction pour rendre une piéce de monnaie à partir d'un compartiment
void RendrePiece(struct  Compartiment c){
            c.nombre-=1;}


/*Fonction permettant de vérfier si on peut ajouter une piéce à un compartiment ou pas (selon le nombre de piéces)
retourne True si oui (nombre de piéces<50)
retourne False sinon*/
int existePlace(float piece, struct Compartiment ListeCompartiments[]){

    //on commence par trouver le compartiment relatif à la piéce, ensuite on fait la vérification
   //on utilisera quelques fonctions définies ci-dessous
    int i=0;
    for (i=0;i<6;++i){
        if (ListeCompartiments[i].valeur==piece)
            if (AutoriserAjouterPiece(ListeCompartiments[i]))
		{AjouterPiece(ListeCompartiments[i]);
                return 1;}
            else{
                printf ("Désolé, il n'y a plus de places pour cette piéce de monnaie. Essayer avec une autre piéce de monnaie\n"); 
                return 0;}
    }
}


//fonction qui vérifie l'existence d'une piece de monnaie dans la liste des piéces  autorisées
int verificationPiece(float piecesAutorisees [],float piece){
	for (int i=0;i<6;i++){
		if (piece==piecesAutorisees[i])
			return 1;}
	return 0;}

//Fonction pour gérer la saisie de piéces de monnaie par le client 
float saisieMonnaie( float piecesAutorisees [],struct Compartiment ListeCompartiments[] ){
    float somme_entree=0;//somme de l'argent entrée par le client
    
    while (1){
        //demander au client de saisir une valeur représentant une piéce de monnaie
	printf("Entrer une piéce de monnaie. Pour arreter la saisie,taper 0\n");
	float piece;
	scanf("%f",&piece);

        //Tests sur la valeur saisie
        //pour 0, on sort de la boucle et on rajoute la somme d'argent non rendue au client précedent
        
	if (piece==0){
            somme_entree+=sommeRestante ;
            return somme_entree;
		}
        
	//si l'utilisateur saisit une valeur inchoérante, on retourne 0
	else if (verificationPiece(piecesAutorisees,piece)){
            printf("entree invalide, réessayer une autre fois\n");
	}
        
	//sinon (valeur autorisée), on vérifie si on peut la rajouter à un compartiment (on appelle la fonction existePlace)    
        else{
            if (existePlace(piece,ListeCompartiments)==1)
                somme_entree+=piece;

    }
}

}


//fonction qui demande à l'utilisateur de saisir un libelle, elle retourne le libelle siaisi
char* saisieLibelle(){

    char* libelle;
    printf("entrer le libelle de la friandise désirée\n");
    scanf("%s",libelle);
    return libelle;}

    

//fonction pour vérifier si un libelle correspond à un  libellé des friandises existantes
//retourne True si oui, sinon False
int existLibelle(char* libelle,struct Friandise listeFriandise[],int size ){
int i=0;
    for (i=0;i<size;i++)
    {if (listeFriandise[i].libelle==libelle)
            return 1;}
    return 0;}




//fonction pour vérifier s'il y'a des friandises disponibles dans le stock à partir d'un libelle donnée
//retourne True si oui, sinon False
int friandiseDisponible(char* libelle,struct Friandise listeFriandise[],int size){
    
	int i=0;
	for (i=0;i<size;++i){
        if (listeFriandise[i].libelle==libelle){
            if (estEnstock(listeFriandise[i])==1)
                return 1;
        return 0;}
	}
}

//fonction pour déterminer le prix d'une friandise correspondante à un libellé donné 
float prixFriandise(char* libelle,struct Friandise listeFriandise[],int size){
        //parcourir le tableau, faire le test et retourner le prix
        
	int i=0;
        for (i=0;i<size;++i){
              if (listeFriandise[i].libelle==libelle){

		return listeFriandise[i].prix;}}}

void mettreAjourStockFriandises(char* libelle,struct Friandise listeFriandise[],int size){
        //parcourir le tableau, faire le test et mettre à jour le stock de friandise
                
	        int i=0;
        for (i=0;i<size;++i){
              if (listeFriandise[i].libelle==libelle){

	MiseAjourStock(listeFriandise[i]);
                return ;}}}

//fonction pour rendre l'argent au client
void RendreArgent(float entree, float prix,struct Compartiment ListeCompartiments[]){

//3 cas possibles:
//prix égal à l'entrée
    if(entree==prix){
        printf("Pas de rendu\n");
        return;}
//prix supérieur à l'entrée
	float sommeArendre=0;
    if (entree<prix){
        printf("Désolé, l'argent que vous avez entrée est inférieure au prix\n");
        sommeArendre=entree;
    }
//prix inférieur à l'entrée  
    else
        sommeArendre=entree-prix ;

//Boucle pour rendre la monnaie
//Priorité aux piéces de monnaies les plus grandes
//on doit parcourir le tableau des compartiments 
    while(sommeArendre>=0.05){
	    int i;
	    for (i=0;i<6;i++){
            if(sommeArendre>ListeCompartiments[i].valeur){
                if(AutoriserRendrePiece(ListeCompartiments[i]))//s'il y'a des piéces
		{RendrePiece(ListeCompartiments[i]); //rendre une piéce et mettre à jour le nombre de piéces
                    sommeArendre-=ListeCompartiments[i].valeur;}
    sommeRestante=sommeArendre; //garder la somme d'argent au client suivant
    }
	    }
    		}
			}



//fonction pour réaliser l'achat d'une friandise pour un seul client
//pour pouvoir l'utiliser il faut initialiser correctement  les variables globales défines au début de fichier
void traitementAchat(struct Compartiment ListeCompartiments[],struct Friandise listeFriandise[],int size){
    
    float somme_entree=saisieMonnaie(piecesAutorisees,ListeCompartiments)+sommeRestante; //entrer les piéces d'argent et ajouter la somme due au client  précedent
    char* libelle=saisieLibelle() ;//saisir le libelle
    
    //vérifier si le libelle saisi existe et que la  friandise est disponible
    if (existLibelle(libelle,listeFriandise,size) && friandiseDisponible(libelle,listeFriandise,size))
        RendreArgent(somme_entree,prixFriandise(libelle,listeFriandise,size),ListeCompartiments);
    else{
        if (existLibelle(libelle,listeFriandise,size)==0)
            printf("Désolé, le libellé saisi n'existe pas");
        else
            printf("Désolé, cette friandise n'est plus disponible");
    }
}



int main(){
	return 0;
}
