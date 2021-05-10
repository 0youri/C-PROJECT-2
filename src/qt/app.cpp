#include "app.h"
#include "ui_app.h"
#include <iostream>
#include <stdio.h>



using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->accueil);

    // accueil
    vector<string> sport1 = {"Musculation", "StreetWorkout","Basketball"};
    Profil profil1("youri", "youri@gmail.com","12345", "Novikov", "Youri", 20, "Homme", "Villeurbanne", "07777777", "0youri", "", "", "", "Sportif", sport1, "data/profil1.png");
    vector<string> sport2 = {"StreetWorkout","Football","Musculation"};
    Profil profil2("lucas", "lucas@gmail.com","12345", "Brustolin", "Lucas", 21, "Homme", "Lyon", "07777777", "0lucas", "", "", "", "Sportif", sport2, "data/profil2.png");
    vector<string> sport3 = {"Football","Basketball"};
    Profil profil3("nicolas", "nicolas@gmail.com","12345", "Planche", "Nicolas", 22, "Homme", "Lyon", "07777777", "0nicolas", "", "", "", "Coach", sport3, "data/profil3.png");
    vector<string> sport4 = {"Basketball", "Musculation"};
    Profil profil4("alice", "alice@gmail.com","12345", "Chouabe", "Alice", 20, "Femme", "Lyon", "07777777", "0alice", "", "", "", "Sportive", sport4, "data/profil4.png");
    vector<string> sport5 = {"Football", "Escalade"};
    Profil profil5("camille", "camille@gmail.com","12345", "Labonne", "Camille", 23, "Femme", "Villeurbanne", "07777777", "0camille", "", "", "", "Sportive", sport5, "data/profil5.png");
    profils.addProfil(profil1);
    profils.addProfil(profil2);
    profils.addProfil(profil3);
    profils.addProfil(profil4);
    profils.addProfil(profil5);
    ui->label_ErreurID->setText("Identifiant incorrect!");
    ui->label_ErreurID->setStyleSheet("color: red;");
    ui->label_ErreurPASS->setText("Mot de passe incorrect!");
    ui->label_ErreurPASS->setStyleSheet("color: red;");
    ui->label_ErreurID->hide();
    ui->label_ErreurPASS->hide();





    // subscribe
    ui->label_ErrorMdp->setText("Ce champ est obligatoire!");
    ui->label_ErrorNom->setText("Ce champ est obligatoire!");
    ui->label_ErrorPrenom->setText("Ce champ est obligatoire!");
    ui->label_ErrorVille->setText("Ce champ est obligatoire!");
    ui->label_ErrorSport->setText("Faites au moins 1 choix!");
    ui->label_ErrorButton->setText("Le formulaire n'a pas pu etre finalisé!");

    ui->label_ErrorUsername->setStyleSheet("color: red;");
    ui->label_ErrorMail->setStyleSheet("color: red;");
    ui->label_ErrorMdp->setStyleSheet("color: red;");
    ui->label_ErrorConfMdp->setStyleSheet("color: red;");
    ui->label_ErrorNom->setStyleSheet("color: red;");
    ui->label_ErrorPrenom->setStyleSheet("color: red;");
    ui->label_ErrorVille->setStyleSheet("color: red;");
    ui->label_ErrorSport->setStyleSheet("color: red;");
    ui->label_ErrorCrd->setStyleSheet("color: red;");
    ui->label_ErrorButton->setStyleSheet("color: red;");

    ui->label_ErrorUsername->hide();
    ui->label_ErrorMail->hide();
    ui->label_ErrorMdp->hide();
    ui->label_ErrorConfMdp->hide();
    ui->label_ErrorNom->hide();
    ui->label_ErrorPrenom->hide();
    ui->label_ErrorVille->hide();
    ui->label_ErrorSport->hide();
    ui->label_ErrorCrd->hide();
    ui->label_ErrorButton->hide();

    ui->lineEdit_Portable->hide();
    ui->lineEdit_IG->hide();
    ui->lineEdit_SC->hide();
    ui->lineEdit_FB->hide();
    ui->lineEdit_TT->hide();

    // recherche
    ui->label_age_min->hide();
    ui->label_age_max->hide();
    ui->spinBox_age_min->hide();
    ui->spinBox_age_max->hide();
    ui->comboBox_sexe->hide();
    ui->lineEdit_ville->hide();
    ui->label_aucun->hide();

    ui->label_error_age->setText("Pas possible !");
    ui->label_error_age->hide();
    ui->label_error_age->setStyleSheet("color: red;");

    // connect & chose profil

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_CONNECT_clicked()
{

    if ( profils.existeUsername(ui->lineEdit_ID->text().toStdString()) )
    {
        ui->label_ErreurID->hide();
        if ( !profils.verifPassword(ui->lineEdit_ID->text().toStdString(),ui->lineEdit_PASS->text().toStdString()) )
            ui->label_ErreurPASS->show();
        else
        {
            ui->label_ErreurPASS->hide();
            connectprofil = profils.getProfil(ui->lineEdit_ID->text().toStdString());
            ui->lineEdit_ID->setText("");
            ui->lineEdit_PASS->setText("");
            ui->stackedWidget->setCurrentWidget(ui->recherche);
        }
    }
    else ui->label_ErreurID->show();

}


void MainWindow::on_pushButton_SUBSCRIBE_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->subscribe);
}

void MainWindow::on_button_ANNULER_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->accueil);
}

