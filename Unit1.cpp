//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	bool isconnect = liaison->connect_socket();

	if(isconnect==true)
	{
		Label2->Caption = "Connect�";

	}
	else
	{
		Label2->Caption = "erreur";
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	liaison = new Liaisontcp("192.168.64.100",502);
	int recvsocket = liaison->createsocket();

	if(recvsocket != -1)
	{
	   Label2->Caption = "socket cr�e";
	}
	else
	{
	   Label2->Caption = "erreur";
	}
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	   char trame[14];

	   trame[0] = 0x00;
	   trame[1] = 0x00;
	   trame[2] = 0x00;
	   trame[3] = 0x00;
	   trame[4] = 0x00;
	   trame[5] = 0x06;
	   trame[6] = 0x00;
	   trame[7] = 0x06;
	   trame[8] = 0x00;
	   trame[9] = 0x02;
	   trame[10] = 0x00;
	   trame[11] = 0x12;
	   trame[12] = 0x01;
	   trame[13] = 0x01;

	   liaison->sendsocket(trame);


}

