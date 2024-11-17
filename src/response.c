#include "response.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

// send an HTTP response to the client
void send_response(int client_socket, const char *status, const char *content_type, const char *body)
{
    char response[1024];               // buffer to hold response message
    int content_length = strlen(body); // calculate length of response body

    // create HTTP response string
    snprintf(response, sizeof(response),
             "HTTP/1.1 %s\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %d\r\n"
             "\r\n"
             "%s",
             status, content_type, content_length, body);

    // sent HTTP response to client over socket
    // send() takes socket descriptor, message buffer, length of message, and flags (0 for none)
    send(client_socket, response, strlen(response), 0);
}