#ifndef Avis_h
#define Avis_h

#include <iostream>
#include <stdio.h>
#include <cassert>
#include <string>

using namespace std;

/**
    @brief Initialisation de la classe Avis permettant d'emettre un avis et/ou un commentaire sur un profile.
*/

class Avis 
{
    private:
    /** @brief declartion du username l'utilisateur.*/
    string ausername; 
     /** @brief declaration du booleen like */
    bool like; 
     /** @brief declaration du commentaire de l'utilisateur.*/
    string commentaire;   
   
    public:
    /** 
    @brief constructeur avec des valeur donnees obligatoires et valeur facultatives.  
    @param nusername :username de l'utilisateur
    @param like : si l'utilisateur a like ou non
    @param ncommentaire :commentaire de l'utilisateur 
    */
    Avis(const string nusername, const bool nlike, const string ncommentaire);
    /** @brief destructeur */
    ~Avis(); 

    /** @brief retourne le username de l'utilisateur */
    string getUsername() const;
    /** @brief retourne si il y a un like de l'utilisateur */
    bool getLike() const;
    /** @brief retourne le commentaire de l'utilisateur */
    string getCommentaire() const;
   
    /** @brief change le statue du like de l'utilisateur*/     
    void setLike();                      
    /** @brief supprime un commentaire de l'utilisateur*/
    void deleteCommentaire();  
                            
};
#endif
