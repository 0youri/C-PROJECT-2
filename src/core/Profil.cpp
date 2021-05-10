#include "Profil.h"
#include <cassert>
#include <vector>

using namespace std;

Profil::Profil()
{
    username = mail = password = nom = prenom = sexe = ville = portable = ig = sc = fb = tt = type_profil = photo = "";
    age = -1;
}

Profil::Profil(const string nusername, const string nmail, const string npassword, const string nnom,const string nprenom, const int nage, 
    const string nsexe,const string nville, const string nportable, const string nig, const string nsc , const string nfb, 
    const string ntt, const string ntype_profil, const vector<string> ntype_sport, const string nphoto)
{
    username = nusername;
    mail = nmail;
    password = npassword;
    nom = nnom;
    prenom = nprenom;
    age = nage;
    sexe = nsexe;
    ville = nville;
    portable = nportable;
    ig = nig;
    sc = nsc;
    fb = nfb;
    tt = ntt;
    type_profil = ntype_profil;
    type_sport = ntype_sport;
    photo = nphoto;
}

Profil::~Profil()
{
    this->vider();
}

void Profil::vider()
{
    username = mail = password = nom = prenom = sexe = ville = portable = ig = sc = fb = tt = type_profil = photo = "";
    age = 0;
    type_sport.clear();
    avis.clear();
    followers.clear();
    following.clear();
}

string Profil::getUsername() const
{
    return username;
}

string Profil::getMail() const
{
    return mail;
}

string Profil::getPassword() const
{
    return password;
}

string Profil::getNom() const
{
    return nom;
}

string Profil::getPrenom() const
{
    return prenom;
}

int Profil::getAge() const
{
    return age;
}

string Profil::getSexe() const
{
    return sexe;
}

string Profil::getVille() const
{
    return ville;
}

string Profil::getPortable() const
{
    return portable;
}

string Profil::getIG() const
{
    return ig;
}

string Profil::getSC() const
{
    return sc;
}

string Profil::getFB() const
{
    return fb;
}

string Profil::getTT() const
{
    return tt;
}

string Profil::getTypeProfil() const
{
    return type_profil;
}

vector<string> Profil::getTypeSport() const
{
    return type_sport;
}

string Profil::getPhoto() const
{
    return photo;
}

vector<string> Profil::getFollowers() const
{
    return followers;
}

vector<string> Profil::getFollowing() const
{
    return following;
}

vector<Avis> Profil::getAvis() const
{
    return avis;
}

void Profil::setUsername(const string nusername)
{
    username = nusername;
}

bool Profil::setMail(const string nmail, const string apassword)
{
    if ( password == apassword )
    {
        mail = nmail;
        return true;
    }
    else return false;
}

bool Profil::setPassword(const string npassword, const string apassword)
{
    if ( password == apassword )
    {
        password = npassword;
        return true;
    }
    return false;
}

void Profil::setNom(const string nnom)
{
    nom = nnom;
}

void Profil::setPrenom(const string nprenom)
{
    prenom = nprenom;
}

void Profil::setAge(const int nage)
{
    age = nage;
}


void Profil::setSexe(const string nsexe)
{
    sexe = nsexe;
}

void Profil::setVille(const string nville)
{
    ville = nville;
}

void Profil::setPortable(const string nportable)
{
    portable = nportable;
}

void Profil::setIG(const string nig)
{
    ig = nig;
}

void Profil::setSC(const string nsc)
{
    sc = nsc;
}

void Profil::setFB(const string nfb)
{
    fb = nfb;
}

void Profil::setTT(const string ntt)
{
    tt = ntt;
}

void Profil::setTypeProfil(const string ntype_profil)
{
    type_profil = ntype_profil;
}

void Profil::setPhoto(const string nphoto)
{
    photo = nphoto;
}

void Profil::ajouterTypeSport(const string ntype_sport)
{
    type_sport.push_back(ntype_sport);
}

void Profil::ajouterFollowers(const string ausername)
{
    followers.push_back(ausername);
}

void Profil::ajouterFollowing(const string ausername)
{
    following.push_back(ausername);
}

void Profil::creationAvis(const string ausername, const bool like, const string commentaire)
{
    Avis navis(ausername, like,commentaire );
    avis.push_back(navis);
}

void Profil::deleteTypeSport(const string dtype_sport)
{
    for ( int i = 0; i < type_sport.size(); i++ )
    {
        if ( type_sport[i] == dtype_sport )
        {
            type_sport.erase(type_sport.begin()+i);
            break;
        }
    }
}

void Profil::deleteFollowers(const string dfollowers)
{
    for ( int i = 0; i < followers.size(); i++ )
    {
        if ( followers[i] == dfollowers )
        {
            followers.erase(followers.begin()+i);
            break;
        }
    }
}

void Profil::deleteFollowing(const string dfollowing)
{
    for ( int i = 0; i < following.size(); i++ )
    {
        if ( following[i] == dfollowing )
        {
            following.erase(following.begin()+i);
            break;
        }
    }
}

