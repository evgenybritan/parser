#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <QString>

enum Packet_type{
  Null ,
  Audio_Clock_Regeneration,
  Audio_Sample,
  General_Control,
  ACP_Packet,
  ISRC1_Packet,
  ISRC2_Packet,
  One_Bit_Audio_Sample_Packet,
  DST_Audio_Packet,
  High_Bitrate_Audio_Stream_Packet,
  Gamut_Metadata_Packet,
  InfoFrame_Packet
};
class Parser
{

public:
    Parser(QString);
    void parse(QString);

private:
    QString _path;
};

#endif // PARSER_H
