// includes various types for system calls
#include <sys/types.h>
#include <sys/socket.h>
// domain address stuff
#include <netinet/in.h>
#include <stdio.h>

#include "sock_server/server.h"

void error(char *errMsg);

int start_server(int portnumber) {

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) return -1;

  return 0;

}
