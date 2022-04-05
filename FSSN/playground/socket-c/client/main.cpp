#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>

#define PACKET_SIZE 1024

int main()
{
	struct sockaddr_in server{};
	char server_ip[20] = "127.0.0.1";
	int port = 8081;
	int s;
	long read_size;
	int s_bis;
	char packet[PACKET_SIZE];
	char received[PACKET_SIZE];

//	std::cout << "Input port number > ";
//	std::cin >> port;
//	std::cout << "Input server IP address > ";
//	std::cin >> server_ip;

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s < 0) {
		std::cout << "error while building socket\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "socket: " << s << std::endl;

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(server_ip);
	server.sin_port = port;

	s_bis = connect(s, (struct sockaddr *) &server, sizeof(server));
	if (s_bis < 0) {
		std::cout << "connection failed\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "connection established\n";
	std::cout << "server socket: " << s_bis << std::endl;

	while (true) {
		memset(packet, 0, PACKET_SIZE);
		memset(received, 0, PACKET_SIZE);
		std::cout << "Message > ";
		std::cin.getline(packet, PACKET_SIZE, '\n');

		if (send(s, packet, strlen(packet), 0) != strlen(packet)) {
			std::cout << "error while sending message\n";
			exit(EXIT_FAILURE);
		}

		read_size = recv(s, received, PACKET_SIZE, 0);
		if (read_size < 0) {
			std::cout << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
		std::cout << "received > " << received << std::endl;

		if (strcmp(packet, "quit") == 0) {
			close(s_bis);
			break ;
		}

		std::cin.clear();
	}
	close(s);

	return 0;
}
