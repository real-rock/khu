#include "socket.h"

int main()
{
	Socket sock;
	int port;

	std::cout << "Input port number > ";
	std::cin >> port;

	sock.bind_and_listen(port);
	sock.wait_for_conn();
	return 0;
}
