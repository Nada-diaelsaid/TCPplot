#include<stdio.h>
// #include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define PORT 1234

using namespace std;
int main()
{

ifstream file ( "data.csv" );
string time, floatno;
// while ( file.good() )
// {
//      getline ( file, time, ',' );
//      getline(file, floatno, '\n'); 
//      cout << time << " "<< floatno<<endl; // display value removing the first and the
// //     cout << string( value, 1, value.length() ); // display value removing the first and the last character from it
// }
////////////////////////////////////////////////////////////////////////////////////////
 sockaddr_in address;
    int sock = 0, valread;
    int port;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from the other side";
    char buffer[1024] = {0};
    cout << "Welcome, please enter port number:\n";
    cin >> port;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  cout << "waiting for connection..."<<endl;
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
        while ( file.good() )
    {
        getline ( file, time, ',' );
        char *ctime = new char[time.length() + 1];
        strcpy(ctime, time.c_str());

        getline(file, floatno);
        char *cfloatno = new char[floatno.length() + 1];
        strcpy(cfloatno, floatno.c_str()); 

        // cout << time << " "<< floatno<<endl;

        send(sock , ctime , strlen(ctime) , 0 );
        send(sock , "," , strlen(",") , 0 );

        // send(sock, " ", strlen(" "), 0);
        // send(sock , "\n" , strlen("\n") , 0 );
        send(sock , cfloatno , strlen(cfloatno) , 0 );
        send(sock , "," , strlen(",") , 0 );
    //     cout << string( value, 1, value.length() ); // display value removing the first and the last character from it
    }
    // send(sock , hello , strlen(hello) , 0 );
    printf("Data sent\n");
    // valread = read( sock , buffer, 1024);
    // printf("%s\n",buffer );

return 0;
}
