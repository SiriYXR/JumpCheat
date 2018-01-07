#pragma once

#include <QtWidgets/QMainWindow>
#include <QAbstractNativeEventFilter>
#include <QLabel>
#include <QSpinBox>

#include <windows.h>

class Cheat : public QMainWindow, public QAbstractNativeEventFilter
{
	Q_OBJECT

public:
	Cheat(QWidget *parent = Q_NULLPTR);
	~Cheat();
protected:
	virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;
	int hk1;
	int hk2;
	int hk3;
	int hk4;
	HWND id;
	POINT start;
	POINT end;

	QLabel *labPoint1;
	QLabel *labPoint2;
	QLabel *labKValue;
	QLabel *labInfor;

	QSpinBox *spinKValue;

	bool isFirst;
};
