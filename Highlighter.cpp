/*Highlighter.cpp 
fichier de l'application Aash, ce fichier est redistribu sous license GNU/GPL merci de laisser ce commentaire
Et de toujours citer l'auteur de ce fichier si vous le rutilisez. La license est disponible dans le dossier ressources/license
Auteur : Kustom*/


#include "Highlighter.h"
#include <QFile>
#include <QtXml>
#include <iostream>

using namespace std;

 Highlighter::Highlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {

   

  QDomDocument doc;

  // Read the DOM tree form file
 
  QFile f("ressources/xml/colC.xml");
  f.open(QIODevice::ReadOnly);
  doc.setContent(&f);
  f.close();

  // Parse the DOM tree

  // The root node is supposed to be a "stone" tag, we retrieve its name
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
	  if (child.tagName() == "couleurClass")
	  {
		  // We traverse children
		  QDomElement grandChild=child.firstChild().toElement();
		  while(!grandChild.isNull())
		  {
			  // We know how to treat color
			  if (grandChild.tagName() == "couleurRouge")
			  {
				  colCR = grandChild.text();
				  
				  icolCR=colCR.toInt();
				 
			  }
			  
			  else if (grandChild.tagName() == "couleurVert")
			  {
				  colCV = grandChild.text();
				  icolCV=colCV.toInt();
				 
			  }
			  
			  else if (grandChild.tagName() == "couleurBleu")
			  {
				  colCB = grandChild.text();
				  icolCB=colCB.toInt();
			  }
			  
			  grandChild = grandChild.nextSibling().toElement();
		  }
		  
	  }
	  
   child = child.nextSibling().toElement();
  }
     HighlightingRule rule;

     keywordFormat.setForeground(QColor(icolMclefR, icolMclefV, icolMclefB));
     keywordFormat.setFontWeight(QFont::Bold);

     QStringList keywordPatterns;
 keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                     << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                     << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                     << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                     << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                     << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                     << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                     << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                     << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                     << "\\bvoid\\b" << "\\bvolatile\\b";
     foreach (QString pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }
     
     
     ifFormat.setForeground(QColor(icolIR, icolIV, icolIB));
     QStringList ifPatterns;
     ifPatterns << "\\bif\\b" << "\\belse\\b" << "\\belif\\b"
                     << "\\break\\b" << "\\bcase\\b" << "\\bswitch\\b"
                     << "\\bfriend\\b" << "\\binline\\b" << "\\return\\b"
					<< "\\do\\b"<< "\\cin\\b"<< "\\cout\\b"<< "\\new\\b"<< "\\const\\b"<< "\\foreach\\b"<< "\\while\\b";
     foreach (QString pattern, ifPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = ifFormat;
         highlightingRules.append(rule);
     }
     
 

     classFormat.setForeground(QColor(icolCR, icolCV, icolCB));
     rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
     rule.format = classFormat;
     highlightingRules.append(rule);

     singleLineCommentFormat.setForeground(Qt::darkRed);
     rule.pattern = QRegExp("//[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);

     includeFormat.setForeground(Qt::darkMagenta);
     rule.pattern = QRegExp("\\#[A-Za-z]+\\b");
     rule.format = includeFormat;
     highlightingRules.append(rule);
     
     pointeurFormat.setForeground(QColor(222,152,22));
     rule.pattern = QRegExp("\\*[A-Za-z]+\\b");
     rule.format = pointeurFormat;
     highlightingRules.append(rule);

     multiLineCommentFormat.setForeground(Qt::darkRed);

     quotationFormat.setForeground(QColor(255, 0, 0));
     rule.pattern = QRegExp("\".*\"");
     rule.format = quotationFormat;
     highlightingRules.append(rule);
     
     guilleFormat.setForeground(QColor(188, 122, 0));
     rule.pattern = QRegExp("\\<.*\\>");
     rule.format = guilleFormat;
     highlightingRules.append(rule);

     //functionFormat.setFontItalic(true);
     functionFormat.setForeground(Qt::darkBlue);
     rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
     rule.format = functionFormat;
     highlightingRules.append(rule);

     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");
 }

 void Highlighter::highlightBlock(const QString &text)
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
