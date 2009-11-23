/*mainFen.cpp 
fichier de l'application Aash, ce fichier est redistribuÈ sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le rÈutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/


#include "mainFen.h"
#include <fstream>
#include <iostream>
 
mainFen::mainFen()
{
  //Creation et gestion du splash screen (pour les config plus modestes)
  QPixmap p_splash (":/ressources/images/TextEditor.png");
  QSplashScreen splash(p_splash);
  splash.show();
  splash.showMessage(tr("Chargement des menus.."));
  
  //intitialisation de la fentre et marquage en temps rel du splash screen
  creerActions();
  creerMenus();
  splash.showMessage(tr("Menus chargés"));
  splash.showMessage(tr("Chargement de la barre d'outils..."));
  creerBarresOutils();
  onglets = new QTabWidget;
  onglets->addTab(creerOnglet(), tr("Scratch"));
  onglets->setTabsClosable ( true );
  onglets->setMovable(true);
  connect(onglets, SIGNAL(tabCloseRequested ( int  )), this, SLOT(croixFermer(int)));
  splash.showMessage(tr("Chargement de l'afficheur principal..."));
  //Ouverture du buffer initial
  
  
  QString adresseFichier(":/ressources/texte/scratch.txt");
  QFile file(adresseFichier);
  if (!file.open(QFile::ReadOnly)) 
    {
           
    }
QTextStream in(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     editeurActuel()->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();
  creerSets();
  //Gestion du titre et connection des onglets
  changementTitre(adresseFichier);
  
  connect(onglets, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));
  connect(editeurActuel(), SIGNAL(textChanged()), this, SLOT(nonSauve()));
  onglets->setDocumentMode(true);
  setCentralWidget(onglets);
  this->setUnifiedTitleAndToolBarOnMac(true);

  
    
  barreEtat = statusBar();
  barreEtat->showMessage("Prêt");
  
  //Proprits de base de la fentre
  setMinimumSize(500, 350);
  setWindowIcon(QIcon(":/ressources/images/TextEditor.png"));
  setWindowTitle(tr("AAash"));
  
}
void mainFen::creerActions()
{
  //Cration des diffrentes actions et connection si besoin aux fonctions requises (voir plus bas)
  actionQuitter = new QAction(tr("&Quitter"), this);
  actionQuitter->setShortcut(tr("Ctrl+Q"));
  connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    
    
  actionAnnuler = new QAction(tr("Annuler"), this);
  actionAnnuler->setShortcut(tr("Ctrl+Z"));
  connect(actionAnnuler, SIGNAL(triggered()), this, SLOT(annuler()));
    
  actionRefaire = new QAction(tr("Refaire"), this);
  actionRefaire->setShortcut(tr("Ctrl+Y"));
  connect(actionRefaire, SIGNAL(triggered()), this, SLOT(refaire()));

  actionZoomer = new QAction(tr("Zoomer"), this);
  actionZoomer->setShortcut(tr("Ctrl+I"));
  connect(actionZoomer, SIGNAL(triggered()), this, SLOT(zoomer()));

  actionDezoomer = new QAction(tr("Dzoomer"), this);
  actionDezoomer->setShortcut(tr("Ctrl+O"));
  connect(actionDezoomer, SIGNAL(triggered()), this, SLOT(dezoomer()));

  actionNouveau = new QAction(QIcon(":/ressources/images/filenew-256.png"),tr("&Nouveau Document"), this);
  actionNouveau->setShortcut(tr("Ctrl+N"));
  connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));

  actionOuvrir = new QAction(QIcon(":/ressources/images/fileopen-256.png"),tr("&Ouvrir"), this);
  actionOuvrir->setShortcut(tr("Ctrl+O"));
  connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrir()));
    
  actionSauver = new QAction(QIcon(":/ressources/images/filesave-256.png"),tr("&Sauvegarder le document"),this);
  actionSauver->setShortcut(tr("Ctrl+S"));
  connect(actionSauver, SIGNAL(triggered()), this, SLOT(sauver()));
    
  actionSauverSous = new QAction(QIcon(":/ressources/images/filesaveas-256.png"),tr("Sauvegarder le document sous..."),this);
  connect(actionSauverSous, SIGNAL(triggered()), this, SLOT(sauverSous()));
    
  actionCopier = new QAction(QIcon(":/ressources/images/editcopy-256.png"),tr("&Copier"),this);
  actionCopier->setShortcut(tr("Ctrl+C"));
  connect(actionCopier, SIGNAL(triggered()), this, SLOT(copier()));

  actionCouper = new QAction(QIcon(":/ressources/images/editcut-256.png"),tr("Couper"),this);
  actionCouper->setShortcut(tr("Ctrl+X"));
  connect(actionCouper, SIGNAL(triggered()), this, SLOT(couper()));
    
  actionColler = new QAction(QIcon(":/ressources/images/editpaste-256.png"),tr("Coller"),this);
  actionColler->setShortcut(tr("Ctrl+V"));
  connect(actionColler, SIGNAL(triggered()), this, SLOT(coller()));

  actionFermer = new QAction(QIcon(":/ressources/images/tab_remove-256.png"),tr("Fermer l'onglet en cours"),this);
  connect(actionFermer, SIGNAL(triggered()), this, SLOT(fermerOnglet()));
    
  actionCompiler = new QAction(QIcon(":/ressources/images/exec-256.png"),tr("Compiler"),this);
  connect(actionCompiler, SIGNAL(triggered()), this, SLOT(compiler()));
  
  actionOuvrirWeb = new QAction(QIcon(":/ressources/images/exec-256.png"),tr("Ouvrir la page dans le navigateur"),this);
  connect(actionOuvrirWeb, SIGNAL(triggered()), this, SLOT(telechargerSourceWeb()));
    
}

void mainFen::creerMenus()
{
  //Creation des menus
  QMenu *menuFichier = menuBar()->addMenu(tr("&Fichier"));
  menuFichier->addAction(actionNouveau);
  menuFichier->addAction(actionOuvrir);
  
  menuFichier->addSeparator();
  
  menuFichier->addAction(actionSauver);
  menuFichier->addAction(actionSauverSous);

  menuFichier->addSeparator();
  
  menuFichier->addAction(actionQuitter);

  
  QMenu *menuEditer = menuBar()->addMenu(tr("&Edition"));
  menuEditer->addAction(actionCopier);
  menuEditer->addAction(actionCouper);
  menuEditer->addAction(actionColler);
  
  menuEditer->addSeparator();
  
  menuEditer->addAction(actionAnnuler);
  menuEditer->addAction(actionRefaire);
  
  menuEditer->addSeparator();
  
  menuEditer->addAction(actionZoomer);
  menuEditer->addAction(actionDezoomer);
  
  menuEditer->addSeparator();
  menuEditer->addAction(actionCompiler);
}

void mainFen::creerBarresOutils()
{
  //Cration de la barre d'outils et de ce qu'elle contiens
  QToolBar *toolBarFichier = addToolBar(tr("Fichier"));
  
  QComboBox *comboLexer = new QComboBox;
  comboLexer->addItem("C++");
  comboLexer->addItem("(x)HTML / PHP");
  comboLexer->addItem("Java");
  comboLexer->addItem("C");
  comboLexer->addItem("C#");
  comboLexer->addItem("XML");
  comboLexer->addItem("Lua");
  comboLexer->addItem("Perl");
  comboLexer->addItem("(La)TeX");
  comboLexer->addItem("JavaScript");
  comboLexer->addItem("Pov-Ray");
  comboLexer->addItem("SQL");
  comboLexer->addItem("D");
  comboLexer->addItem("Makefile");
  comboLexer->addItem("Ini / Config");
  comboLexer->addItem("Ruby");
  connect(comboLexer, SIGNAL(activated(int)), this, SLOT(changementColo(int)));

  toolBarFichier->addAction(actionNouveau);
  toolBarFichier->addAction(actionOuvrir);
  toolBarFichier->addAction(actionSauver);
  toolBarFichier->addAction(actionSauverSous);
  toolBarFichier->addAction(actionCopier);
  toolBarFichier->addAction(actionCouper);
  toolBarFichier->addAction(actionColler);
  toolBarFichier->addAction(actionFermer);
  toolBarFichier->addAction(actionCompiler);
  toolBarFichier->addAction(actionOuvrirWeb);
  toolBarFichier->addWidget(comboLexer);
  
}
QWidget *mainFen::creerOnglet()
{
  //Fonction de cration d'un onglet
  QWidget *pageOnglet = new QWidget;    //le widget conteneur
  QPlainTextEdit *zoneTexte = new QPlainTextEdit;    //la nouvelle zone de texte
  connect(zoneTexte, SIGNAL(textChanged()), this, SLOT(nonSauve())); //Connection du signal de changement de texte  la fonction de marquage de texte modifi
  
  //zoneTexte->setTextFormat(PlainText);
  //Mise en forme des widgets et affichage
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setContentsMargins(0,0,0,0);
  layout->addWidget(zoneTexte);
  pageOnglet->setLayout(layout);
  //creerSets();    //On assigne quelques proprts lmentaires
  
  return pageOnglet;
}
QPlainTextEdit *mainFen::editeurActuel()
{
  return onglets->currentWidget()->findChild<QPlainTextEdit *>(); //fonction permettant d'accder au QScintilla courrament utilis
}
void mainFen::fermerOnglet()
{
  //fonction de fermeture d'onglet, avec une simple vrification
  if (onglets->count() > 1) //Si le nombre d'onglets est suprieur  1, on supprime l'onglet en cours 
    {
      onglets->removeTab(onglets->currentIndex());
    }
  else //Sinon, on empche l'utilisateur, ou il ne pourra plus utiliser le programme
    {
      QMessageBox::critical(this, tr("AquaAash Erreur"), tr("Vous ne pouvez pas supprimer l'onglet courrant car c'est le dernier."));
    }
}
//Fonctions dont le nom est explicite, voir la doc de QScintilla pour plus d'infos sur les fonctions utilises.
void mainFen::nouvelOnglet()
{
  int indexNouvelOnglet = onglets->addTab(creerOnglet(), tr("Nouveau Document"));
  onglets->setCurrentIndex(indexNouvelOnglet);

}
void mainFen::couper()
{
  editeurActuel()->cut();
  
}
void mainFen::copier()
{
  editeurActuel()->copy();
  
}
void mainFen::coller()
{
  editeurActuel()->paste();
  
}
void mainFen::sauver()
{
  //Dbut de la fonction de sauvegarde rapide
  barreEtat->showMessage("Sauvegarde...");
  QString texteASauver = editeurActuel()->toPlainText();//On rcupre le texte du QScintilla actuel
  QString adresseFichier = onglets->tabText(onglets->currentIndex());//Et l'adresse du fichier en cours d'dition
  QFile fichier (adresseFichier);
  if (fichier.open(QFile::WriteOnly))//Boucle d'enregistrement, si on arrive  ouvrir le fichier en mode d'criture uniquement
    {
      QTextStream out(&fichier);//On cr une sortie
      out << texteASauver;//Et on envoie le texte dans la sortie
    }
  barreEtat->showMessage("Fichier Sauvegardé", 3000);
  changementTitre(adresseFichier);
}
void mainFen::sauverSous()
{
  //Mme fonction que ci dessus, seul change le procd de dtermination de l'adresse du document
  QString texteASauver = editeurActuel()->toPlainText();
  QString adresseFichier = QFileDialog::getSaveFileName(this, "Enregistrer le document", QString(), "Tout document texte(*.*)");
  QFile fichier (adresseFichier);
  if (fichier.open(QFile::WriteOnly))
    {
      QTextStream out(&fichier);
      out << texteASauver;
    }

  changementTitre(adresseFichier);
}
void mainFen::ouvrir()
{
  
  QString texteOuvert(""); 
  QString adresseFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(),  "Tout document texte(*.*)"); //On rcupre l'adresse du fichier
  if (adresseFichier != "")
    {
      QFile file(adresseFichier);
      if (file.open(QFile::ReadOnly)) //Si on peut ouvrir le document en mode de lecture uniquement
	{
	  QTextStream in(&file);//On cr une entre
	  int compteur = 0;
	  while (!in.atEnd()) //Tant qu'on est pas arriv  la fin du document
	    {
	      texteOuvert += in.readLine() + "\n";//On ajoute la ligne parcourue  l'entre, avec un retour  la ligne  la fin
	      compteur++;
	    }
	 texteOuvert = texteOuvert.toUtf8();
	 

	}
      
      int indexTabDocOuvert = onglets->addTab(creerOnglet(), tr("Nouveau Document"));
      onglets->setCurrentIndex(indexTabDocOuvert);
         // display contents
         editeurActuel()->setPlainText(texteOuvert);
         
	 if (adresseFichier.right(4)==".cpp")
	    {
	      highlighterCCPP = new Highlighter(editeurActuel()->document());
	    }
	 else if (adresseFichier.right(2)==".c")
	    {
	      highlighterCCPP = new Highlighter(editeurActuel()->document());
	    }
	 else if (adresseFichier.right(5)==".html")
	    {
	      highlighterhtml = new highlighterHTML(editeurActuel()->document());
	    }
	 else if (adresseFichier.right(4)==".php")
	    {
	      highlighterhtml = new highlighterHTML(editeurActuel()->document());
	    }
   changementTitre(adresseFichier);
   connect(editeurActuel(), SIGNAL(cursorPositionChanged()), this, SLOT(updateLigne()));
   creerSets();
     }
}

void mainFen::changementOnglet(int index)
{
  QString adresseFichier  = onglets->tabText(onglets->currentIndex());

  changementTitre(adresseFichier);
  creerSets();
    
}
void mainFen::changementColo(int indexCombo)
{
  if (indexCombo == 0)
    {  
      Highlighter *highlighterCCPP = new Highlighter(editeurActuel()->document()); 

    }
   else if (indexCombo == 1)
     {
       highlighterHTML *highlighterhtml = new highlighterHTML(editeurActuel()->document());
       //highlighterhtml->setDocument(editeurActuel()->document());
     }
}
void mainFen::changementTitre(QString adresseFichier)
{ //Fonction pompe, désolé :D
  QString titreComplet = adresseFichier;
  QString titreCourt = titreComplet;

  
  if (titreComplet.size() > 40)
    {
      titreCourt = "..." + titreComplet.right(40);
    }
    
 
  setWindowTitle(titreCourt + " - " + tr("AquaAsh"));
  onglets->setTabText(onglets->currentIndex(), titreComplet);
}

bool mainFen::nonSauve()
{
  QString titre = windowTitle();
  QString b_titre = onglets->tabText(onglets->currentIndex());//Pour une amlioration future
  if (titre.left(1) != "*")//Si le document n'est pas encore marqu comme non sauv
    {
      titre = "*"+titre+"*";// on ajoute une toile de chaque cot du titre du document pour signaler qu'il est rest sans sauvegarde
      setWindowTitle(titre + " - " + tr("Aash"));// et on update le titre
      return true;
    }
  else
    {
      return false;
    }
  
  
  
}
void mainFen::annuler()
{
  editeurActuel()->undo();
}
void mainFen::refaire()
{
  editeurActuel()->redo();
}
void mainFen::zoomer()
{
  //editeurActuel()->zoomIn(1);
}
void mainFen::dezoomer()
{
  //editeurActuel()->zoomOut(1);
}
void mainFen::creerSets()
{

}
void mainFen::compiler()
{
  /*// QString slash = "";
  QString adresseCompilation = "cd " + onglets->tabText(onglets->currentIndex());
  
    adresseCompilation = adresseCompilation.remove(adresseCompilation.right(1));
 
  char *adresseCompilationChar = "";
  adresseCompilationChar = adresseCompilation.toAscii().data();
  system(adresseCompilationChar);
  system("qmake");
  system("make -f /Users/Paul/Documents/mash/Makefile");*/
}

