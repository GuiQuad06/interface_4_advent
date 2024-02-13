#include "puzzle.h"

#include <QStringList>

int puzzle_2023_1(QString &result, const QString &input) {

    QStringList line_list;
    unsigned int acc = 0;
    QString a = "", b = "";

    if(!input.isEmpty()) {
        // Split the input into lines
        line_list.append(input.split("\n"));
    }

    // Process the input
    for (auto line : line_list) {
        // Process the line from the begining
        for (auto it = line.begin(); it != line.end(); ++it) {
            QChar c = *it;
            if (c.isDigit()) {
                a.append(c);
                break;
            }
        }
        // Process the line from the end
        for (auto it = line.rbegin(); it != line.rend(); ++it) {
            QChar c = *it;
            if (c.isDigit()) {
                b.append(c);
                break;
            }
        }
        acc += (a + b).toUInt();
        a.clear();
        b.clear();
    }
    result = QString::number(acc);

    return 0;
}