void MainWindow::on_button_SUBSCRIBE_clicked()
{
    // Username
    bool boolUsername;
    if ( ui->lineEdit_Username->text().isEmpty() )
    {
        ui->label_ErrorUsername->setText("Ce champ est obligatoire!");
        ui->label_ErrorUsername->show();
        boolUsername = false;
    }
    else if ( profils.existeUsername(ui->lineEdit_Username->text().toStdString()) )
    {
        ui->label_ErrorUsername->setText("Ce username est déjà utilisé!");
        ui->label_ErrorUsername->show();
        boolUsername = false;
    }
    else
    {
        ui->label_ErrorUsername->hide();
        boolUsername = true;
    }

    // Mail
    bool boolMail;
    if ( ui->lineEdit_Mail->text().isEmpty() )
    {
        ui->label_ErrorMail->setText("Ce champ est obligatoire!");
        ui->label_ErrorMail->show();
        boolMail = false;
    }
    else if ( profils.existeMail(ui->lineEdit_Mail->text().toStdString()) )
    {
        ui->label_ErrorMail->setText("Ce mail est déjà utilisé!");
        ui->label_ErrorMail->show();
        boolMail = false;
    }
    else
    {
        ui->label_ErrorMail->hide();
        boolMail = true;
    }

    // Mdp
    bool boolMdp;
    if ( ui->lineEdit_Mdp->text().isEmpty() )
    {
        ui->label_ErrorMdp->show();
        boolMdp = false;
    }
    else
    {
        ui->label_ErrorMdp->hide();
        boolMdp = true;
    }
    bool boolConfMdp;
    if ( ui->lineEdit_ConfMdp->text().isEmpty() )
    {
        ui->label_ErrorConfMdp->setText("Ce champ est obligatoire!");
        ui->label_ErrorConfMdp->show();
        boolConfMdp = false;
    }
    else if ( ui->lineEdit_ConfMdp->text().toStdString() != ui->lineEdit_Mdp->text().toStdString() )
    {
        ui->label_ErrorConfMdp->setText("Les mots de passe ne sont pas identiques!");
        ui->label_ErrorConfMdp->show();
        boolConfMdp = false;
    }
    else
    {
        ui->label_ErrorConfMdp->hide();
        boolConfMdp = true;
    }

    // Nom
    bool boolNom;
    if ( ui->lineEdit_Nom->text().isEmpty() )
    {
        ui->label_ErrorNom->show();
        boolNom = false;
    }
    else
    {
        ui->label_ErrorNom->hide();
        boolNom = true;
    }

    // Prénom
    bool boolPrenom;
    if ( ui->lineEdit_Prenom->text().isEmpty() )
    {
        ui->label_ErrorPrenom->show();
        boolPrenom = false;
    }
    else
    {
        ui->label_ErrorPrenom->hide();
        boolPrenom = true;     
    }

    // Ville
    bool boolVille;
    if ( ui->lineEdit_Ville->text().isEmpty() )
    {
        ui->label_ErrorVille->show();
        boolVille = false;
    }
    else
    {
        ui->label_ErrorVille->hide();
        boolVille = true;
    }

    // Type sport
    bool boolSport;
    if ( ui->checkBox_Basket->checkState() == 2 || ui->checkBox_Foot->checkState() == 2 || ui->checkBox_Street->checkState() == 2
         || ui->checkBox_Escalade->checkState() == 2 || ui->checkBox_Muscu->checkState() == 2)
    {
        ui->label_ErrorSport->hide();
        boolSport = true;
    }
    else
    {
        ui->label_ErrorSport->show();
        boolSport = false;
    }

    // Coordonnées
    bool boolCrd;
    if ( ui->checkBox_Portable->checkState() == 2 || ui->checkBox_IG->checkState() == 2 || ui->checkBox_SC->checkState() == 2
         || ui->checkBox_FB->checkState() == 2 || ui->checkBox_TT->checkState() == 2)
    {
        if ( ui->lineEdit_Portable->text().isEmpty() && ui->lineEdit_IG->text().isEmpty() && ui->lineEdit_SC->text().isEmpty()
             && ui->lineEdit_FB->text().isEmpty() && ui->lineEdit_TT->text().isEmpty() )
        {
            ui->label_ErrorCrd->setText("Remplissez le champ choisie!");
            ui->label_ErrorCrd->show();
            boolCrd = false;
        }
        else
        {
            ui->label_ErrorCrd->hide();
            boolCrd = true;
        }
    }
    else
    {
        ui->label_ErrorCrd->setText("Faites au moins 1 choix!");
        ui->label_ErrorCrd->show();
        boolCrd = false;
    }


    if ( boolUsername && boolMail && boolMdp && boolConfMdp && boolNom && boolPrenom && boolVille && boolSport && boolCrd )
    {
        ui->label_ErrorButton->hide();
        const string nusername = ui->lineEdit_Username->text().toStdString();
        const string nmail = ui->lineEdit_Mail->text().toStdString();
        const string npassword = ui->lineEdit_Mdp->text().toStdString();
        const string nnom = ui->lineEdit_Nom->text().toStdString();
        const string nprenom = ui->lineEdit_Prenom->text().toStdString();
        const int nage = ui->spinBox_Age->value();
        const string nsexe = ui->comboBox_Sexe->currentText().toStdString();
        const string nville = ui->lineEdit_Ville->text().toStdString();
        const string ntypeprofil = ui->comboBox_Profil->currentText().toStdString();
        vector<string> sport;
        if ( ui->checkBox_Basket->checkState() == 2 ) sport.push_back("Basketball");
        if ( ui->checkBox_Foot->checkState() == 2 ) sport.push_back("Football");
        if ( ui->checkBox_Street->checkState() == 2 ) sport.push_back("StreetWorkout");
        if ( ui->checkBox_Escalade->checkState() == 2 ) sport.push_back("Escalade");
        if ( ui->checkBox_Muscu->checkState() == 2 ) sport.push_back("Musculation");

        string nportable, nig, nsc, nfb, ntt;
        nportable = nig = nsc = nfb = ntt = "";
        if ( !ui->lineEdit_Portable->text().isEmpty() ) nportable = ui->lineEdit_Portable->text().toStdString();
        if ( !ui->lineEdit_IG->text().isEmpty() ) nig = ui->lineEdit_IG->text().toStdString();
        if ( !ui->lineEdit_SC->text().isEmpty() ) nsc = ui->lineEdit_SC->text().toStdString();
        if ( !ui->lineEdit_FB->text().isEmpty() ) nfb = ui->lineEdit_FB->text().toStdString();
        if ( !ui->lineEdit_TT->text().isEmpty() ) string ntt = ui->lineEdit_TT->text().toStdString();

        Profil nprofil(nusername,nmail,npassword,nnom,nprenom,nage,nsexe,nville,nportable,nig,nsc,nfb,ntt,ntypeprofil,sport,"");

        profils.addProfil(nprofil);
        connectprofil = nprofil;
        ui->stackedWidget->setCurrentWidget(ui->recherche);
    }
    else ui->label_ErrorButton->show();
}

