# Projet pour LIFAP4

Notre projet est une application de rencontres sportives. L'application permet de trouver un partenaire qui pratique les mêmes sports que vous.
En s'abonnant à leurs profils, s'il y a un abonnement en retour, vous aurez accès aux réseaux l'un de l'autre.
L'application regroupe seulement 5 sports à ce jour, mais cela va évoluer en fonction de la popularité de l'application.

## Le code et l'organisation des fichiers
Ce code est construit de manière à avoir les fonctionnalités de base regroupées dans le dossier src 
puis d'avoir le dossier qt qui gère l'affichage de l'application.

L'organisation des fichiers est la suivante.

- ** src/ **    : les classes Profil, Avis et EnsembleProfils
- ** qt/ **.    : les classes Qt
- ** data/ **   : les photos de profils
- ** doc/ **    : le fichier doxygen qui permet de générer la documentation du code
- ** bin/ **    : répertoire où les executables seront compilés
- ** obj/ **    : répertoire comportant les compilations intermédiaires (.o)
- ** Makefile **    : ce fichier permet de compiler et générer les fichiers .o et les executables à partir des dossiers src/ et qt/



## Pour compiler

Compilez en rentrant la commande suivante dans un terminal UNIX : "qmake src/qt/app.pro". 
Pour exécuter, tapez la commande "open build_qt/app.app".

Si cela n'a pas fonctionné, essayez la procédure suivante :

Vous devez ouvrir app.pro dans le logiciel Qt Creator puis cliquer sur le bouton "OK" du message d'erreur puis sur "Configure Project".
Vous pourrez ensuite exécuter le projet en allant dans " Compiler->Exécuter " ou à l'aide de CTRL+R.


## Génération de la documentation doxygen

Pour générer la documentation doxygen, rentrez la commande suivante dans un terminal UNIX "doxygen doc/app.doxy"
