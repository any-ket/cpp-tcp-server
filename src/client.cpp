#include <arpa/inet.h>
#include <cstdio>
#include <exception>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_pthread/_pthread_t.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <thread>
#include <vector>
#include <unistd.h> // read(), write(), close()

#define SA struct sockaddr

#include "client.h"

// Function designed for chat between client and server.
void * chat(void* connfd)
{
  char buff[MAX];
  int n;
  // infinite loop for chat
  for (;;) {
    bzero(buff, MAX);
    // read the message from client and copy it in buffer
    read((*(int *)connfd), buff, sizeof(buff));
    // print buffer which contains the client contents
    printf("From client: %s", buff);

    // if msg contains "Exit" then server exit and chat ended.
    if (strncmp("exit", buff, 4) == 0) {
      printf("Server Exit...\n");
      close(*(int *)connfd);
      break;
    }
  }
  pthread_exit(NULL);
}

tcp_socket::tcp_socket(){

  // socket create and verification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully created..\n");

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  // Binding newly created socket to given IP and verification
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket bind failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully binded..\n");


  // Now server is ready to listen and verification
  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  }
  else
    printf("Server listening.. on %d\n", PORT);

   // Accept the data packet from client and verification
  //TODO: add multithreading to handle connection with multiple clients
  int i = MAX;
  std::vector<pthread_t> threads(i);
  std::vector<struct sockaddr_in> clients(i);
  std::vector<int> connfd(i);
  while(i--){
    socklen_t len = sizeof(clients[i]);
     connfd[i] = accept(sockfd, (SA*)&clients[i], &len);
     if (connfd[i] < 0) {
       printf("server accept failed...\n");
       exit(0);
     }
     else
       printf("server accept the client...\n");

    // Function for chatting between client and server
     //create a thread to chat
    pthread_create(&threads[i], NULL, chat, (void *) &connfd[i]);
  }
  pthread_exit(NULL);
}
