//---------------------------------------------------------------------------

#ifndef LiaisontcpH
#define LiaisontcpH

class Liaisontcp
{
    private:

			 int socket_to_send;
			 char* ip;
			 int port;

   public:
             Liaisontcp(char* ip1,int port1);
			 int createsocket();
			 bool sendsocket(char* buffer); //en mode connect� ;)
			 bool receivsocket(char* buffer,int taille,int flag); //en mode connect�
			 bool connect_socket();
             void closeSocket();







};
#endif
