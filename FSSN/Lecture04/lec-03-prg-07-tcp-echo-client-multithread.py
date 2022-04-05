import socket
import threading

HOST = '127.0.0.1'
PORT = 65456

# {CHAT#1} Create a separate receive handler
def recvHandler(clientSocket):
    while True:
        recvData = clientSocket.recv(1024)
        print('> received:', recvData.decode('utf-8'))
        if recvData.decode('utf-8') == "quit":
            break

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as clientSocket:

        try:
            if clientSocket.connect((HOST, PORT)) == -1:
                    print('> connect() failed and program terminated')
                    clientSocket.close()
                    return
        except Exception as exceptionObj:
            print('> connect() failed by exception:', exceptionObj)
            return
        
        # {CHAT#2} Create a receive handler and set to exit the thread, then execute the thread
        clientThread = threading.Thread(target=recvHandler, args=(clientSocket,))
        clientThread.daemon = True
        clientThread.start()

        while True:
            # [=start=]
            sendMsg = input('> ')
            clientSocket.sendall(bytes(sendMsg, 'utf-8'))
            if sendMsg == "quit":
                break
            # [==end==]

if __name__ == "__main__":
    print('> echo-client is activated')
    main()
    print('> echo-client is de-activated')
