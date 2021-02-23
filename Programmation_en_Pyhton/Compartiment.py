class Compartiment():
    
    #Cette classe posséde trois attributs:
        #numero: le numéro du compartiment: 0,1,2...
        #valeur: valeur des piéces de monnaies relatives: 2 euros, 1 euro...
        #quantite: nombre de piéces de monnaies dans le distributeur

    #Constructeur de la classe 
    def __init__(self, numero,valeur,quantite):
        self.numero=numero
        self.valeur=valeur
        self.quantite=quantite

    #Méthode pour ajouter une piéce au compartiment
    def ajouterPiece(self):
        if (self.quantite<50):
            self.quantite+=1
            retutn True
         return False

     #Méthode pour rendre une piéce de monnaie
    def rendrePiece(self):
        if (self.quantite>0):
            self.quantite-=1
            return True
        return False

    
        
