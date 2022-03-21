/**
 * @brief			leetcode 13 题：罗马数字转 Int 值
 * @author		Koter
 * @date			2022-03-21
 *
 */
#include <QCoreApplication>
#include <QString>
#include <QChar>
#include <QDebug>

// 罗马数字对应的整型值
#define		ROMA_UNKNOWN	-1
#define 	ROMA_I			1
#define		ROMA_V			5
#define		ROMA_X			10
#define		ROMA_L			50
#define		ROMA_C			100
#define		ROMA_D			500
#define		ROMA_M			1000

/**
 * @brief		单个罗马数字转整形值
 * @param 		[in] c 	罗马数字
 * @return		[out]	整型值
 */
int singleRomanToInt(const QChar &c) {

    int translate = 0;
    switch (c.toLatin1()) {
    case 'I':
        translate = ROMA_I;
        break;
    case 'V':
        translate = ROMA_V;
        break;
    case 'X':
        translate = ROMA_X;
        break;
    case 'L':
        translate = ROMA_L;
        break;
    case 'C':
        translate = ROMA_C;
        break;
    case 'D':
        translate = ROMA_D;
        break;
    case 'M':
        translate = ROMA_M;
        break;
    default:
        translate = ROMA_UNKNOWN;
    }

    return translate;
}


int romanToInt(const QString &s) {

    int translate = 0;
    int translateTmp = 0;
    foreach (QChar c, s) {

        if (c.isNull()) {
            continue;
        }

        translateTmp = singleRomanToInt(c);
        if (translateTmp) {
            translate += translateTmp;
        }
    }

    return translate;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "III = " << romanToInt("III");

    return a.exec();
}