void Profil::deleteProfil(const string apassword)
{
    if ( password == apassword )
    {
        username = mail = password = nom = prenom = sexe = ville = portable = ig = sc = fb = tt = type_profil = photo = "";
        age = 0;
        type_sport.clear();
        avis.clear();
        followers.clear();
        following.clear();
    }
}

void Profil::testRegression()
{
    vector<string> sport = {"sport1", "sport2", "sport3"};
    Profil profil1("youri", "youri@gmail.com","12345", "Novikov", "Youri", 20, "M", "Lyon", "07777777", "0youri", "", "", "", "Spotif", sport, "data/profil1.png");
    assert(profil1.getUsername() == "youri");
    assert(profil1.getMail() == "youri@gmail.com");
    assert(profil1.getNom() == "Novikov");
    assert(profil1.getPrenom() == "Youri");
    assert(profil1.getAge() == 20);
    assert(profil1.getSexe() == "M");
    assert(profil1.getVille() == "Lyon");
    assert(profil1.getPortable() == "07777777");
    assert(profil1.getIG() == "0youri"); 
    assert(profil1.getSC() == ""); 
    assert(profil1.getFB() == "");
    assert(profil1.getTT() == "");
    assert(profil1.getTypeProfil() == "Spotif");
    assert(profil1.getTypeSport()[1] == "sport2");
    assert(profil1.getPhoto() == "data/profil1.png");
    profil1.setUsername("iruoy");
    assert(profil1.getUsername() == "iruoy");
    profil1.setMail("iruoy@gmail.com", "12345");
    assert(profil1.getMail() == "iruoy@gmail.com");
    profil1.setPassword("54321","12345");
    profil1.setMail("dsqdqsdsq@gmail.com", "54321");
    assert(profil1.getMail() == "dsqdqsdsq@gmail.com");
    profil1.setNom("Nov");
    assert(profil1.getNom() == "Nov");
    profil1.setPrenom("You");
    assert(profil1.getPrenom() == "You");
    profil1.setAge(18);
    assert(profil1.getAge() == 18);
    profil1.setSexe("F");
    assert(profil1.getSexe() == "F");
    profil1.setVille("Villeurbanne");
    assert(profil1.getVille() == "Villeurbanne");
    profil1.setPortable("088888888");
    assert(profil1.getPortable() == "088888888");
    profil1.setTypeProfil("Coach");
    assert(profil1.getTypeProfil() == "Coach");
    profil1.ajouterTypeSport("sport4");
    assert(profil1.getTypeSport()[3] == "sport4");
    profil1.ajouterFollowers("lucas");
    assert(profil1.getFollowers()[0] == "lucas");
    profil1.ajouterFollowers("nicolas");
    assert(profil1.getFollowers()[1] == "nicolas");
    profil1.ajouterFollowing("nicolas");
    assert(profil1.getFollowing()[0] == "nicolas");
    profil1.ajouterFollowing("lucas");
    assert(profil1.getFollowing()[1] == "lucas");
    profil1.creationAvis("lucas", true, "");
    assert(profil1.getAvis()[0].getLike());
    assert(profil1.getAvis()[0].getUsername() == "lucas");
    profil1.creationAvis("nicolas", false, "dqsdqsd");
    assert(!profil1.getAvis()[1].getLike());
    assert(profil1.getAvis()[1].getCommentaire() == "dqsdqsd");
    profil1.deleteTypeSport("sport2");
    assert(profil1.getTypeSport()[1] != "sport2");
    profil1.deleteFollowers("lucas");
    assert(profil1.getFollowers()[0] != "lucas");
    profil1.deleteFollowing("nicolas");
    assert(profil1.getFollowing()[0] != "nicolas");
    profil1.deleteProfil("54321");
    assert(profil1.getUsername() == "");
}


void Profil::operator=(const Profil & recopie)
{
    this->vider();

    username = recopie.username;
    mail = recopie.mail;
    password = recopie.password;
    nom = recopie.nom;
    prenom = recopie.prenom;
    sexe = recopie.sexe;
    ville = recopie.ville;
    portable = recopie.portable;
    ig = recopie.ig;
    sc = recopie.sc;
    fb = recopie.fb;
    tt = recopie.tt;
    type_profil = recopie.type_profil;
    age = recopie.age;
    type_sport = recopie.type_sport;
    avis = recopie.avis;
    followers = recopie.followers;
    following = recopie.following;
}


bool Profil::existeFollowers(const string susername)
{
    for(int i=0; i < followers.size(); i++)
    {
        if(susername == followers[i])
        {
            return true;
        }
    }
    return false;
}

bool Profil::existeFollowing(const string susername)
{
    for(int i=0; i < following.size(); i++)
    {
        if(susername == following[i])
        {
            return true;
        }
    }
    return false;
}