#ifndef FULCRUM_X16RV2_H
#define FULCRUM_X16RV2_H

#include <QByteArray>

namespace X16RV2 {
    QByteArray HashX16RV2(const QByteArray &header, const QByteArray &prevHash);
}

#endif // FULCRUM_X16RV2_H
