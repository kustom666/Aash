/*highlighterhtml.cpp 
fichier de l'application Aash, ce fichier est redistribuÈ sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le rÈutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/



#include "highlighterhtml.h"

#include <QFile>
#include <QtXml>
#include <iostream>

 highlighterHTML::highlighterHTML(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {


  QDomDocument doc;

  // Read the DOM tree form file
 
  QFile f("ressources/xml/colHTML.xml");
  f.open(QIODevice::ReadOnly);
  doc.setContent(&f);
  f.close();

  // Parse the DOM tree

  
  QDomElement root=doc.documentElement();
 
  // We traverse its children
QDomElement child=root.firstChild().toElement();
  while(!child.isNull())
  {
	  if (child.tagName() == "couleurMotsClef")
      {
		  QDomElement grandChild=child.firstChild().toElement();
		  while(!grandChild.isNull())
		  {
			  // We know how to treat color
			  if (grandChild.tagName() == "couleurRouge")
			  {
				  colMclefR = grandChild.text();
				  
				  icolMclefR=colMclefR.toInt();
				  
			  }
			  
			  else if (grandChild.tagName() == "couleurVert")
			  {
				  colMclefV = grandChild.text();
				  icolMclefV=colMclefV.toInt();
				  
			  }
			  
			  else if (grandChild.tagName() == "couleurBleu")
			  {
				  colMclefB = grandChild.text();
				  icolMclefB=colMclefB.toInt();
			  }
			  
			  grandChild = grandChild.nextSibling().toElement();
		  }
		  
      }
	  else if (child.tagName() == "couleurIf")
      {
	QDomElement grandChild=child.firstChild().toElement();
      while(!grandChild.isNull())
	{
	// We know how to treat color
	if (grandChild.tagName() == "couleurRouge")
	  {
	    colIR = grandChild.text();
	    
	    icolIR=colIR.toInt();

	  }
    
	else if (grandChild.tagName() == "couleurVert")
	  {
	    colIV = grandChild.text();
		  icolIV=colIV.toInt();

	  }

	else if (grandChild.tagName() == "couleurBleu")
	  {
	    colIB = grandChild.text();
	    icolIB=colIB.toInt();
	  }
	
      grandChild = grandChild.nextSibling().toElement();
      }
	
      }
	  if (child.tagName() == "couleurSpec")
	  {
		  // We traverse children
		  QDomElement grandChild=child.firstChild().toElement();
		  while(!grandChild.isNull())
		  {
			  // We know how to treat color
			  if (grandChild.tagName() == "couleurRouge")
			  {
				  colSpecR = grandChild.text();
				  
				  icolSpecR=colSpecR.toInt();
				 
			  }
			  
			  else if (grandChild.tagName() == "couleurVert")
			  {
				  colSpecV = grandChild.text();
				  icolSpecV=colSpecV.toInt();
				 
			  }
			  
			  else if (grandChild.tagName() == "couleurBleu")
			  {
				  colSpecB = grandChild.text();
				  icolSpecB=colSpecB.toInt();
			  }
			  
			  grandChild = grandChild.nextSibling().toElement();
		  }
		  
	  }
	  
   child = child.nextSibling().toElement();
  }

     HighlightingRule rule;

     motsClefFormat.setForeground(QColor(icolMclefR, icolMclefV, icolMclefB));
     motsClefFormat.setFontWeight(QFont::Bold);
     QStringList motsClefPatterns;
     motsClefPatterns << "\\bscript\\b"
                      << "\\bstyle\\b"<< "\\bh1\\b"<< "\\bacronym\\b"<< "\\bh2\\b"<< "\\bh3\\b"<< "\\bh4\\b"<< "\\bh5\\b"<< "\\boption\\b"<< "\\bselect\\b"<< "\\bblockquote\\b"<<"\\bcite\\b"<< "\\bq\\b"<< "\\bsub\\b"<< "\\bsup\\b"<< "\\bem\\b"<< "\\bimg\\b"<<"\\bdel\\b"<< "\\bins\\b"<< "\\bdfl\\b"<< "\\bkbd\\b"<< "\\bdl\\b"<< "\\bdt\\b"<< "\\bdd\\b"<< "\\btbody\\b"<< "\\btfoot\\b"<<  "\\bhr\\b"<<  "\\binput\\b"<< "\\bvalue\\b"<< "\\bfont\\b"<< "\\bcolor\\b"
                     << "\\bmeta\\b" << "\\bpre\\b"<< "\\btd\\b"<< "\\btr\\b"<< "\\btbody\\b"<< "\\btable\\b" << "\\bcontent\\b"
                     << "\\bhead\\b" << "\\bbody\\b" << "\\b/body\\b"<< "\\b/ul\\b"<< "\\bul\\b"<< "\\bspan\\b"<< "\\b/span\\b"<< "\\bli\\b"<< "\\b/li\\b"<< "\\ba\\b"<< "\\b/a\\b"<< "\\bp\\b"<< "\\bhttp\\b"<< "\\bhttp-equiv\\b"<< "\\bhtml\\b"<< "\\bxmlns\\b"<< "\\b/p\\b"<< "\\b/strong\\b"<< "\\bstrong\\b"<< "\\bbr\\b"<< "\\bbr/\\b"
		      << "\\b/head\\b"<< "\\blink\\b" "\\bhref=\\b"<< "\\bcontent=\\b"<< "\\btype=\\b"<< "\\btype\\b"<< "\\boptgroup\\b"<< "\\b/\\b"<< "\\bdiv\\b"<< "\\b/div\\b"<< "\\bform\\b"<< "\\bmethod\\b"<< "\\bform=\\b"<< "\\bmethod=\\b"<< "\\btt\\b"<< "\\bth\\b"<< "\\bb\\b"<< "\\bi\\b"<< "\\bhr\\b"<< "\\bthead\\b";
     foreach (QString pattern, motsClefPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = motsClefFormat;
         highlightingRules.append(rule);
     }
     
     specFormat.setForeground(QColor(icolSpecR, icolSpecV, icolSpecB));
     QStringList specPatterns;
     specPatterns << "DOCTYPE" << "!DOCTYPE" << "PUBLIC"<< "\\btitle\\b"<< "\\blabel\\b"<< "\\bvalue\\b"<< "\\bmedia\\b"<< "\\btitle=\\b"<< "\\bname\\b"<< "\\btype\\b" << "\\bsrc\\b"<< "\\balign\\b"<< "\\bwidth\\b" << "\\bhref\\b"<< "\\bclass\\b"<< "\\bid\\b" << "\\bhref=\\b" << "\\balt=\\b"<< "\\brel\\b" << "\\brel=\\b"<< "\\bname=\\b"<< "\\balt\\b"<< "\\bvalign\\b";
     foreach (QString pattern, specPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = specFormat;
         highlightingRules.append(rule);
     }

     fonctionFormat.setForeground(QColor(30,127,123));
     QStringList fonctionPatterns;
     fonctionPatterns << "echo";
     foreach (QString pattern, fonctionPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = fonctionFormat;
         highlightingRules.append(rule);
     }

     balisesFormat.setForeground(Qt::darkBlue);
     balisesFormat.setFontWeight(QFont::Bold);
     QStringList balisesPatterns;
     balisesPatterns << "<" << ">" << "/>";
     foreach (QString pattern, balisesPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = balisesFormat;
         highlightingRules.append(rule);
     }
     
     
     texteFormat.setForeground(Qt::darkRed);
     rule.pattern = QRegExp("\".*\"");
     rule.format = texteFormat;
     highlightingRules.append(rule);
     
  

     /*
     bTexteFormat.setForeground(QColor(9, 106, 9));
     rule.pattern = QRegExp("\\>[A-Za-z]\\<");
     rule.format = bTexteFormat;
     highlightingRules.append(rule);*/

     /* balisesFormat.setForeground(Qt::darkBlue);
     rule.pattern = QRegExp("\\<.*\\>");
     rule.format = balisesFormat;
     highlightingRules.append(rule);*/
     
     multiLineCommentFormat.setForeground(Qt::darkRed);
     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");
    
 }

 void highlighterHTML::highlightBlock(const QString &text)
 {
     foreach (HighlightingRule rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = text.indexOf(expression);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = text.indexOf(expression, index + length);
         }
     }
     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = text.indexOf(commentStartExpression);

     while (startIndex >= 0) {
         int endIndex = text.indexOf(commentEndExpression, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + commentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, multiLineCommentFormat);
         startIndex = text.indexOf(commentStartExpression,
                                                 startIndex + commentLength);
     }
 }
