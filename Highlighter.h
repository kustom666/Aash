/*highlighter.h
fichier de l'application Aash, ce fichier est redistribué sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le réutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/


#ifndef HIGHLIGHTER_H_INCLUDED
#define HIGHLIGHTER_H_INCLUDED
#include <QtGui>
class Highlighter : public QSyntaxHighlighter
 {
     Q_OBJECT

 public:
     Highlighter(QTextDocument *parent = 0);


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
     int icolCR;
     int icolCV;
     int icolCB;
     QString colCR;
     QString colCV;
     QString colCB;
     QTextCharFormat keywordFormat;
     QTextCharFormat ifFormat;
     QTextCharFormat classFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat multiLineCommentFormat;
     QTextCharFormat includeFormat;
     QTextCharFormat pointeurFormat;
     QTextCharFormat guilleFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat functionFormat;
 };


#endif // HIGHLIGHTER_H_INCLUDED
