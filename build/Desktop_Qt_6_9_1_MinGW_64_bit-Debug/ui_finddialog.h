/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *findLabel;
    QLineEdit *findEdit;
    QCheckBox *caseSensitiveCheck;
    QPushButton *findNextButton;
    QPushButton *closeButton;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName("FindDialog");
        gridLayout = new QGridLayout(FindDialog);
        gridLayout->setObjectName("gridLayout");
        findLabel = new QLabel(FindDialog);
        findLabel->setObjectName("findLabel");

        gridLayout->addWidget(findLabel, 0, 0, 1, 1);

        findEdit = new QLineEdit(FindDialog);
        findEdit->setObjectName("findEdit");

        gridLayout->addWidget(findEdit, 0, 1, 1, 2);

        caseSensitiveCheck = new QCheckBox(FindDialog);
        caseSensitiveCheck->setObjectName("caseSensitiveCheck");

        gridLayout->addWidget(caseSensitiveCheck, 1, 0, 1, 2);

        findNextButton = new QPushButton(FindDialog);
        findNextButton->setObjectName("findNextButton");

        gridLayout->addWidget(findNextButton, 1, 2, 1, 1);

        closeButton = new QPushButton(FindDialog);
        closeButton->setObjectName("closeButton");

        gridLayout->addWidget(closeButton, 2, 2, 1, 1);


        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276", nullptr));
        findLabel->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        findEdit->setPlaceholderText(QCoreApplication::translate("FindDialog", "\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\346\226\207\346\234\254", nullptr));
        caseSensitiveCheck->setText(QCoreApplication::translate("FindDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        findNextButton->setText(QCoreApplication::translate("FindDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        closeButton->setText(QCoreApplication::translate("FindDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
