#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <functional>
#include <map>
#include <string>

#include "socketbuffer.h"

#define MAXDATASIZE 1024

namespace beej {

class server {
public:
  explicit server(int port);

  __attribute__((noreturn)) void run();
  void on_line(std::function<std::pair<bool,std::string>(const std::string&)> callback);

private:
  int port;
  int listener;
  int newfd;
  struct sockaddr_storage remoteaddr;
  socklen_t addrlen;
  char buf[256];
  char remoteIP[INET6_ADDRSTRLEN];
  int fd_count = 0;
  int fd_size = 5;
  struct pollfd* pfds;
  std::map<int, socketbuffer> buffers;
  std::function<std::pair<bool, std::string>(const std::string& line)> callback = [](const std::string&) -> std::pair<bool, std::string> {
    return {false, ""};
  };
};

class client {
public:
  client(std::string hostname, int port);
  ~client();
  void connect();
  void disconnect();
  void send(const std::string& data);
  void read(std::function<void(const std::string&)> callback);

private:
  std::string hostname;
  int port;
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];
  char buf[256];
  socketbuffer buffer;
};

}  // namespace beej
