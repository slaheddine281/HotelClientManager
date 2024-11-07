
#ifndef CLIENT_H
#define CLIENT_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
    int id_client;
    QString nom;
    QString prenom;
    QString mail;
    QString adresse;
    int telephone;
    QString type;  // "visiteur" or "resident"
    QString nationalite;
    int CIN;
    int reference_reservation;
    int nbpointcadeau;

public:
    Client();
    Client(int, QString, QString, QString, QString, int, QString, QString, int, int, int);

    // Getters
    int getIdClient() { return id_client; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getMail() { return mail; }
    QString getAdresse() { return adresse; }
    int getTelephone() { return telephone; }
    QString getType() { return type; }
    QString getNationalite() { return nationalite; }
    int getCIN() { return CIN; }
    int getReferenceReservation() { return reference_reservation; }
    int getNbPointCadeau() { return nbpointcadeau; }

    // Setters
    void setIdClient(int id) { id_client = id; }
    void setNom(QString n) { nom = n; }
    void setPrenom(QString p) { prenom = p; }
    void setMail(QString e) { mail = e; }
    void setAdresse(QString addr) { adresse = addr; }
    void setTelephone(int tel) { telephone = tel; }
    void setType(QString t) { type = t; }
    void setNationalite(QString nat) { nationalite = nat; }
    void setCIN(int c) { CIN = c; }
    void setReferenceReservation(int ref) { reference_reservation = ref; }
    void setNbPointCadeau(int nb) { nbpointcadeau = nb; }

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
};

#endif // CLIENT_H
