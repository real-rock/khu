import socketserver

# {CHAT#1} Create a DB to register all client's socket information
group_queue = []

class MyUDPHandler(socketserver.BaseRequestHandler):
    """
    This class works similar to the TCP handler class, except that
    self.request consists of a pair of data and client socket, and since
    there is no connection the client address must be given explicitly
    when sending data back via sendto().
    """

    def handle(self):
        # [=start=]
        RecvData = self.request[0].strip()
        RecvSocket = self.request[1]
    
        RecvCmd = RecvData.decode('utf-8')
        # {CHAT#2} Command line protocol to client reggistration and deregistration
        if RecvCmd[0] == "#" or RecvCmd == "quit":
            if RecvCmd == "#REG":
                print("> client registered", self.client_address)
                group_queue.append(self.client_address)
            elif RecvCmd == "#DEREG" or RecvCmd == "quit":
                if group_queue.__contains__(self.client_address) == True:
                    print("> client de-registered", self.client_address)
                    group_queue.remove(self.client_address)
        else:
            # {CHAT#3} Prohibit an un-registered client message
            if len(group_queue) == 0:
                print("> no clients to echo")
            elif group_queue.__contains__(self.client_address) == False:
                print('> ignores a message from un-registered client')
            else:
                # {CHAT#4} Forward a client message to whole clients (currently a broadcast)
                print('> received (', RecvData.decode('utf-8'), ') and echoed to ', len(group_queue), 'clients')
                for clientConn in group_queue:
                    RecvSocket.sendto(RecvData, clientConn)
        # [==end==]

if __name__ == "__main__":
    HOST, PORT = '127.0.0.1', 65456
    print('> echo-server is activated')
    # Create the server, binding to localhost on port 65456
    with socketserver.UDPServer((HOST, PORT), MyUDPHandler) as server:
        # Activate the server; this will keep running until you interrupt the program with Ctrl-C
        server.serve_forever()
    print('> echo-server is de-activated')
