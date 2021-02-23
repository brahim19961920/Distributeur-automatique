class Friandise:
    
    #Constructeur
    def __init__(self,prix,libelle,quantite):
         
        self.prix=prix
        self.libelle=libelle
        self.quantite=quantite
    
    #Méthode pour vérifier si la friandise est en stock
    #retourne True si la friandise est en stock, sinon, False
    def estEnStock(self):
        if(self.quantite>0):
            return True
        return False
    
    #Méthode pour mettre à jour le stock aprés un achat
    def MiseAjourStock(self):
        if (self.estEnStock()):
            self.quantite-=1