void MainWindow::on_checkBox_Portable_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_Portable->show();
    else ui->lineEdit_Portable->hide();
}

void MainWindow::on_checkBox_IG_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_IG->show();
    else ui->lineEdit_IG->hide();
}

void MainWindow::on_checkBox_SC_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_SC->show();
    else ui->lineEdit_SC->hide();
}

void MainWindow::on_checkBox_FB_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_FB->show();
    else ui->lineEdit_FB->hide();
}

void MainWindow::on_checkBox_TT_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_TT->show();
    else ui->lineEdit_TT->hide();
}









// recherche

void MainWindow::on_pushButton_search_clicked()
{


    QGridLayout *layout = new QGridLayout;
    int min = ui->spinBox_age_min->value();
    int max = ui->spinBox_age_max->value();
    string sexe = ui->comboBox_sexe->currentText().toStdString();
    string ville = ui->lineEdit_ville->text().toStdString();
    vector<string> matchs = profils.matching(connectprofil, min, max, ville, sexe);
    ui->gridLayout_liste_profils->addLayout(layout, matchs.size(), 3);
    for(int j = 0; j<matchs.size(); j++)
    {
        for(int i = 0; i<profils.getSize(); i++)
        {
            if(profils[i].getUsername() == matchs[j])
            {
                QLabel *nom = new QLabel(QString::fromStdString(profils[i].getNom()));
                QLabel *prenom = new QLabel(QString::fromStdString(profils[i].getPrenom()));
                QPushButton *button = new QPushButton("Profil");
                layout->addWidget(nom,j,0);
                layout->addWidget(prenom,j,1);
                layout->addWidget(button,j,2);
            }
        }
    }
}

void MainWindow::on_checkBox_age_clicked(bool checked)
{
    if(checked)
    {
        ui->label_age_min->show();
        ui->label_age_max->show();
        ui->spinBox_age_min->show();
        ui->spinBox_age_max->show();
    }
    else
    {
        ui->label_age_min->hide();
        ui->label_age_max->hide();
        ui->spinBox_age_min->hide();
        ui->spinBox_age_max->hide();
        ui->spinBox_age_min->setValue(15);
        ui->spinBox_age_max->setValue(100);
    }
}

void MainWindow::on_checkBox_sexe_clicked(bool checked)
{
    if(checked)ui->comboBox_sexe->show();
    else ui->comboBox_sexe->hide(); ui->comboBox_sexe->setCurrentText("");
}

void MainWindow::on_checkBox_ville_clicked(bool checked)
{
    if(checked) ui->lineEdit_ville->show();
    else ui->lineEdit_ville->hide(); ui->lineEdit_ville->setText("");
}















// connect & chose profil

void MainWindow::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
    ui->label_OKpp2->hide();
    ui->stackedWidget->setCurrentWidget(ui->param);
}

void MainWindow::on_pushButton_retour_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramconfi);
    ui->lineEdit_ConfMdpp->clear();
    ui->lineEdit_ConfMdpp_2->clear();
    ui->lineEdit_ConfMdpp_3->clear();
    ui->label_ErrorCrdp_3->hide();
    ui->label_ErrorCrdp_4->hide();
    ui->label_ErrorCmdp_5->hide();
}

void MainWindow::on_pushButton_retour_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramconfi);
    ui->lineEdit_Mdpp->clear();
    ui->lineEdit_Mail_2->clear();
    ui->label_ErrorMdpp->hide();
    ui->label_ErrorMail_2->hide();
}

void MainWindow::on_toolButton_modifier_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->param);
}

void MainWindow::on_pushButton_confi_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramconfi);
}

void MainWindow::on_pushButton_coordonnes_clicked()
{
    ui->label_tpp_2->hide();
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
}

void MainWindow::on_pushButton_sport_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramsport);
    ui->pcheckBox_Basketp->setChecked(0);
    ui->checkBox_Escaladep->setChecked(0);
    ui->checkBox_Muscup->setChecked(0);
    ui->checkBox_Streetp->setChecked(0);
    ui->checkBox_Footp->setChecked(0);
    if(presentvect2("Basketball"))
    {
        ui->pcheckBox_Basketp->setChecked(2);
    }
    if(presentvect2("Escalade"))
    {
        ui->checkBox_Escaladep->setChecked(2);
    }
    if(presentvect2("Musculation"))
    {
        ui->checkBox_Muscup->setChecked(2);
    }
    if(presentvect2("StreetWorkout"))
    {
        ui->checkBox_Streetp->setChecked(2);
    }
    if(presentvect2("Football"))
    {
        ui->checkBox_Footp->setChecked(2);
    }
}


void MainWindow::on_pushButton_retour_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->param);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramusername);
    ui->label_okusr->hide();
}

void MainWindow::on_pushButton_retour_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
    ui->lineEdit_usernamep_2->clear();
     ui->label_Errorusrp_2->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramnom);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramprenom);
}

void MainWindow::on_pushButton_retour_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
    ui->lineEdit_Prenom_3->clear();
     ui->label_ErrorPrenom_2->hide();
     ui->label_ok_4->hide();
}

