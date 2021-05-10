#include "EnsembleProfils.h"
#include <iostream>


using namespace std;
int main()
{
    vector<string> sport;
    Profil profil("", "","", "", "", 0, "", "", "", "", "", "", "", "", sport, "");
    profil.testRegression();
    EnsembleProfils profils;
    profils.testRegression();
    return 0;

}