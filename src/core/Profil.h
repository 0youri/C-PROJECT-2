#ifndef Profil_h
#define Profil_h

#include "Avis.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** 
	@brief La classe Profil contient une chaine de caractères qui est username, une chaine de caractères qui est adresse mail, 
    une chaine de caractères qui est password, avec le nom, le prenom, l'age, le sexe, la ville, le portable , l'instagram, 
    le snapchat, le facebook et le tiktok (les reseaux sont facultatifs), une chaine de caractères qui est type de profil, 
    un tableau de chaines de caractères qui est type de sport, une chaine de caractères qui est lien vers une photo,
    un tableau des liens sur Avis, un tableau de chaines de caractères qui est liste de followers, 
    un tableau de chaines de caractères qui est liste de following
*/
class Profil
{
private:
	/** @brief Définition d'une chaine de caractères */
    string username;
    /** @brief Définition d'une chaine de caractères */
    string mail;
    /** @brief Définition d'une chaine de caractères */
    string password;
    /** @brief declartion du nomde l'utilisateur */
    string nom; 
    /** @brief declaration du prenom de l'utilisateur */
    string prenom;
    /** @brief declaration d l'age de l'utilisateur */  
    int age;    
    /** @brief dclaration du sexe de l'utilisateur */
    string sexe;    
    /** @brief declaration de la ville de l'utilisateur.*/
    string ville;   
     /** @brief declaration du numero de telephone de l'utilisateur */
    string portable;
    /** @brief declaration de l'instagram de l'utilisateur */
    string ig;  
    /** @brief declaration du snapchat de l'utilisateur */
    string sc;  
    /** @brief declaration du facebook de l'utilisateur */
    string fb;  
    /** @brief declaration du tiktok de l'utilisateur */
    string tt;  
    /** @brief Définition d'une chaine de caractères qui est type de profil  */
    string type_profil;
    /** @brief Définition d'un tableau de chaines de caractères qui est type de sport  */
    vector<string> type_sport;
    /** @brief Définition d'une chaine de caractères qui est lien vers une photo  */
    string photo;
    /** @brief Définition d'un tableau des liens sur Avis  */
    vector<Avis> avis;
    /** @brief Définition d'un tableau de chaines de caractères qui est liste de followers  */
    vector<string> followers;
    /** @brief Définition d'un tableau de chaines de caractères qui est liste de following  */
    vector<string> following;
    
    /** @brief Retourne une chaine de caractères contenant le mot de passe */
    string getPassword() const;

public:
    /** 
	@brief Constructeur par défaut et avec des valeurs données
    @param nusername : définition d'une chaine de caractères qui est username d'un nouveau utilisateur
    @param nmail : définition d'une chaine de caractères qui est adresse mail d'un nouveau utilisateur
    @param npassword : définition d'une chaine de caractères qui est mot de passe d'un nouveau utilisateur
    @param nnom :nom de l'utilisateur
    @param nprenom :prenom de l'utilisateur 
    @param nage :age de l'utilisateur 
    @param nsexe :sexe de l'utilisateur 
    @param nville :ville de l'utilisateur 
    @param nportable :numero de portable de l'utilisateur 
    @param nig :instagram de l'utilisateur 
    @param nsc :snapchat de l'utilisateur 
    @param nfb :facebook de l'utilisateur  
    @param ntt :tiktok de l'utilisateur         
    @param ntype_profil : définition d'une chaine de caractères qui est type de profil
    @param ntype_sport : définition  d'un tableau de chaines de caractères qui est type de sport, par défaut NULL
    @param nphoto : définition d'une chaine de caractères qui est lien vers une photo, par défaut NULL
	 */
    Profil(const string nusername, const string nmail, const string npassword, const string nnom,const string nprenom, const int nage, 
    const string nsexe,const string nville, const string nportable, const string nig, const string nsc , const string nfb, 
    const string ntt, const string ntype_profil, const vector<string> ntype_sport, const string nphoto);
    
    /** @brief Destructeur */
    ~Profil();
    
    /** @brief Retourne une chaine de caractères contenant username */
    string getUsername() const;
    /** @brief Retourne une chaine de caractères contenant l'adresse mail */
    string getMail() const;
    /** @brief retourne le Nom de l'utilisateur    */
    string getNom() const; 
    /** @brief retourne le Prenom de l'utilisateur    */
    string getPrenom() const;
    /** @brief retourne l'age de l'utilisateur    */
    int getAge() const;
    /** @brief retourne le Sexe de l'utilisateur    */
    string getSexe() const;
    /** @brief retourne la ville de l'utilisateur    */
    string getVille() const;
    /** @brief retourne le numero de portable de l'utilisateur    */
    string getPortable() const;
    /** @brief retourne l'instagram' de l'utilisateur    */
    string getIG() const;
    /** @brief retourne le snapchat de l'utilisateur    */
    string getSC() const;
    /** @brief retourne le facebook de l'utilisateur    */
    string getFB() const;
    /** @brief retourne le tiktok de l'utilisateur    */
    string getTT() const;
	/** @brief Retourne le type du profil */
    string getTypeProfil() const;
    /** @brief Retourne le tableau de type de sport */
    vector<string> getTypeSport() const;
    /** @brief Retourne le lien de la photo */
    string getPhoto() const;
    /** @brief Retourne le tableau de followers */
    vector<string> getFollowers() const;
    /** @brief Retourne le type de following */
    vector<string> getFollowing() const;
    /** @brief Retourne le tableau des liens sur Avis */
    vector<Avis> getAvis() const;

