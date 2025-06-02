//Reciever.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main(){
key_t key;
int msgid;

//ftok to generate unique key
key = ftok("progfile",65);

//msg creates message queue
//and return identifier

msgid = msgget(key,0666|IPC_CREAT);

//msgrcv to recieve message
msgrcv(msgid,&message, sizeof(message), 1, 0);
//display the message
printf("Data recieved is: %s \n",message.mesg_text);
//to destroy the message queuemsgctl(msgid, IPC_RMID, NULL);

return 0;

}