#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>

#define MAX 80
#define PORT 8080

class tcp_socket {
  private:
    int sockfd;
    struct sockaddr_in servaddr;
  public:
    tcp_socket();
};

#endif