#include "http_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// setup server socket
int setup_server(int port)
{
    int server_socket;
    struct sockaddr_in server_addr; // sockaddr_in is a struct that contains IPv4 address

    // create a socket for the server
    // AF_INET: Address family for IPv4
    // SOCK_STREAM: type for TCP (Transmission Control Protocol)
    // Protocol: 0 lets os select appropriate protocol for SOCK_STREAM (TCP)
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Failed to create socket"); // debugging
        exit(EXIT_FAILURE);                // exit program if socket creation fails
    }

    // fill in server address information
    server_addr.sin_family = AF_INET;         // address family for IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // bind to any available network interface
    server_addr.sin_port = htons(port);       // conver port number from host byte order to network byte order (little endian (if host is little endian) -> big endian)

    // bind socket to specified IP address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed"); // debugging
        close(server_socket);  // close socket to release resources
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    // second argument specifies backlog (i.e., number of pending connections that can be queued)
    if (listen(server_socket, 5) < 0)
    {
        perror("Listen failed"); // debugging for listen failure
        close(server_socket);    // close socket to release resources
        exit(EXIT_FAILURE);
    }

    // return server socket file descriptor
    return server_socket;
}

// accepts a client connection
int accept_client(int server_socket)
{
    struct sockaddr_in client_addr;                  // structure to store client addresses
    socklen_t client_addr_len = sizeof(client_addr); // length of client address

    // accept an incoming client connection
    // accept() function returns a new socket file descriptor for the accepted client
    int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket < 0)
    {
        perror("Accept failed"); // debuggined if error for accepting client
        return -1;               // indicates failure
    }

    // return client socket file descriptor
    return client_socket;
}