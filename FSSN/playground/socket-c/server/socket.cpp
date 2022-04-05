//
// Created by Jinseok Heo on 2022/03/20.
//

#include "socket.h"

Socket::Socket() = default;

void Socket::bind_and_listen(int port) {
	_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_fd == -1) {
		throw BuildingFailedException();
	}

	std::cout << "Socket successfully built!\n";
	_server.sin_family = AF_INET;
	_server.sin_port = port;
	_server.sin_addr.s_addr = INADDR_ANY;

	if (bind(_fd, (struct sockaddr *)&_server, sizeof(_server)) == -1) {
		throw BindingFailedException();
	}
	std::cout << "Socket successfully bind!\n";
	listen(_fd, C_MAX);
}

void Socket::wait_for_conn() {
	int client_fd;
	struct sockaddr_in client{};
	int dim = sizeof(client);

	while ((client_fd = accept(_fd, (struct sockaddr *) &client, reinterpret_cast<socklen_t *>(&dim))) == -1);
	std::cout << "connection established!\n";
	std::cout << "client address" << inet_ntoa(client.sin_addr) << ":" << client.sin_port << std::endl;
	Worker worker(client_fd, client, _worker_pool);
}

const char *Socket::BuildingFailedException::what() const noexcept {
	return "error while building socket, probably this port is used by another socket";
}

const char *Socket::BindingFailedException::what() const noexcept {
	return "error while binding socket to address";
}