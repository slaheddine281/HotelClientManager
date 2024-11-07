#include "mainwindow.h"
#include "QMessageBox"
#include "qlineedit.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(client.afficher()); // Actualisation initiale de la tableView
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id_c = ui->lineEdit_id->text().toInt();
    QString nom_c = ui->lineEdit_nom->text();
    QString prenom_c = ui->lineEdit_prenom->text();
    QString email_c = ui->lineEdit_email->text();
    QString adresse_c = ui->lineEdit_adresse->text();
    int numtel_c = ui->lineEdit_numtel->text().toInt();
    QString type_c = ui->comboBox_type->currentText();
    QString nationalite_c = ui->lineEdit_nationalite->text();
    int cin_c = ui->lineEdit_cin->text().toInt();
    int reference_c = ui->lineEdit_reference->text().toInt();
    int nbpoints_c = ui->lineEdit_points->text().toInt();

    Client cl(id_c, nom_c, prenom_c, email_c, adresse_c, numtel_c, type_c, nationalite_c, cin_c, reference_c, nbpoints_c);

    bool test = cl.ajouter();
    if (test) {
        ui->tableView->setModel(client.afficher()); // Actualiser la tableView
        QMessageBox::information(nullptr, QObject::tr("Ajouter un client"), QObject::tr("Client ajouté avec succès!"), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'ajout a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_c = ui->lineEdit_id->text().toInt();

    bool test = client.supprimer(id_c);
    if (test) {
        ui->tableView->setModel(client.afficher()); // Actualiser la tableView
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"), QObject::tr("Client supprimé avec succès!"), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La suppression a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id_c = ui->lineEdit_id->text().toInt();
    QString nom_c = ui->lineEdit_nom->text();
    QString prenom_c = ui->lineEdit_prenom->text();
    QString email_c = ui->lineEdit_email->text();
    QString adresse_c = ui->lineEdit_adresse->text();
    int numtel_c = ui->lineEdit_numtel->text().toInt();
    QString type_c = ui->comboBox_type->currentText();
    QString nationalite_c = ui->lineEdit_nationalite->text();
    int cin_c = ui->lineEdit_cin->text().toInt();
    int reference_c = ui->lineEdit_reference->text().toInt();
    int nbpoints_c = ui->lineEdit_points->text().toInt();

    client.setIdClient(id_c);
    client.setNom(nom_c);
    client.setPrenom(prenom_c);
    client.setMail(email_c);
    client.setAdresse(adresse_c);
    client.setTelephone(numtel_c);
    client.setType(type_c);
    client.setNationalite(nationalite_c);
    client.setCIN(cin_c);
    client.setReferenceReservation(reference_c);
    client.setNbPointCadeau(nbpoints_c);

    bool test = client.modifier();
    if (test) {
        ui->tableView->setModel(client.afficher()); // Actualiser la tableView
        QMessageBox::information(nullptr, QObject::tr("Modifier un client"), QObject::tr("Client modifié avec succès!"), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La modification a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tableView->setModel(client.afficher()); // Affiche tous les clients
}
QLineEdit
