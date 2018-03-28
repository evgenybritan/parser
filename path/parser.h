#ifndef PARSER_H
#define PARSER_H


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <QString>

using namespace std;

class parser_packet
{
private:
    QString path;
public:
    parser_packet(QString);
    void parse(QString);
};

#endif // PARSER_H
