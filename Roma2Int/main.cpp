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
 * @brief		检查罗马数字字符串是否有效
 * @param 		[in] romaString		罗马数字字符串
 * @return		true 有效，false 无效
 */
bool checkVaild(const QString & romaString) {

    bool ret = true;
    QString::const_iterator itBegin = romaString.begin();
    while (itBegin != romaString.end()) {

        // 迭代器下一个位置
        QString::const_iterator itNext = itBegin + 1;

        // 当前迭代字符为 I
        if ((*itBegin) == "I") {

            // I 为最后一个
            if (itNext == romaString.end()) {
                return true;
            }

            // I 的下一个字符大于 I，且不能与 I 组合
            if ((*itNext) != "I" && (*itNext) != "V" && (*itNext) != "X") {
                return false;
            }
        }
        else if ((*itBegin) == "V" &&
            ((*itNext) == "V" || (*itNext) == "X" || (*itNext) == "L" ||
             (*itNext) == "C" || (*itNext) == "D" || (*itNext) == "M")) {
            return false;
        }

        ++itBegin;
    }



    return ret;
}

/**
 * @brief		单个罗马数字转整形值
 * @param 		[in] singleRomaString 	罗马数字字符串
 * @return		整型值
 */
int singleRomanToInt(const QString &singleRomaString) {

    int translate = 0;
    if (0 == singleRomaString.compare("I", Qt::CaseInsensitive)) {
        translate = ROMA_I;
    }
    else if (0 == singleRomaString.compare("V", Qt::CaseInsensitive)) {
        translate = ROMA_V;
    }
    else if (0 == singleRomaString.compare("X", Qt::CaseInsensitive)) {
        translate = ROMA_X;
    }
    else if (0 == singleRomaString.compare("L", Qt::CaseInsensitive)) {
        translate = ROMA_L;
    }
    else if (0 == singleRomaString.compare("C", Qt::CaseInsensitive)) {
        translate = ROMA_C;
    }
    else if (0 == singleRomaString.compare("D", Qt::CaseInsensitive)) {
        translate = ROMA_D;
    }
    else if (0 == singleRomaString.compare("M", Qt::CaseInsensitive)) {
        translate = ROMA_M;
    }
    else {
        translate = ROMA_UNKNOWN;
    }


    return translate;
}

/**
 * @brief		罗马数字字符串转为整型值
 * @param 		[in] romaString		罗马数字字符串
 * @return		整型值
 */
int romanToInt(const QString &romaString) {

    int translate = 0;
    int translateTmp = 0;

    QString::const_iterator itBegin = romaString.begin();
    while (itBegin != romaString.end()) {

        ++itBegin;
    }


    foreach (QChar c, romaString) {

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

    qDebug() << "IV" << checkVaild("IV");
    qDebug() << "VI" << checkVaild("VI");

    qDebug() << "IX" << checkVaild("IX");
    qDebug() << "XI" << checkVaild("XI");

    qDebug() << "IL" << checkVaild("IL");
    qDebug() << "LI" << checkVaild("LI");

    qDebug() << "IC" << checkVaild("IC");
    qDebug() << "CI" << checkVaild("CI");

    qDebug() << "ID" << checkVaild("ID");
    qDebug() << "DI" << checkVaild("DI");

    qDebug() << "IM" << checkVaild("IM");
    qDebug() << "MI" << checkVaild("MI");



    return a.exec();
}
