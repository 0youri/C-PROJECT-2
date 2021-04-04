#include "EnsembleProfils.h"

using namespace std;

EnsembleProfils::~EnsembleProfils()
{
    profils.clear();
}

void EnsembleProfils::addProfil(const Profil &p)
{
    profils.push_back(p);
}

void EnsembleProfils::deleteProfil(const string username)
{
    for(int i=0; i<profils.size(); i++)
    {
        if(profils[i].getUsername() == username)
        {
            profils.erase(profils.begin()+i);
            break;
        }
    }
}

bool EnsembleProfils::existeUsername(const string username)
{
    for(int i=0; i<profils.size(); i++)
    {
        if(username == profils[i].getUsername())
        {
            return true;
        }
    }
    return false;
}

bool EnsembleProfils::existeMail(const string mail)
{
    for(int i=0; i<profils.size(); i++)
    {
        if(mail == profils[i].getMail())
        {
            return true;
        }
    }
    return false;
}

vector<string> EnsembleProfils::matchTypeSport(const Profil &profil)
{
    vector<string> matchs;
    int taille = matchs.size();
    for(int i=0; i<profils.size(); i++)
    {
        if(profils[i].getUsername() != profil.getUsername())
        {
            for(int j=0; j<profil.getTypeSport().size(); j++)
            {
                for(int k=0; k<profils[i].getTypeSport().size(); k++)
                {
                    if(profil.getTypeSport()[j] == profils[i].getTypeSport()[k])
                    {
                        matchs.push_back(profils[i].getUsername());
                        break;
                    }
                }
                if(taille != matchs.size())
                {
                    taille = matchs.size();
                    break;
                }
            }
        }
    }
    return matchs;
}

vector<string> EnsembleProfils::matchAge(const int minAge, const int maxAge, string username)
{
    vector<string> matchs;
    if(minAge != 15 && maxAge != 100)
    {
        for(int i=0; i<profils.size(); i++)
        {
            if(profils[i].getUsername() != username && minAge <= profils[i].getAge() && maxAge >= profils[i].getAge())
            {
                matchs.push_back(profils[i].getUsername());
            }
        }
    }
    return matchs;
}

vector<string> EnsembleProfils::matchVille(const string ville, const string username)
{
    vector<string> matchs;
    if(ville != "")
    {
        for(int i=0; i<profils.size(); i++)
        {
            if(profils[i].getUsername() != username && ville == profils[i].getVille())
            {
                matchs.push_back(profils[i].getUsername());
            }
        }
    }
    return matchs;
}

vector<string> EnsembleProfils::matchSexe(const string sexe, const string username)
{
    vector<string> matchs;
    if(sexe != "")
    {
        for(int i=0; i<profils.size(); i++)
        {
            if(profils[i].getUsername() != username && sexe == profils[i].getSexe())
            {
                matchs.push_back(profils[i].getUsername());
            }
        }
    }
    return matchs;
}

vector<string> EnsembleProfils::matching(const Profil & profil, const int minAge, const int maxAge, const string ville, 
const string sexe)
{
    vector<string> matchs = matchTypeSport(profil);
    vector<string> compare = matchingASV(minAge, maxAge, sexe, ville, profil.getUsername());
    if(!compare.empty())
        triEnleve(matchs, compare);
    return matchs;
}

vector<string> EnsembleProfils::matchingASV(const int minAge, const int maxAge, const string sexe, const string ville, 
const string username)
{
    vector<string> matchs;
    vector<string> tabAge = matchAge(minAge, maxAge, username);
    vector<string> tabSexe = matchSexe(sexe, username);
    vector<string> tabVille = matchVille(ville, username);

    /// Vérification de tous les cas possibles
    if(!tabAge.empty() && !tabSexe.empty())
    {
        matchs = compareMatchs(tabAge, tabSexe);
        if(!tabVille.empty())
        {
            triEnleve(matchs, tabVille);            
        }
    }
    else if(!tabAge.empty() && !tabVille.empty())
    {
        matchs = compareMatchs(tabAge, tabVille);
        if(!tabSexe.empty())
        {
            triEnleve(matchs, tabSexe);            
        }
    }
    else if(!tabVille.empty() && !tabSexe.empty())
    {
        matchs = compareMatchs(tabVille, tabSexe);
        if(!tabAge.empty())
        {
            triEnleve(matchs, tabAge);            
        }
    }
    else if(!tabAge.empty() && tabSexe.empty() && tabVille.empty())
    {
        matchs = tabAge;
    }
    else if(tabAge.empty() && !tabSexe.empty() && tabVille.empty())
    {
        matchs = tabSexe;
    }
    else if(tabAge.empty() && tabSexe.empty() && !tabVille.empty())
    {
        matchs = tabVille;
    }
    return matchs;
}

