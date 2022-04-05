//
// Created by Jinseok Heo on 2022/03/20.
//

#include "worker.h"

Worker::Worker(int _fd_in, struct sockaddr_in _client_in, std::vector<Worker> &pool) {
	_fd = _fd_in;
	_client = _client_in;
	_id = (int)_pool.size();
}

void Worker::work() {
	_receive();
}

void Worker::_receive() {
	long read_size;

	while (true) {
		read_size = recv(_fd, _packet, PACKET_SIZE, 0);
		if (read_size < 0) {
			std::cout << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
		if (strcmp(_packet, "quit") == 0) {
			_disconnect();
			return ;
		}
		_broadcast_to_all(_packet);
		memset(_packet, 0, PACKET_SIZE);
	}
}

void Worker::_send(char *msg) const {
	size_t size = strlen(msg);

	if (send(_fd, msg, size, 0) != size) {
		std::cout << "error while sending message\n";
		exit(EXIT_FAILURE);
	}
}

void Worker::_broadcast_to_all(char *msg) {
	for (Worker &worker : _pool) {
		worker._send(msg);
	}
}

void Worker::_disconnect() {
	std::cout << "disconnect with client\n";
	close(_fd);
	_pool.erase(_pool.begin() + _id);
	_thread.join();
}

int Worker::get_id() {
	return _id;
}
