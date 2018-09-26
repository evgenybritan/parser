#ifndef PARSER_H
#define PARSER_H

#include "parser_global.h"
#include <QString>

class PARSERSHARED_EXPORT Parser
{
public:
    Parser();
    Parser(QString &filename, QString &resultparse);

    QString filename() const;
    void getfilename(QString &filename);

    QString resultparse() ;
    void parse(QString &resultparse);

private:
    QString mFilename;
    QString mResult;
};

#endif // PARSER_H
