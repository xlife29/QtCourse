/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *findLabel;
    QLineEdit *findEdit;
    QLabel *replaceLabel;
    QLineEdit *replaceEdit;
    QCheckBox *caseSensitiveCheck;
    QPushButton *findNextButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName("ReplaceDialog");
        ReplaceDialog->setModal(true);
        gridLayout = new QGridLayout(ReplaceDialog);
        gridLayout->setObjectName("gridLayout");
        findLabel = new QLabel(ReplaceDialog);
        findLabel->setObjectName("findLabel");

        gridLayout->addWidget(findLabel, 0, 0, 1, 1);

        findEdit = new QLineEdit(ReplaceDialog);
        findEdit->setObjectName("findEdit");

        gridLayout->addWidget(findEdit, 0, 1, 1, 3);

        replaceLabel = new QLabel(ReplaceDialog);
        replaceLabel->setObjectName("replaceLabel");

        gridLayout->addWidget(replaceLabel, 1, 0, 1, 1);

        replaceEdit = new QLineEdit(ReplaceDialog);
        replaceEdit->setObjectName("replaceEdit");

        gridLayout->addWidget(replaceEdit, 1, 1, 1, 3);

        caseSensitiveCheck = new QCheckBox(ReplaceDialog);
        caseSensitiveCheck->setObjectName("caseSensitiveCheck");

        gridLayout->addWidget(caseSensitiveCheck, 2, 0, 1, 4);

        findNextButton = new QPushButton(ReplaceDialog);
        findNextButton->setObjectName("findNextButton");

        gridLayout->addWidget(findNextButton, 3, 0, 1, 1);

        replaceButton = new QPushButton(ReplaceDialog);
        replaceButton->setObjectName("replaceButton");

        gridLayout->addWidget(replaceButton, 3, 1, 1, 1);

        replaceAllButton = new QPushButton(ReplaceDialog);
        replaceAllButton->setObjectName("replaceAllButton");

        gridLayout->addWidget(replaceAllButton, 3, 2, 1, 1);

        closeButton = new QPushButton(ReplaceDialog);
        closeButton->setObjectName("closeButton");

        gridLayout->addWidget(closeButton, 3, 3, 1, 1);


        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\345\222\214\346\233\277\346\215\242", nullptr));
        findLabel->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\345\206\205\345\256\271\357\274\232", nullptr));
        findEdit->setPlaceholderText(QCoreApplication::translate("ReplaceDialog", "\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\346\226\207\346\234\254", nullptr));
        replaceLabel->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272\357\274\232", nullptr));
        replaceEdit->setPlaceholderText(QCoreApplication::translate("ReplaceDialog", "\350\276\223\345\205\245\346\233\277\346\215\242\346\226\207\346\234\254", nullptr));
        caseSensitiveCheck->setText(QCoreApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        findNextButton->setText(QCoreApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        replaceButton->setText(QCoreApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        replaceAllButton->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242", nullptr));
        closeButton->setText(QCoreApplication::translate("ReplaceDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
