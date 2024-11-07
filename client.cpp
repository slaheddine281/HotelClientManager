
#include "client.h"

Client::Client() {}

Client::Client(int id, QString n, QString p, QString e, QString addr, int tel, QString t, QString nat, int cin, int ref, int nb)
{
    this->id_client = id;
    this->nom = n;
    this->prenom = p;
    this->mail = e;
    this->adresse = addr;
    this->telephone = tel;
    this->type = t;
    this->nationalite = nat;
    this->CIN = cin;
    this->reference_reservation = ref;
    this->nbpointcadeau = nb;
}

bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (id_client, nom, prenom, mail, adresse, telephone, type, nationalite, CIN, reference_reservation, nbpointcadeau) "
                  "VALUES (:id_client, :nom, :prenom, :mail, :adresse, :telephone, :type, :nationalite, :CIN, :reference_reservation, :nbpointcadeau)");
    query.bindValue(":id_client", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":type", type);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":CIN", CIN);
    query.bindValue(":reference_reservation", reference_reservation);
    query.bindValue(":nbpointcadeau", nbpointcadeau);

    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Reference Reservation"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Nb Point Cadeau"));

    return model;
}

bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE id_client = :id");
    query.bindValue(":id", id);

    return query.exec();
}

bool Client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET nom=:nom, prenom=:prenom, mail=:mail, adresse=:adresse, telephone=:telephone, "
                  "type=:type, nationalite=:nationalite, CIN=:CIN, reference_reservation=:reference_reservation, nbpointcadeau=:nbpointcadeau "
                  "WHERE id_client=:id_client");
    query.bindValue(":id_client", id_client);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":type", type);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":CIN", CIN);
    query.bindValue(":reference_reservation", reference_reservation);
    query.bindValue(":nbpointcadeau", nbpointcadeau);

    return query.exec();
}
