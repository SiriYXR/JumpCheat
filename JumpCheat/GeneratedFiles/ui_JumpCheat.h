/********************************************************************************
** Form generated from reading UI file 'JumpCheat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUMPCHEAT_H
#define UI_JUMPCHEAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JumpCheatClass
{
public:

    void setupUi(QWidget *JumpCheatClass)
    {
        if (JumpCheatClass->objectName().isEmpty())
            JumpCheatClass->setObjectName(QStringLiteral("JumpCheatClass"));
        JumpCheatClass->resize(600, 400);

        retranslateUi(JumpCheatClass);

        QMetaObject::connectSlotsByName(JumpCheatClass);
    } // setupUi

    void retranslateUi(QWidget *JumpCheatClass)
    {
        JumpCheatClass->setWindowTitle(QApplication::translate("JumpCheatClass", "JumpCheat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JumpCheatClass: public Ui_JumpCheatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUMPCHEAT_H
