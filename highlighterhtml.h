/*highlighterhtml.h
fichier de l'application Aash, ce fichier est redistribuÈ sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le rÈutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/

#ifndef HIGHLIGHTERHTML_H_INCLUDED
#define HIGHLIGHTERHTML_H_INCLUDED
#include "QtGui"
class highlighterHTML : public QSyntaxHighlighter
 {
     Q_OBJECT

 public:
     highlighterHTML(QTextDocument *parent = 0);
    
 protected:
     void highlightBlock(const QString &text);

 private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QRegExp commentStartExpression;
     QRegExp commentEndExpression;

     QTextCharFormat balisesFormat;
     QTextCharFormat fonctionFormat;
 
     QTextCharFormat specFormat;
     QTextCharFormat commentaireFormat;
     QTextCharFormat texteFormat;
     QTextCharFormat bTexteFormat;
     
     QTextCharFormat motsClefFormat;
     QTextCharFormat multiLineCommentFormat;

      int icolMclefR;
     int icolMclefV;
     int icolMclefB;
     QString colMclefR;
     QString colMclefV;
     QString colMclefB;
     int icolIR;
     int icolIV;
     int icolIB;
     QString colIR;
     QString colIV;
     QString colIB;
     int icolSpecR;
     int icolSpecV;
     int icolSpecB;
     QString colSpecR;
     QString colSpecV;
     QString colSpecB;
     
 };


#endif // HIGHLIGHTER_H_INCLUDED
