import socket
import hashlib

host = 'local host'
port = 5000

# creating sockets for connection using TCP/IP
s = socket.socket(socket.AF_INET,
                  socket.SOCK_STREAM)

# connect server to client
s.bind(('', port))

# allow maximum 1 connection to the socket
s.listen(1)

# wait till a client accept the connection
c, addr = s.accept()

# display client address
print("CONNECTION FROM:", str(addr))

# send password to the client after
# encoding into binary string
message = input('Enter the message to be encoded: ')
# c.send(message)
c.send(b"Password received")

# encode the password using SHA-1 Hashing function and send to client
encodedMsg = hashlib.sha1(message.encode())
c.send(encodedMsg.hexdigest().encode())

# disconnect the server
c.close()
