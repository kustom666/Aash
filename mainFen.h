/*mainFen.h
fichier de l'application Aash, ce fichier est redistribué sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le réutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/


#ifndef DEF_MAINFEN
#define DEF_MAINFEN
#include "highlighterhtml.h"
#include "Highlighter.h"
#include <QtGui>

class mainFen : public QMainWindow
{
    Q_OBJECT

    public:
        mainFen();

    private:
        void creerActions();
        void creerMenus();
        void creerBarresOutils();
	void creerSets();

        QWidget *creerOnglet();
        QPlainTextEdit *editeurActuel();
	Highlighter *highlighterCCPP;
	highlighterHTML *highlighterhtml;
    private slots:

	void updateLigne();
	void nouvelOnglet();
	void fermerOnglet();
	void couper();
	void copier();
	void coller();
	void sauver();
	void telechargerSourceWeb();
	void sauverSous();
	void changementOnglet(int);
	void changementTitre(QString);
	void ouvrir();
	void croixFermer(int);
	void changementColo(int);
	void annuler();
	void refaire();
	void zoomer();
	void dezoomer();
	void compiler();
	void closeEvent(QCloseEvent *event);
	bool nonSauve();


    private:
	QLCDNumber *compteurLignes ;
        QTabWidget *onglets;
	QStatusBar *barreEtat;
        QAction *actionQuitter;
	QAction *actionAnnuler;
	QAction *actionRefaire;
	QAction *actionNouveau;
	QAction *actionZoomer;
	QAction *actionDezoomer;
	QAction *actionOuvrir;
	QAction *actionSauver;
	QAction *actionSauverSous;
	QAction *actionCopier;
	QAction *actionCouper;
	QAction *actionColler;
        QAction *actionFermer;
	QAction *actionCPP;
	QAction *actionHTML;
	QAction *actionCompiler;
	QAction *actionCSS;
	QAction *actionOuvrirWeb;
	QString *texteCombo;
	QFile *file;
	QComboBox *comboLexer;
	QStatusBar *barreLignes;
	QSettings *settings;
	int *compteur;
};


#endif
