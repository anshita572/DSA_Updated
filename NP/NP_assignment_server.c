#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{

char message[10][150],buffer[150];
    int i=0;
 int clientSocket;
    FILE *file_in;
    file_in=fopen("config.txt", "r");

    /*stores and prints the data from the string*/
    while(fgets(buffer,150,file_in)){
        strcpy(message[i],buffer);
       // printf("%s",message[i]);
        i++;
    }
 
     
        char *delim = ":";
        unsigned count = 0;
        char Port[100],Dir[100];
        
        char *token =strtok(message,delim);
        count++;


        strcpy(Port,token);
        token = strtok(NULL,delim);
        strcpy(Port,token);
        token = strtok(NULL,delim);
        token = strtok(NULL,delim);
        strcpy(Dir,token);
        
int PORT=atoi(Port);

fclose(file_in);




int server_fd, new_socket, valread;
char httpHeader[8000] = "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 1000\n\n";

FILE *htmlData = fopen("index.html","r");
    char line[100];
    char responseData[8000];
    while (fgets(line, 100, htmlData) != 0) {
        strcat(responseData, line);
    }
    // char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    strcat(httpHeader, responseData);
    
struct sockaddr_in address;
if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
{
perror("In socket");
exit(EXIT_FAILURE);
}
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(PORT);
if (bind(server_fd, (struct sockaddr *)&address,
sizeof(address) ) <0)
{
perror("In bind");
exit(EXIT_FAILURE);
}
if (listen(server_fd, 10) < 0)
{
perror("In listen");
exit(EXIT_FAILURE);
}
int addrlen = sizeof(address);

while(1) // infinite while loop for accepting request of different clients
{
if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
(socklen_t*)&addrlen))<0)
{
perror("In accept");
exit(EXIT_FAILURE);
}
char buffer[30000] = {0};
valread = read( new_socket , buffer, 30000);
printf("%s\n",buffer );


//setHttpHeader(httpHeader,Dir);  // Custom function to set header
write(new_socket ,httpHeader,sizeof(httpHeader)); 
printf("-------Response sent to client---------\n");
close(new_socket);
}
return 0;
}