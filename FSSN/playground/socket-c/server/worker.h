//
// Created by Jinseok Heo on 2022/03/20.
//

#ifndef SERVER_WORKER_H
#define SERVER_WORKER_H
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cerrno>
#include <vector>

#define PACKET_SIZE 1024

class Worker : std::thread{
private:
	int _id;
	std::vector<Worker> _pool;
	int _fd;
	struct sockaddr_in _client;
	char _packet[PACKET_SIZE];

	void _receive();
	void _send(char *msg) const;
	void _broadcast_to_all(char *msg);
	void _disconnect();

public:
	Worker(int _fd_in, struct sockaddr_in _client_in, std::vector<Worker> &pool);
	void work();
	int get_id();
};


#endif //SERVER_WORKER_H
