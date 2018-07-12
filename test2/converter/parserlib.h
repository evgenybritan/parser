#ifndef PARSERLIB_H
#define PARSERLIB_H

#include "parserlib_global.h"
#include <QString>

class PARSERLIBSHARED_EXPORT Parserlib
{
public:
    Parserlib(QString);
    QString _path;
    QByteArray Bytes;
    int HB0, HB1, HB2, SB0, SB1, SB2, SB3, SB4, SB5, SB6, PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15, PB16, PB17, PB18, PB19, PB20, PB21, PB22, PB23, PB24, PB25, PB26, PB27;
    int bit, High_Bits, Low_Bits, way, h0, h1, h2;
    QString result, arr, high, low, s0,s1,s2,s3,s4,s5,s6,p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27;
};

#endif // PARSERLIB_H
