module;
#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
export module abspeer;
#define MAXLINE 1024

export class AbstractPeer{
        public:
        AbstractPeer()=default;
        virtual void init()=0;
        virtual void init1()=0;
        virtual void selinit()=0;
        virtual void sel()=0;
        virtual void conn()=0;
        virtual void sendmes()=0;
        AbstractPeer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        int sock;
        struct sockaddr_in addres;
        char buffer[MAXLINE]={0};
        fd_set read_fd={0};

        

};
