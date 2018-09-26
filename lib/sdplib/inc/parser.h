#ifndef PARSER_H
#define PARSER_H

#include "parser_global.h"
#include <QString>


class PARSERSHARED_EXPORT Parser
{
public:
    Parser();

    enum Error{
        NO_ERRORS       = 0,
        FILE_NOT_FOUND  = 1,
        INVALID_PACKET  = 2
    };

    Error parse(QString const filename, QString &result);


};

#endif // PARSER_H
