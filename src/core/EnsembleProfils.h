#ifndef EnsembleProfils_h
#define EnsembleProfils_h

#include "Profil.h"

using namespace std;

class EnsembleProfils
{
    private :
        vector<Profil> profils;

    public :

        /**
        @brief Destructeur 
        */
        ~EnsembleProfils();

        /**
        @brief Fonction permettant d'ajouter un profil à la liste des profils
        @param p : Référence sur le profil à ajouter
        */ 
        void addProfil(const Profil &p);

        /**
        @brief Fonction permettant de supprimer un profil de la liste des profils
        @param username : Nom du profil à supprimer
        */ 
        void deleteProfil(const string username);

        /**
        @brief Fonction permettant de savoir si un username est déjà utilisé
        @param username : username a comparer avec ceux déjà existants dans la liste de profils
        */
        bool existeUsername(const string username);

        /**
        @brief Fonction permettant de savoir si une adresse mail est déjà utilisée
        @param mail : adresse mail a comparer avec celles déjà existantes dans la liste de profils
        */
        bool existeMail(const string mail);

        /** 
        @brief Matching par type de sport 
        @param tab : liste de type de sport de l'utilisateur 
        @param username : username de l'utilisateur faisant la recherche  
        */ 
        vector<string> matchTypeSport(const Profil &profil);

        /**
        @brief Matching par age 
        @param minAge : age minimale de matching
        @param maxAge : age maximale de matching
        @param username : username de l'utilisateur faisant la recherche
        */
        vector<string> matchAge(const int minAge, const int maxAge, string username);

        /** 
        @brief Matching par ville 
        @param ville : ville recherchée par l'utilisateur
        @param username : username de l'utilisateur faisant la recherche
        */
        vector<string> matchVille(const string ville, const string username);

        /** 
        @brief Matching par sexe
        @param sexe : sexe recherché par l'utilisateur 
        @param username : username de l'utilisateur faisant la recherche
        */
        vector<string> matchSexe(const string sexe, const string username);
        
        /**
        @brief Recherche les profils correspondants aux critères choisis par l'utilisateur
        @param tabSport : liste des sports de l'utilisateur
        @param minAge : age minimale de matching
        @param maxAge : age maximale de matching
        @param ville : ville recherchée par l'utilisateur
        @param sexe : sexe recherché par l'utilisateur 
        @param username : username de l'utilisateur faisant la recherche
        */
        vector<string> matching(const Profil & profil, const int minAge, const int maxAge, const string ville, const string sexe);

        /**
        @brief Recherche les profils correspondants aux critères choisis par l'utilisateur sans prendre en compte les types de sport
        @param minAge : age minimale de matching
        @param maxAge : age maximale de matching
        @param ville : ville recherchée par l'utilisateur
        @param sexe : sexe recherché par l'utilisateur 
        @param username : username de l'utilisateur faisant la recherche
        */
        vector<string> matchingASV(const int minAge, const int maxAge, const string sexe, const string ville, const string username);

        /**
        @brief Compare 2 listes et rend une liste avec les memes valeurs
        @param tab1 : 1er tableau
        @param tab2 : 2ème tableau
        */
        vector<string> compareMatchs(const vector<string> tab1, const vector<string> tab2);
        
        /**
        @brief Enleve du tableau tabmatchs les valeurs qui ne sont pas présentes dans tab
        @param tabmatchs : 1er tableau
        @param tab : 2ème tableau
        */
        void triEnleve(vector<string> tabmatchs, const vector<string> tab);

        /**
        @brief Operateur[] pour pouvoir faire par exemple profils[0].getUsername()
        @param i : index de la liste
        */
        Profil & operator[](int i);

        /**
        @brief Test de regression teste toutes les fonctions de la classe
        */
        void testRegression();
};

#endif