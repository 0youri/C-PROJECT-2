#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "../core/EnsembleProfils.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Classe de fenetre d'application avec tous les outils de Qt 
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur par défaut
    */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructeur
    */
    ~MainWindow();

private slots:
    // accueil
    /**
     * @brief Fonction se déclenche lors d'appuie sur le bouton SE CONNECTER
     * et affiche la page de recherche
    */
    void on_pushButton_CONNECT_clicked();
    /**
     * @brief Fonction se déclenche lors d'appuie sur le bouton S'INSCRIRE
     * et affiche la page d'inscription 
    */
    void on_pushButton_SUBSCRIBE_clicked();
    /**
     * @brief Fonction qui déclenche lors d'appuie sur le bouton ANNULER
     * et revient sur la page de connexion
    */
    void on_button_ANNULER_clicked();

    // subscribe
    /**
     * @brief Fonction qui déclenche  lors d'appuie sur le bouton S'INSCRIRE
     * et affiche la page d'accueil si l'utilisateur a réussi à s'incrire
    */
    void on_button_SUBSCRIBE_clicked();
    /**
     * @brief Fonction vérifie l'état du checkBox
     * @param checked : état du checkBox (true/false)
    */
    void on_checkBox_Portable_clicked(bool checked);
    /**
     * @brief Fonction vérifie l'état du checkBox
     * @param checked : état du checkBox (true/false)
    */
    void on_checkBox_IG_clicked(bool checked);
    /**
     * @brief Fonction vérifie l'état du checkBox
     * @param checked : état du checkBox (true/false)
    */
    void on_checkBox_SC_clicked(bool checked);
    /**
     * @brief Fonction vérifie l'état du checkBox
     * @param checked : état du checkBox (true/false)
    */
    void on_checkBox_FB_clicked(bool checked);
    /**
     * @brief Fonction vérifie l'état du checkBox
     * @param checked : état du checkBox (true/false)
    */
    void on_checkBox_TT_clicked(bool checked);

    // connect & chose profil
    /** @brief bouton permettant de retourner à la page d'acceuil*/
    void on_pushButton_retour_clicked();

    /** @brief bouton permettant de retourner à la page des paramettres.*/
    void on_pushButton_retour_2_clicked();

    /** @brief bouton permettant de retourner à la page de confidencialité en supprimant les label d'erreurs et
    de succes de la page Mot de passes. les champs remplissable par l'utilisateurs sont vidés.*/
    void on_pushButton_retour_3_clicked();

    /** @brief bouton permettant de retourner à la page de confidencialité en supprimant les label d'erreurs et
    de succes de la page Email. les champs remplissable par l'utilisateurs sont vidés.*/
    void on_pushButton_retour_4_clicked();

    /** @brief bouton permettant d'aller à la page des paramettres depuis la page d'acceuil.*/
    void on_toolButton_modifier_clicked();

    /** @brief bouton permettant d'aller à la page des modifications de confidencialité depuis la page des paramettres.*/
    void on_pushButton_confi_clicked();

    /** @brief bouton permettant d'aller à la page des modifications de coordonnees depuis la page des paramettres.*/
    void on_pushButton_coordonnes_clicked();

    /** @brief bouton permettant d'aller à la page des modifications des sports depuis la page des paramettres.*/
    void on_pushButton_sport_clicked();

    /** @brief bouton permettant d'aller à la page des paramettres depuis la page des choix de modifications.*/
    void on_pushButton_retour_6_clicked();

    /** @brief bouton permettant d'aller à la page des modifications du Username depuis la page des choix de modifications.*/
    void on_pushButton_clicked();

    /** @brief bouton permettant d'aller à la page des choix de modifications  depuis la page du Username.*/
    void on_pushButton_retour_5_clicked();

    /** @brief bouton permettant d'aller à la page de la modification du Nom  depuis la page du choix des modifications.*/
    void on_pushButton_2_clicked();

    /** @brief bouton permettant d'aller à la page de la modification du Prénom depuis la page du choix des modifications.*/
    void on_pushButton_3_clicked();

    /** @brief bouton retour permettant d'aller à la page du choix des modifications depuis la page du Prénom.*/
    void on_pushButton_retour_8_clicked();

    /** @brief bouton retour permettant d'aller à la page du choix des modifications depuis la page du Nom.*/
    void on_pushButton_retour_7_clicked();

    /** @brief bouton permettant d'aller à la page des modifications du type de profil depuis la page des choix de modifications.*/
    void on_pushButton_5_clicked();

    /** @brief bouton permettant d'aller à la page des modifications des Réseaux depuis la page des choix de modifications.*/
    void on_pushButton_6_clicked();

    /** @brief bouton retour permettant d'aller à la page du choix des modifications depuis la page du type de profil.*/
    void on_pushButton_retour_10_clicked();

    /** @brief bouton permettant d'aller à la page des modifications du Mot de passe depuis la page confidentialité.*/
    void on_pushButton_8_clicked();

    /** @brief bouton permettant d'aller à la page des modifications de la ville depuis la page des choix de modifications.*/
    void on_pushButton_4_clicked();

    /** @brief bouton permettant d'aller à la page des modifications du compte depuis la page des paramettres.*/
    void on_pushButtoncompte_clicked();

    /** @brief bouton validant le changement du Username dans la BD et par un label. */
    void on_buttonBox_okanUsername_4_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement de username.*/
    void on_buttonBox_okanUsername_4_rejected();

    /** @brief bouton validant le changement du Prénom dans la BD et par un label. */
    void on_buttonBox_okanPrenom_6_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement du Prénom.*/
    void on_buttonBox_okanPrenom_6_rejected();

    /** @brief bouton validant le changement de ville dans la BD et par un label. */
    void on_buttonBox_okanVille_7_accepted();

    /** @brief bouton retour permettant d'aller à la page du choix des modifications depuis la page du changement de ville.*/
    void on_pushButton_retour_9_clicked();

    /** @brief bouton retournant à l'acceuil depuis la page du changement de la ville.*/
    void on_buttonBox_okanVille_7_rejected();

    /** @brief bouton validant le changement de Nom dans la BD et par un label. */
    void on_buttonBox_okanNom_5_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement de nom.*/
    void on_buttonBox_okanNom_5_rejected();

    /** @brief bouton validant le changement de Type de Profil dans la BD et par un label. */
    void on_buttonBox_okanTprofil_8_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement de Type de profil.*/
    void on_buttonBox_okanTprofil_8_rejected();

    /** @brief bouton validant le changement des Réseaux dans la BD et par un label. */
    void on_buttonBox_okanReseaux_9_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement des Réseaux.*/
    void on_buttonBox_okanReseaux_9_rejected();

    /** @brief bouton validant le changement des Sports dans la BD et par un label. */
    void on_buttonBox_okansport_3_accepted();

    /** @brief bouton retournant aux paramettres pour depuis la page de confidencialité.*/
    void on_pushButton_retour_12_clicked();

    /** @brief bouton permettant d'aller à la page des modifications de l'email depuis la page de confidencialité.*/
    void on_pushButton_emailp_clicked();

    /** @brief bouton validant le changement d'email dans la BD et par un label. */
    void on_buttonBox_okan_mailp_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page du changement d'email.*/
    void on_buttonBox_okan_mailp_rejected();

    /** @brief bouton validant le changement de mot de passes dans la BD et par un label. */
    void on_buttonBox_okan_2_accepted();

    /** @brief bouton permettant d'effectuer une recherche de profil.*/
    void on_pushButton_rechercher_clicked();

    /** @brief bouton permettant de suivre un profil (de s'abonner).*/
    void on_pushButton_suivre_clicked();

    /** @brief bouton permettant de ne plus suivre un profil (se désabonner).*/
    void on_pushButton_suivre2_clicked();

    /** @brief bouton permettant d'aller a la page d'edition d'un avis.*/
    void on_pushButton_ecrAvis_clicked();

    /** @brief bouton permettant de revenir au profil depuis la page d'édition des avis.*/
    void on_pushButton_retour_25_clicked();

    /** @brief bouton validant le poste d'un avis sur un profil et par un label. */
    void on_buttonBoxokanavis_accepted();

    /** @brief bouton retournant à la page des paramettres depuis la page de suppression du compte.*/
    void on_pushButton_retour_26_clicked();

    /** @brief bouton validant la suppression du compte. */
    void on_buttonBox_accepted();

    /** @brief bouton retournant à l'acceuil depuis la page de suppression du compte.*/
    void on_buttonBox_rejected();

    /** @brief bouton retournant à l'acceuil depuis la page de changement de mot de passe.*/
    void on_buttonBox_okan_2_rejected();

    /** @brief bouton retour permettant d'aller à la page du choix des modifications depuis la page des Réseaux.*/
    void on_pushButton_retour_11_clicked();

    /** @brief rends la checkbox non checké et cache la barre d'ecriture pour TikTok*/
    void on_checkBox_TTp_2_clicked(bool checked);

    /** @brief rends la checkbox non checké et cache la barre d'ecriture pour Facebook*/
    void on_checkBox_FBp_2_clicked(bool checked);

    /** @brief rends la checkbox non checké et cache la barre d'ecriture pour snapchat*/
    void on_checkBox_SCp_2_clicked(bool checked);

    /** @brief rends la checkbox non checké et cache la barre d'ecriture pour Instagram*/
    void on_checkBox_IGp_2_clicked(bool checked);

    /** @brief rends la checkbox non checké et cache la barre d'ecriture pour LEe téléphone*/
    void on_checkBox_Portablep_2_clicked(bool checked);

    /** @brief bouton retournant à l'acceuil depuis la page de sport.*/
    void on_buttonBox_okansport_3_rejected();

    /**
     * @brief Fonction déconnecte la personne de son profil et affiche la page de connexion
     * */
    void on_pushButtoncompte_Deconnect_clicked();

    /**
     * @brief Fonction affiche la page de recherche
    */
    void on_pushButton_retour_RECHERCHER_clicked();
    /** @brief fonction renvoyant si le sport en paramettre est dans la liste */
    bool presentvect2(string sport);

    /** @brief fonction qui affiche les sports */
    void affichagesport();

    /** @brief fonction ajoute un sport si le sport en paramettre n'est pas dans la liste */
    void presentvect(string sport);

    /** @brief fonction verifie si les deux profils se suivent mutuellement */
    void verififollow();


    // recherche
    /**
     * @brief Effectue la recherche des profils correspondants au critères séléctionnés.
     */
    void on_pushButton_search_clicked();

    /**
     * @brief Permet de filtrer les profils par âge.
     * @param checked booléen permettant de savoir si la case est cochée ou non.
     */
    void on_checkBox_age_clicked(bool checked);

    /**
     * @brief Permet de filtrer les profils par sexe.
     * @param checked booléen permettant de savoir si la case est cochée ou non.
     */
    void on_checkBox_sexe_clicked(bool checked);

    /**
     * @brief Permet de filtrer les profils par ville.
     * @param checked booléen permettant de savoir si la case est cochée ou non.
     */
    void on_checkBox_ville_clicked(bool checked);

    /**
    * @brief Effectue la recherche des profils correspondants au critères séléctionnés.
    */
    void on_pushButton_profil_clicked();

    /**
     * @brief Fonction choisit un profil au hasard et l'affiche
    */
    void on_pushButton_profil_au_hasard_clicked();

    /**
     * @brief Fonction affiche la page de recherche
    */
    void on_pushButton_rechercher_2_clicked();

    /**
     * @brief Fonction cache erreur sur la page de createavis
    */
    void on_buttonBoxokanavis_rejected();

private:
    /**
     * @brief La fenetre d'affichage d'application 
    */
    Ui::MainWindow *ui;
    /**
     * @brief La base de données de profils
    */
    EnsembleProfils profils;
    /**
     * @brief Profil connecté 
    */
    Profil connectprofil;
    /**
     * @brief Profil choisi 
    */
    Profil choseprofil;


};
#endif // APP_H
