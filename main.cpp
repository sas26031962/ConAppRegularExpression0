/*
20151129_082830.jpg
2015-11-29 08-28-30.JPG

*/

#include <QCoreApplication>
#include <QRegularExpression>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString pattern = "[0-9]+"; // Регулярное выражение: одна или более цифр
    QString pattern1 = "^20[0-9]{6}_[0-9]{6}\\.jpg$";
    QString pattern2 = "^20[0-9]{2}-[0-9]{2}-[0-9]{2} [0-9]{2}-[0-9]{2}-[0-9]{2}\\.jpg";

    QRegularExpression re1(pattern1);
    QRegularExpression re2(pattern2);

    QString input1 = "20151129_082830.jPg";
    QString input2 = "2015-11-29 08-28-30.JPG";

    bool match1 = re1.match(input1.toLower()).hasMatch();
    bool match2 = re2.match(input2.toLower()).hasMatch();

    if (match1) {
        qDebug() << "Строка " << input1 << " соответствует регулярному выражению:" << pattern1;
    } else {
        qDebug() << "Строка " << input1 << " не соответствует регулярному выражению:" << pattern1;
    }

    if (match2) {
        qDebug() << "Строка " << input2 << " соответствует регулярному выражению:" << pattern2;
    } else {
        qDebug() << "Строка " << input2 << " не соответствует регулярному выражению:" << pattern2;
    }

    return a.exec();
}