void MainWindow::on_pushButton_retour_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
    ui->lineEdit_Nomp_2->clear();
     ui->label_ErrorNomp_2->hide();
     ui->label_ok6->hide();

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramtypeprofil);
    if ( connectprofil.getTypeProfil() == "Sportif" ) ui->comboBox_Profil_2->setCurrentIndex(0);
    else ui->comboBox_Profil_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramreseaux);
}

void MainWindow::on_pushButton_retour_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);

}

void MainWindow::on_pushButton_retour_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_FBp_2->setChecked(false);
    ui->checkBox_IGp_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_SCp_2->setChecked(false);
    ui->checkBox_TTp_2->setChecked(false);
    ui->label_ErrorCrdp_2->hide();
    ui->label_OKpp->hide();
    on_checkBox_Portablep_2_clicked(false);
    on_checkBox_IGp_2_clicked(false);
    on_checkBox_SCp_2_clicked(false);
    on_checkBox_FBp_2_clicked(false);
    on_checkBox_TTp_2_clicked(false);
}

void MainWindow::on_pushButton_retour_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramcoord);
    ui->lineEdit_Nomp_3->clear();
     ui->label_ErrorNomp_3->hide();
     ui->label_okville->hide();


}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paramville);

}
void MainWindow::on_pushButton_retour_12_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->param);

}
void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->parampassword);
}



void MainWindow::on_buttonBox_okanUsername_4_accepted()
{
    bool boolUsernamep;
    if (ui->lineEdit_usernamep_2->text().isEmpty())
    {
         ui->label_Errorusrp_2->hide();
        ui->label_Errorusrp_2->setText("Ce champ est obligatoire!");
        ui->label_Errorusrp_2->show();
        boolUsernamep = false;
    }
    else if ( profils.existeUsername(ui->lineEdit_usernamep_2->text().toStdString()) )
    {
        ui->label_Errorusrp_2->hide();
        ui->label_Errorusrp_2->setText("Ce username existe déjà!");
        ui->label_Errorusrp_2->show();
        boolUsernamep = false;
    }
    else{
        ui->label_Errorusrp_2->hide();
        ui->label_okusr->setText("OK !");
        ui->label_okusr->show();
        boolUsernamep = true;

    }
    if(boolUsernamep)
    {
       /*

        Ajouter conditions pour que le username ne soit pas le meme quand dans la BD
       */
        QString newus = ui->lineEdit_usernamep_2->text();
        std::string newusr = newus.toLocal8Bit().constData();

        QString::fromStdString(newusr);

        connectprofil.setUsername(newusr);
        ui->label_usernamep->setText(QString::fromStdString(connectprofil.getUsername()));
        ui->label_usernamep_2->setText(QString::fromStdString(connectprofil.getUsername()));



    }

}
void MainWindow::on_buttonBox_okanUsername_4_rejected()
{
    ui->lineEdit_usernamep_2->clear();
     ui->label_Errorusrp_2->hide();
     ui->stackedWidget->setCurrentWidget(ui->paramcoord);

}




void MainWindow::on_buttonBox_okanPrenom_6_accepted()
{
    bool boolUsernamep;
    if ( ui->lineEdit_Prenom_3->text().isEmpty() )
    {
        ui->label_ok_4->hide();
        ui->label_ErrorPrenom_2->setText("Ce champ est obligatoire!");
        ui->label_ErrorPrenom_2->show();
        boolUsernamep = false;
    }else{
        ui->label_ok_4->setText("OK !");
        ui->label_ok_4->show();
        ui->label_ErrorPrenom_2->hide();
        boolUsernamep = true;

    }
    if(boolUsernamep)
    {
        ui->label_ErrorPrenom_2->hide();



        QString newus = ui->lineEdit_Prenom_3->text();
        std::string newusr = newus.toLocal8Bit().constData();

        QString::fromStdString(newusr);

        connectprofil.setPrenom(newusr);


    }
}

void MainWindow::on_buttonBox_okanPrenom_6_rejected()
{
    ui->lineEdit_Prenom_3->clear();
     ui->label_ErrorPrenom_2->hide();
     ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->label_ok_4->hide();
}

void MainWindow::on_buttonBox_okanVille_7_accepted()
{

            bool boolUsernamep;
            if ( ui->lineEdit_Nomp_3->text().isEmpty() )
            {
                ui->label_ErrorNomp_3->setText("Ce champ est obligatoire!");
                ui->label_okville->hide();

                ui->label_ErrorNomp_3->show();
                boolUsernamep = false;
            }else{
                ui->label_ErrorNomp_3->hide();
                ui->label_okville->setText("OK !");
                ui->label_okville->show();
                boolUsernamep = true;

            }
            if(boolUsernamep)
            {
                ui->label_ErrorNomp_3->hide();



                QString newus = ui->lineEdit_Nomp_3->text();
                std::string newusr = newus.toLocal8Bit().constData();

                QString::fromStdString(newusr);

                connectprofil.setVille(newusr);

}
}


void MainWindow::on_buttonBox_okanVille_7_rejected()
{
    ui->lineEdit_Nomp_3->clear();
     ui->label_ErrorNomp_3->hide();
     ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->label_okville->hide();

}

void MainWindow::on_buttonBox_okanNom_5_accepted()
{

            bool boolUsernamep;
            if ( ui->lineEdit_Nomp_2->text().isEmpty() )
            {
                ui->label_ErrorNomp_2->setText("Ce champ est obligatoire!");
                ui->label_ok6->hide();

                ui->label_ErrorNomp_2->show();
                boolUsernamep = false;
            }else{
                ui->label_ok6->setText("OK !");
                ui->label_ok6->show();
                ui->label_ErrorNomp_2->hide();
                boolUsernamep = true;

            }
            if(boolUsernamep)
            {
                ui->label_ErrorNomp_2->hide();



                QString newus = ui->lineEdit_Nomp_2->text();
                std::string newusr = newus.toLocal8Bit().constData();

                QString::fromStdString(newusr);

                connectprofil.setNom(newusr);
}
}

