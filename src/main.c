#include <stdio.h>
#include <unistd.h>
#include "http_server.h" // header file for server setup and client handling functions
#include "response.h"    //  header file for response generation functions

#define PORT 8080 // port number for server to listen on

int main()
{
    // initialize a socket for the server and bint it to the specified port
    int server_socket = setup_server(PORT); // file descriptor representing the server's socket
    printf("Server is listening on port %d...\n", PORT);

    // infinite loop to keep server running and accepting multiple clients
    while (1)
    {
        // accept a new client connection
        int client_socket = accept_client(server_socket); // file descriptor for the connected client
        if (client_socket < 0)
        {
            continue; // if accept fails, skip to next iteration
        }

        // send response to connected client
        send_response(client_socket, "200 OK", "text/plain", "Hello World!");

        // close client socket after handling request
        close(client_socket); // releases resources associated with client socket
    }

    // close server socket (this line never reached in infinite loop)
    close(server_socket);
    return 0;
}