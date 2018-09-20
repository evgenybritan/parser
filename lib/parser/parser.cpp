#include "parser.h"
#include <stdlib.h>
#include <QString>
#include <QFile>
#include <QObject>

using namespace std;

static const int INFO_FRAME_PACKET_BIT = 0x80;
int HB0, HB1, HB2, SB0, SB1, SB2, SB3, SB4, SB5, SB6, PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15, PB16, PB17, PB18, PB19, PB20, PB21, PB22, PB23, PB24, PB25, PB26, PB27;


Parser::Parser():
    mFilename(""),
    mResult("")
{
}

Parser::Parser(QString &filename, QString &resultparse):
    mFilename(filename),
    mResult(resultparse)
{
}

QString Parser::filename() const
{
    //parce(QString &filename, QString &resultparce);
    return mFilename;
}

void Parser::getfilename(QString &filename)
{
    QFile fileIn(filename);
    if(fileIn.open(QIODevice::ReadOnly)){

        bool ok;
        QString h0=fileIn.read(2);
        QString h1=fileIn.read(3);
        QString h2=fileIn.read(3);
        HB0=h0.toInt(&ok,16);
        HB1=h1.toInt(&ok,16);
        HB2=h2.toInt(&ok,16);
        if ((HB0&INFO_FRAME_PACKET_BIT) ==0){
        QString s0=fileIn.read(4);
        QString s1=fileIn.read(3);
        QString s2=fileIn.read(3);
        QString s3=fileIn.read(3);
        QString s4=fileIn.read(3);
        QString s5=fileIn.read(3);
        QString s6=fileIn.read(3);
        SB0=s0.toInt(&ok,16);
        SB1=s1.toInt(&ok,16);
        SB2=s2.toInt(&ok,16);
        SB3=s3.toInt(&ok,16);
        SB4=s4.toInt(&ok,16);
        SB5=s5.toInt(&ok,16);
        SB6=s6.toInt(&ok,16);
        }
        else{
        QString p0=fileIn.read(4);
        QString p1=fileIn.read(3);
        QString p2=fileIn.read(3);
        QString p3=fileIn.read(3);
        QString p4=fileIn.read(3);
        QString p5=fileIn.read(3);
        QString p6=fileIn.read(3);
        QString p7=fileIn.read(3);
        QString p8=fileIn.read(3);
        QString p9=fileIn.read(3);
        QString p10=fileIn.read(3);
        QString p11=fileIn.read(3);
        QString p12=fileIn.read(3);
        QString p13=fileIn.read(3);
        QString p14=fileIn.read(3);
        QString p15=fileIn.read(3);
        QString p16=fileIn.read(3);
        QString p17=fileIn.read(3);
        QString p18=fileIn.read(3);
        QString p19=fileIn.read(3);
        QString p20=fileIn.read(3);
        QString p21=fileIn.read(3);
        QString p22=fileIn.read(3);
        QString p23=fileIn.read(3);
        QString p24=fileIn.read(3);
        QString p25=fileIn.read(3);
        QString p26=fileIn.read(3);
        QString p27=fileIn.read(3);
        PB0=p0.toInt(&ok,16);
        PB1=p1.toInt(&ok,16);
        PB2=p2.toInt(&ok,16);
        PB3=p3.toInt(&ok,16);
        PB4=p4.toInt(&ok,16);
        PB5=p5.toInt(&ok,16);
        PB6=p6.toInt(&ok,16);
        PB7=p7.toInt(&ok,16);
        PB8=p8.toInt(&ok,16);
        PB9=p9.toInt(&ok,16);
        PB10=p10.toInt(&ok,16);
        PB11=p11.toInt(&ok,16);
        PB12=p12.toInt(&ok,16);
        PB13=p13.toInt(&ok,16);
        PB14=p14.toInt(&ok,16);
        PB15=p15.toInt(&ok,16);
        PB16=p16.toInt(&ok,16);
        PB17=p17.toInt(&ok,16);
        PB18=p18.toInt(&ok,16);
        PB19=p19.toInt(&ok,16);
        PB20=p20.toInt(&ok,16);
        PB21=p21.toInt(&ok,16);
        PB22=p22.toInt(&ok,16);
        PB23=p23.toInt(&ok,16);
        PB24=p24.toInt(&ok,16);
        PB25=p25.toInt(&ok,16);
        PB26=p26.toInt(&ok,16);
        PB27=p27.toInt(&ok,16);
        }
    }
}

