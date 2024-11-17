#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

int setup_server(int port);
int accept_client(int server_socket);

#endif