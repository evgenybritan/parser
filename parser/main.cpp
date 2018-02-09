#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

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
const char *arr_type[]= {"Null",
                         "Audio Clock Regeneration",
                         "Audio Sample",
                         "General Control",
                         "ACP Packet",
                         "ISRC1 Packet",
                         "ISRC2 Packet",
                         "One Bit Audio Sample Packet",
                         "DST Audio Packet",
                         "High Bitrate (HBR) Audio Stream Packet (IEC 61937)",
                         "Gamut Metadata Packet",
                         "InfoFrame Packet"
                        };

const char *iftype[]= {  "Vendor Specific InfoFrame",
                         "AVI InfoFrame",
                         "Source Product Descriptor InfoFrame",
                         "Audio InfoFrame",
                         "MPEG Source InfoFrame"
                        };
int main() {
    
    int HB0=0;
    int HB1=0;
    int HB2=0;
    int SB0=0;
    int SB1=0;
    int SB2=0;
    int SB3=0;
    int SB4=0;
    int SB5=0;
    int SB6=0;
    int PB0=0;
    int PB1=0;
    int PB2=0;
    int PB3=0;
    int PB4=0;
    int PB5=0;
    int PB6=0;
    int PB7=0;
    int PB8=0;
    int PB9=0;
    int PB10=0;
    int PB11=0;
    int PB12=0;
    int PB13=0;
    int PB14=0;
    int PB15=0;
    int PB16=0;
    int PB17=0;
    int PB18=0;
    int PB19=0;
    int PB20=0;
    int PB21=0;
    int PB22=0;
    int PB23=0;
    int PB24=0;
    int PB25=0;
    int PB26=0;
    int PB27=0;



    ifstream in("E:\\test_files\\parser1.txt",ios::binary|ios::in);
      in.read((char*)&HB0,sizeof HB0);
      in.read((char*)&HB1,sizeof HB1);
      in.read((char*)&HB2,sizeof HB2);
      in.read((char*)&SB0,sizeof SB0);
      in.read((char*)&SB1,sizeof SB1);
      in.read((char*)&SB2,sizeof SB2);
      in.read((char*)&SB3,sizeof SB3);
      in.read((char*)&SB4,sizeof SB4);
      in.read((char*)&SB5,sizeof SB5);
      in.read((char*)&SB6,sizeof SB6);
      in.read((char*)&PB0,sizeof PB0);
      in.read((char*)&PB1,sizeof PB1);
      in.read((char*)&PB2,sizeof PB2);
      in.read((char*)&PB3,sizeof PB3);
      in.read((char*)&PB4,sizeof PB4);
      in.read((char*)&PB5,sizeof PB5);
      in.read((char*)&PB6,sizeof PB6);
      in.read((char*)&PB7,sizeof PB7);
      in.read((char*)&PB8,sizeof PB8);
      in.read((char*)&PB9,sizeof PB9);
      in.read((char*)&PB10,sizeof PB10);
      in.read((char*)&PB11,sizeof PB11);
      in.read((char*)&PB12,sizeof PB12);
      in.read((char*)&PB13,sizeof PB13);
      in.read((char*)&PB14,sizeof PB14);
      in.read((char*)&PB15,sizeof PB15);
      in.read((char*)&PB16,sizeof PB16);
      in.read((char*)&PB17,sizeof PB17);
      in.read((char*)&PB18,sizeof PB18);
      in.read((char*)&PB19,sizeof PB19);
      in.read((char*)&PB20,sizeof PB20);
      in.read((char*)&PB21,sizeof PB21);
      in.read((char*)&PB22,sizeof PB22);
      in.read((char*)&PB23,sizeof PB23);
      in.read((char*)&PB24,sizeof PB24);
      in.read((char*)&PB25,sizeof PB25);
      in.read((char*)&PB26,sizeof PB26);
      in.read((char*)&PB27,sizeof PB27);
    in.close();
    int k = HB0-129;
    Packet_type pflag;



    switch (HB0) {
    case 0x00:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x01:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) && (HB2 == 0) && (SB0 == 0)&& ((SB1>>4) == 0)){
            long CTS = (SB1<<16)|(SB2<<8)|SB3;
            long N = (SB4<< 16)|(SB5<<8)|SB6;
            cout<<"CTS: "<< CTS <<endl;
            cout<<"N: "<< N <<endl;
        }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x02:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1>>5) == 0){
              long layout = HB1&0x10;
              long spX = HB1&0xF;
              long sfX = HB2&0xF;
              long B = HB2&(0xF0);
              long L = (SB0<<4)|(SB1<<12)|(SB2<<20);
              long R = (SB3<<4)|(SB4<<12)|(SB5<<20);
              long Vl =(SB6&0x01);
              long Vr =(SB6&0x10);
              long Ul =(SB6&0x02);
              long Ur =(SB6&0x20);
              long Cl =(SB6&0x04);
              long Cr =(SB6&0x40);
              long Pl =(SB6&0x08);
              long Pr =(SB6&0x80);

              cout<<"layout: "<<layout<<endl;
              cout<<"sample_present.spX: "<<spX<<endl;
              cout<<"sample_flat.spX: "<<sfX<<endl;
              cout<<"B: "<<B<<endl;
              cout<<"L: "<<L<<endl;
              cout<<"R: "<<R<<endl;
              cout<<"Vl: "<<Vl<<endl;
              cout<<"Vr: "<<Vr<<endl;
              cout<<"Ul: "<<Ul<<endl;
              cout<<"Ur: "<<Ur<<endl;
              cout<<"Cl: "<<Cl<<endl;
              cout<<"Cr: "<<Cr<<endl;
              cout<<"Pl: "<<Pl<<endl;
              cout<<"Pr: "<<Pr<<endl;
         }
        else{
            cout<<"invalid"<<endl;
        }
        break;
    case 0x03:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
         if ((HB1 == 0) && (HB2 == 0) && ((SB0&0xEE)==0) && ((SB2>>1)==0) && (SB3 == 0) && (SB4 == 0) && (SB5 == 0) && (SB6 == 0)){
             long setAVMUTE = (SB0&0x01);
             long clearAVMUTE = (SB0&0x10);
             long PP = (SB1)&(0xF0);
             long CD = (SB1&0xF);
             long defaultPhase = (SB2&0x01);
             cout<<"Set_AVMUTE: "<<setAVMUTE<<endl;
             cout<<"Clear_AVMUTE: "<<clearAVMUTE<<endl;
             cout<<"PP: "<<PP<<endl;
             cout<<"CD: "<<CD<<endl;
             cout<<"Default_Phase: "<<defaultPhase<<endl;
         }
        break;
    case 0x04:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (HB2 == 0){
            switch (HB1) {
            case 0x00:
                if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                cout<<"ACP_Type: Generic Audio"<<endl;}
                break;
            case 0x01:
                if ((PB0 | PB1 | PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                cout<<"ACP_Type: IEC 60958-Identified Audio"<<endl;}
                break;
            case 0x02:
                cout<<"ACP_Type: DVD-Audio"<<endl;
            if ((PB2 | PB3 | PB4 | PB5 |PB6 | PB7 | PB8 |PB9 | PB10 | PB11 |PB12 | PB13 | PB14 |PB15 | PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                    long DATDG = (PB0&0xFF);
                    long CopyP = (PB1&0xC0);
                    long CopyN = (PB1&0x38);
                    long Quality = (PB1&0x06);
                    long Trans = (PB1&0x01);
                    cout<<"DVD-Audio_Type_Dependent_Generation: "<<DATDG<<endl;
                    cout<<"Copy_Permission: "<<CopyP<<endl;
                    cout<<"Copy_Number: "<<CopyN<<endl;
                    cout<<"Quality: "<<Quality<<endl;
                    cout<<"Transaction: "<<Trans<<endl;
                }
                break;
           case 0x03:
                cout<<"ACP_Type: Super Audio CD"<<endl;
                if ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0){
                long CCI = PB0 | PB1 | PB2 | PB3 | PB4 | PB5 | PB6 | PB7 | PB8 | PB9 | PB10 | PB11 | PB12 | PB13 | PB14 | PB15 ;
                cout<<"CCI_1: "<<CCI<<endl;
                }
            default:

                break;
            }

        }
        break;
    case 0x05:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if (((HB1&0x38) == 0) && (HB2==0)) {
            long Cont = (HB1&0x80);
            long Status = (HB1&0x07);
            long Valid =(HB1&0x40);
            cout<<"ISRC_Cont: "<<Cont<<endl;
            cout<<"ISRC_Status: "<<Status<<endl;
            cout<<"ISRC_Valid: "<<Valid<<endl;
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
                cout<<"UPC_EAN_ISRC_0"<<UEI0<<endl;
                cout<<"UPC_EAN_ISRC_1"<<UEI1<<endl;
                cout<<"UPC_EAN_ISRC_2"<<UEI2<<endl;
                cout<<"UPC_EAN_ISRC_3"<<UEI3<<endl;
                cout<<"UPC_EAN_ISRC_4"<<UEI4<<endl;
                cout<<"UPC_EAN_ISRC_5"<<UEI5<<endl;
                cout<<"UPC_EAN_ISRC_6"<<UEI6<<endl;
                cout<<"UPC_EAN_ISRC_7"<<UEI7<<endl;
                cout<<"UPC_EAN_ISRC_8"<<UEI8<<endl;
                cout<<"UPC_EAN_ISRC_9"<<UEI9<<endl;
                cout<<"UPC_EAN_ISRC_10"<<UEI10<<endl;
                cout<<"UPC_EAN_ISRC_11"<<UEI11<<endl;
                cout<<"UPC_EAN_ISRC_12"<<UEI12<<endl;
                cout<<"UPC_EAN_ISRC_13"<<UEI13<<endl;
                cout<<"UPC_EAN_ISRC_14"<<UEI14<<endl;
                cout<<"UPC_EAN_ISRC_15"<<UEI15<<endl;
            }
        }
        break;
    case 0x06:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        if ((HB1 == 0) && (HB2 == 0) && ((PB16 | PB17 |PB18 | PB19 | PB20 |PB21 | PB22 | PB23 |PB24 | PB25 | PB26 |PB27)==0)){
            long UEI16 = PB16;
            long UEI17 = PB17;
            long UEI18 = PB18;
            long UEI19 = PB19;
            long UEI20 = PB20;
            long UEI21 = PB21;
            long UEI22 = PB22;
            long UEI23 = PB23;
            long UEI24 = PB24;
            long UEI25 = PB25;
            long UEI26 = PB26;
            long UEI27 = PB27;
            long UEI28 = PB28;
            long UEI29 = PB29;
            long UEI30 = PB30;
            long UEI31 = PB31;
            cout<<"UPC_EAN_ISRC_16"<<UEI16<<endl;
            cout<<"UPC_EAN_ISRC_17"<<UEI17<<endl;
            cout<<"UPC_EAN_ISRC_18"<<UEI18<<endl;
            cout<<"UPC_EAN_ISRC_19"<<UEI19<<endl;
            cout<<"UPC_EAN_ISRC_20"<<UEI20<<endl;
            cout<<"UPC_EAN_ISRC_21"<<UEI21<<endl;
            cout<<"UPC_EAN_ISRC_22"<<UEI22<<endl;
            cout<<"UPC_EAN_ISRC_23"<<UEI23<<endl;
            cout<<"UPC_EAN_ISRC_24"<<UEI24<<endl;
            cout<<"UPC_EAN_ISRC_25"<<UEI25<<endl;
            cout<<"UPC_EAN_ISRC_26"<<UEI26<<endl;
            cout<<"UPC_EAN_ISRC_27"<<UEI27<<endl;
            cout<<"UPC_EAN_ISRC_28"<<UEI28<<endl;
            cout<<"UPC_EAN_ISRC_29"<<UEI29<<endl;
            cout<<"UPC_EAN_ISRC_30"<<UEI30<<endl;
            cout<<"UPC_EAN_ISRC_31"<<UEI31<<endl;
        }
        break;
    case 0x07:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
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
            cout<<"layout: "<<layout1<<endl;
            cout<<"samples_present.sp0: "<<sp0<<endl;
            cout<<"samples_present.sp1: "<<sp1<<endl;
            cout<<"samples_present.sp2: "<<sp2<<endl;
            cout<<"samples_invalid.sp0: "<<si0<<endl;
            cout<<"samples_invalid.sp1: "<<si1<<endl;
            cout<<"samples_invalid.sp2: "<<si2<<endl;
            cout<<"samples_invalid.sp3: "<<si3<<endl;
        }
        break;
    case 0x08:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x09:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x0A:
        pflag=Packet_type(HB0);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x80 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x81 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x82 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x83 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x84 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    case 0x85 :
        pflag=Packet_type(11);
        cout<<"packet type: "<<arr_type[pflag]<<endl;
        break;
    default:
        cerr<<"invalid byte"<<endl;

        break;
    }
    switch (HB0) {
    case 0x81:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x82:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x83:
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x84:                      
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    case 0x85:           
            cout<<"InfoFrame type: "<<iftype[k]<<endl;
            break;
    default:
        break;
    }

}