QString Parser::resultparse()
{
    QByteArray Bytes, byte;
    int bit, High_Bits, Low_Bits;
    QString result, high, low;

    bit = HB0;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=high+low;

    bit = HB1;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = HB2;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

   if ((HB0&INFO_FRAME_PACKET_BIT) ==0){
    bit = SB0;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB1;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB2;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB3;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB4;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB5;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = SB6;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low+"\n";
}
   if (((HB0&INFO_FRAME_PACKET_BIT) !=0) && ((HB2&0xE0) == 0)){

    bit = PB0;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB1;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB2;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB3;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB4;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB5;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB6;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB7;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB8;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB9;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB10;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB11;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB12;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB13;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB14;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB15;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB16;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB17;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB18;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB19;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB20;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB21;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB22;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB23;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB24;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB25;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB26;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low;

    bit = PB27;
    High_Bits=(bit&0xF0)>>4;
    Low_Bits=bit&0x0F;
    high=QString("%1").arg(High_Bits,0,16);
    low=QString("%1").arg(Low_Bits,0,16);
    result+=" "+high+low+"\n";
}

   switch (HB0) {
   case 0x00:
       result+= "Packet type: Null \n"  ;
       break;
   case 0x01:
       result+= "Packet type: Audio Clock Regeneration \n"  ;
       if ((HB1 | HB2 | SB0 |(SB1>>4) | (SB4>>4)) == 0){
           long CTS = (SB1<<16)|(SB2<<8)|SB3;
           long N = (SB4<<16)|(SB5<<8)|SB6;
           QString cts = QString::number(CTS);
           QString n = QString::number(N);
           result+= "СTS: " + cts + " \n"  ;
           result+= "N: " + n + " \n"  ;
       }
       else{
           result+= "*invalid packet* \n"  ;
       }
       break;
   case 0x02:
       result+= "Packet type: Audio Sample \n"  ;
       if ((HB1>>5) == 0){
             long layout = HB1&0x10;
             long spX = HB1&0xF;
             long sfX = HB2&0xF;
             long B = HB2&(0xF0);
             long L = (SB0<<4)|(SB1<<12)|(SB2+20);
             long R = (SB3<<4)|(SB4<<12)|(SB5+20);
             long Vl =(SB6&0x01);
             long Vr =(SB6&0x10);
             long Ul =(SB6&0x02);
             long Ur =(SB6&0x20);
             long Cl =(SB6&0x04);
             long Cr =(SB6&0x40);
             long Pl =(SB6&0x08);
             long Pr =(SB6&0x80);
             QString lay = QString::number(layout);
             QString spx = QString::number(spX);
             QString sfx = QString::number(sfX);
             QString b = QString::number(B);
             QString l = QString::number(L);
             QString r = QString::number(R);
             QString vl = QString::number(Vl);
             QString vr = QString::number(Vr);
             QString ul = QString::number(Ul);
             QString ur = QString::number(Ur);
             QString cl = QString::number(Cl);
             QString cr = QString::number(Cr);
             QString pl = QString::number(Pl);
             QString pr = QString::number(Pr);
             result+= "Layout: " + lay + " \n"  ;
             result+= "sample_present.spX: " + spx + " \n"  ;
             result+= "sample_flat.spX: " + sfx + " \n"  ;
             result+= "B: " + b + " \n"  ;
             result+= "L: " + l + " \n"  ;
             result+= "R: " + r + " \n"  ;
             result+= "Vl: " + vl + " \n"  ;
             result+= "Vr: " + vr + " \n"  ;
             result+= "Ul: " + ul + " \n"  ;
             result+= "Ur: " + ur + " \n"  ;
             result+= "Cl: " + cl + " \n"  ;
             result+= "Cr: " + cr + " \n"  ;
             result+= "Pl: " + pl + " \n"  ;
             result+= "Pr: " + pr + " \n"  ;
        }
       else{
           result+= "*invalid packet* \n"  ;
       }
       break;
   case 0x03:
       result+= "Packet type: General Control \n"  ;
       if ((HB1 | HB2 | (SB0&0xEE) | (SB2>>1) | SB3 | SB4 | SB5 | SB6 )==0){
            long setAVMUTE = (SB0&0x01);
            long clearAVMUTE = (SB0&0x10);
            long PP = (SB1)&(0xF0);
            long CD = (SB1&0xF);
            long defaultPhase = (SB2&0x01);
            QString steavmute = QString::number(setAVMUTE);
            QString clearavmute = QString::number(clearAVMUTE);
            QString pp = QString::number(PP);
            QString cd = QString::number(CD);
            QString defaultphase = QString::number(defaultPhase);
            result+= "Set_AVMUTE: " + steavmute + " \n"  ;
            result+= "Clear_AVMUTE: " + clearavmute + " \n"  ;
            result+= "PP: " + pp + " \n"  ;
            result+= "CD: " + cd + " \n"  ;
            result+= "Default_Phase: " + defaultphase + " \n"  ;

        }
       else{
           result+= "*invalid packet* \n"  ;
       }
       break;
   case 0x04:
       result+="Packet type: ACP Packet \n"  ;
       if (HB2 == 0){
           switch (HB1) {
           case 0x00:
               if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
               result+="ACP_Type: Generic Audio \n";}
               break;
           case 0x01:
               if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
               result+="ACP_Type: IEC 60958-Identified Audio \n";}
               break;
           case 0x02:
               result+="ACP_Type: DVD-Audio \n";
           if ((PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                   long DATDG = (PB0&0xFF);
                   long CopyP = (PB1&0xC0);
                   long CopyN = (PB1&0x38);
                   long Quality = (PB1&0x06);
                   long Trans = (PB1&0x01);
                   QString datdg = QString::number(DATDG);
                   QString Copyp = QString::number(CopyP);
                   QString Copyn = QString::number(CopyN);
                   QString quality = QString::number(Quality);
                   QString trans = QString::number(Trans);
                   result+="DVD-Audio_Type_Dependent_Generation: "+datdg+" \n";
                   result+="Copy_Permission: "+Copyp+" \n";
                   result+="Copy_Number: "+Copyn+" \n";
                   result+="Quality: "+quality+" \n";
                   result+="Transaction: "+trans+" \n";
               }
               break;
          case 0x03:
               result+="ACP_Type: Super Audio CD \n";
               if ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
               long CCI = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 | PB6 | PB7 | PB8 | PB9 | PB10 | PB11 | PB12 | PB13 | PB14 | PB15 ;
               QString cci = QString::number(CCI);
               result+="CCI_1: "+cci+" \n";
               }
           default:
               break;
           }

       }
       break;
   case 0x05:
       result+= "Packet type: ISRC1 Packet \n"  ;
       if (((HB1&0x38) == 0) && (HB2==0)) {
           long Cont = (HB1&0x80);
           long Status = (HB1&0x07);
           long Valid =(HB1&0x40);
           QString cont = QString::number(Cont);
           QString status = QString::number(Status);
           QString valid = QString::number(Valid);
           result+="ISRC_Cont: "+cont+" \n";
           result+="ISRC_Status: "+status+" \n";
           result+="ISRC_Valid: "+valid+" \n";
           if((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
               long UEI0 = PB0;
               long UEI1 = PB1;
               long UEI2 = PB2;
               long UEI3 = PB3;
               long UEI4 = PB4;
               long UEI5 = PB5;
               long UEI6 = PB6;
               long UEI7 = PB7;
               long UEI8 = PB8;
               long UEI9 = PB9;
               long UEI10 = PB10;
               long UEI11 = PB11;
               long UEI12 = PB12;
               long UEI13 = PB13;
               long UEI14 = PB14;
               long UEI15 = PB15;
               QString uei0 = QString::number(UEI0);
               QString uei1 = QString::number(UEI1);
               QString uei2 = QString::number(UEI2);
               QString uei3 = QString::number(UEI3);
               QString uei4 = QString::number(UEI4);
               QString uei5 = QString::number(UEI5);
               QString uei6 = QString::number(UEI6);
               QString uei7 = QString::number(UEI7);
               QString uei8 = QString::number(UEI8);
               QString uei9 = QString::number(UEI9);
               QString uei10 = QString::number(UEI10);
               QString uei11 = QString::number(UEI11);
               QString uei12 = QString::number(UEI12);
               QString uei13 = QString::number(UEI13);
               QString uei14 = QString::number(UEI14);
               QString uei15 = QString::number(UEI15);
               result+="UPC_EAN_ISRC_0"+uei0+" \n";
               result+="UPC_EAN_ISRC_1"+uei1+" \n";
               result+="UPC_EAN_ISRC_2"+uei2+" \n";
               result+="UPC_EAN_ISRC_3"+uei3+" \n";
               result+="UPC_EAN_ISRC_4"+uei4+" \n";
               result+="UPC_EAN_ISRC_5"+uei5+" \n";
               result+="UPC_EAN_ISRC_6"+uei6+" \n";
               result+="UPC_EAN_ISRC_7"+uei7+" \n";
               result+="UPC_EAN_ISRC_8"+uei8+" \n";
               result+="UPC_EAN_ISRC_9"+uei9+" \n";
               result+="UPC_EAN_ISRC_10"+uei10+" \n";
               result+="UPC_EAN_ISRC_11"+uei11+" \n";
               result+="UPC_EAN_ISRC_12"+uei12+" \n";
               result+="UPC_EAN_ISRC_13"+uei13+" \n";
               result+="UPC_EAN_ISRC_14"+uei14+" \n";
               result+="UPC_EAN_ISRC_15"+uei15+" \n";
           }
       }
       break;
   case 0x06:
       result+= "Packet type: ISRC2 Packet \n"  ;
       if ((HB1 == 0) && (HB2 == 0) && ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0)){
           long UEI16 = PB0;
           long UEI17 = PB1;
           long UEI18 = PB2;
           long UEI19 = PB3;
           long UEI20 = PB4;
           long UEI21 = PB5;
           long UEI22 = PB6;
           long UEI23 = PB7;
           long UEI24 = PB8;
           long UEI25 = PB9;
           long UEI26 = PB10;
           long UEI27 = PB11;
           long UEI28 = PB12;
           long UEI29 = PB13;
           long UEI30 = PB14;
           long UEI31 = PB15;
           QString uei16 = QString::number(UEI16);
           QString uei17 = QString::number(UEI17);
           QString uei18 = QString::number(UEI18);
           QString uei19 = QString::number(UEI19);
           QString uei20 = QString::number(UEI20);
           QString uei21 = QString::number(UEI21);
           QString uei22 = QString::number(UEI22);
           QString uei23 = QString::number(UEI23);
           QString uei24 = QString::number(UEI24);
           QString uei25 = QString::number(UEI25);
           QString uei26 = QString::number(UEI26);
           QString uei27 = QString::number(UEI27);
           QString uei28 = QString::number(UEI28);
           QString uei29 = QString::number(UEI29);
           QString uei30 = QString::number(UEI30);
           QString uei31 = QString::number(UEI31);
           result+="UPC_EAN_ISRC_16"+uei16+" \n";
           result+="UPC_EAN_ISRC_17"+uei17+" \n";
           result+="UPC_EAN_ISRC_18"+uei18+" \n";
           result+="UPC_EAN_ISRC_19"+uei19+" \n";
           result+="UPC_EAN_ISRC_20"+uei20+" \n";
           result+="UPC_EAN_ISRC_21"+uei21+" \n";
           result+="UPC_EAN_ISRC_22"+uei22+" \n";
           result+="UPC_EAN_ISRC_23"+uei23+" \n";
           result+="UPC_EAN_ISRC_24"+uei24+" \n";
           result+="UPC_EAN_ISRC_25"+uei25+" \n";
           result+="UPC_EAN_ISRC_26"+uei26+" \n";
           result+="UPC_EAN_ISRC_27"+uei27+" \n";
           result+="UPC_EAN_ISRC_28"+uei28+" \n";
           result+="UPC_EAN_ISRC_29"+uei29+" \n";
           result+="UPC_EAN_ISRC_30"+uei30+" \n";
           result+="UPC_EAN_ISRC_31"+uei31+" \n";
       }
       break;
   case 0x07:
       result+= "Packet type: One Bit Audio Sample Packet \n"  ;
       if (((HB1&0xE0)==0) && ((HB2&0xF0)==0)){
           long layout1 = (HB1&0x10);
           long sp3 = (HB1&0x08);
           long sp2 = (HB1&0x04);
           long sp1 = (HB1&0x02);
           long sp0 = (HB1&0x01);
           long si0 = (HB2&0x01);
           long si1 = (HB2&0x02);
           long si2 = (HB2&0x04);
           long si3 = (HB2&0x08);
           long ChA = (SB0)|(SB1<<8)|(SB2<<16)|(SB6&0xF);
           long ChB = (SB3)|(SB4<<8)|(SB5<<16)|(SB6&0xF);
           QString lay1 = QString::number(layout1);
           QString SP3 = QString::number(sp3);
           QString SP2 = QString::number(sp2);
           QString SP1 = QString::number(sp1);
           QString SP0 = QString::number(sp0);
           QString SI0 = QString::number(si0);
           QString SI1 = QString::number(si1);
           QString SI2 = QString::number(si2);
           QString SI3 = QString::number(si3);
           QString cha = QString::number(ChA);
           QString chb = QString::number(ChB);

           result+="layout: "+lay1+" \n";
           result+="samples_present.sp0: "+SP0+" \n";
           result+="samples_present.sp1: "+SP1+" \n";
           result+="samples_present.sp2: "+SP2+" \n";
           result+="samples_present.sp3: "+SP3+" \n";
           result+="samples_invalid.sp0: "+SI0+" \n";
           result+="samples_invalid.sp1: "+SI1+" \n";
           result+="samples_invalid.sp2: "+SI2+" \n";
           result+="samples_invalid.sp3: "+SI3+" \n";
           result+="ChA: "+cha+" \n";
           result+="ChB: "+chb+" \n";
       }
       break;
   case 0x08:
       result+= "Packet type: DST Audio Packet \n"  ;
       if (((HB1&0x3E) == 0) && (HB2 == 0)){
           long frames = (HB1&0x80);
           long samplesi = (HB1&0x40);
           long DSTnd = (HB1&0x01);
           long Dx = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
           QString fram = QString::number(frames);
           QString sam = QString::number(samplesi);
           QString dst = QString::number(DSTnd);
           QString dx = QString::number(Dx);
           result+="farme_start: "+fram+" \n";
           result+="saqmples_invalid: "+sam+" \n";
           result+="DST_normal_double: "+dst+" \n";
           result+="D.X: "+dx+" \n";
       }
       break;
   case 0x09:
       result+= "Packet type: High Bitrate (HBR) Audio Stream Packet (IEC 61937) \n"  ;
       if ((HB1 == 0) && ((HB2&0xF) == 0)){
           long Bx = (HB2&0xF0);
           QString bx = QString::number(Bx);
           result+="B.X: "+bx+" \n";
   }

       break;
   case 0x0A:
       result+= "Packet type: Gamut Metadata Packet \n"  ;
       if ((HB2&0x40)==0){
           long nextf = HB1&0x80;
           long nocrnt = HB2&0x80;
           long GBDprof = HB1&0x70;
           long agsn = HB1&0xF;
           long cgsn = HB2&0xF;
           long packetseq = HB2&0x30;
           QString next = QString::number(nextf);
           QString nocrn = QString::number(nocrnt);
           QString GBDpro = QString::number(GBDprof);
           QString ags = QString::number(agsn);
           QString cgs = QString::number(cgsn);
           QString packetse = QString::number(packetseq);
           result+="Next_Field: "+next+" \n";
           result+="No_Current_GBD: "+nocrn+" \n";
           result+="GBD_profile: "+GBDpro+" \n";
           result+="Affected_Gamut_Seq_Num: "+ags+" \n";
           result+="Current_Gamut_Seq_Num: "+cgs+" \n";
           result+="Packet_Seq: "+packetse+" \n";
           switch (GBDprof) {
              case 0:{
               result+="P0 \n";
               long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
               QString gbd  = QString::number(GBD);
               result+="GBD: "+gbd+" \n";}
               break;
              case 0x01:{
               result+="P1\n";
               if (packetseq == 0){
                   long GBDLengthH = (PB0);
                   long GBDLengthL = (PB1);
                   long Checksum = (PB2);
                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString GBDLengthh  = QString::number(GBDLengthH);
                   QString GBDLengthl = QString::number(GBDLengthL);
                   QString Checksu = QString::number(Checksum);
                   QString gbd  = QString::number(GBD);
                   result+="GBD_Length_H: "+GBDLengthh+" \n";
                   result+="GBD_Length_L: "+GBDLengthl+" \n";
                   result+="Checksum: "+Checksu+" \n";
                   result+="GBD: "+gbd+" \n";
               }

               else {
                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString gbd  = QString::number(GBD);
                   result+="GBD: "+gbd+" \n";
               }}
               break;
           case 2:{
               result+="P2 \n";
               if (packetseq == 0){
                   long GBDLengthH = (PB0);
                   long GBDLengthL = (PB1);
                   long Checksum = (PB2);
                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString GBDLengthh  = QString::number(GBDLengthH);
                   QString GBDLengthl = QString::number(GBDLengthL);
                   QString Checksu = QString::number(Checksum);
                   QString gbd  = QString::number(GBD);
                   result+="GBD_Length_H: "+GBDLengthh+" \n";
                   result+="GBD_Length_L: "+GBDLengthl+" \n";
                   result+="Checksum: "+Checksu+" \n";
                   result+="GBD: "+gbd+" \n";
               }
               else {
                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString gbd  = QString::number(GBD);
                   result+="GBD: "+gbd+" \n";
               }}
               break;
           case 3:{
               result+="P3\n";
               if (packetseq == 0){
                   long GBDLengthH = (PB0);
                   long GBDLengthL = (PB1);
                   long Checksum = (PB2);
                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString GBDLengthh  = QString::number(GBDLengthH);
                   QString GBDLengthl = QString::number(GBDLengthL);
                   QString Checksu = QString::number(Checksum);
                   QString gbd  = QString::number(GBD);
                   result+="GBD_Length_H: "+GBDLengthh+" \n";
                   result+="GBD_Length_L: "+GBDLengthl+" \n";
                   result+="Checksum: "+Checksu+" \n";
                   result+="GBD: "+gbd+" \n";
               }
               else {
                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
                   QString gbd  = QString::number(GBD);
                   result+="GBD: "+gbd+" \n";
               }
               break;}
           default:{
                       result+="check spicifications\n";
               break;
           }}

       }
       break;
   case -0x80 :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7F :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7E :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7D :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7C :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7B :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x7A :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   case -0x79 :
       result+= "Packet type: InfoFrame Packet \n"  ;
       break;
   default:
       result+="invalid byte\n";
       break;
   }
   if (((HB0&INFO_FRAME_PACKET_BIT) !=0) && ((HB2&0xE0) == 0)){
       long IFType = HB0&0x7F;

       switch (IFType) {
       case 0x01:{
           result+="InfoFrame Type: Vendor Specific InfoFrame\n";
            HB0=0x81;
            long IFVersion = HB1;
            long IFLenght = HB2&0x1F;
            QString IFVersio = QString::number(IFVersion);
            QString IFLeng = QString::number(IFLenght);
            if (IFVersion == 0x01){
                 long IEEE= PB1 | (PB2<<8) | (PB3<<16);
                 long VA = (PB4&0xF0)>>4;
                 long VB = (PB4&0xF);
                 long VC = (PB5&0xF0)>>4;
                 long VD = (PB5&0xF);
                 long SupAI = (PB6&0x80)>>7;
                 long DC48bit = (PB6&0x40)>>6;
                 long DC36bit = (PB6&0x20)>>5;
                 long DC30bit = (PB6&0x10)>>4;
                 long DCY444 = (PB6&0x08)>>3;
                 long DVIDUAL = (PB6&0x01);
                 long MAXTMDS = (PB7);
                 long LFP = (PB8&0x80)>>7;
                 long ILFP = (PB8&0x40)>>6;
                 QString IEE = QString::number(IEEE);
                 QString va = QString::number(VA);
                 QString vb = QString::number(VB);
                 QString vc = QString::number(VC);
                 QString vd = QString::number(VD);
                 QString SupA = QString::number(SupAI);
                 QString DC48bi = QString::number(DC48bit);
                 QString DC36bi = QString::number(DC36bit);
                 QString DC30bi = QString::number(DC30bit);
                 QString DCy444 = QString::number(DCY444);
                 QString DVIDU = QString::number(DVIDUAL);
                 QString MAXTMD = QString::number(MAXTMDS);
                 QString LFP1 = QString::number(LFP);
                 QString ILFP2 = QString::number(ILFP);
                 result+="InfoFrame_version: "+IFVersio+" \n";
                 result+="InfoFrame_length: "+IFLeng+" \n";
                 result+="IEEE Registration Identifier: "+IEE+" \n";
                 result+="A: "+va+" \n";
                 result+="B: "+vb+" \n";
                 result+="C: "+vc+" \n";
                 result+="D: "+vd+" \n";
                 result+="Supports_AI: "+SupA+" \n";
                 result+="DC_30bit: "+DC30bi+" \n";
                 result+="DC_36bit: "+DC36bi+" \n";
                 result+="DC_48bit: "+DC48bi+" \n";
                 result+="DC_Y444: "+DCy444+" \n";
                 result+="DVI_Dual: "+DVIDU+" \n";
                 result+="Max_TMDS_Clock: "+MAXTMD+" \n";
                 result+="Latency_Fields_Present: "+LFP1+" \n";
                 result+="I_Latency_Fields_Present: "+ILFP2+" \n";
                }
            if (IFLenght>=9){
               long VideoLatency = PB9;
               QString VideoLatenc = QString::number(VideoLatency);
               result+="Video_Latency: "+VideoLatenc+" \n";
               if (IFLenght>=10){
                   long AudioLatency = PB10;
                   QString AudioLatenc = QString::number(AudioLatency);
                   result+="Audio_Latency: "+AudioLatenc+" \n";
                   if (IFLenght>=11){
                       long InterlacedVideoLatency = PB11;
                       QString InterlacedVideoLatenc = QString::number(InterlacedVideoLatency);
                       result+="Interlaced_Video_Latency: "+InterlacedVideoLatenc+" \n";
                       if (IFLenght>=12){
                           long InterlacedAudioLatency = PB12;
                           QString InterlacedAudioLatenc = QString::number(InterlacedAudioLatency);
                           result+="Interlaced_Audio_Latency: "+InterlacedAudioLatenc+" \n";
                   }
               }
            }
            }
           break;}
       case 0x02:{
           HB0=0x82;
           result+="InfoFrame Type: AVI InfoFrame\n";
           long IFVersion = HB1;
           if (IFVersion == 0x01){
                long IFLenght = HB2&0x1F;
                QString IFVersio = QString::number(IFVersion);
                QString IFLengt = QString::number(IFLenght);
                result+="Version: "+IFVersio+" \n";
                result+="Length: "+IFLengt+" \n";
                long Y = (PB1&0x60)>>5;
                QString y = QString::number(Y);
                switch (Y) {
                case 0x00:{
                    result+="Y: "+ y +" : RGB (default)"+" \n";
                    break;}
                case 0x01:{
                    result+="Y: "+ y +" : YCBCR 4:2:2"+" \n";
                    break;}
                case 0x02:{
                    result+="Y: "+ y +" : YCBCR 4:4:4"+" \n";
                    break;}
                case 0x03:{
                    result+="Y: "+ y +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long A = (PB1&0x10)>>4;
                QString a = QString::number(A);
                switch (A) {
                case 0x00:{
                    result+="A: "+ a +" : No Active Format Information"+" \n";
                    break;}
                case 0x01:{
                    result+="A: "+ a +" : Active Format (R3...R0) Information present"+" \n";
                    break;}
                default:{

                    break;}
                }
                long B = (PB1&0x0C)>>2;
                QString b = QString::number(B);
                switch (B) {
                case 0x00:{
                    result+="B: "+ b +" : Bar Data not present"+" \n";
                    break;}
                case 0x01:{
                    result+="B: "+ b +" : Vert. Bar Info present"+" \n";
                    break;}
                case 0x02:{
                    result+="B: "+ b +" : Horiz. Bar Info present"+" \n";
                    break;}
                case 0x03:{
                    result+="B: "+ b +" : Vert. and Horiz. Bar Info present"+" \n";
                    break;}
                default:{

                    break;}
                }
                long S = (PB1&0x03);
                QString s = QString::number(S);
                switch (S) {
                case 0x00:{
                    result+="S: "+ s +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="S: "+ s +" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."+" \n";
                    break;}
                case 0x02:{
                    result+="S: "+ s +" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."+" \n";
                    break;}
                case 0x03:{
                    result+="S: "+ s +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long C = (PB2&0xC0)>>6;
                QString c = QString::number(C);
                switch (C) {
                case 0x00:{
                    result+="C: "+ c +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="C: "+ c +" : SMPTE 170M [1]"+" \n";
                    break;}
                case 0x02:{
                    result+="C: "+ c +" : ITU-R 709 [7]"+" \n";
                    break;}
                case 0x03:{
                    result+="C: "+ c +" : Extended Colorimetry Information Valid"+" \n";
                    break;}
                default:{

                    break;}
                }
                long M = (PB2&0x30)>>4;
                QString m = QString::number(M);
                switch (M) {
                case 0x00:{
                    result+="M: "+ m +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="M: "+ m +" : 4:3"+" \n";
                    break;}
                case 0x02:{
                    result+="M: "+ m +" : 16:9"+" \n";
                    break;}
                case 0x03:{
                    result+="M: "+ m +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long R = (PB2&0x0F);
                QString r = QString::number(R);
                switch (R) {
                case 0x08:{
                    result+="R: "+ r +" : Same as coded frame aspect ratio"+" \n";
                    break;}
                case 0x09:{
                    result+="R: "+ r +" : 4:3 (center)"+" \n";
                    break;}
                case 0x0A:{
                    result+="R: "+ r +" : 16:9 (center)"+" \n";
                    break;}
                case 0x0B:{
                    result+="R: "+ r +" : 14:9 (center)"+" \n";
                    break;}
                default:{
                    result+="R: "+ r +" : Varies. See Annex H."+" \n";
                    break;}
                }
                long SC = (PB3&0x03);
                QString sc = QString::number(SC);
                switch (SC) {
                case 0x00:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : No Know non-uniform Scaling"+" \n";
                    break;}
                case 0x01:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally"+" \n";
                    break;}
                case 0x02:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled vertically"+" \n";
                    break;}
                case 0x03:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally and vertically"+" \n";
                    break;}
                default:{

                    break;}}
                long ETB = (PB5&0xFF) | (PB6&0xFF00);
                long SBB = (PB7&0xFF) | (PB8&0xFF00);
                long ELB = (PB9&0xFF) | (PB10&0xFF00);
                long SRB = (PB11&0xFF) | (PB12&0xFF00);
                QString etb = QString::number(ETB);
                QString sbb = QString::number(SBB);
                QString elb = QString::number(ELB);
                QString srb = QString::number(SRB);
                result+="ETB: "+etb+" \n";
                result+="SBB: "+sbb+" \n";
                result+="ELB: "+elb+" \n";
                result+="SRB: "+srb+" \n";
           }
           if (IFVersion == 0x02){
                long IFLenght = HB2&0x1F;
                QString IFVersio = QString::number(IFVersion);
                QString IFLengh = QString::number(IFLenght);
                result+="Version: "+IFVersio+" \n";
                result+="Length: "+IFLengh+" \n";

                long Y = (PB1&0x60)>>5;
                QString y = QString::number(Y);
                switch (Y) {
                case 0x00:{
                    result+="Y: "+ y +" : RGB (default)"+" \n";
                    break;}
                case 0x01:{
                    result+="Y: "+ y +" : YCBCR 4:2:2"+" \n";
                    break;}
                case 0x02:{
                    result+="Y: "+ y +" : YCBCR 4:4:4"+" \n";
                    break;}
                case 0x03:{
                    result+="Y: "+ y +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long A = (PB1&0x10)>>4;
                QString a = QString::number(A);
                switch (A) {
                case 0x00:{
                    result+="A: "+ a +" : No Active Format Information"+" \n";
                    break;}
                case 0x01:{
                    result+="A: "+ a +" : Active Format (R3...R0) Information present"+" \n";
                    break;}
                default:{

                    break;}
                }
                long B = (PB1&0x0C)>>2;
                QString b = QString::number(B);
                switch (B) {
                case 0x00:{
                    result+="B: "+ b +" : Bar Data not present"+" \n";
                    break;}
                case 0x01:{
                    result+="B: "+ b +" : Vert. Bar Info present"+" \n";
                    break;}
                case 0x02:{
                    result+="B: "+ b +" : Horiz. Bar Info present"+" \n";
                    break;}
                case 0x03:{
                    result+="B: "+ b +" : Vert. and Horiz. Bar Info present"+" \n";
                    break;}
                default:{

                    break;}
                }
                long S = (PB1&0x03);
                QString s = QString::number(S);
                switch (S) {
                case 0x00:{
                    result+="S: "+ s +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="S: "+ s +" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."+" \n";
                    break;}
                case 0x02:{
                    result+="S: "+ s +" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."+" \n";
                    break;}
                case 0x03:{
                    result+="S: "+ s +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long C = (PB2&0xC0)>>6;
                QString c = QString::number(C);
                switch (C) {
                case 0x00:{
                    result+="C: "+ c +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="C: "+ c +" : SMPTE 170M [1]"+" \n";
                    break;}
                case 0x02:{
                    result+="C: "+ c +" : ITU-R 709 [7]"+" \n";
                    break;}
                case 0x03:{
                    result+="C: "+ c +" : Extended Colorimetry Information Valid"+" \n";
                    break;}
                default:{

                    break;}
                }
                long M = (PB2&0x30)>>4;
                QString m = QString::number(M);
                switch (M) {
                case 0x00:{
                    result+="M: "+ m +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="M: "+ m +" : 4:3"+" \n";
                    break;}
                case 0x02:{
                    result+="M: "+ m +" : 16:9"+" \n";
                    break;}
                case 0x03:{
                    result+="M: "+ m +" : *future*"+" \n";
                    break;}
                default:{

                    break;}
                }
                long R = (PB2&0x0F);
                QString r = QString::number(R);
                switch (R) {
                case 0x08:{
                    result+="R: "+ r +" : Same as coded frame aspect ratio"+" \n";
                    break;}
                case 0x09:{
                    result+="R: "+ r +" : 4:3 (center)"+" \n";
                    break;}
                case 0x0A:{
                    result+="R: "+ r +" : 16:9 (center)"+" \n";
                    break;}
                case 0x0B:{
                    result+="R: "+ r +" : 14:9 (center)"+" \n";
                    break;}
                default:{
                    result+="R: "+ r +" : Varies. See Annex H."+" \n";
                    break;}
                }
                long ITC = (PB3&0x80)>>7;
                QString itc = QString::number(ITC);
                switch (ITC) {
                case 0x00:{
                    result+="IT content: "+ itc +" : No Data"+" \n";
                    break;}
                case 0x01:{
                    result+="IT content: "+ itc +" : IT content (Byte 5 CN bits valid)"+" \n";
                    break;}
                default:{

                    break;}
                }
                long EC = (PB3&0x70)>>4;
                QString ec  = QString::number(EC);
                switch (EC) {
                case 0x00:{
                    result+="Extended Colorimetry: "+ ec +" : xvYCC601"+" \n";
                    break;}
                case 0x01:{
                    result+="Extended Colorimetry: "+ ec +" : xvYCC709"+" \n";
                    break;}
                case 0x02:{
                    result+="Extended Colorimetry: "+ ec +" : sYCC601"+" \n";
                    break;}
                case 0x03:{
                    result+="Extended Colorimetry: "+ ec +" : AdobeYCC601"+" \n";
                    break;}
                case 0x04:{
                    result+="Extended Colorimetry: "+ ec +" : AdobeRGB"+" \n";
                    break;}
                default:{
                    result+="EC: "+ ec +" \n";
                    break;}
                }
                long Q = (PB3&0x0C)>>2;
                QString q  = QString::number(Q);
                switch (Q) {
                case 0x00:{
                    result+="RGB Quanitization Range: "+ q +" : Default (depends on video format)"+" \n";
                    break;}
                case 0x01:{
                    result+="RGB Quanitization Range: "+ q +" : Limit Range"+" \n";
                    break;}
                case 0x02:{
                    result+="RGB Quanitization Range: "+ q +" : Full Range"+" \n";
                    break;}
                case 0x03:{
                    result+="RGB Quanitization Range: "+ q +" : Reserved"+" \n";
                    break;}
                default:{

                    break;}}
                long SC = (PB3&0x03);
                QString sc = QString::number(SC);
                switch (SC) {
                case 0x00:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : No Know non-uniform Scaling"+" \n";
                    break;}
                case 0x01:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally"+" \n";
                    break;}
                case 0x02:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled vertically"+" \n";
                    break;}
                case 0x03:{
                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally and vertically"+" \n";
                    break;}
                default:{

                    break;}}
                long VIC = (PB4&0x7F);
                QString vic = QString::number(VIC);
                switch (VIC) {
                case 1:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 640x480p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: No Repetition \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 2:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: No Repetition \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 3:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: No Repetition \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 4:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: No Repetition \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 5:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080i @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: No Repetition \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 6:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 7:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 8:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x240p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 9:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x240p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
                    result+="AVI w/PR Required: No \n";
                    break;}
                case 10:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x480i @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 11:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x480i @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 12:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x240p @ 59.94/60Hz \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 13:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x240p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 14:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1440x480p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 2 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 15:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1440x480p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 2 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 16:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 17:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 18:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 19:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 20:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080i @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 21:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 22:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 23:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x288p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 24:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x288p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 25:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x576i @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 26:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x576i @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 27:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x288p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 28:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x288p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 29:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1440x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 or 2 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 30:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1440x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1 or 2 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 31:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 32:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 23.98/24Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 33:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 25Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 34:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 29.98/30Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 35:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x480p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 36:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x480p @ 59.94/60Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 37:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 38:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 2880x576p @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
                    result+="AVI w/PR Required: Yes  \n";
                    break;}
                case 39:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080i (1250) @ 50Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 40:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080i @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 41:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 42:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 43:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 44:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 45:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 46:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080i @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 47:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 48:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 49:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 50:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 51:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 119.88/120Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 52:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 200Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 53:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x576p @ 200Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 54:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 200Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 55:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x576i @ 200Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 56:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 239.76/240Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 57:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720x480p @ 239.76/240Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 58:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 239.76/240Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 59:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 720(1440)x480i @ 239.76/240Hz  \n";
                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 60:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 23.97Hz/24Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 61:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 25Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 62:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1280x720p @ 29.97Hz/30Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 63:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 119.88Hz/120Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                case 64:{
                    result+="VIC: "+ vic +" \n";
                    result+="Video Description: 1920x1080p @ 100Hz  \n";
                    result+="Valid Pixel Repeat Values: No Repetition  \n";
                    result+="AVI w/PR Required: No  \n";
                    break;}
                default:{
                    result+="VIC: "+ vic +" \n";
                    break;}}
                long YQ = (PB3&0xC0)>>6;
                QString yq = QString::number(YQ);
                switch (YQ) {
                case 0x00:{
                    result+="YCC Quanitization Range: "+ yq +" : Limited Range"+" \n";
                    break;}
                case 0x01:{
                    result+="YCC Quanitization Range: "+ yq +" : Full Range"+" \n";
                    break;}
                case 0x02:{
                    result+="YCC Quanitization Range: "+ yq +" : Reserved"+" \n";
                    break;}
                case 0x03:{
                    result+="YCC Quanitization Range: "+ yq +" : Reserved"+" \n";
                    break;}
                default:{

                    break;}}
                long CN = (PB3&0x30)>>4;
                QString cn = QString::number(CN);
                switch (CN) {
                case 0x00:{
                    result+="IT Content Type: "+ cn +" : Graphics"+" \n";
                    break;}
                case 0x01:{
                    result+="IT Content Type: "+ cn +" : Photo"+" \n";
                    break;}
                case 0x02:{
                    result+="IT Content Type: "+ cn +" : Cinema"+" \n";
                    break;}
                case 0x03:{
                    result+="IT Content Type: "+ cn +" : Game"+" \n";
                    break;}
                default:{

                    break;}}
                long PR = PB4&0x0F;
                QString pr = QString::number(PR);
                switch (PR) {
                case 0x00:{
                    result+="Pixel Repetition Factor: "+ pr +" : No Repetition (i.e., pixel date sent once)"+" \n";
                    break;}
                case 0x01:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 2 times (i.e., repeated once)"+" \n";
                    break;}
                case 0x02:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 3 times"+" \n";
                    break;}
                case 0x03:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 4 times"+" \n";
                    break;}
                case 0x04:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 5 times"+" \n";
                    break;}
                case 0x05:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 6 times"+" \n";
                    break;}
                case 0x06:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 7 times"+" \n";
                    break;}
                case 0x07:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 8 times"+" \n";
                    break;}
                case 0x08:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 9 times"+" \n";
                    break;}
                case 0x09:{
                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 10 times"+" \n";
                    break;}
                default:{
                    result+="Pixel Repetition Factor: "+ pr +" : Reserved"+" \n";
                    break;}
                }
                long ETB = (PB5&0xFF) | (PB6&0xFF00);
                long SBB = (PB7&0xFF) | (PB8&0xFF00);
                long ELB = (PB9&0xFF) | (PB10&0xFF00);
                long SRB = (PB11&0xFF) | (PB12&0xFF00);
                QString etb = QString::number(ETB);
                QString sbb = QString::number(SBB);
                QString elb = QString::number(ELB);
                QString srb = QString::number(SRB);
                result+="ETB: "+etb+" \n";
                result+="SBB: "+sbb+" \n";
                result+="ELB: "+elb+" \n";
                result+="SRB: "+srb+" \n";

           }
           break;}
       case 0x03:{
           HB0=0x83;
           result+="InfoFrame Type: Source Product Descriptor InfoFrame \n";
           long IFVersion = HB1;
           long IFLenght = HB2&0x1F;
           if ((IFVersion == 0x01) && (IFLenght == 25)){
               QString IFVersio = QString::number(IFVersion);
               QString IFLengh = QString::number(IFLenght);
               result+="Version: "+IFVersio+" \n";
               result+="Length: "+IFLengh+" \n";
                long VN1 = PB1&0xEF;
                long VN2 = PB2&0xEF;
                long VN3 = PB3&0xEF;
                long VN4 = PB4&0xEF;
                long VN5 = PB5&0xEF;
                long VN6 = PB6&0xEF;
                long VN7 = PB7&0xEF;
                long VN8 = PB8&0xEF;
                long PD1 = PB9&0xEF;
                long PD2 = PB10&0xEF;
                long PD3 = PB11&0xEF;
                long PD4 = PB12&0xEF;
                long PD5 = PB13&0xEF;
                long PD6 = PB14&0xEF;
                long PD7 = PB15&0xEF;
                long PD8 = PB16&0xEF;
                long PD9 = PB17&0xEF;
                long PD10 = PB18&0xEF;
                long PD11 = PB19&0xEF;
                long PD12 = PB20&0xEF;
                long PD13 = PB21&0xEF;
                long PD14 = PB22&0xEF;
                long PD15 = PB23&0xEF;
                long PD16 = PB24&0xEF;
                QString vn1 = QString::number(VN1);
                QString vn2 = QString::number(VN2);
                QString vn3 = QString::number(VN3);
                QString vn4 = QString::number(VN4);
                QString vn5 = QString::number(VN5);
                QString vn6 = QString::number(VN6);
                QString vn7 = QString::number(VN7);
                QString vn8 = QString::number(VN8);
                QString pd1 = QString::number(PD1);
                QString pd2 = QString::number(PD2);
                QString pd3 = QString::number(PD3);
                QString pd4 = QString::number(PD4);
                QString pd5 = QString::number(PD5);
                QString pd6 = QString::number(PD6);
                QString pd7 = QString::number(PD7);
                QString pd8 = QString::number(PD8);
                QString pd9 = QString::number(PD9);
                QString pd10 = QString::number(PD10);
                QString pd11 = QString::number(PD11);
                QString pd12 = QString::number(PD12);
                QString pd13 = QString::number(PD13);
                QString pd14 = QString::number(PD14);
                QString pd15 = QString::number(PD15);
                QString pd16 = QString::number(PD16);
                result+="VN1: "+vn1+" \n";
                result+="VN2: "+vn2+" \n";
                result+="VN3: "+vn3+" \n";
                result+="VN4: "+vn4+" \n";
                result+="VN5: "+vn5+" \n";
                result+="VN6: "+vn6+" \n";
                result+="VN7: "+vn7+" \n";
                result+="VN8: "+vn8+" \n";
                result+="PD1: "+pd1+" \n";
                result+="PD2: "+pd2+" \n";
                result+="PD3: "+pd3+" \n";
                result+="PD4: "+pd4+" \n";
                result+="PD5: "+pd5+" \n";
                result+="PD6: "+pd6+" \n";
                result+="PD7: "+pd7+" \n";
                result+="PD8: "+pd8+" \n";
                result+="PD9: "+pd9+" \n";
                result+="PD10: "+pd10+" \n";
                result+="PD11: "+pd11+" \n";
                result+="PD12: "+pd12+" \n";
                result+="PD13: "+pd13+" \n";
                result+="PD14: "+pd14+" \n";
                result+="PD15: "+pd15+" \n";
                result+="PD16: "+pd16+" \n";
                long SourceINFO = PB25;
                QString si = QString::number(SourceINFO);
                switch (SourceINFO) {
                case 0x00:
                    result+="Source Information: unknown ( "+si+" )"+" \n";
                    break;
                case 0x01:
                    result+="Source Information: Digital STB ( "+si+" )"+" \n";
                    break;
                case 0x02:
                    result+="Source Information: DVD player ( "+si+" )"+" \n";
                    break;
                case 0x03:
                    result+="Source Information: D-VHS ( "+si+" )"+" \n";
                    break;
                case 0x04:
                    result+="Source Information: HDD Videorecorder ( "+si+" )"+" \n";
                    break;
                case 0x05:
                    result+="Source Information: DVC ( "+si+" )"+" \n";
                    break;
                case 0x06:
                    result+="Source Information: DSC ( "+si+" )"+" \n";
                    break;
                case 0x07:
                    result+="Source Information: Video CD ( "+si+" )"+" \n";
                    break;
                case 0x08:
                    result+="Source Information: Game ( "+si+" )"+" \n";
                    break;
                case 0x09:
                    result+="Source Information: PC general ( "+si+" )"+" \n";
                    break;
                case 0x0A:
                    result+="Source Information: Blu-Ray Disk (BD) ( "+si+" )"+" \n";
                    break;
                case 0x0B:
                    result+="Source Information: Super Audio CD ( "+si+" )"+" \n";
                    break;
                case 0x0C:
                    result+="Source Information: HD DVD ( "+si+" )"+" \n";
                    break;
                case 0x0D:
                    result+="Source Information: PMP ( "+si+" )"+" \n";
                    break;
                default:
                    result+="Source Information: *reserved* ( "+si+" )"+" \n";
                    break;
                }
           }
           break;}
       case 0x04:{
           HB0=0x84;
           result+="InfoFrame Type: Audio InfoFrame \n";
           long IFVersion = HB1;
           long IFLenght = HB2&0x1F;
           if ((IFVersion == 1) && (IFLenght == 10)){
               QString IFVersio = QString::number(IFVersion);
               QString IFLengh = QString::number(IFLenght);
               result+="Version: "+IFVersio+" \n";
               result+="Length: "+IFLengh+" \n";
                long CT = (PB1&0xF0)>>4;
                QString ct = QString::number(CT);
                switch (CT) {
                case 0x00:{
                    result+="CT="+ ct +" >> Refer to Stream Header"+" \n";
                    break;}
                case 0x01:{
                    result+="CT="+ ct +" >> Audio Coding Type: PCM ; Audio Stream Standard: IEC 60958-3 [13]"+" \n";
                    break;}
                case 0x02:{
                    result+="CT="+ ct +" >> Audio Coding Type: AC-3 ; Audio Stream Encoding Standard: ATSC A/58B [12] excluding Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"+" \n";
                    break;}
                case 0x03:{
                    result+="CT="+ ct +" >> Audio Coding Type: MPEG-1 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 1 or Layer 2 ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
                    break;}
                case 0x04:{
                    result+="CT="+ ct +" >> Audio Coding Type: MP3 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 3 ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
                    break;}
                case 0x05:{
                    result+="CT="+ ct +" >> Audio Coding Type: MPEG2 ; Audio Stream Encoding Standard: ISO/IEC 13818-3 [23] ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
                    break;}
                case 0x06:{
                    result+="CT="+ ct +" >> Audio Coding Type: AAC LC ; Audio Stream Encoding Standard: ISO/IEC 14496-3 [24] ; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
                    break;}
                case 0x07:{
                    result+="CT="+ ct +" >> Audio Coding Type: DTS; Audio Stream Encoding Standard: ETSI TS 102 114 [37] ; Audio Stream Transport Standart: IEC 61937-5 [17]"+" \n";
                    break;}
                case 0x08:{
                    result+="CT="+ ct +" >> Audio Coding Type: ATRAC ; Audio Stream Encoding Standard: IEC 61909 [14] See also ATRAC [61] ; Audio Stream Transport Standart: IEC 61937-7 [19]"+" \n";
                    break;}
                case 0x09:{
                    result+="CT="+ ct +" >> Audio Coding Type: DSD ; Audio Stream Standard: ISO/IEC 14496-3 [24], subpart 10, See also Super Audio CD [70]"+" \n";
                    break;}
                case 0x0A:{
                    result+="CT="+ ct +" >> Audio Coding Type: E-AC-3 ; Audio Stream Encoding Standard: ATSC A/52B [12] with Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"+" \n";
                    break;}
                case 0x0B:{
                    result+="CT="+ ct +" >> Audio Coding Type: DTS-HD ; Audio Stream Encoding Standard: DVD Forum DTS-HD [28] ; Audio Stream Transport Standart: IEC 61937-5 [17]"+" \n";
                    break;}
                case 0x0C:{
                    result+="CT="+ ct +" >> Audio Coding Type: MLP ; Audio Stream Encoding Standard: DVD Forum MLP [27] ; Audio Stream Transport Standart: IEC 61937-9 [21]"+" \n";
                    break;}
                case 0x0D:{
                    result+="CT="+ ct +" >> Audio Coding Type: DST ; Audio Stream Standard:  ISO/IEC 14496-3 [24], subpart 10"+" \n";
                    break;}
                case 0x0E:{
                    result+="CT="+ ct +" >> Audio Coding Type: WWA Pro ; Audio Stream Encoding Standard: WWA Pro Decoder Specification [30] ; Audio Stream Transport Standart: IEC 61937-8 [20]"+" \n";
                    break;}
                case 0x0F:{
                    result+="CT="+ ct +" >> Refer to Audio Codding Extension Type (CXT) field in Data Byte 3"+" \n";
                    break;}
                default:{

                    break;}}
                long CC = PB1&0x07;
                QString cc = QString::number(CC);
                switch (CC) {
                case 0x00:{
                    result+="CС="+ cc +" >> Refer to Stream Header"+" \n";
                    break;}
                case 0x01:{
                    result+="CС="+ cc +" >> Audio Channel Count: 2 channels"+" \n";
                    break;}
                case 0x02:{
                    result+="CС="+ cc +" >> Audio Channel Count: 3 channels"+" \n";
                    break;}
                case 0x03:{
                    result+="СС="+ cc +" >> Audio Channel Count: 4 channels"+" \n";
                    break;}
                case 0x04:{
                    result+="CС="+ cc +" >> Audio Channel Count: 5 channels"+" \n";
                    break;}
                case 0x05:{
                    result+="CС="+ cc +" >> Audio Channel Count: 6 channels"+" \n";
                    break;}
                case 0x06:{
                    result+="CС="+ cc +" >> Audio Channel Count: 7 channels"+" \n";
                    break;}
                case 0x07:{
                    result+="CC="+ cc +" >> Audio Channel Count: 8 channels"+" \n";
                    break;}
                default:{
                    break;}}
                long SF = PB2&0x1C;
                QString sf = QString::number(SF);
                switch (SF) {
                case 0x00:{
                    result+="SF="+ sf +" >> Refer to Stream Header"+" \n";
                    break;}
                case 0x01:{
                    result+="SF="+ sf +" >> Samping Frequency: 32 kHz"+" \n";
                    break;}
                case 0x02:{
                    result+="SF="+ sf +" >> Samping Frequency: 44.1 kHz (CD) "+" \n";
                    break;}
                case 0x03:{
                    result+="SF="+ sf +" >> Samping Frequency: 48 kHz "+" \n";
                    break;}
                case 0x04:{
                    result+="SF="+ sf +" >> Samping Frequency: 88.2 kHz"+" \n";
                    break;}
                case 0x05:{
                    result+="SF="+ sf +" >> Samping Frequency: 96 kHZ"+" \n";
                    break;}
                case 0x06:{
                    result+="SF="+ sf +" >> Samping Frequency: 176.4 kHz"+" \n";
                    break;}
                case 0x07:{
                    result+="SF="+ sf +" >> Samping Frequency: 192 kHz"+" \n";
                    break;}
                default:{
                    break;}}
                long SS = PB2&0x03;
                QString ss = QString::number(SS);
                switch (SS) {
                case 0x00:{
                    result+="SS="+ ss +" >> Refer to Stream Header"+" \n";
                    break;}
                case 0x01:{
                    result+="SS="+ ss +" >> Sample Size: 16bit"+" \n";
                    break;}
                case 0x02:{
                    result+="SS="+ ss +" >> Sample Size: 20bit"+" \n";
                    break;}
                case 0x03:{
                    result+="SS="+ ss +" >> Sample Size: 24bit"+" \n";
                    break;}
                default:{
                    break;}}
                long CXT = PB3&0x1F;
                QString cxt = QString::number(CXT);
                switch (CXT) {
                case 0x00:{
                    result+="CXT="+ cxt +" >> Refer to Stream Header"+" \n";
                    break;}
                case 0x01:{
                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: HE-AAC ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005 [24]; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
                    break;}
                case 0x02:{
                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: HE-AAACv2 ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005/AMD2:2006 [25] ; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
                    break;}
                case 0x03:{
                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: AC-3 ; Audio Stream Encoding Standard: ISO/IEC 230003-1:2007 [26]"+" \n";
                    break;}
                default:{
                    result+="CXT="+ cxt +" >> *reserved*"+" \n";
                    break;}}
                long CA = PB4&0xFF;
                QString ca = QString::number(CA);
                result+="|........|                    Channels:                    |  \n";
                result+="|   CA  |  8  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  \n";
                switch (CA) {
                case 0x00:{
                    result+="| 0x00 |  -  |  -  |  -  |  -  |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x01:{
                    result+="| 0x01 |  -  |  -  |  -  |  -  |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x02:{
                    result+="| 0x02 |  -  |  -  |  -  |  -  |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x03:{
                    result+="| 0x03 |  -  |  -  |  -  |  -  |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x04:{
                    result+="| 0x04 |  -  |  -  |  -  |  RC |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x05:{
                    result+="| 0x05 |  -  |  -  |  -  |  RC |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x06:{
                    result+="| 0x06 |  -  |  -  |  -  |  RC |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x07:{
                    result+="| 0x07 |  -  |  -  |  -  |  RC |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x08:{
                    result+="| 0x08 |  -  |  -  |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x09:{
                    result+="| 0x09 |  -  |  -  |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x0A:{
                    result+="| 0x0A |  -  |  -  |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x0B:{
                    result+="| 0x0B |  -  |  -  |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x0C:{
                    result+="| 0x0C |  -  |  RC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x0D:{
                    result+="| 0x0D |  -  |  RC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x0E:{
                    result+="| 0x0E |  -  |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x0F:{
                    result+="| 0x0F |  -  |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x10:{
                    result+="| 0x10 | RRC | RLC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x11:{
                    result+="| 0x11 | RRC | RLC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x12:{
                    result+="| 0x12 | RRC | RLC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x13:{
                    result+="| 0x13 | RRC | RLC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x14:{
                    result+="| 0x14 | FRC | FLC |  -  |  -  |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x15:{
                    result+="| 0x15 | FRC | FLC |  -  |  -  |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x16:{
                    result+="| 0x16 | FRC | FLC |  -  |  -  |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x17:{
                    result+="| 0x17 | FRC | FLC |  -  |  -  |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x18:{
                    result+="| 0x18 | FRC | FLC |  -  |  RC |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x19:{
                    result+="| 0x19 | FRC | FLC |  -  |  RC |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x1A:{
                    result+="| 0x1A | FRC | FLC |  -  |  RC |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x1B:{
                    result+="| 0x1B | FRC | FLC |  -  |  RC |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x1C:{
                    result+="| 0x1C | FRC | FLC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x1D:{
                    result+="| 0x1D | FRC | FLC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x1E:{
                    result+="| 0x1E | FRC | FLC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x1F:{
                    result+="| 0x1F | FRC | FLC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x20:{
                    result+="| 0x20 |  -  | FCH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x21:{
                    result+="| 0x21 |  -  | FCH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x22:{
                    result+="| 0x22 |  TC |  -  |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x23:{
                    result+="| 0x23 |  TC |  -  |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x24:{
                    result+="| 0x24 | FRH | FLH |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x25:{
                    result+="| 0x25 | FRH | FLH |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x26:{
                    result+="| 0x26 | FRW | FLW |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
                    break;}
                case 0x27:{
                    result+="| 0x27 | FRW | FLW |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
                    break;}
                case 0x28:{
                    result+="| 0x28 |  TC |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x29:{
                    result+="| 0x29 |  TC |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x2A:{
                    result+="| 0x2A | FCH |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x2B:{
                    result+="| 0x2B | FCH |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x2C:{
                    result+="| 0x2C |  TC | FCH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x2D:{
                    result+="| 0x2D |  TC | FCH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x2E:{
                    result+="| 0x2E | FRH | FLH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x2F:{
                    result+="| 0x2F | FRH | FLH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                case 0x30:{
                    result+="| 0x30 | FRW | FLW |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
                    break;}
                case 0x31:{
                    result+="| 0x31 | FRW | FLW |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
                    break;}
                default:{
                    result+="| "+ca+"|                  *reserved*                   |  \n";
                    break;}
                }
                long DMINH = (PB5&0x80)>>7;
                switch (DMINH) {
                case 0x00:
                    result+="Mixed stereo output is: permitted or no information about any assertion of this \n";
                    break;
                case 0x01:
                    result+="Mixed stereo output is: prohibited \n";
                    break;
                default:
                    break;
                }
                long LSV = (PB5&0x78)>>3;
                QString lsv = QString::number(LSV);
                switch (LSV) {
                case 0x00:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 0dB"+" \n";
                    break;}
                case 0x01:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 1dB"+" \n";
                    break;}
                case 0x02:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 2dB"+" \n";
                    break;}
                case 0x03:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 3dB"+" \n";
                    break;}
                case 0x04:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 4dB"+" \n";
                    break;}
                case 0x05:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 5dB"+" \n";
                    break;}
                case 0x06:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 6dB"+" \n";
                    break;}
                case 0x07:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 7dB"+" \n";
                    break;}
                case 0x08:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 8dB"+" \n";
                    break;}
                case 0x09:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 9dB"+" \n";
                    break;}
                case 0x0A:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 10dB"+" \n";
                    break;}
                case 0x0B:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 11dB"+" \n";
                    break;}
                case 0x0C:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 12dB"+" \n";
                    break;}
                case 0x0D:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 13dB"+" \n";
                    break;}
                case 0x0E:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 14dB"+" \n";
                    break;}
                case 0x0F:{
                    result+="LSV ="+ lsv +" >> Level Shift Value: 15dB"+" \n";
                    break;}
                default:
                    break;
                }
                long LFEPBL = PB5&0x02;
                QString lf = QString::number(LFEPBL);
                switch (LFEPBL) {
                case 0x00:{
                    result+="LFEPBL="+ lf +" >> LFE playback level: unknown or refer to other information"+" \n";
                    break;}
                case 0x01:{
                    result+="LFEPBL="+ lf +" >> 0 dB playback"+" \n";
                    break;}
                case 0x02:{
                    result+="LFEPBL="+ lf +" >> + 10 dB playback"+" \n";
                    break;}
                case 0x03:{
                    result+="LFEPBL="+ lf +" >> *reserved*"+" \n";
                    break;}
                default:
                    break;
                }



           }
           break;}
       case 0x05:{
           HB0=0x85;
           result+="InfoFrame Type: MPEG Source InfoFrame \n";
           long IFVersion = HB1;
           long IFLenght = HB2&0x1F;
           if (IFVersion == 0x01){
               QString IFVersio = QString::number(IFVersion);
               QString IFLengh = QString::number(IFLenght);
               result+="Version: "+IFVersio+" \n";
               result+="Length: "+IFLengh+" \n";
               long MB = (PB1) | ((PB2&0xFF)<<8)| ((PB3&0xFF)<<16)| ((PB4&0xFF)+24);
               QString mb = QString::number(MB);
               result+="MPEG bit rate: "+mb+" \n";
               long FR = (PB5&0x10)>>4;
               QString fr = QString::number(FR);
               switch (FR) {
               case 0x00:
                   result+="FR="+fr+" >> Field Repeat: New field(picture) "+" \n";
                   break;
               case 0x01:
                   result+="FR="+fr+" >> Field Repeat: Repeated Field "+" \n";
                   break;
               default:
                   break;
               }
               long MF = PB5&0x03;
               QString mf = QString::number(MF);
               switch (MF) {
               case 0x00:
                   result+="MF="+mf+" >> Unknown (no data)"+" \n";
                   break;
               case 0x01:
                   result+="MF="+mf+" >> I Picture"+" \n";
                   break;
               case 0x02:
                   result+="MF="+mf+" >> B Picture"+" \n";
                   break;
               case 0x03:
                   result+="MF="+mf+" >> P Picture"+" \n";
                   break;
               default:
                   break;
               }
           }
           break;}
       case 0x06:{
           HB0=0x86;
           result+="InfoFrame Type: NTSC VBI InfoFrame \n";
           long IFVersion = HB1;
           long IFLenght = HB2&0x1F;
           if (IFVersion == 0x01){
               QString IFVersio = QString::number(IFVersion);
               QString IFLengh = QString::number(IFLenght);
               result+="Version: "+IFVersio+" \n";
               result+="Length: "+IFLengh+" \n";
               int i,k;
               int n=IFLenght;
               for(i=1;i++;i<=n){
                   k=10+i;
                   QString K = QString::number(k);
                   QString I = QString::number(i);
                   long b=byte[k];
                   QString B = QString::number(b);
                   result+="PES"+I+"= "+B+" \n";

               }
           }
           break;}
       case 0x07:{
           HB0=0x87;
           result+="InfoFrame Type: 7 \n";
           long IFVersion = HB1;
           long IFLenght = HB2&0x1F;
           QString IFVersio = QString::number(IFVersion);
           QString IFLengh = QString::number(IFLenght);
           result+="Version: "+IFVersio+" \n";
           result+="Length: "+IFLengh+" \n";
           break;}

       default:{
           result+="invalid InfoFrame \n";
           break;}
       }
   }


    mResult=result;
    return mResult;

}

