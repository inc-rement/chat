#include <arpa/inet.h>  
#include "server.h" 

int main(void){

	ServerPolicy *pol= new TCPServerPolicy();
	Server *ser_=new Server(pol);
	ser_->createSocket();
	//ser_->connectInit();
	//ser_->connectInit("123");
	//ser_->selinit();
        //select(300, &ser_->read_fd, NULL, NULL, NULL);
	//ser_->sel();///<\param void  \return void
	//ser_->conn();///<\param void  \return void
	//ser_->sendmes();///<\param void  \return void

return 0;
}
