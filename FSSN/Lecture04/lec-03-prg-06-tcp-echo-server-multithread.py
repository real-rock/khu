import socketserver
import threading

class ThreadedTCPRequestHandler(socketserver.BaseRequestHandler):

    def handle(self):
        # Show a client connection information
        print('> client connected by IP address {0} with Port number {1}'.format(self.client_address[0], self.client_address[1]))

        while True:
            # [=start=]
            RecvData = self.request.recv(1024)
            cur_thread = threading.current_thread()
            print('> echoed:', RecvData.decode('utf-8'), 'by', cur_thread.name)
            self.request.sendall(RecvData)
            if RecvData.decode('utf-8') == 'quit':
                break
            # [==end==]

class ThreadedTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass

if __name__ == "__main__":
    HOST, PORT = "localhost", 65456
    print('> echo-server is activated')

    server = ThreadedTCPServer((HOST, PORT), ThreadedTCPRequestHandler)
    with server:
        ip, port = server.server_address

        # Start a thread with the server -- that thread will then start one
        # more thread for each request
        server_thread = threading.Thread(target=server.serve_forever)

        # Set to exit the server thread when the main thread terminates, then execute the main thread
        server_thread.daemon = True
        server_thread.start()
        print("> server loop running in thread (main thread):", server_thread.name)
        
        # Server termination by input "quit" when all client connections are disconnected
        baseThreadNumber = threading.active_count()
        while True:
            msg = input('> ')
            if msg == 'quit':
                if baseThreadNumber == threading.active_count():
                    print("> stop procedure started")
                    break
                else:
                    print("> active threads are remained :", threading.active_count() - baseThreadNumber, "threads")

        print('> echo-server is de-activated')
        server.shutdown()
        