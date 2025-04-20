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

    int Year, Month, Day, Hour, Min, Sec;

    if (match1)
    {
        Year = input1.mid(0, 4).toInt();
        Month = input1.mid(4, 2).toInt();
        Day = input1.mid(6, 2).toInt();
        Hour = input1.mid(9, 2).toInt();
        Min = input1.mid(11, 2).toInt();
        Sec = input1.mid(13, 2).toInt();
        qDebug() << "Строка " << input1 << " is Ok for:" << pattern1 << ": Year=" << Year << " Month=" << Month << " Day=" << Day << " Hour=" << Hour << " Min=" << Min << " Sec=" << Sec;
    }
    else
    {
        qDebug() << "Строка " << input1 << " не соответствует регулярному выражению:" << pattern1;
    }

    if (match2)
    {
        Year = input2.mid(0, 4).toInt();
        Month = input2.mid(5, 2).toInt();
        Day = input2.mid(8, 2).toInt();
        Hour = input2.mid(11, 2).toInt();
        Min = input2.mid(14, 2).toInt();
        Sec = input2.mid(17, 2).toInt();
        qDebug() << "Строка " << input1 << " is Ok for:" << pattern2 << ": Year=" << Year << " Month=" << Month << " Day=" << Day << " Hour=" << Hour << " Min=" << Min << " Sec=" << Sec;
    }
    else
    {
        qDebug() << "Строка " << input2 << " не соответствует регулярному выражению:" << pattern2;
    }

    return a.exec();
}