void MainWindow::on_buttonBox_okanNom_5_rejected()
{
    ui->lineEdit_Nomp_2->clear();
     ui->label_ErrorNomp_2->hide();
     ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->label_ok6->hide();

}

void MainWindow::on_buttonBox_okanTprofil_8_accepted()
{


                ui->label_ErrorNomp_3->hide();
                connectprofil.setTypeProfil(ui->comboBox_Profil_2->currentText().toStdString());
                ui->plabel_profil->setText(QString::fromStdString(connectprofil.getTypeProfil()));
                ui->plabel_profil_2->setText(QString::fromStdString(connectprofil.getTypeProfil()));
                ui->label_tpp_2->setText("OK !");
                ui->label_tpp_2->show();

}

void MainWindow::on_buttonBox_okanTprofil_8_rejected()
{
     ui->label_tpp_2->hide();
     ui->stackedWidget->setCurrentWidget(ui->connectprofil);
}

void MainWindow::on_buttonBox_okanReseaux_9_accepted()
{
    bool boolCrd;
    if ( ui->checkBox_Portablep_2->checkState() == 2 || ui->checkBox_IGp_2->checkState() == 2 || ui->checkBox_SCp_2->checkState() == 2
         || ui->checkBox_FBp_2->checkState() == 2 || ui->checkBox_TTp_2->checkState() == 2)
    {
        boolCrd = true;

    }
    else
    {
        ui->label_ErrorCrdp_2->setText("Faites au moins 1 choix!");
        ui->label_ErrorCrdp_2->show();
        boolCrd = false;
    }
    if(boolCrd)
    {
        if( ui->checkBox_Portablep_2->checkState() == 2)
        {
            QString newus = ui->lineEdit_Portablep_2->text();
            std::string newusr = newus.toLocal8Bit().constData();

            QString::fromStdString(newusr);

            connectprofil.setPortable(newusr);
            ui->label_telp->setText("Tél : " + QString::fromStdString(connectprofil.getPortable()));
            ui->label_telp_2->setText("Tél : " + QString::fromStdString(connectprofil.getPortable()));


        }
        if(ui->checkBox_IGp_2->checkState() == 2)
        {
            QString newus = ui->lineEdit_IGp_2->text();
            std::string newusr = newus.toLocal8Bit().constData();

            QString::fromStdString(newusr);

            connectprofil.setIG(newusr);
            ui->label_instagramp->setText("Instagram : @" + QString::fromStdString(connectprofil.getIG()));
            ui->label_instagramp_2->setText("Instagram : @" + QString::fromStdString(connectprofil.getIG()));


        }
        if(ui->checkBox_SCp_2->checkState() == 2)
        {
            QString newus = ui->lineEdit_SCp_2->text();
            std::string newusr = newus.toLocal8Bit().constData();

            QString::fromStdString(newusr);

            connectprofil.setSC(newusr);
            ui->label_snapchatp->setText("Snapchat : " + QString::fromStdString(connectprofil.getSC()));
            ui->label_snapchatp_2->setText("Snapchat : " + QString::fromStdString(connectprofil.getSC()));


        }
        if(!ui->lineEdit_FBp_2->text().isEmpty() )
        {
            QString newus = ui->lineEdit_FBp_2->text();
            std::string newusr = newus.toLocal8Bit().constData();

            QString::fromStdString(newusr);

            connectprofil.setFB(newusr);
            ui->label_fbp->setText("Facebook : " + QString::fromStdString(connectprofil.getFB()));
            ui->label_fbp_2->setText("Facebook : " + QString::fromStdString(connectprofil.getFB()));


        }
        if( ui->checkBox_TTp_2->checkState() == 2)
        {
            QString newus = ui->lineEdit_TTp_2->text();
            std::string newusr = newus.toLocal8Bit().constData();

            QString::fromStdString(newusr);

            connectprofil.setTT(newusr);
            ui->label_TTp->setText("TikTok : " + QString::fromStdString(connectprofil.getTT()));
            ui->label_TTp_2->setText("TikTok : " + QString::fromStdString(connectprofil.getTT()));


        }


    ui->label_OKpp->setText("OK !");


    ui->label_OKpp->show();
    ui->label_ErrorCrdp_2->hide();
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_FBp_2->setChecked(false);
    ui->checkBox_IGp_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_SCp_2->setChecked(false);
    ui->checkBox_TTp_2->setChecked(false);
    on_checkBox_Portablep_2_clicked(false);
    on_checkBox_IGp_2_clicked(false);
    on_checkBox_SCp_2_clicked(false);
    on_checkBox_FBp_2_clicked(false);
    on_checkBox_TTp_2_clicked(false);
    }
}

void MainWindow::on_buttonBox_okanReseaux_9_rejected()
{
    ui->lineEdit_TTp_2->clear();
    ui->lineEdit_FBp_2->clear();
    ui->lineEdit_SCp_2->clear();
    ui->lineEdit_IGp_2->clear();
    ui->lineEdit_Portablep_2->clear();
    ui->label_ErrorCrdp_2->hide();
    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_FBp_2->setChecked(false);
    ui->checkBox_IGp_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_Portablep_2->setChecked(false);
    ui->checkBox_SCp_2->setChecked(false);
    ui->checkBox_TTp_2->setChecked(false);
    ui->label_OKpp->hide();
    on_checkBox_Portablep_2_clicked(false);
    on_checkBox_IGp_2_clicked(false);
    on_checkBox_SCp_2_clicked(false);
    on_checkBox_FBp_2_clicked(false);
    on_checkBox_TTp_2_clicked(false);
}

