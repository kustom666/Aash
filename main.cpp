/*Main.cpp 
fichier de l'application Aash, ce fichier est redistribu� sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le r�utilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/


#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "mainFen.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QApplication::setLibraryPaths(QStringList(QString("plugins/")));
    // Traduction des cha�nes pr�d�finies par Qt dans notre langue
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    // Ouverture de la fen�tre principale du navigateur
    mainFen principale;
    
    principale.show();
    
    return app.exec();
}
