#ifndef VERSION_H
#define VERSION_H

#include "parser_global.h"
#include <QString>


class PARSERSHARED_EXPORT Version
{
public:
    Version();

    struct Info{
        QString major;
        QString minor;
        QString date;
        QString specifications;
    };

    static Info getVesionInfo();
};

#endif // VERSION_H