void MainWindow::on_buttonBox_okansport_3_accepted()//modified
{

    if (ui->pcheckBox_Basketp->checkState() == 2)
    {
        presentvect("Basketball");
    }
    if (ui->checkBox_Footp->checkState() == 2)
    {
        presentvect("Football");
    }
    if (ui->checkBox_Streetp->checkState() == 2)
    {
        presentvect("StreetWorkout");
    }
    if (ui->checkBox_Muscup->checkState() == 2)
    {
        presentvect("Musculation");
    }
    if (ui->checkBox_Escaladep->checkState() == 2)
    {
        presentvect("Escalade");
    }
    if (ui->checkBox_Escaladep->checkState() == 0)
    {
        connectprofil.deleteTypeSport("Escalade");
        affichagesport();
    }
    if (ui->checkBox_Muscup->checkState() == 0)
    {
        connectprofil.deleteTypeSport("Musculation");
        affichagesport();
    }
    if (ui->pcheckBox_Basketp->checkState() == 0)
    {
        connectprofil.deleteTypeSport("Basketball");
        affichagesport();
    }
    if (ui->checkBox_Footp->checkState() == 0)
    {
        connectprofil.deleteTypeSport("Football");
        affichagesport();
    }
    if (ui->checkBox_Streetp->checkState() == 0)
    {
        connectprofil.deleteTypeSport("StreetWorkout");
        affichagesport();
    }

    ui->label_OKpp2->setText("OK !");
    ui->label_OKpp2->show();
}




void MainWindow::on_pushButton_emailp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->parammail);
}

void MainWindow::on_buttonBox_okan_mailp_accepted()
{

           QString mdpQs = ui->lineEdit_Mdpp->text();
           std::string mdps = mdpQs.toLocal8Bit().constData();

           QString mailQs = ui->lineEdit_Mail_2->text();
           std::string mails = mailQs.toLocal8Bit().constData();

          if(!ui->lineEdit_Mdpp->text().isEmpty())
          {

              if(!connectprofil.setMail(mails,mdps))
              {
                     ui->label_ErrorMdpp->setText("Le mot de passe est incorrect");
                     ui->label_ErrorMdpp->show();
              }else
                         {
                             ui->label_ErrorMail_2->setText("OK !");
                             ui->label_ErrorMail_2->show();
                             ui->label_ErrorMdpp->hide();
                         }
             }
}

void MainWindow::on_buttonBox_okan_mailp_rejected()
{
     ui->lineEdit_Mdpp->clear();
     ui->lineEdit_Mail_2->clear();
     ui->label_ErrorMdpp->hide();
     ui->label_ErrorMail_2->hide();
     ui->stackedWidget->setCurrentWidget(ui->connectprofil);
}

void MainWindow::on_buttonBox_okan_2_accepted()
{


        std::string nmdps = ui->lineEdit_ConfMdpp->text().toLocal8Bit().constData();
        std::string Cnmdps = ui->lineEdit_ConfMdpp_2->text().toLocal8Bit().constData();
        std::string mdpacts = ui->lineEdit_ConfMdpp_3->text().toLocal8Bit().constData();
        if(nmdps==Cnmdps)
        {
            ui->label_ErrorCmdp_5->hide();

            if(mdpacts == connectprofil.getPassword())
            {
                connectprofil.setPassword(nmdps,mdpacts);
            ui->label_ErrorCrdp_3->setText("OK !");
            ui->label_ErrorCrdp_3->show();
            ui->label_ErrorCrdp_4->hide();
            }else{
                ui->label_ErrorCrdp_4->show();
                ui->label_ErrorCrdp_4->setText("Mot de pass actuel incorrect");
                 }
        }else{
            ui->label_ErrorCmdp_5->show();
            ui->label_ErrorCmdp_5->setText("Les mots de passes ne correspondent pas");
            }





}

void MainWindow::on_pushButton_rechercher_clicked()
{
    //fonctionrechercherlucas

    ui->stackedWidget->setCurrentWidget(ui->recherche);
}


void MainWindow::on_pushButton_suivre_clicked()
{

    ui->pushButton_suivre->hide();
    ui->pushButton_suivre2->show();

    choseprofil.ajouterFollowers(connectprofil.getUsername());
    connectprofil.ajouterFollowing(choseprofil.getUsername());
    int abonnement = connectprofil.getFollowing().size();
    ui->lcdNumber_abonne->display(abonnement);
    int abonne = choseprofil.getFollowers().size();
    ui->lcdNumber_abonne_2->display(abonne);
    verififollow();
}

void MainWindow::on_pushButton_suivre2_clicked()
{
    ui->pushButton_suivre->show();
    ui->pushButton_suivre2->hide();

    choseprofil.deleteFollowers(connectprofil.getUsername());
    int abonne = choseprofil.getFollowers().size();
    ui->lcdNumber_abonne_2->display(abonne);
    connectprofil.deleteFollowing(choseprofil.getUsername());
    int abonnement = connectprofil.getFollowing().size();
    ui->lcdNumber_abonne->display(abonnement);
    ui->groupBox_8->hide();
}

void MainWindow::on_pushButton_ecrAvis_clicked()
{
    for (unsigned int i = 0; i < choseprofil.getFollowers().size(); i++)
        {
            if (connectprofil.getUsername() == choseprofil.getFollowers()[i])
            {
                ui->label_erreurAvis->hide();
                ui->stackedWidget->setCurrentWidget(ui->createavis);
                break;


            }
            else {
                ui->label_erreurAvis->setText("Abonnnez vous pour \n donner un avis");
                ui->label_erreurAvis->show();
            }



        }
}

void MainWindow::on_pushButton_retour_25_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->choseprofil);
    ui->label_Erroravis->hide();
}


