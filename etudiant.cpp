#include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Etudiant::Etudiant()
{
id=0; nom=" "; prenom=" ";
}


Etudiant::Etudiant(int id,QString nom,QString prenom)
{this->id=id;
 this->nom=nom;
 this->prenom=prenom;
}

int Etudiant::getid(){return id;}
QString Etudiant::getnom(){return nom;}
QString Etudiant::getprenom(){return prenom;}


void Etudiant::setid(int id){this->id=id;}
void Etudiant::setnom(QString nom){this->nom=nom;}
void Etudiant::setprenom(QString prenom){this->prenom=prenom;}


bool Etudiant::ajouter()
{
   QString id_string= QString::number(id);
   QSqlQuery query;
        query.prepare("INSERT INTO ETUDIANT (ID, NOM, PRENOM) "
                      "VALUES (:id, :forename, :surname)");
        query.bindValue(":id", id_string);
        query.bindValue(":forename", nom);
        query.bindValue(":surname", prenom);
        return query.exec();
}
bool Etudiant::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
         query.prepare("Delete from etudiant where ID=:id");
         query.bindValue(":id", res);
         return query.exec();


}
QSqlQueryModel* Etudiant::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM etudiant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));

    return model;
}
