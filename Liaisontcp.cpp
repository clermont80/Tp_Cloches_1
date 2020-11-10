//---------------------------------------------------------------------------

#pragma hdrstop

#include "Liaisontcp.h"
#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
#pragma package(smart_init)

int Liaisontcp::createsocket()
{
	WSADATA wsaData;

	WSAStartup(MAKEWORD(2,2), &wsaData);

	int sock = socket(AF_INET,SOCK_STREAM,0);

	if(sock==INVALID_SOCKET)
	{

	   return -1;
	}
	else
	{
	   socket_to_send = sock;
       return sock;
	}
}

bool Liaisontcp::sendsocket(char* buffer)
{


	int send_socket = send(socket_to_send,buffer,14,0);


	if(send_socket == SOCKET_ERROR)
	{
		return false;
	}
	else  //la valeur de retour est la taille en octet
	{
		return true;
	}



}
	 /*
 bool Liaisontcp::receivsocket(char* buffer,int taille,int flag)
 {

	int recvLen = 0;

	 do
	 {
		 int recev_socket = recv(socket_to_send,buffer + recvLen,taille,0);

		 if(recev_socket == SOCKET_ERROR)
		 {
			return false;
		 }

		 recvLen += recev_socket;
	 }
	 while(recvLen < taille);

	 buffer[recvLen] = 0x00;

	 return true;
 }

 */

bool Liaisontcp::connect_socket()
 {

	struct hostent *hostinfo = NULL;
	SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
	const char *hostname = "192.168.64.100";

	hostinfo = gethostbyname(hostname); /* on r�cup�re les informations de l'h�te auquel on veut se connecter */

	if (hostinfo == NULL) /* l'h�te n'existe pas */
	{
		fprintf (stderr, "Unknown host %s.\n", hostname);
		exit(EXIT_FAILURE);

	}

	sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
	sin.sin_port = htons(502); /* on utilise htons pour le port */
	sin.sin_family = AF_INET;

	if(connect(socket_to_send,(SOCKADDR*) &sin,sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		perror("connect()");
		return false;
	}

    return true;


 }


 Liaisontcp::Liaisontcp(char* ip1,int port1)
 {
   int taille = strlen(ip1);
   ip = new char[taille];
   port = port1;
 }

 void Liaisontcp::closeSocket()
 {
	closesocket(socket_to_send);
 }

