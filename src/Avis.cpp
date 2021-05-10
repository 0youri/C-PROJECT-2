#include "Avis.h"

Avis::Avis(const string nusername, const bool nlike, const string ncommentaire)
{
	ausername = nusername;
	like = nlike;
	commentaire = ncommentaire;
}
 
Avis::~Avis()
{
	ausername = "";
	like = false;
	commentaire = "";
}

string Avis::getUsername() const
{
	return ausername;
}

bool Avis::getLike() const
{
	return like;
}

string Avis::getCommentaire() const
{
	return commentaire;
}

void Avis::setLike()
{
	like = !like;
}

void Avis::deleteCommentaire()
{
	commentaire = "";
}


