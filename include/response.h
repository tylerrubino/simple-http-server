#ifndef RESPONSE_H
#define RESPONSE_H

void send_response(int client_socket, const char *status, const char *content_type, const char *body);

#endif