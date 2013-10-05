#ifndef COMIC_VINE_DIALOG_H
#define COMIC_VINE_DIALOG_H

#include <QDialog>
#include <QLineEdit>

#include "comic_db.h"

class QPushButton;
class QStackedWidget;
class QLabel;
class QRadioButton;

class ScrapperLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	ScrapperLineEdit(const QString & title, QWidget * widget = 0);
protected:
	void resizeEvent(QResizeEvent *);
private:
	QLabel * titleLabel;
};

//----------------------------------------
class TitleHeader : public QWidget
{
	Q_OBJECT
public:
	TitleHeader(QWidget * parent = 0);
public slots:
	void setTitle(const QString & title);
	void setSubtitle(const QString & title);
	void showButtons(bool show);
private:
	QLabel * mainTitleLabel;
	QLabel * subTitleLabel;
};

//----------------------------------------
class SeriesQuestion : public QWidget
{
	Q_OBJECT
public:
	SeriesQuestion(QWidget * parent = 0);
	inline bool getYes();
private:
	QRadioButton * yes;
	QRadioButton * no;
};

//----------------------------------------
class SearchSingleComic : public QWidget
{
	Q_OBJECT
public:
	SearchSingleComic(QWidget * parent = 0);
private:
	ScrapperLineEdit * titleEdit;
	ScrapperLineEdit * numberEdit;
	ScrapperLineEdit * volumeEdit;
};

//----------------------------------------
class SearchVolume : public QWidget
{
	Q_OBJECT
public:
	SearchVolume(QWidget * parent = 0);
private:
	ScrapperLineEdit * volumeEdit;
};

//----------------------------------------
class ComicVineDialog : public QDialog
{
	Q_OBJECT
public:
	explicit ComicVineDialog(QWidget *parent = 0);
	QString databasePath;
	QString basePath;
	void setComics(const QList<ComicDB> & comics);
signals:
	
public slots:
	void show();
protected slots:
	void goNext();
private:
	TitleHeader * titleHeader;
	QPushButton * nextButton; 
	QPushButton * closeButton;

	//stacked widgets
	QStackedWidget * content;

	QWidget * infoNotFound;
	QWidget * singleComicBrowser;
	
	void doLayout();
	void doStackedWidgets();
	void doLoading();
	void doConnections();

	QList<ComicDB> comics;

	SeriesQuestion * seriesQuestion;
	SearchSingleComic * searchSingleComic;
	SearchVolume * searchVolume;
};

#endif // COMIC_VINE_DIALOG_H
