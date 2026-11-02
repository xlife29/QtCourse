/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *infoLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName("verticalLayout");
        iconLabel = new QLabel(AboutDialog);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(28);
        iconLabel->setFont(font);

        verticalLayout->addWidget(iconLabel);

        titleLabel = new QLabel(AboutDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        titleLabel->setFont(font1);

        verticalLayout->addWidget(titleLabel);

        infoLabel = new QLabel(AboutDialog);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLabel);

        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "\345\205\263\344\272\216\347\256\200\345\215\225\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        iconLabel->setText(QCoreApplication::translate("AboutDialog", "\360\237\223\235", nullptr));
        titleLabel->setText(QCoreApplication::translate("AboutDialog", "\347\256\200\345\215\225\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        infoLabel->setText(QCoreApplication::translate("AboutDialog", "Qt Widgets \346\226\207\346\234\254\347\274\226\350\276\221\345\231\250\\n\346\224\257\346\214\201\346\226\207\346\234\254\346\226\207\344\273\266\347\274\226\350\276\221\343\200\201\346\237\245\346\211\276\346\233\277\346\215\242\345\222\214\346\240\274\345\274\217\350\256\276\347\275\256\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
