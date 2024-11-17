# Simple HTTP Server

This project is a basic HTTP server implemented in C. It listens on port 8080 and responds to incoming client requests with a simple, "Hello, World!" message. The server demonstrates core concepts of systems programming, including socket communication, basic HTTP response handling, and resource management.

## Current Features

- **Single-threaded HTTP Server**: The server currently handles one client at a time.
- **Basic HTTP Response**: Responds to each incoming request with a "Hello, World!" message.
- **Port configuration**: Listens on port 8080.

## How to Run

1. Compile the program using `make`:

   ```bash
   make
   ```

2. Run the server:

   ```bash
   ./build/simple-http-server
   ```

3. Open a browser or use `curl` to connect to the server:
   ```bash
   curl http://localhost:8080
   ```

## Future Improvements

- **Multithreading**: Add threading support to handle multiple clients concurrently.
- **Serve Static Files**: Implement the ability to serve HTML, CSS, and image files from a directory.
- **HTTP Request Parsing**: Improve the server's ability to parse incoming HTTP requests and handle different types of HTTP methods (e.g., GET, POST).
- **Error Handling**: Provide proper error messages (e.g., 404 Not Found, 500 Internal Server Error).
- **Logging**: Add logging to track client requests, response statuses and errors.
- **Security (HTTPS)**: Integrate OpenSSL and SSL/TLS support for secure communication.

## Project Structure

- **src/main.c**: Entry points of the application.
- **src/http_server.c**: Handles server socket setup and client connections.
- **src/response.c**: Generates and sends HTTP responses.
- **include/http_server.h**: Header file for `http_server.c`.
- **include/response.h**: Header file for `response.c`.

## Building

- Run `make` to compile the project.
- Run `make clean` to remove compiled files.
