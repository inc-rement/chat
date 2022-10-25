#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <map>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <typeinfo>
#define MAXLINE 1024
#define PORT 3111 
typedef std::map<int,char*> nmap;
//enimeration for ip scaner
enum PeerType{
        _Server,
        _Client
};
char s[80];
struct arg{
        std::thread tid;
        int x;
        char y[256];
        enum PeerType isServer;
};


typedef struct arg args;
std::queue<args*> qq;
struct sockaddr_in addr;

using Func = void (*)(class Peer *self);



class Peer{
        public:
	int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE];
        fd_set read_fd;
        Func crt_sock, cls_sock, sel_conn;
        
};


class Server:public Peer{
	Func bnd_sock, lsn_sock, acpt_conn, cnt_to_sock;
        int  sd, sd2, new_socket, client_socket[30], max_clients=30, activity, i, max_sd;
        int valread;
        nmap nicknames;
        

};

class Client:public Peer{
	/*
        public:
	int sock;
	struct sockaddr_in addres;
	char buffer[MAXLINE];
	fd_set read_fd;
	Func crt_sock, cls_sock, sel_conn;
	*/

};
class Peers{

public:        
        Server *server;
        Client *client;
void connect();
template<class T> void run(T*s);

};
Peers *peers=new Peers();
enum PeerType isserver=_Server;
