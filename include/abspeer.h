#ifndef absp
#define absp
#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
//#include <stdio.h>  //printf()
//#include <unistd.h>  //close(), fread()
#define MAXLINE 1024
#include <vector>
/**
 *\file abspeer.h
 *\author Денис Вергун
 *\brief Файл содержит описание наследуемого абстрактного класса 
 *\version
 *\date 27-06-2023
 *
 *
 */
#ifdef DEBUG
#  define Trace(x)  {fprintf x ; fflush(stderr); fflush(stdout);}
#else
#  define Trace(x);
#endif


///\brief Абстрактный узел связи. 
/**
Вводим определение узла связи Peer.
Создает интерфейс для наследующих классов клиета и сервера.
Содержит виртуальные функции создания сокета, соединения, основного цикла.
*/

class AbsPar{
	public:
        AbsPar(){};
	int sock;
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
        auto _valread() -> int& {return valread;}; 
	private:
	int valread;
        int new_socket, client_socket[30], max_clients=30, activity, i, max_sd, sd;
        std::vector<std::pair<int, char*>> nicknames;       
};

class Chat{
        public:
        Chat()=default;///<Конструктор без параметров  \param void
        virtual void createSocket()=0;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        //virtual void connectInit(const char* addr)=0;///<Запись в переменную addres и подготовка соединения \param void  \return void
        virtual void connectInit()=0;///\param void  \return void
        virtual void selinit()=0;///<\param void  \return void
        virtual void sel()=0;///<\param void  \return void
        virtual void conn()=0;///<\param void  \return void
        virtual void sendmes()=0;///<\param void  \return void
        /**
         \brief Конструктор с параметрами
         
         \param _sock
         \param _addres
         \return конструкторы ничего не возвращают
         */

        //Peer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}

};


#endif
