import socket
import hashlib

host = 'local host'
port = 5000

# creating sockets for connection using TCP/IP
s = socket.socket(socket.AF_INET,
                  socket.SOCK_STREAM)

# connect server to client
s.connect(('127.0.0.1', port))

# receive message 1
msg = s.recv(1024)

# recieve next messages (in this case: SHA1 Hashed password)
while msg:
    print('Received:' + msg.decode())
    passwordHashed = msg.decode()
    msg = s.recv(1024)

# get the password for authentication
authMsg = input('Enter password:')
encodedAuthMsg = hashlib.sha1(authMsg.encode())
if(passwordHashed == encodedAuthMsg.hexdigest()):
    print('Authentication Successful')
else:
    print('Authentication Failed')

# disconnect the client
s.close()