/// Fonction pour comparer 2 listes de username et renvoyer une liste avec les usernames communs
vector<string> EnsembleProfils::compareMatchs(const vector<string> tab1, const vector<string> tab2)
{
    vector<string> matchs;
    for(int i=0; i<tab1.size(); i++)
    {
        for(int j=0; j<tab2.size(); j++)
        {
            if(tab1[i] == tab2[j])
            {
                matchs.push_back(tab1[i]);
                break;
            }
        }
    }
    return matchs;
}

/// Enleve les usernames de tabmatchs qui ne sont pas dans la liste tab
void EnsembleProfils::triEnleve(vector<string> tabmatchs, const vector<string> tab)
{
    for (int i=0; i<tabmatchs.size(); i++)
    {
        bool b = false;
        for(int j=0; j<tab.size(); j++)
        {
            if(tabmatchs[i] == tab[j])
            {
                b = true;
                break;
            }
        }
        if(!b)
        {
            tabmatchs.erase(tabmatchs.begin()+i);
        }
    }
}


Profil & EnsembleProfils::operator[](int i)
{
    return profils[i];
}

void EnsembleProfils::testRegression()
{
    vector<string> sport1 = {"sport1", "sport2", "sport3"};
    Profil profil1("youri", "youri@gmail.com","12345", "Novikov", "Youri", 20, "M", "Villeurbanne", "07777777", "0youri", "", "", "", "Spotif", sport1, "data/profil1.png");
    vector<string> sport2 = {"sport3", "sport5", "sport6"};
    Profil profil2("lucas", "lucas@gmail.com","12345", "Brustolin", "Lucas", 21, "M", "Lyon", "07777777", "0lucas", "", "", "", "Spotif", sport2, "data/profil2.png");
    vector<string> sport3 = {"sport7", "sport8", "sport9"};
    Profil profil3("nicolas", "nicolas@gmail.com","12345", "Planche", "Nicolas", 22, "M", "Lyon", "07777777", "0nicolas", "", "", "", "Coach", sport3, "data/profil3.png");
    EnsembleProfils profils;
    profils.addProfil(profil1);
    assert(profils.existeUsername("youri"));
    assert(profils.existeMail("youri@gmail.com"));
    profils.addProfil(profil2);
    assert(profils.existeUsername("lucas"));
    assert(profils.existeMail("lucas@gmail.com"));
    profils.deleteProfil("youri");
    assert(!profils.existeUsername("youri"));
    assert(!profils.existeMail("youri@gmail.com"));
    profils.addProfil(profil1);
    profils.addProfil(profil3);
    assert(profils.matchTypeSport(profil1)[0] == "lucas");
    assert(profils.matchTypeSport(profil1).size() == 1);
    assert(profils.matchTypeSport(profil3).size() == 0);
    assert(profils.matchAge(21,25,profil1.getUsername())[1] == "nicolas" );
    assert(profils.matchAge(21,25,profil1.getUsername()).size() == 2 );
    assert(profils.matchVille( "Lyon",profil1.getUsername() ).size() == 2);
    assert(profils.matchVille("Lyon",profil1.getUsername() )[0] == "lucas");
    assert(profils.matchVille("Lyon",profil1.getUsername() )[1] == "nicolas");
    assert(profils.matchSexe("F",profil1.getUsername()).size() == 0);
    assert(profils.matchSexe("M",profil1.getUsername()).size() == 2);
    assert(profils.matchingASV(21,21,"M","Lyon",profil1.getUsername()).size() == 1 );
    assert(profils.matchingASV(21,21,"M","Lyon",profil1.getUsername())[0] == "lucas" );
    assert(profils.matching(profil1, 20,22,"Lyon","M").size() == 1);
}