#include "Cheat.h"

#include <QApplication>
#include <QCoreApplication>

#include <QDebug>

Cheat::Cheat(QWidget *parent) : QMainWindow(parent)
{
	start.x =start.y= 0;
	end.x = end.y = 0;
	id = reinterpret_cast<HWND>(this->winId());
	hk1 = GlobalAddAtomA("Ctrl+A");
	hk2 = GlobalAddAtomA("Ctrl+S");
	hk3 = GlobalAddAtomA("Ctrl+D");

	RegisterHotKey(id, hk1, MOD_CONTROL, 0x41);
	RegisterHotKey(id, hk2, MOD_CONTROL, 0x53);
	RegisterHotKey(id, hk3, MOD_CONTROL, 0x44);
	qApp->installNativeEventFilter(this);

	setWindowTitle(u8"ÌøÒ»Ìø¸¨Öú");
	setFixedSize(250,100);

	labPoint1 = new QLabel(this);
	labPoint1->setGeometry(10, 10, 200, 30);
	labPoint1->setText("Point1:(0,0)");

	labPoint2 = new QLabel(this);
	labPoint2->setGeometry(10, 40, 200, 30);
	labPoint2->setText("Point2:(0,0)");

	labInfor = new QLabel(this);
	labInfor->setGeometry(130, 10, 200, 80);
	labInfor->setText("Mark Point1:Ctrl+A \n\nMark Point2:Ctrl+S \n\nPlay:Ctrl+D");
}

Cheat::~Cheat()
{
	UnregisterHotKey(id, hk1);
	UnregisterHotKey(id, hk2);
	UnregisterHotKey(id, hk3);
}

bool Cheat::nativeEventFilter(const QByteArray & eventType, void * message, long * result)
{
	MSG *msg = static_cast<MSG *>(message);
	if (msg->message != WM_HOTKEY)
	{
		return false;
	}

	auto parameter = msg->wParam;
	if (parameter == hk1) {
		GetCursorPos(&start);
		char str[255];
		sprintf(str, "Point1:(%d,%d)", start.x, start.y);
		labPoint1->setText(str);
		
		return true;
	}
	else if (parameter == hk2) {
		GetCursorPos(&end);
		char str[255];
		sprintf(str, "Point2:(%d,%d)", end.x, end.y);
		labPoint2->setText(str);
	
		return true;
	}
	else if (parameter == hk3) {
		double t = sqrt((end.x - start.x)*(end.x - start.x) + (end.y - start.y)*(end.y - start.y));

		t *= 3;

		int s = (int)t;

		if (t - s >= 0.5)
		{
			++s;
		}

		INPUT    Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		Sleep(s);

		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		::SendInput(1, &Input, sizeof(INPUT));
		return true;
	}

	return false;
}