void Parser::parse(QString &resultparse)
{
//    QByteArray Bytes, byte;
//    int bit, High_Bits, Low_Bits;
//    QString result, high, low;

//    bit = HB0;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=high+low;

//    bit = HB1;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = HB2;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//   if ((HB0&INFO_FRAME_PACKET_BIT) ==0){
//    bit = SB0;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB1;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB2;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB3;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB4;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB5;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = SB6;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low+"\n";
//}
//   if (((HB0&INFO_FRAME_PACKET_BIT) !=0) && ((HB2&0xE0) == 0)){

//    bit = PB0;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB1;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB2;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB3;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB4;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB5;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB6;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB7;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB8;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB9;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB10;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB11;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB12;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB13;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB14;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB15;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB16;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB17;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB18;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB19;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB20;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB21;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB22;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB23;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB24;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB25;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB26;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low;

//    bit = PB27;
//    High_Bits=(bit&0xF0)>>4;
//    Low_Bits=bit&0x0F;
//    high=QString("%1").arg(High_Bits,0,16);
//    low=QString("%1").arg(Low_Bits,0,16);
//    result+=" "+high+low+"\n";
//}

//   switch (HB0) {
//   case 0x00:
//       result+= "Packet type: Null \n"  ;
//       break;
//   case 0x01:
//       result+= "Packet type: Audio Clock Regeneration \n"  ;
//       if ((HB1 | HB2 | SB0 |(SB1>>4) | (SB4>>4)) == 0){
//           long CTS = (SB1<<16)|(SB2<<8)|SB3;
//           long N = (SB4<<16)|(SB5<<8)|SB6;
//           QString cts = QString::number(CTS);
//           QString n = QString::number(N);
//           result+= "СTS: " + cts + " \n"  ;
//           result+= "N: " + n + " \n"  ;
//       }
//       else{
//           result+= "*invalid packet* \n"  ;
//       }
//       break;
//   case 0x02:
//       result+= "Packet type: Audio Sample \n"  ;
//       if ((HB1>>5) == 0){
//             long layout = HB1&0x10;
//             long spX = HB1&0xF;
//             long sfX = HB2&0xF;
//             long B = HB2&(0xF0);
//             long L = (SB0<<4)|(SB1<<12)|(SB2+20);
//             long R = (SB3<<4)|(SB4<<12)|(SB5+20);
//             long Vl =(SB6&0x01);
//             long Vr =(SB6&0x10);
//             long Ul =(SB6&0x02);
//             long Ur =(SB6&0x20);
//             long Cl =(SB6&0x04);
//             long Cr =(SB6&0x40);
//             long Pl =(SB6&0x08);
//             long Pr =(SB6&0x80);
//             QString lay = QString::number(layout);
//             QString spx = QString::number(spX);
//             QString sfx = QString::number(sfX);
//             QString b = QString::number(B);
//             QString l = QString::number(L);
//             QString r = QString::number(R);
//             QString vl = QString::number(Vl);
//             QString vr = QString::number(Vr);
//             QString ul = QString::number(Ul);
//             QString ur = QString::number(Ur);
//             QString cl = QString::number(Cl);
//             QString cr = QString::number(Cr);
//             QString pl = QString::number(Pl);
//             QString pr = QString::number(Pr);
//             result+= "Layout: " + lay + " \n"  ;
//             result+= "sample_present.spX: " + spx + " \n"  ;
//             result+= "sample_flat.spX: " + sfx + " \n"  ;
//             result+= "B: " + b + " \n"  ;
//             result+= "L: " + l + " \n"  ;
//             result+= "R: " + r + " \n"  ;
//             result+= "Vl: " + vl + " \n"  ;
//             result+= "Vr: " + vr + " \n"  ;
//             result+= "Ul: " + ul + " \n"  ;
//             result+= "Ur: " + ur + " \n"  ;
//             result+= "Cl: " + cl + " \n"  ;
//             result+= "Cr: " + cr + " \n"  ;
//             result+= "Pl: " + pl + " \n"  ;
//             result+= "Pr: " + pr + " \n"  ;
//        }
//       else{
//           result+= "*invalid packet* \n"  ;
//       }
//       break;
//   case 0x03:
//       result+= "Packet type: General Control \n"  ;
//       if ((HB1 | HB2 | (SB0&0xEE) | (SB2>>1) | SB3 | SB4 | SB5 | SB6 )==0){
//            long setAVMUTE = (SB0&0x01);
//            long clearAVMUTE = (SB0&0x10);
//            long PP = (SB1)&(0xF0);
//            long CD = (SB1&0xF);
//            long defaultPhase = (SB2&0x01);
//            QString steavmute = QString::number(setAVMUTE);
//            QString clearavmute = QString::number(clearAVMUTE);
//            QString pp = QString::number(PP);
//            QString cd = QString::number(CD);
//            QString defaultphase = QString::number(defaultPhase);
//            result+= "Set_AVMUTE: " + steavmute + " \n"  ;
//            result+= "Clear_AVMUTE: " + clearavmute + " \n"  ;
//            result+= "PP: " + pp + " \n"  ;
//            result+= "CD: " + cd + " \n"  ;
//            result+= "Default_Phase: " + defaultphase + " \n"  ;

//        }
//       else{
//           result+= "*invalid packet* \n"  ;
//       }
//       break;
//   case 0x04:
//       result+="Packet type: ACP Packet \n"  ;
//       if (HB2 == 0){
//           switch (HB1) {
//           case 0x00:
//               if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
//               result+="ACP_Type: Generic Audio \n";}
//               break;
//           case 0x01:
//               if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
//               result+="ACP_Type: IEC 60958-Identified Audio \n";}
//               break;
//           case 0x02:
//               result+="ACP_Type: DVD-Audio \n";
//           if ((PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
//                   long DATDG = (PB0&0xFF);
//                   long CopyP = (PB1&0xC0);
//                   long CopyN = (PB1&0x38);
//                   long Quality = (PB1&0x06);
//                   long Trans = (PB1&0x01);
//                   QString datdg = QString::number(DATDG);
//                   QString Copyp = QString::number(CopyP);
//                   QString Copyn = QString::number(CopyN);
//                   QString quality = QString::number(Quality);
//                   QString trans = QString::number(Trans);
//                   result+="DVD-Audio_Type_Dependent_Generation: "+datdg+" \n";
//                   result+="Copy_Permission: "+Copyp+" \n";
//                   result+="Copy_Number: "+Copyn+" \n";
//                   result+="Quality: "+quality+" \n";
//                   result+="Transaction: "+trans+" \n";
//               }
//               break;
//          case 0x03:
//               result+="ACP_Type: Super Audio CD \n";
//               if ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
//               long CCI = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 | PB6 | PB7 | PB8 | PB9 | PB10 | PB11 | PB12 | PB13 | PB14 | PB15 ;
//               QString cci = QString::number(CCI);
//               result+="CCI_1: "+cci+" \n";
//               }
//           default:
//               break;
//           }

//       }
//       break;
//   case 0x05:
//       result+= "Packet type: ISRC1 Packet \n"  ;
//       if (((HB1&0x38) == 0) && (HB2==0)) {
//           long Cont = (HB1&0x80);
//           long Status = (HB1&0x07);
//           long Valid =(HB1&0x40);
//           QString cont = QString::number(Cont);
//           QString status = QString::number(Status);
//           QString valid = QString::number(Valid);
//           result+="ISRC_Cont: "+cont+" \n";
//           result+="ISRC_Status: "+status+" \n";
//           result+="ISRC_Valid: "+valid+" \n";
//           if((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
//               long UEI0 = PB0;
//               long UEI1 = PB1;
//               long UEI2 = PB2;
//               long UEI3 = PB3;
//               long UEI4 = PB4;
//               long UEI5 = PB5;
//               long UEI6 = PB6;
//               long UEI7 = PB7;
//               long UEI8 = PB8;
//               long UEI9 = PB9;
//               long UEI10 = PB10;
//               long UEI11 = PB11;
//               long UEI12 = PB12;
//               long UEI13 = PB13;
//               long UEI14 = PB14;
//               long UEI15 = PB15;
//               QString uei0 = QString::number(UEI0);
//               QString uei1 = QString::number(UEI1);
//               QString uei2 = QString::number(UEI2);
//               QString uei3 = QString::number(UEI3);
//               QString uei4 = QString::number(UEI4);
//               QString uei5 = QString::number(UEI5);
//               QString uei6 = QString::number(UEI6);
//               QString uei7 = QString::number(UEI7);
//               QString uei8 = QString::number(UEI8);
//               QString uei9 = QString::number(UEI9);
//               QString uei10 = QString::number(UEI10);
//               QString uei11 = QString::number(UEI11);
//               QString uei12 = QString::number(UEI12);
//               QString uei13 = QString::number(UEI13);
//               QString uei14 = QString::number(UEI14);
//               QString uei15 = QString::number(UEI15);
//               result+="UPC_EAN_ISRC_0"+uei0+" \n";
//               result+="UPC_EAN_ISRC_1"+uei1+" \n";
//               result+="UPC_EAN_ISRC_2"+uei2+" \n";
//               result+="UPC_EAN_ISRC_3"+uei3+" \n";
//               result+="UPC_EAN_ISRC_4"+uei4+" \n";
//               result+="UPC_EAN_ISRC_5"+uei5+" \n";
//               result+="UPC_EAN_ISRC_6"+uei6+" \n";
//               result+="UPC_EAN_ISRC_7"+uei7+" \n";
//               result+="UPC_EAN_ISRC_8"+uei8+" \n";
//               result+="UPC_EAN_ISRC_9"+uei9+" \n";
//               result+="UPC_EAN_ISRC_10"+uei10+" \n";
//               result+="UPC_EAN_ISRC_11"+uei11+" \n";
//               result+="UPC_EAN_ISRC_12"+uei12+" \n";
//               result+="UPC_EAN_ISRC_13"+uei13+" \n";
//               result+="UPC_EAN_ISRC_14"+uei14+" \n";
//               result+="UPC_EAN_ISRC_15"+uei15+" \n";
//           }
//       }
//       break;
//   case 0x06:
//       result+= "Packet type: ISRC2 Packet \n"  ;
//       if ((HB1 == 0) && (HB2 == 0) && ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0)){
//           long UEI16 = PB0;
//           long UEI17 = PB1;
//           long UEI18 = PB2;
//           long UEI19 = PB3;
//           long UEI20 = PB4;
//           long UEI21 = PB5;
//           long UEI22 = PB6;
//           long UEI23 = PB7;
//           long UEI24 = PB8;
//           long UEI25 = PB9;
//           long UEI26 = PB10;
//           long UEI27 = PB11;
//           long UEI28 = PB12;
//           long UEI29 = PB13;
//           long UEI30 = PB14;
//           long UEI31 = PB15;
//           QString uei16 = QString::number(UEI16);
//           QString uei17 = QString::number(UEI17);
//           QString uei18 = QString::number(UEI18);
//           QString uei19 = QString::number(UEI19);
//           QString uei20 = QString::number(UEI20);
//           QString uei21 = QString::number(UEI21);
//           QString uei22 = QString::number(UEI22);
//           QString uei23 = QString::number(UEI23);
//           QString uei24 = QString::number(UEI24);
//           QString uei25 = QString::number(UEI25);
//           QString uei26 = QString::number(UEI26);
//           QString uei27 = QString::number(UEI27);
//           QString uei28 = QString::number(UEI28);
//           QString uei29 = QString::number(UEI29);
//           QString uei30 = QString::number(UEI30);
//           QString uei31 = QString::number(UEI31);
//           result+="UPC_EAN_ISRC_16"+uei16+" \n";
//           result+="UPC_EAN_ISRC_17"+uei17+" \n";
//           result+="UPC_EAN_ISRC_18"+uei18+" \n";
//           result+="UPC_EAN_ISRC_19"+uei19+" \n";
//           result+="UPC_EAN_ISRC_20"+uei20+" \n";
//           result+="UPC_EAN_ISRC_21"+uei21+" \n";
//           result+="UPC_EAN_ISRC_22"+uei22+" \n";
//           result+="UPC_EAN_ISRC_23"+uei23+" \n";
//           result+="UPC_EAN_ISRC_24"+uei24+" \n";
//           result+="UPC_EAN_ISRC_25"+uei25+" \n";
//           result+="UPC_EAN_ISRC_26"+uei26+" \n";
//           result+="UPC_EAN_ISRC_27"+uei27+" \n";
//           result+="UPC_EAN_ISRC_28"+uei28+" \n";
//           result+="UPC_EAN_ISRC_29"+uei29+" \n";
//           result+="UPC_EAN_ISRC_30"+uei30+" \n";
//           result+="UPC_EAN_ISRC_31"+uei31+" \n";
//       }
//       break;
//   case 0x07:
//       result+= "Packet type: One Bit Audio Sample Packet \n"  ;
//       if (((HB1&0xE0)==0) && ((HB2&0xF0)==0)){
//           long layout1 = (HB1&0x10);
//           long sp3 = (HB1&0x08);
//           long sp2 = (HB1&0x04);
//           long sp1 = (HB1&0x02);
//           long sp0 = (HB1&0x01);
//           long si0 = (HB2&0x01);
//           long si1 = (HB2&0x02);
//           long si2 = (HB2&0x04);
//           long si3 = (HB2&0x08);
//           long ChA = (SB0)|(SB1<<8)|(SB2<<16)|(SB6&0xF);
//           long ChB = (SB3)|(SB4<<8)|(SB5<<16)|(SB6&0xF);
//           QString lay1 = QString::number(layout1);
//           QString SP3 = QString::number(sp3);
//           QString SP2 = QString::number(sp2);
//           QString SP1 = QString::number(sp1);
//           QString SP0 = QString::number(sp0);
//           QString SI0 = QString::number(si0);
//           QString SI1 = QString::number(si1);
//           QString SI2 = QString::number(si2);
//           QString SI3 = QString::number(si3);
//           QString cha = QString::number(ChA);
//           QString chb = QString::number(ChB);

//           result+="layout: "+lay1+" \n";
//           result+="samples_present.sp0: "+SP0+" \n";
//           result+="samples_present.sp1: "+SP1+" \n";
//           result+="samples_present.sp2: "+SP2+" \n";
//           result+="samples_present.sp3: "+SP3+" \n";
//           result+="samples_invalid.sp0: "+SI0+" \n";
//           result+="samples_invalid.sp1: "+SI1+" \n";
//           result+="samples_invalid.sp2: "+SI2+" \n";
//           result+="samples_invalid.sp3: "+SI3+" \n";
//           result+="ChA: "+cha+" \n";
//           result+="ChB: "+chb+" \n";
//       }
//       break;
//   case 0x08:
//       result+= "Packet type: DST Audio Packet \n"  ;
//       if (((HB1&0x3E) == 0) && (HB2 == 0)){
//           long frames = (HB1&0x80);
//           long samplesi = (HB1&0x40);
//           long DSTnd = (HB1&0x01);
//           long Dx = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//           QString fram = QString::number(frames);
//           QString sam = QString::number(samplesi);
//           QString dst = QString::number(DSTnd);
//           QString dx = QString::number(Dx);
//           result+="farme_start: "+fram+" \n";
//           result+="saqmples_invalid: "+sam+" \n";
//           result+="DST_normal_double: "+dst+" \n";
//           result+="D.X: "+dx+" \n";
//       }
//       break;
//   case 0x09:
//       result+= "Packet type: High Bitrate (HBR) Audio Stream Packet (IEC 61937) \n"  ;
//       if ((HB1 == 0) && ((HB2&0xF) == 0)){
//           long Bx = (HB2&0xF0);
//           QString bx = QString::number(Bx);
//           result+="B.X: "+bx+" \n";
//   }

//       break;
//   case 0x0A:
//       result+= "Packet type: Gamut Metadata Packet \n"  ;
//       if ((HB2&0x40)==0){
//           long nextf = HB1&0x80;
//           long nocrnt = HB2&0x80;
//           long GBDprof = HB1&0x70;
//           long agsn = HB1&0xF;
//           long cgsn = HB2&0xF;
//           long packetseq = HB2&0x30;
//           QString next = QString::number(nextf);
//           QString nocrn = QString::number(nocrnt);
//           QString GBDpro = QString::number(GBDprof);
//           QString ags = QString::number(agsn);
//           QString cgs = QString::number(cgsn);
//           QString packetse = QString::number(packetseq);
//           result+="Next_Field: "+next+" \n";
//           result+="No_Current_GBD: "+nocrn+" \n";
//           result+="GBD_profile: "+GBDpro+" \n";
//           result+="Affected_Gamut_Seq_Num: "+ags+" \n";
//           result+="Current_Gamut_Seq_Num: "+cgs+" \n";
//           result+="Packet_Seq: "+packetse+" \n";
//           switch (GBDprof) {
//              case 0:{
//               result+="P0 \n";
//               long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//               QString gbd  = QString::number(GBD);
//               result+="GBD: "+gbd+" \n";}
//               break;
//              case 0x01:{
//               result+="P1\n";
//               if (packetseq == 0){
//                   long GBDLengthH = (PB0);
//                   long GBDLengthL = (PB1);
//                   long Checksum = (PB2);
//                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString GBDLengthh  = QString::number(GBDLengthH);
//                   QString GBDLengthl = QString::number(GBDLengthL);
//                   QString Checksu = QString::number(Checksum);
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD_Length_H: "+GBDLengthh+" \n";
//                   result+="GBD_Length_L: "+GBDLengthl+" \n";
//                   result+="Checksum: "+Checksu+" \n";
//                   result+="GBD: "+gbd+" \n";
//               }

//               else {
//                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD: "+gbd+" \n";
//               }}
//               break;
//           case 2:{
//               result+="P2 \n";
//               if (packetseq == 0){
//                   long GBDLengthH = (PB0);
//                   long GBDLengthL = (PB1);
//                   long Checksum = (PB2);
//                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString GBDLengthh  = QString::number(GBDLengthH);
//                   QString GBDLengthl = QString::number(GBDLengthL);
//                   QString Checksu = QString::number(Checksum);
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD_Length_H: "+GBDLengthh+" \n";
//                   result+="GBD_Length_L: "+GBDLengthl+" \n";
//                   result+="Checksum: "+Checksu+" \n";
//                   result+="GBD: "+gbd+" \n";
//               }
//               else {
//                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD: "+gbd+" \n";
//               }}
//               break;
//           case 3:{
//               result+="P3\n";
//               if (packetseq == 0){
//                   long GBDLengthH = (PB0);
//                   long GBDLengthL = (PB1);
//                   long Checksum = (PB2);
//                   long GBD = PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString GBDLengthh  = QString::number(GBDLengthH);
//                   QString GBDLengthl = QString::number(GBDLengthL);
//                   QString Checksu = QString::number(Checksum);
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD_Length_H: "+GBDLengthh+" \n";
//                   result+="GBD_Length_L: "+GBDLengthl+" \n";
//                   result+="Checksum: "+Checksu+" \n";
//                   result+="GBD: "+gbd+" \n";
//               }
//               else {
//                   long GBD = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27;
//                   QString gbd  = QString::number(GBD);
//                   result+="GBD: "+gbd+" \n";
//               }
//               break;}
//           default:{
//                       result+="check spicifications\n";
//               break;
//           }}

//       }
//       break;
//   case -0x80 :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7F :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7E :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7D :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7C :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7B :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x7A :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   case -0x79 :
//       result+= "Packet type: InfoFrame Packet \n"  ;
//       break;
//   default:
//       result+="invalid byte\n";
//       break;
//   }
//   if (((HB0&INFO_FRAME_PACKET_BIT) !=0) && ((HB2&0xE0) == 0)){
//       long IFType = HB0&0x7F;

//       switch (IFType) {
//       case 0x01:{
//           result+="InfoFrame Type: Vendor Specific InfoFrame\n";
//            HB0=0x81;
//            long IFVersion = HB1;
//            long IFLenght = HB2&0x1F;
//            QString IFVersio = QString::number(IFVersion);
//            QString IFLeng = QString::number(IFLenght);
//            if (IFVersion == 0x01){
//                 long IEEE= PB1 | (PB2<<8) | (PB3<<16);
//                 long VA = (PB4&0xF0)>>4;
//                 long VB = (PB4&0xF);
//                 long VC = (PB5&0xF0)>>4;
//                 long VD = (PB5&0xF);
//                 long SupAI = (PB6&0x80)>>7;
//                 long DC48bit = (PB6&0x40)>>6;
//                 long DC36bit = (PB6&0x20)>>5;
//                 long DC30bit = (PB6&0x10)>>4;
//                 long DCY444 = (PB6&0x08)>>3;
//                 long DVIDUAL = (PB6&0x01);
//                 long MAXTMDS = (PB7);
//                 long LFP = (PB8&0x80)>>7;
//                 long ILFP = (PB8&0x40)>>6;
//                 QString IEE = QString::number(IEEE);
//                 QString va = QString::number(VA);
//                 QString vb = QString::number(VB);
//                 QString vc = QString::number(VC);
//                 QString vd = QString::number(VD);
//                 QString SupA = QString::number(SupAI);
//                 QString DC48bi = QString::number(DC48bit);
//                 QString DC36bi = QString::number(DC36bit);
//                 QString DC30bi = QString::number(DC30bit);
//                 QString DCy444 = QString::number(DCY444);
//                 QString DVIDU = QString::number(DVIDUAL);
//                 QString MAXTMD = QString::number(MAXTMDS);
//                 QString LFP1 = QString::number(LFP);
//                 QString ILFP2 = QString::number(ILFP);
//                 result+="InfoFrame_version: "+IFVersio+" \n";
//                 result+="InfoFrame_length: "+IFLeng+" \n";
//                 result+="IEEE Registration Identifier: "+IEE+" \n";
//                 result+="A: "+va+" \n";
//                 result+="B: "+vb+" \n";
//                 result+="C: "+vc+" \n";
//                 result+="D: "+vd+" \n";
//                 result+="Supports_AI: "+SupA+" \n";
//                 result+="DC_30bit: "+DC30bi+" \n";
//                 result+="DC_36bit: "+DC36bi+" \n";
//                 result+="DC_48bit: "+DC48bi+" \n";
//                 result+="DC_Y444: "+DCy444+" \n";
//                 result+="DVI_Dual: "+DVIDU+" \n";
//                 result+="Max_TMDS_Clock: "+MAXTMD+" \n";
//                 result+="Latency_Fields_Present: "+LFP1+" \n";
//                 result+="I_Latency_Fields_Present: "+ILFP2+" \n";
//                }
//            if (IFLenght>=9){
//               long VideoLatency = PB9;
//               QString VideoLatenc = QString::number(VideoLatency);
//               result+="Video_Latency: "+VideoLatenc+" \n";
//               if (IFLenght>=10){
//                   long AudioLatency = PB10;
//                   QString AudioLatenc = QString::number(AudioLatency);
//                   result+="Audio_Latency: "+AudioLatenc+" \n";
//                   if (IFLenght>=11){
//                       long InterlacedVideoLatency = PB11;
//                       QString InterlacedVideoLatenc = QString::number(InterlacedVideoLatency);
//                       result+="Interlaced_Video_Latency: "+InterlacedVideoLatenc+" \n";
//                       if (IFLenght>=12){
//                           long InterlacedAudioLatency = PB12;
//                           QString InterlacedAudioLatenc = QString::number(InterlacedAudioLatency);
//                           result+="Interlaced_Audio_Latency: "+InterlacedAudioLatenc+" \n";
//                   }
//               }
//            }
//            }
//           break;}
//       case 0x02:{
//           HB0=0x82;
//           result+="InfoFrame Type: AVI InfoFrame\n";
//           long IFVersion = HB1;
//           if (IFVersion == 0x01){
//                long IFLenght = HB2&0x1F;
//                QString IFVersio = QString::number(IFVersion);
//                QString IFLengt = QString::number(IFLenght);
//                result+="Version: "+IFVersio+" \n";
//                result+="Length: "+IFLengt+" \n";
//                long Y = (PB1&0x60)>>5;
//                QString y = QString::number(Y);
//                switch (Y) {
//                case 0x00:{
//                    result+="Y: "+ y +" : RGB (default)"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Y: "+ y +" : YCBCR 4:2:2"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Y: "+ y +" : YCBCR 4:4:4"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Y: "+ y +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long A = (PB1&0x10)>>4;
//                QString a = QString::number(A);
//                switch (A) {
//                case 0x00:{
//                    result+="A: "+ a +" : No Active Format Information"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="A: "+ a +" : Active Format (R3...R0) Information present"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long B = (PB1&0x0C)>>2;
//                QString b = QString::number(B);
//                switch (B) {
//                case 0x00:{
//                    result+="B: "+ b +" : Bar Data not present"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="B: "+ b +" : Vert. Bar Info present"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="B: "+ b +" : Horiz. Bar Info present"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="B: "+ b +" : Vert. and Horiz. Bar Info present"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long S = (PB1&0x03);
//                QString s = QString::number(S);
//                switch (S) {
//                case 0x00:{
//                    result+="S: "+ s +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="S: "+ s +" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."+" \n";
//                    break;}
//                case 0x02:{
//                    result+="S: "+ s +" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."+" \n";
//                    break;}
//                case 0x03:{
//                    result+="S: "+ s +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long C = (PB2&0xC0)>>6;
//                QString c = QString::number(C);
//                switch (C) {
//                case 0x00:{
//                    result+="C: "+ c +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="C: "+ c +" : SMPTE 170M [1]"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="C: "+ c +" : ITU-R 709 [7]"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="C: "+ c +" : Extended Colorimetry Information Valid"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long M = (PB2&0x30)>>4;
//                QString m = QString::number(M);
//                switch (M) {
//                case 0x00:{
//                    result+="M: "+ m +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="M: "+ m +" : 4:3"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="M: "+ m +" : 16:9"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="M: "+ m +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long R = (PB2&0x0F);
//                QString r = QString::number(R);
//                switch (R) {
//                case 0x08:{
//                    result+="R: "+ r +" : Same as coded frame aspect ratio"+" \n";
//                    break;}
//                case 0x09:{
//                    result+="R: "+ r +" : 4:3 (center)"+" \n";
//                    break;}
//                case 0x0A:{
//                    result+="R: "+ r +" : 16:9 (center)"+" \n";
//                    break;}
//                case 0x0B:{
//                    result+="R: "+ r +" : 14:9 (center)"+" \n";
//                    break;}
//                default:{
//                    result+="R: "+ r +" : Varies. See Annex H."+" \n";
//                    break;}
//                }
//                long SC = (PB3&0x03);
//                QString sc = QString::number(SC);
//                switch (SC) {
//                case 0x00:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : No Know non-uniform Scaling"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled vertically"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally and vertically"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long ETB = (PB5&0xFF) | (PB6&0xFF00);
//                long SBB = (PB7&0xFF) | (PB8&0xFF00);
//                long ELB = (PB9&0xFF) | (PB10&0xFF00);
//                long SRB = (PB11&0xFF) | (PB12&0xFF00);
//                QString etb = QString::number(ETB);
//                QString sbb = QString::number(SBB);
//                QString elb = QString::number(ELB);
//                QString srb = QString::number(SRB);
//                result+="ETB: "+etb+" \n";
//                result+="SBB: "+sbb+" \n";
//                result+="ELB: "+elb+" \n";
//                result+="SRB: "+srb+" \n";
//           }
//           if (IFVersion == 0x02){
//                long IFLenght = HB2&0x1F;
//                QString IFVersio = QString::number(IFVersion);
//                QString IFLengh = QString::number(IFLenght);
//                result+="Version: "+IFVersio+" \n";
//                result+="Length: "+IFLengh+" \n";

//                long Y = (PB1&0x60)>>5;
//                QString y = QString::number(Y);
//                switch (Y) {
//                case 0x00:{
//                    result+="Y: "+ y +" : RGB (default)"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Y: "+ y +" : YCBCR 4:2:2"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Y: "+ y +" : YCBCR 4:4:4"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Y: "+ y +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long A = (PB1&0x10)>>4;
//                QString a = QString::number(A);
//                switch (A) {
//                case 0x00:{
//                    result+="A: "+ a +" : No Active Format Information"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="A: "+ a +" : Active Format (R3...R0) Information present"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long B = (PB1&0x0C)>>2;
//                QString b = QString::number(B);
//                switch (B) {
//                case 0x00:{
//                    result+="B: "+ b +" : Bar Data not present"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="B: "+ b +" : Vert. Bar Info present"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="B: "+ b +" : Horiz. Bar Info present"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="B: "+ b +" : Vert. and Horiz. Bar Info present"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long S = (PB1&0x03);
//                QString s = QString::number(S);
//                switch (S) {
//                case 0x00:{
//                    result+="S: "+ s +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="S: "+ s +" : Composed for an overscanned display, where some active pixels and lines at the edges are not displayed."+" \n";
//                    break;}
//                case 0x02:{
//                    result+="S: "+ s +" : Composed for an underscanned display, where all active pixels & lines are displayed, with or without a border."+" \n";
//                    break;}
//                case 0x03:{
//                    result+="S: "+ s +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long C = (PB2&0xC0)>>6;
//                QString c = QString::number(C);
//                switch (C) {
//                case 0x00:{
//                    result+="C: "+ c +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="C: "+ c +" : SMPTE 170M [1]"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="C: "+ c +" : ITU-R 709 [7]"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="C: "+ c +" : Extended Colorimetry Information Valid"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long M = (PB2&0x30)>>4;
//                QString m = QString::number(M);
//                switch (M) {
//                case 0x00:{
//                    result+="M: "+ m +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="M: "+ m +" : 4:3"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="M: "+ m +" : 16:9"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="M: "+ m +" : *future*"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long R = (PB2&0x0F);
//                QString r = QString::number(R);
//                switch (R) {
//                case 0x08:{
//                    result+="R: "+ r +" : Same as coded frame aspect ratio"+" \n";
//                    break;}
//                case 0x09:{
//                    result+="R: "+ r +" : 4:3 (center)"+" \n";
//                    break;}
//                case 0x0A:{
//                    result+="R: "+ r +" : 16:9 (center)"+" \n";
//                    break;}
//                case 0x0B:{
//                    result+="R: "+ r +" : 14:9 (center)"+" \n";
//                    break;}
//                default:{
//                    result+="R: "+ r +" : Varies. See Annex H."+" \n";
//                    break;}
//                }
//                long ITC = (PB3&0x80)>>7;
//                QString itc = QString::number(ITC);
//                switch (ITC) {
//                case 0x00:{
//                    result+="IT content: "+ itc +" : No Data"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="IT content: "+ itc +" : IT content (Byte 5 CN bits valid)"+" \n";
//                    break;}
//                default:{

//                    break;}
//                }
//                long EC = (PB3&0x70)>>4;
//                QString ec  = QString::number(EC);
//                switch (EC) {
//                case 0x00:{
//                    result+="Extended Colorimetry: "+ ec +" : xvYCC601"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Extended Colorimetry: "+ ec +" : xvYCC709"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Extended Colorimetry: "+ ec +" : sYCC601"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Extended Colorimetry: "+ ec +" : AdobeYCC601"+" \n";
//                    break;}
//                case 0x04:{
//                    result+="Extended Colorimetry: "+ ec +" : AdobeRGB"+" \n";
//                    break;}
//                default:{
//                    result+="EC: "+ ec +" \n";
//                    break;}
//                }
//                long Q = (PB3&0x0C)>>2;
//                QString q  = QString::number(Q);
//                switch (Q) {
//                case 0x00:{
//                    result+="RGB Quanitization Range: "+ q +" : Default (depends on video format)"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="RGB Quanitization Range: "+ q +" : Limit Range"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="RGB Quanitization Range: "+ q +" : Full Range"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="RGB Quanitization Range: "+ q +" : Reserved"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long SC = (PB3&0x03);
//                QString sc = QString::number(SC);
//                switch (SC) {
//                case 0x00:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : No Know non-uniform Scaling"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled vertically"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Non-Uniform Picture Scaling: "+ sc +" : Picture has been scaled horizontally and vertically"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long VIC = (PB4&0x7F);
//                QString vic = QString::number(VIC);
//                switch (VIC) {
//                case 1:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 640x480p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: No Repetition \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 2:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: No Repetition \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 3:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: No Repetition \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 4:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: No Repetition \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 5:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080i @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: No Repetition \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 6:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 7:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 8:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x240p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 9:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x240p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times \n";
//                    result+="AVI w/PR Required: No \n";
//                    break;}
//                case 10:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x480i @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 11:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x480i @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 12:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x240p @ 59.94/60Hz \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 13:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x240p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 14:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1440x480p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 2 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 15:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1440x480p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 2 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 16:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 17:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 18:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 19:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 20:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080i @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 21:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 22:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 23:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x288p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 24:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x288p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 25:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x576i @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 26:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x576i @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 27:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x288p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 28:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x288p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 to 10 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 29:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1440x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 or 2 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 30:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1440x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1 or 2 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 31:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 32:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 23.98/24Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 33:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 25Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 34:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 29.98/30Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 35:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x480p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 36:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x480p @ 59.94/60Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 37:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 38:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 2880x576p @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 1, 2 or 4 times  \n";
//                    result+="AVI w/PR Required: Yes  \n";
//                    break;}
//                case 39:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080i (1250) @ 50Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 40:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080i @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 41:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 42:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 43:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 44:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 45:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 46:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080i @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 47:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 48:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 49:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 50:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 51:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 119.88/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 52:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 200Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 53:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x576p @ 200Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 54:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 200Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 55:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x576i @ 200Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 56:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 239.76/240Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 57:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720x480p @ 239.76/240Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 58:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 239.76/240Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 59:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 720(1440)x480i @ 239.76/240Hz  \n";
//                    result+="Valid Pixel Repeat Values: pixel data sent 2 times  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 60:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 23.97Hz/24Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 61:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 25Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 62:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1280x720p @ 29.97Hz/30Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 63:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 119.88Hz/120Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                case 64:{
//                    result+="VIC: "+ vic +" \n";
//                    result+="Video Description: 1920x1080p @ 100Hz  \n";
//                    result+="Valid Pixel Repeat Values: No Repetition  \n";
//                    result+="AVI w/PR Required: No  \n";
//                    break;}
//                default:{
//                    result+="VIC: "+ vic +" \n";
//                    break;}}
//                long YQ = (PB3&0xC0)>>6;
//                QString yq = QString::number(YQ);
//                switch (YQ) {
//                case 0x00:{
//                    result+="YCC Quanitization Range: "+ yq +" : Limited Range"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="YCC Quanitization Range: "+ yq +" : Full Range"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="YCC Quanitization Range: "+ yq +" : Reserved"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="YCC Quanitization Range: "+ yq +" : Reserved"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long CN = (PB3&0x30)>>4;
//                QString cn = QString::number(CN);
//                switch (CN) {
//                case 0x00:{
//                    result+="IT Content Type: "+ cn +" : Graphics"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="IT Content Type: "+ cn +" : Photo"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="IT Content Type: "+ cn +" : Cinema"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="IT Content Type: "+ cn +" : Game"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long PR = PB4&0x0F;
//                QString pr = QString::number(PR);
//                switch (PR) {
//                case 0x00:{
//                    result+="Pixel Repetition Factor: "+ pr +" : No Repetition (i.e., pixel date sent once)"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 2 times (i.e., repeated once)"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 3 times"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 4 times"+" \n";
//                    break;}
//                case 0x04:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 5 times"+" \n";
//                    break;}
//                case 0x05:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 6 times"+" \n";
//                    break;}
//                case 0x06:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 7 times"+" \n";
//                    break;}
//                case 0x07:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 8 times"+" \n";
//                    break;}
//                case 0x08:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 9 times"+" \n";
//                    break;}
//                case 0x09:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Pixel data sent 10 times"+" \n";
//                    break;}
//                default:{
//                    result+="Pixel Repetition Factor: "+ pr +" : Reserved"+" \n";
//                    break;}
//                }
//                long ETB = (PB5&0xFF) | (PB6&0xFF00);
//                long SBB = (PB7&0xFF) | (PB8&0xFF00);
//                long ELB = (PB9&0xFF) | (PB10&0xFF00);
//                long SRB = (PB11&0xFF) | (PB12&0xFF00);
//                QString etb = QString::number(ETB);
//                QString sbb = QString::number(SBB);
//                QString elb = QString::number(ELB);
//                QString srb = QString::number(SRB);
//                result+="ETB: "+etb+" \n";
//                result+="SBB: "+sbb+" \n";
//                result+="ELB: "+elb+" \n";
//                result+="SRB: "+srb+" \n";

//           }
//           break;}
//       case 0x03:{
//           HB0=0x83;
//           result+="InfoFrame Type: Source Product Descriptor InfoFrame \n";
//           long IFVersion = HB1;
//           long IFLenght = HB2&0x1F;
//           if ((IFVersion == 0x01) && (IFLenght == 25)){
//               QString IFVersio = QString::number(IFVersion);
//               QString IFLengh = QString::number(IFLenght);
//               result+="Version: "+IFVersio+" \n";
//               result+="Length: "+IFLengh+" \n";
//                long VN1 = PB1&0xEF;
//                long VN2 = PB2&0xEF;
//                long VN3 = PB3&0xEF;
//                long VN4 = PB4&0xEF;
//                long VN5 = PB5&0xEF;
//                long VN6 = PB6&0xEF;
//                long VN7 = PB7&0xEF;
//                long VN8 = PB8&0xEF;
//                long PD1 = PB9&0xEF;
//                long PD2 = PB10&0xEF;
//                long PD3 = PB11&0xEF;
//                long PD4 = PB12&0xEF;
//                long PD5 = PB13&0xEF;
//                long PD6 = PB14&0xEF;
//                long PD7 = PB15&0xEF;
//                long PD8 = PB16&0xEF;
//                long PD9 = PB17&0xEF;
//                long PD10 = PB18&0xEF;
//                long PD11 = PB19&0xEF;
//                long PD12 = PB20&0xEF;
//                long PD13 = PB21&0xEF;
//                long PD14 = PB22&0xEF;
//                long PD15 = PB23&0xEF;
//                long PD16 = PB24&0xEF;
//                QString vn1 = QString::number(VN1);
//                QString vn2 = QString::number(VN2);
//                QString vn3 = QString::number(VN3);
//                QString vn4 = QString::number(VN4);
//                QString vn5 = QString::number(VN5);
//                QString vn6 = QString::number(VN6);
//                QString vn7 = QString::number(VN7);
//                QString vn8 = QString::number(VN8);
//                QString pd1 = QString::number(PD1);
//                QString pd2 = QString::number(PD2);
//                QString pd3 = QString::number(PD3);
//                QString pd4 = QString::number(PD4);
//                QString pd5 = QString::number(PD5);
//                QString pd6 = QString::number(PD6);
//                QString pd7 = QString::number(PD7);
//                QString pd8 = QString::number(PD8);
//                QString pd9 = QString::number(PD9);
//                QString pd10 = QString::number(PD10);
//                QString pd11 = QString::number(PD11);
//                QString pd12 = QString::number(PD12);
//                QString pd13 = QString::number(PD13);
//                QString pd14 = QString::number(PD14);
//                QString pd15 = QString::number(PD15);
//                QString pd16 = QString::number(PD16);
//                result+="VN1: "+vn1+" \n";
//                result+="VN2: "+vn2+" \n";
//                result+="VN3: "+vn3+" \n";
//                result+="VN4: "+vn4+" \n";
//                result+="VN5: "+vn5+" \n";
//                result+="VN6: "+vn6+" \n";
//                result+="VN7: "+vn7+" \n";
//                result+="VN8: "+vn8+" \n";
//                result+="PD1: "+pd1+" \n";
//                result+="PD2: "+pd2+" \n";
//                result+="PD3: "+pd3+" \n";
//                result+="PD4: "+pd4+" \n";
//                result+="PD5: "+pd5+" \n";
//                result+="PD6: "+pd6+" \n";
//                result+="PD7: "+pd7+" \n";
//                result+="PD8: "+pd8+" \n";
//                result+="PD9: "+pd9+" \n";
//                result+="PD10: "+pd10+" \n";
//                result+="PD11: "+pd11+" \n";
//                result+="PD12: "+pd12+" \n";
//                result+="PD13: "+pd13+" \n";
//                result+="PD14: "+pd14+" \n";
//                result+="PD15: "+pd15+" \n";
//                result+="PD16: "+pd16+" \n";
//                long SourceINFO = PB25;
//                QString si = QString::number(SourceINFO);
//                switch (SourceINFO) {
//                case 0x00:
//                    result+="Source Information: unknown ( "+si+" )"+" \n";
//                    break;
//                case 0x01:
//                    result+="Source Information: Digital STB ( "+si+" )"+" \n";
//                    break;
//                case 0x02:
//                    result+="Source Information: DVD player ( "+si+" )"+" \n";
//                    break;
//                case 0x03:
//                    result+="Source Information: D-VHS ( "+si+" )"+" \n";
//                    break;
//                case 0x04:
//                    result+="Source Information: HDD Videorecorder ( "+si+" )"+" \n";
//                    break;
//                case 0x05:
//                    result+="Source Information: DVC ( "+si+" )"+" \n";
//                    break;
//                case 0x06:
//                    result+="Source Information: DSC ( "+si+" )"+" \n";
//                    break;
//                case 0x07:
//                    result+="Source Information: Video CD ( "+si+" )"+" \n";
//                    break;
//                case 0x08:
//                    result+="Source Information: Game ( "+si+" )"+" \n";
//                    break;
//                case 0x09:
//                    result+="Source Information: PC general ( "+si+" )"+" \n";
//                    break;
//                case 0x0A:
//                    result+="Source Information: Blu-Ray Disk (BD) ( "+si+" )"+" \n";
//                    break;
//                case 0x0B:
//                    result+="Source Information: Super Audio CD ( "+si+" )"+" \n";
//                    break;
//                case 0x0C:
//                    result+="Source Information: HD DVD ( "+si+" )"+" \n";
//                    break;
//                case 0x0D:
//                    result+="Source Information: PMP ( "+si+" )"+" \n";
//                    break;
//                default:
//                    result+="Source Information: *reserved* ( "+si+" )"+" \n";
//                    break;
//                }
//           }
//           break;}
//       case 0x04:{
//           HB0=0x84;
//           result+="InfoFrame Type: Audio InfoFrame \n";
//           long IFVersion = HB1;
//           long IFLenght = HB2&0x1F;
//           if ((IFVersion == 1) && (IFLenght == 10)){
//               QString IFVersio = QString::number(IFVersion);
//               QString IFLengh = QString::number(IFLenght);
//               result+="Version: "+IFVersio+" \n";
//               result+="Length: "+IFLengh+" \n";
//                long CT = (PB1&0xF0)>>4;
//                QString ct = QString::number(CT);
//                switch (CT) {
//                case 0x00:{
//                    result+="CT="+ ct +" >> Refer to Stream Header"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="CT="+ ct +" >> Audio Coding Type: PCM ; Audio Stream Standard: IEC 60958-3 [13]"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="CT="+ ct +" >> Audio Coding Type: AC-3 ; Audio Stream Encoding Standard: ATSC A/58B [12] excluding Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="CT="+ ct +" >> Audio Coding Type: MPEG-1 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 1 or Layer 2 ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
//                    break;}
//                case 0x04:{
//                    result+="CT="+ ct +" >> Audio Coding Type: MP3 ; Audio Stream Encoding Standard: ISO/IEC 11172-3 [22] Layer 3 ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
//                    break;}
//                case 0x05:{
//                    result+="CT="+ ct +" >> Audio Coding Type: MPEG2 ; Audio Stream Encoding Standard: ISO/IEC 13818-3 [23] ; Audio Stream Transport Standart: IEC 61937-4 [16]"+" \n";
//                    break;}
//                case 0x06:{
//                    result+="CT="+ ct +" >> Audio Coding Type: AAC LC ; Audio Stream Encoding Standard: ISO/IEC 14496-3 [24] ; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
//                    break;}
//                case 0x07:{
//                    result+="CT="+ ct +" >> Audio Coding Type: DTS; Audio Stream Encoding Standard: ETSI TS 102 114 [37] ; Audio Stream Transport Standart: IEC 61937-5 [17]"+" \n";
//                    break;}
//                case 0x08:{
//                    result+="CT="+ ct +" >> Audio Coding Type: ATRAC ; Audio Stream Encoding Standard: IEC 61909 [14] See also ATRAC [61] ; Audio Stream Transport Standart: IEC 61937-7 [19]"+" \n";
//                    break;}
//                case 0x09:{
//                    result+="CT="+ ct +" >> Audio Coding Type: DSD ; Audio Stream Standard: ISO/IEC 14496-3 [24], subpart 10, See also Super Audio CD [70]"+" \n";
//                    break;}
//                case 0x0A:{
//                    result+="CT="+ ct +" >> Audio Coding Type: E-AC-3 ; Audio Stream Encoding Standard: ATSC A/52B [12] with Annex E ; Audio Stream Transport Standart: IEC 61937-3 [15]"+" \n";
//                    break;}
//                case 0x0B:{
//                    result+="CT="+ ct +" >> Audio Coding Type: DTS-HD ; Audio Stream Encoding Standard: DVD Forum DTS-HD [28] ; Audio Stream Transport Standart: IEC 61937-5 [17]"+" \n";
//                    break;}
//                case 0x0C:{
//                    result+="CT="+ ct +" >> Audio Coding Type: MLP ; Audio Stream Encoding Standard: DVD Forum MLP [27] ; Audio Stream Transport Standart: IEC 61937-9 [21]"+" \n";
//                    break;}
//                case 0x0D:{
//                    result+="CT="+ ct +" >> Audio Coding Type: DST ; Audio Stream Standard:  ISO/IEC 14496-3 [24], subpart 10"+" \n";
//                    break;}
//                case 0x0E:{
//                    result+="CT="+ ct +" >> Audio Coding Type: WWA Pro ; Audio Stream Encoding Standard: WWA Pro Decoder Specification [30] ; Audio Stream Transport Standart: IEC 61937-8 [20]"+" \n";
//                    break;}
//                case 0x0F:{
//                    result+="CT="+ ct +" >> Refer to Audio Codding Extension Type (CXT) field in Data Byte 3"+" \n";
//                    break;}
//                default:{

//                    break;}}
//                long CC = PB1&0x07;
//                QString cc = QString::number(CC);
//                switch (CC) {
//                case 0x00:{
//                    result+="CС="+ cc +" >> Refer to Stream Header"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="CС="+ cc +" >> Audio Channel Count: 2 channels"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="CС="+ cc +" >> Audio Channel Count: 3 channels"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="СС="+ cc +" >> Audio Channel Count: 4 channels"+" \n";
//                    break;}
//                case 0x04:{
//                    result+="CС="+ cc +" >> Audio Channel Count: 5 channels"+" \n";
//                    break;}
//                case 0x05:{
//                    result+="CС="+ cc +" >> Audio Channel Count: 6 channels"+" \n";
//                    break;}
//                case 0x06:{
//                    result+="CС="+ cc +" >> Audio Channel Count: 7 channels"+" \n";
//                    break;}
//                case 0x07:{
//                    result+="CC="+ cc +" >> Audio Channel Count: 8 channels"+" \n";
//                    break;}
//                default:{
//                    break;}}
//                long SF = PB2&0x1C;
//                QString sf = QString::number(SF);
//                switch (SF) {
//                case 0x00:{
//                    result+="SF="+ sf +" >> Refer to Stream Header"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="SF="+ sf +" >> Samping Frequency: 32 kHz"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="SF="+ sf +" >> Samping Frequency: 44.1 kHz (CD) "+" \n";
//                    break;}
//                case 0x03:{
//                    result+="SF="+ sf +" >> Samping Frequency: 48 kHz "+" \n";
//                    break;}
//                case 0x04:{
//                    result+="SF="+ sf +" >> Samping Frequency: 88.2 kHz"+" \n";
//                    break;}
//                case 0x05:{
//                    result+="SF="+ sf +" >> Samping Frequency: 96 kHZ"+" \n";
//                    break;}
//                case 0x06:{
//                    result+="SF="+ sf +" >> Samping Frequency: 176.4 kHz"+" \n";
//                    break;}
//                case 0x07:{
//                    result+="SF="+ sf +" >> Samping Frequency: 192 kHz"+" \n";
//                    break;}
//                default:{
//                    break;}}
//                long SS = PB2&0x03;
//                QString ss = QString::number(SS);
//                switch (SS) {
//                case 0x00:{
//                    result+="SS="+ ss +" >> Refer to Stream Header"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="SS="+ ss +" >> Sample Size: 16bit"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="SS="+ ss +" >> Sample Size: 20bit"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="SS="+ ss +" >> Sample Size: 24bit"+" \n";
//                    break;}
//                default:{
//                    break;}}
//                long CXT = PB3&0x1F;
//                QString cxt = QString::number(CXT);
//                switch (CXT) {
//                case 0x00:{
//                    result+="CXT="+ cxt +" >> Refer to Stream Header"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: HE-AAC ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005 [24]; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: HE-AAACv2 ; Audio Stream Encoding Standard: ISO/IEC 14496-3:2005/AMD2:2006 [25] ; Audio Stream Transport Standart: IEC 61937-6 [18]"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="CXT="+ cxt +"  >> Audio Coding Extension Type: AC-3 ; Audio Stream Encoding Standard: ISO/IEC 230003-1:2007 [26]"+" \n";
//                    break;}
//                default:{
//                    result+="CXT="+ cxt +" >> *reserved*"+" \n";
//                    break;}}
//                long CA = PB4&0xFF;
//                QString ca = QString::number(CA);
//                result+="|........|                    Channels:                    |  \n";
//                result+="|   CA  |  8  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  \n";
//                switch (CA) {
//                case 0x00:{
//                    result+="| 0x00 |  -  |  -  |  -  |  -  |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x01:{
//                    result+="| 0x01 |  -  |  -  |  -  |  -  |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x02:{
//                    result+="| 0x02 |  -  |  -  |  -  |  -  |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x03:{
//                    result+="| 0x03 |  -  |  -  |  -  |  -  |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x04:{
//                    result+="| 0x04 |  -  |  -  |  -  |  RC |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x05:{
//                    result+="| 0x05 |  -  |  -  |  -  |  RC |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x06:{
//                    result+="| 0x06 |  -  |  -  |  -  |  RC |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x07:{
//                    result+="| 0x07 |  -  |  -  |  -  |  RC |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x08:{
//                    result+="| 0x08 |  -  |  -  |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x09:{
//                    result+="| 0x09 |  -  |  -  |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x0A:{
//                    result+="| 0x0A |  -  |  -  |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x0B:{
//                    result+="| 0x0B |  -  |  -  |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x0C:{
//                    result+="| 0x0C |  -  |  RC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x0D:{
//                    result+="| 0x0D |  -  |  RC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x0E:{
//                    result+="| 0x0E |  -  |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x0F:{
//                    result+="| 0x0F |  -  |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x10:{
//                    result+="| 0x10 | RRC | RLC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x11:{
//                    result+="| 0x11 | RRC | RLC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x12:{
//                    result+="| 0x12 | RRC | RLC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x13:{
//                    result+="| 0x13 | RRC | RLC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x14:{
//                    result+="| 0x14 | FRC | FLC |  -  |  -  |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x15:{
//                    result+="| 0x15 | FRC | FLC |  -  |  -  |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x16:{
//                    result+="| 0x16 | FRC | FLC |  -  |  -  |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x17:{
//                    result+="| 0x17 | FRC | FLC |  -  |  -  |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x18:{
//                    result+="| 0x18 | FRC | FLC |  -  |  RC |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x19:{
//                    result+="| 0x19 | FRC | FLC |  -  |  RC |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x1A:{
//                    result+="| 0x1A | FRC | FLC |  -  |  RC |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x1B:{
//                    result+="| 0x1B | FRC | FLC |  -  |  RC |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x1C:{
//                    result+="| 0x1C | FRC | FLC |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x1D:{
//                    result+="| 0x1D | FRC | FLC |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x1E:{
//                    result+="| 0x1E | FRC | FLC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x1F:{
//                    result+="| 0x1F | FRC | FLC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x20:{
//                    result+="| 0x20 |  -  | FCH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x21:{
//                    result+="| 0x21 |  -  | FCH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x22:{
//                    result+="| 0x22 |  TC |  -  |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x23:{
//                    result+="| 0x23 |  TC |  -  |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x24:{
//                    result+="| 0x24 | FRH | FLH |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x25:{
//                    result+="| 0x25 | FRH | FLH |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x26:{
//                    result+="| 0x26 | FRW | FLW |  RR |  RL |  -  |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x27:{
//                    result+="| 0x27 | FRW | FLW |  RR |  RL |  -  | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x28:{
//                    result+="| 0x28 |  TC |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x29:{
//                    result+="| 0x29 |  TC |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x2A:{
//                    result+="| 0x2A | FCH |  RC |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x2B:{
//                    result+="| 0x2B | FCH |  RC |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x2C:{
//                    result+="| 0x2C |  TC | FCH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x2D:{
//                    result+="| 0x2D |  TC | FCH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x2E:{
//                    result+="| 0x2E | FRH | FLH |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x2F:{
//                    result+="| 0x2F | FRH | FLH |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                case 0x30:{
//                    result+="| 0x30 | FRW | FLW |  RR |  RL |  FC |  -  |  FR |  FL |  \n";
//                    break;}
//                case 0x31:{
//                    result+="| 0x31 | FRW | FLW |  RR |  RL |  FC | LFE |  FR |  FL |  \n";
//                    break;}
//                default:{
//                    result+="| "+ca+"|                  *reserved*                   |  \n";
//                    break;}
//                }
//                long DMINH = (PB5&0x80)>>7;
//                switch (DMINH) {
//                case 0x00:
//                    result+="Mixed stereo output is: permitted or no information about any assertion of this \n";
//                    break;
//                case 0x01:
//                    result+="Mixed stereo output is: prohibited \n";
//                    break;
//                default:
//                    break;
//                }
//                long LSV = (PB5&0x78)>>3;
//                QString lsv = QString::number(LSV);
//                switch (LSV) {
//                case 0x00:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 0dB"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 1dB"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 2dB"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 3dB"+" \n";
//                    break;}
//                case 0x04:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 4dB"+" \n";
//                    break;}
//                case 0x05:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 5dB"+" \n";
//                    break;}
//                case 0x06:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 6dB"+" \n";
//                    break;}
//                case 0x07:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 7dB"+" \n";
//                    break;}
//                case 0x08:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 8dB"+" \n";
//                    break;}
//                case 0x09:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 9dB"+" \n";
//                    break;}
//                case 0x0A:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 10dB"+" \n";
//                    break;}
//                case 0x0B:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 11dB"+" \n";
//                    break;}
//                case 0x0C:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 12dB"+" \n";
//                    break;}
//                case 0x0D:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 13dB"+" \n";
//                    break;}
//                case 0x0E:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 14dB"+" \n";
//                    break;}
//                case 0x0F:{
//                    result+="LSV ="+ lsv +" >> Level Shift Value: 15dB"+" \n";
//                    break;}
//                default:
//                    break;
//                }
//                long LFEPBL = PB5&0x02;
//                QString lf = QString::number(LFEPBL);
//                switch (LFEPBL) {
//                case 0x00:{
//                    result+="LFEPBL="+ lf +" >> LFE playback level: unknown or refer to other information"+" \n";
//                    break;}
//                case 0x01:{
//                    result+="LFEPBL="+ lf +" >> 0 dB playback"+" \n";
//                    break;}
//                case 0x02:{
//                    result+="LFEPBL="+ lf +" >> + 10 dB playback"+" \n";
//                    break;}
//                case 0x03:{
//                    result+="LFEPBL="+ lf +" >> *reserved*"+" \n";
//                    break;}
//                default:
//                    break;
//                }



//           }
//           break;}
//       case 0x05:{
//           HB0=0x85;
//           result+="InfoFrame Type: MPEG Source InfoFrame \n";
//           long IFVersion = HB1;
//           long IFLenght = HB2&0x1F;
//           if (IFVersion == 0x01){
//               QString IFVersio = QString::number(IFVersion);
//               QString IFLengh = QString::number(IFLenght);
//               result+="Version: "+IFVersio+" \n";
//               result+="Length: "+IFLengh+" \n";
//               long MB = (PB1) | ((PB2&0xFF)<<8)| ((PB3&0xFF)<<16)| ((PB4&0xFF)+24);
//               QString mb = QString::number(MB);
//               result+="MPEG bit rate: "+mb+" \n";
//               long FR = (PB5&0x10)>>4;
//               QString fr = QString::number(FR);
//               switch (FR) {
//               case 0x00:
//                   result+="FR="+fr+" >> Field Repeat: New field(picture) "+" \n";
//                   break;
//               case 0x01:
//                   result+="FR="+fr+" >> Field Repeat: Repeated Field "+" \n";
//                   break;
//               default:
//                   break;
//               }
//               long MF = PB5&0x03;
//               QString mf = QString::number(MF);
//               switch (MF) {
//               case 0x00:
//                   result+="MF="+mf+" >> Unknown (no data)"+" \n";
//                   break;
//               case 0x01:
//                   result+="MF="+mf+" >> I Picture"+" \n";
//                   break;
//               case 0x02:
//                   result+="MF="+mf+" >> B Picture"+" \n";
//                   break;
//               case 0x03:
//                   result+="MF="+mf+" >> P Picture"+" \n";
//                   break;
//               default:
//                   break;
//               }
//           }
//           break;}
//       case 0x06:{
//           HB0=0x86;
//           result+="InfoFrame Type: NTSC VBI InfoFrame \n";
//           long IFVersion = HB1;
//           long IFLenght = HB2&0x1F;
//           if (IFVersion == 0x01){
//               QString IFVersio = QString::number(IFVersion);
//               QString IFLengh = QString::number(IFLenght);
//               result+="Version: "+IFVersio+" \n";
//               result+="Length: "+IFLengh+" \n";
//               int i,k;
//               int n=IFLenght;
//               for(i=1;i++;i<=n){
//                   k=10+i;
//                   QString K = QString::number(k);
//                   QString I = QString::number(i);
//                   long b=byte[k];
//                   QString B = QString::number(b);
//                   result+="PES"+I+"= "+B+" \n";

//               }
//           }
//           break;}
//       case 0x07:{
//           HB0=0x87;
//           result+="InfoFrame Type: 7 \n";
//           long IFVersion = HB1;
//           long IFLenght = HB2&0x1F;
//           QString IFVersio = QString::number(IFVersion);
//           QString IFLengh = QString::number(IFLenght);
//           result+="Version: "+IFVersio+" \n";
//           result+="Length: "+IFLengh+" \n";
//           break;}

//       default:{
//           result+="invalid InfoFrame \n";
//           break;}
//       }
//   }


//   mResult=result;

}
