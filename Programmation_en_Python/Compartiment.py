class Compartiment():
    
    #Cette classe posséde trois attributs:
        #numero: le numéro du compartiment: 0,1,2...
        #valeur: valeur des piéces de monnaies relatives: 2 euros, 1 euro...
        #nombre: nombre de piéces de monnaies dans le distributeur

    #Constructeur de la classe 
    def __init__(self, numero,valeur,nombre):
        self.numero=numero
        self.valeur=valeur
        self.nombre=nombre
    
    #Méthode pour vérifier si on peut ajouter une piéce à un compartiment
    def AutoriserAjouterPiece(self):
        return(self.nombre<50)

    #Méthode pour vérifier si on peut rendre une piéce à partir d'un compartiment
    def AutoriserRendrePiece(self):
        return(self.nombre>0)

    #Méthode pour ajouter une piéce au compartiment
    def AjouterPiece(self):
            self.nombre+=1

     #Méthode pour rendre une piéce de monnaie
    def RendrePiece(self):
            self.nombre-=1

    
        