void MainWindow::on_buttonBoxokanavis_accepted()
{
    std::string username = ui->labeusrchose->text().toLocal8Bit().constData();
    bool like;
    if (ui->radioButtonLikeavis->isChecked()) {
        like = true;
    }
    else like = false;


    QString com = ui->textEditcom->toPlainText();
    std::string commentaire = com.toLocal8Bit().constData();
    choseprofil.creationAvis(username, like, commentaire);
    ui->label_okavis_2->setText("OK !");
    ui->label_okavis_2->show();
    vector<Avis> tab = choseprofil.getAvis();
    string avis = "";
    for (unsigned int i = 0; i < tab.size(); i++)
    {
        if ( tab[i].getLike() )
            avis += tab[i].getUsername() + "\n" + "Commentaire : " + tab[i].getCommentaire() + "\n" + "Like : oui";
        else
            avis += tab[i].getUsername() + "\n" + "Commentaire : " + tab[i].getCommentaire() + "\n" + "Like : non";
    }
    ui->textBrowser_avis_2->setText(QString::fromStdString(avis));
    int nbavis = choseprofil.getAvis().size();
    ui->lcdNumber_avis_2->display(nbavis);
    ui->stackedWidget->setCurrentWidget(ui->choseprofil);
}

void MainWindow::on_pushButton_retour_26_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->param);
}

void MainWindow::on_pushButtoncompte_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->deleteprofil);

}

void MainWindow::on_buttonBox_accepted()
{
   // checkBoxcondlineEditmdps label_mdpcond label_cond
            if(ui->checkBoxcond->isChecked())
            {ui->label_cond->hide();
               if(ui->lineEditmdps->text()==QString::fromStdString(connectprofil.getPassword()))
               {
                    ui->label_mdpcond->hide();
                    profils.deleteProfil(connectprofil.getUsername());
                    ui->stackedWidget->setCurrentWidget(ui->accueil);


               }else
               {
                   ui->label_mdpcond->setText("Mot de passe incorrect");
                   ui->label_mdpcond->show();
               }
            }else
            {
                ui->label_cond->setText("Veuillez cocher la case pour continuer");
                ui->label_cond->show();
            }
}

void MainWindow::on_buttonBox_rejected()
{
    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->checkBoxcond->setChecked(false);
    ui->lineEditmdps->clear();

}

void MainWindow::on_buttonBox_okan_2_rejected()
{
    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
     ui->lineEdit_ConfMdpp->clear();
     ui->lineEdit_ConfMdpp_2->clear();
     ui->lineEdit_ConfMdpp_3->clear();

}


void MainWindow::on_checkBox_Portablep_2_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_Portablep_2->show();
    else ui->lineEdit_Portablep_2->hide();
}

void MainWindow::on_checkBox_IGp_2_clicked(bool checked)
{
    if (checked) ui->lineEdit_IGp_2->show();
    else ui->lineEdit_IGp_2->hide();
}

void MainWindow::on_checkBox_SCp_2_clicked(bool checked)
{
    if (checked) ui->lineEdit_SCp_2->show();
    else ui->lineEdit_SCp_2->hide();
}

void MainWindow::on_checkBox_FBp_2_clicked(bool checked)
{
    if (checked) ui->lineEdit_FBp_2->show();
    else ui->lineEdit_FBp_2->hide();
}

void MainWindow::on_checkBox_TTp_2_clicked(bool checked)
{
    if ( checked ) ui->lineEdit_TTp_2->show();
    else ui->lineEdit_TTp_2->hide();
}

void MainWindow::on_buttonBox_okansport_3_rejected()
{

    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    ui->checkBox_Escaladep->setChecked(false);
    ui->checkBox_Footp->setChecked(false);
    ui->checkBox_Muscup->setChecked(false);
    ui->checkBox_Streetp->setChecked(false);

}

void MainWindow::on_pushButtoncompte_Deconnect_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->accueil);
    profils.getProfil(connectprofil.getUsername()) = connectprofil;
}

void MainWindow::on_pushButton_retour_RECHERCHER_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->recherche);
    profils.getProfil(choseprofil.getUsername()) = choseprofil;
    // UPDATE CONNECT PROFIL
}

void MainWindow::on_pushButton_profil_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->connectprofil);
    // UPDATE CONNECT PROFIL

    string avis="";
    string aviss="";
    vector<Avis> tab = connectprofil.getAvis();


    for (unsigned int i = 0; i < tab.size(); i++)
    {
        if ( tab[i].getLike() )
            avis += tab[i].getUsername() + "\n" + "Commentaire : " + tab[i].getCommentaire() + "\n" + "Like : oui";
        else
            avis += tab[i].getUsername() + "\n" + "Commentaire : " + tab[i].getCommentaire() + "\n" + "Like : non";
    }
    ui->textBrowser_avis->setText(QString::fromStdString(avis));

    ui->label_Errorusrp_2->hide();
    ui->label_usernamep->setText(QString::fromStdString(connectprofil.getUsername()));
    ui->label_usernamep->setAlignment(Qt::AlignCenter);
    ui->plabel_profil->setText(QString::fromStdString(connectprofil.getTypeProfil()));
    ui->plabel_profil->setAlignment(Qt::AlignCenter);
    ui->label_TTp->setText("Tiktok : " + QString::fromStdString((connectprofil.getTT())));
    ui->label_instagramp->setText("Instagram : @" + QString::fromStdString((connectprofil.getIG())));
    ui->label_fbp->setText("Facebook : " + QString::fromStdString((connectprofil.getFB())));
    ui->label_snapchatp->setText("Snapchat : " + QString::fromStdString((connectprofil.getSC())));
    ui->label_telp->setText("Tèl : " + QString::fromStdString((connectprofil.getPortable())));
    ui->lineEdit_Portablep_2->hide();
    ui->lineEdit_SCp_2->hide();
    ui->lineEdit_FBp_2->hide();
    ui->lineEdit_TTp_2->hide();
    ui->lineEdit_IGp_2->hide();
    affichagesport();

    int abonne = connectprofil.getFollowers().size();
    ui->lcdNumber_abonne->display(abonne);

    int abonnement = connectprofil.getFollowing().size();
    ui->lcdNumber_abonnement->display(abonnement);
    string Sport ="";
    for(unsigned int i=0;i< connectprofil.getTypeSport().size();i++)
    {
       Sport +=  connectprofil.getTypeSport()[i] + "\n";
    }
    ui->textBrowser_sport->setText(QString::fromStdString(Sport));
    ui->textBrowser_sport_2->setText(QString::fromStdString(Sport));

    string avvis ="";
    int nbavis = connectprofil.getAvis().size();
    ui->lcdNumber_avis->display(nbavis);

}