void mainFen::closeEvent(QCloseEvent *event)
 {
   QString titre = windowTitle();
   if (titre.left(1) == "*") 
       {
	 int reponse = QMessageBox::question(this, tr("Sauvegarder les fichiers"), tr("Le fichier en cours est modifié, voulez vous le sauvegarder?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	 if (reponse == QMessageBox::Yes)
	   {
	     sauver();
	     event->accept();
	   }
	 else if (reponse == QMessageBox::No)
	   {
	    event->accept();
	   }
	 else if (reponse == QMessageBox::Cancel)
	   {
	    event->ignore();
	   }
       }
   else
     {
       event->accept();
     }
 }
void mainFen::croixFermer(int indexOnglet)
 {if (onglets->count() > 1) //Si le nombre d'onglets est suprieur  1, on supprime l'onglet en cours 
    {
      onglets->removeTab(indexOnglet);
    }
   
  else //Sinon, on empche l'utilisateur, ou il ne pourra plus utiliser le programme
    {
      QMessageBox::critical(this, tr("AquaAash Erreur"), tr("Vous ne pouvez pas supprimer l'onglet courrant car c'est le dernier."));
    }
   
 }
void mainFen::updateLigne()
 {
   int lignes = 0;
   int colonnes = 0;
   lignes = editeurActuel()->textCursor().blockNumber()+1;
   colonnes = editeurActuel()->textCursor().columnNumber();
   QString sLignes = QString::number(lignes);
   QString sColonnes = QString::number(colonnes);
   barreEtat->showMessage("Ligne n° : "+ sLignes +"\t Colonne n° : " + sColonnes);

  
 }
void mainFen::telechargerSourceWeb()
 {

 

#if defined(Q_WS_WIN) // Si on est sous Windows
   QProcess::startDetached("cmd /c start "+ onglets->tabText(onglets->currentIndex()));
#endif
#if defined(Q_WS_MAC) // Si on est sous Mac
   QProcess::startDetached("open " + onglets->tabText(onglets->currentIndex()));
#endif
#if defined(Q_WS_X11) // Si on est sous Linux
   QProcess::startDetached("firefox " + onglets->tabText(onglets->currentIndex()));
#endif
  
 }
