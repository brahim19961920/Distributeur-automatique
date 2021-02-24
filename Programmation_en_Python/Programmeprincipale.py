#importer les deux classes Friandise et Compartiment pour pouvoir les utiliser
import Compartiment
import Friandise

#Initialisations

#Liste contenant les piéces de monnaie autorisées
global piecesAutorisees
piecesAutorisees=[2,0,1.0,0.5,0.2,0.1,0.05]

#Liste pour contenir la liste des friandises disponibles (à initialiser avec des variable de type Friandise). 
global listeFriandises
listeFriandises=[]

#Liste pour contenir la liste des compartiments  (à initialiser avec 6 compartiments. Elle doit contenir des variable de type Compartiment)
global ListeCompartiments
ListeCompartiments=[]

#Somme d'argent non rendue au client précedent
global SommeRestante
SommeRestante=0

#Fonction permettant de vérfier si on peut ajouter une piéce à un compartiment ou pas (selon le nombre de piéces)
#retourne True si oui (nombre de piéces<50)
#retourne False sinon
def existePlace(piece):

    #on commence par trouver le compartiment relatif à la piéce, ensuite on fait la vérification
    #on utilisera quelques méthodes de la classe Compartiment
    
    for compartiment in ListeCompartiments:
        if compartiment.valeur==piece:
            if (compartiment.AutoriserAjouterPiece()):
                compartiment.AjouterPiece()
                return True
            else:
                print ("Désolé, il n'y a plus de places pour cette piéce de monnaie. Essayer avec une autre piéce de monnaie\n") 
                return False

#Fonction pour gérer la saisie de piéces de monnaie par le client 
def saisieMonnaie():
    somme_entree=0#somme de l'argent entrée par le client
    
    while (True):
        #demander au client de saisir une valeur représentant une piéce de monnaie
        piece=float(input("Entrer une piéce de monnaie. Pour arreter la saisie,taper 0\n"))

        #Tests sur la valeur saisie

        #pour 0, on sort de la boucle et on rajoute la somme d'argent non rendue au client précedent
        if (piece==0):
            somme_entree+=sommeRestante 
            return somme_entree

        #si l'utilisateur saisit une valeur inchoérante, on retourne 0
        elif (piece not in piecesAutorisees):
            print("entree invalide, réessayer une autre fois\n")
        
        #sinon (valeur autorisée), on vérifie si on peut la rajouter à un compartiment (on appelle la fonction existePlace)    
        else:
            if existePlace():
                somme_entree+=piece

#fonction qui demande à l'utilisateur de saisir un libelle, elle retourne le libelle siaisi
def saisieLibelle():
    libelle=input("entrer le libelle de la friandise désirée\n")
    return libelle


#fonction pour vérifier si un libelle correspond à un  libellé des friandises existantes
#retourne True si oui, sinon False
def existLibelle(libelle,listeFriandise):
    for friandise in listeFriandise:
        if friandise.libelle==libelle:
            return True 
    return False

#fonction pour vérifier s'il y'a des friandises disponibles dans le stock à partir d'un libelle donnée
#retourne True si oui, sinon False
def friandiseDisponible(libelle,listeFriandise):
    for friandise in listeFriandise:
        if friandise.libelle==libelle:
            if friandise.estEnStock():
                return True 
        return False

# fonction pour déterminer le prix d'une friandise correspondante à un libellé donné 
def prixFriandise(libelle,listeFriandise):
        #parcourir le tableau, faire le test et retourner le prix
        for friandise in listeFriandise:
            if friandise.libelle==libelle:
                return friandise.prix


def mettreAjourStockFriandises(libelle,listeFriandise):
        #parcourir le tableau, faire le test et mettre à jour le stock de friandise
        for friandise in listeFriandise:
            if friandise.libelle==libelle:
                friandise.MiseAjourStock()
                return 

#fonction pour rendre l'argent au client
def RendreArgent(entree,prix):

#3 cas possibles:
#prix égal à l'entrée
    if(entree==prix):
        print("Pas de rendu\n")
        return
#prix supérieur à l'entrée

    if (entree<prix):
        print("Désolé, l'argent que vous avez entrée est inférieure au prix\n")
        sommeArendre=entree

#prix inférieur à l'entrée  
    else:
        sommeArendre=entree-prix 

#Boucle pour rendre la monnaie
#Priorité aux piéces de monnaies les plus grandes
#on doit parcourir le tableau des compartiments 
    while(sommeArendre>=0.05):
        for compartiment in ListeCompartiments():
            if(sommeArendre>compartiment.valeur):#
                if(compartiment.AutoriserRendrePiece()):#s'il y'a des piéces
                    compartiment.Rendre.Piece()#rendre une piéce et mettre à jour le nombre de piéces
                    sommeArendre-=compartiment.valeur
    sommeRestante=sommeArendre#garder la somme d'argent au client suivant



#fonction pour réaliser l'achat d'une friandise pour un seul client
#pour pouvoir l'utiliser il faut initialiser correctement  les variables globales défines au début de fichier
def traitementAchat():
    
    somme_entree=saisieMonnaie()+sommeRestante#entrer les piéces d'argent et ajouter la somme due au client  précedent
    libelle=saisieLibelle()#saisir le libelle
    
    #vérifier si le libelle saisi existe et que la  friandise est disponible
    if (existLibelle(libelle,listeFriandise) and friandiseDisponible(libelle,listeFriandise)):
        RendreArgent(somme_entree,prixFriandise(libelle,listeFriandise))
    else: 
        if (existLibelle(libelle,listeFriandise)==0):
            print("Désolé, le libellé saisi n'existe pas")
        else:
            print("Désolé, cette friandise n'est plus disponible")