void MainWindow::on_pushButton_profil_au_hasard_clicked()
{

    while (true)
    {
        const int random = rand() % profils.getSize();
        if ( profils[random].getUsername() != connectprofil.getUsername() )
        {
            choseprofil = profils.getProfil(profils[random].getUsername());
            ui->stackedWidget->setCurrentWidget(ui->choseprofil);

            ui->label_usernamep_2->setText(QString::fromStdString(choseprofil.getUsername()));
            ui->label_usernamep_2->setAlignment(Qt::AlignCenter);
            ui->plabel_profil_2->setText(QString::fromStdString(choseprofil.getTypeProfil()));
            ui->plabel_profil_2->setAlignment(Qt::AlignCenter);
            int abonne = choseprofil.getFollowers().size();
            ui->lcdNumber_abonne_2->display(abonne);
            int abonnement = choseprofil.getFollowing().size();
            ui->lcdNumber_abonnement_2->display(abonnement);
            int nbavis = choseprofil.getAvis().size();
            ui->lcdNumber_avis_2->display(nbavis);
            ui->groupBox_8->hide();
            verififollow();

            ui->label_instagramp_2->setText("Instagram : @" + QString::fromStdString((choseprofil.getIG())));
            ui->label_TTp_2->setText("Tiktok : " + QString::fromStdString((choseprofil.getTT())));
            ui->label_fbp_2->setText("Facebook : " + QString::fromStdString((choseprofil.getFB())));
            ui->label_snapchatp_2->setText("Snapchat : " + QString::fromStdString((choseprofil.getSC())));
            ui->label_telp_2->setText("Tèl : " + QString::fromStdString((choseprofil.getPortable())));

            ui->labeusrchose->setText("Username : " + QString::fromStdString(connectprofil.getUsername()));
            if ( choseprofil.existeFollowers(connectprofil.getUsername()) )
            {
                ui->pushButton_suivre2->show();
                ui->pushButton_suivre->hide();
            }
            else
            {
                ui->pushButton_suivre2->hide();
                ui->pushButton_suivre->show();
            }

            string Sport ="";
            for(unsigned int i=0;i< choseprofil.getTypeSport().size();i++)
            {
               Sport +=  choseprofil.getTypeSport()[i] + "\n";
            }
            ui->textBrowser_sport_2->setText(QString::fromStdString(Sport));

            vector<Avis> tab2 = choseprofil.getAvis();
            string avis2 = "";//modified
            for (unsigned int i = 0; i < tab2.size(); i++)//modified
            {
                if ( tab2[i].getLike() )
                    avis2 += tab2[i].getUsername() + "\n" + "Commentaire : " + tab2[i].getCommentaire() + "\n" + "Like : oui";
                else
                    avis2 += tab2[i].getUsername() + "\n" + "Commentaire : " + tab2[i].getCommentaire() + "\n" + "Like : non";
            }
            ui->textBrowser_avis_2->setText(QString::fromStdString(avis2));//modified


            ui->label_Errorusrp_2->hide();
            ui->lineEdit_Portablep_2->hide();
            ui->lineEdit_SCp_2->hide();
            ui->lineEdit_FBp_2->hide();
            ui->lineEdit_TTp_2->hide();
            ui->lineEdit_IGp_2->hide();

            break;
        }
    }

}

void MainWindow::on_pushButton_rechercher_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->recherche);
    profils.getProfil(choseprofil.getUsername()) = choseprofil;
    profils.getProfil(connectprofil.getUsername()) = connectprofil;
}


void MainWindow::verififollow() //modified
{
    bool verif1 = false;
    bool verif2 = false;

    for (unsigned int i = 0; i < choseprofil.getFollowers().size(); i++)
    {

        if (connectprofil.getUsername() == choseprofil.getFollowers()[i])
        {
            verif1 = true;
        }
    }
    for (unsigned int i = 0; i < choseprofil.getFollowing().size(); i++)
    {

        if (connectprofil.getUsername() == choseprofil.getFollowing()[i])
        {
            verif2 = true;
        }
    }
    if ((verif1) && (verif2))
    {
        ui->groupBox_8->show();
    }

}


void MainWindow::affichagesport()
{//modified
    string Sport = "";
    for (unsigned int i = 0; i < connectprofil.getTypeSport().size(); i++)
    {
        Sport += connectprofil.getTypeSport()[i] + "\n";
    }
    ui->textBrowser_sport->setText(QString::fromStdString(Sport));
}

bool MainWindow::presentvect2(string sport)//modified
{
    bool present = false;
    for (unsigned int i = 0; i < connectprofil.getTypeSport().size(); i++)
    {
        if (connectprofil.getTypeSport()[i] == sport)
        {
            present = true;
            break;
        }
    }

    return present;

}

void MainWindow::presentvect(string sport)//modified
{
    bool present = false;
    for (unsigned int i = 0; i < connectprofil.getTypeSport().size(); i++)
    {
        if (connectprofil.getTypeSport()[i] == sport)
        {
            present = true;
            break;
        }
        else { present = false; }
    }
    if (!present)
    {
        connectprofil.ajouterTypeSport(sport);
        affichagesport();

    }
}

void MainWindow::on_buttonBoxokanavis_rejected()
{
    ui->label_Erroravis->hide();//modified
    ui->label_okavis_2->hide();//modified
    ui->stackedWidget->setCurrentWidget(ui->choseprofil);
}