    /** 
	@brief Changement d'username
    @param nusername : définition d'une chaine de caractères qui est un nouveau username d'utilisateur
    */
    void setUsername(const string nusername);
    /** 
	@brief Changement de mail
    @param nmail : définition d'une chaine de caractères qui est une nouvelle adresse mail d'utilisateur
    @param apassword : définition d'une chaine de caractères qui est mot de passe actuel mail d'utilisateur
    */
    bool setMail(const string nmail, const string apassword);
    /** 
	@brief Changement de mot de passe
    @param npassword : définition d'une chaine de caractères qui est un nouveau mot de passe d'utilisateur
    @param apassword : définition d'une chaine de caractères qui est mot de passe actuel mail d'utilisateur
    */
    bool setPassword(const string npassword, const string apassword);
    /**
    @brief change le Nom de l'utilisateur
    @param nnom : le nouveaux nom de l'utilisateur    
    */
    void setNom(const string nnom);
    /**
    @brief change le prenom de l'utilisateur
    @param nprenom : le nouveaux prenom de l'utilisateur 
    */
    void setPrenom(const string nprenom);
    /**
    @brief change l'age de l'utilisateur
    @param nage : le nouvel age de l'utilisateur    
    */
    void setAge(const int nage);
    /**
    @brief change le sexe de l'utilisateur
    @param nsexe : le nouveaux sexe de l'utilisateur    
    */
    void setSexe(const string nsexe);
    /** 
    @brief change la ville de l'utilisateur
    @param nville : la nouvelle ville de l'utilisateur    
    */
    void setVille(const string nville);
    /**
    @brief change le numero de portable de l'utilisateur
    @param nportable : le nouveaux numero de portable de l'utilisateur    
    */
    void setPortable(const string nportable);
    /** 
    @brief change l'instagram de l'utilisateur
    @param nig : le nouvel instagram de l'utilisateur    
    */
    void setIG(const string nig);
    /** 
    @brief change le snapchat de l'utilisateur
    @param nsc : le nouveaux snapchat de l'utilisateur    
    */
    void setSC(const string nsc);
    /** 
    @brief change le facebook de l'utilisateur
    @param nfb : le nouveaux facebook de l'utilisateur   
    */
    void setFB(const string nfb);
    /** 
    @brief change le tiktok de l'utilisateur
    @param ntt : le nouveaux tiktok de l'utilisateur    
    */
    void setTT(const string ntt);
    /**
    @brief Changement de type du profil 
    @param ntype_profil : définition d'une chaine de caractères qui est nouveau type de profil
    */
    void setTypeProfil(const string ntype_profil);
    /**
    @brief Changement de lien vers la photo
    @param nphoto : définition d'une chaine de caractères qui est nouvelle lien vers une photo
    */
    void setPhoto(const string nphoto);
    /**
    @brief Ajout d'un type de sport dans le tableau de type de sport
    @param ntype_sport : définition d'une chaine de caractères qui est nouveau type de sport à ajouter
    */
    void ajouterTypeSport(const string ntype_sport);
    /**
    @brief Ajout d'une nouvelle personne avec son username dans la liste de followers
    @param ausername : définition d'une chaine de caractères qui est username de la personne à ajouter
    */
    void ajouterFollowers(const string ausername);
    /**
    @brief Ajout d'une nouvelle personne avec son username dans la liste de following
    @param ausername : définition d'une chaine de caractères qui est username de la personne à ajouter
    */
    void ajouterFollowing(const string ausername);
    
    /**
    @brief Création d'un nouveau avis dans le tableau des liens sur Avis
    @param username : définition d'une chaine de caractères qui est username de la personne qui a laissé avis
    @param like : définition d'un booléen, si true = liké si false = pas liké
    @param commentaire : définition d'une chaine de caractères qui est un commantaire de la personne qui a laissé avis
    */
    void creationAvis(const string ausername, const bool like, const string commentaire);

    /**
    @brief Suppression d'un type du sport dans le tableau de type de sport
    @param dtype_sport : définition d'une chaine de caractères qui est un type de sport à supprimer
    */
    void deleteTypeSport(const string dtype_sport);
    /**
    @brief Suppression d'un followers dans le tableau de followers
    @param dfollowers : définition d'une chaine de caractères qui est username de la personne à supprimer
    */
    void deleteFollowers(const string dfollowers);
    /**
    @brief Suppression d'un following dans le tableau de following
    @param dfollowing : définition d'une chaine de caractères qui est username de la personne à supprimer
    */
    void deleteFollowing(const string dfollowing);
    /**
    @brief Suppression du profil 
    @param apassword : définition d'une chaine de caractères qui est mot de passe du profil pour pouvoir identifier la personne 
    et supprimer le profil
    */
    void deleteProfil(const string apassword);
    /**
    @brief Test de regression teste toutes les fonctions de la classe
    */
    void testRegression();

};

#endif
