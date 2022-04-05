//
// Created by Jinseok Heo on 2022/03/20.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include "worker.h"
#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <vector>
#include <cerrno>
#include <thread>

#define C_MAX 10

class Socket {
private:
	int _fd{};
	struct sockaddr_in _server{};
	std::vector<Worker> _worker_pool;
	std::vector<std::thread> _thread_pool;

public:
	Socket();
	void bind_and_listen(int port);
	void wait_for_conn();

	class BuildingFailedException: public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override ;
	};

	class BindingFailedException: public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override ;
	};
};


#endif //SERVER_SOCKET_H
