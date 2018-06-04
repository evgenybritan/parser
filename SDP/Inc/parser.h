#ifndef PARSER_H
#define PARSER_H



#include <QString>


class Parser
{

public:
    Parser(QString);
    void parse(QString);

private:
    QString _path;
};

#endif // PARSER_H
