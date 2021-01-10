import math
import random

p, q = map(int, input('Choose 2 distinct prime numbers: ').split())
m = int(input('Enter the value of plaintext: '))
n = p*q
totient_n = (n-1)*(p-1)

for i in range(2, totient_n):
    if math.gcd(i, totient_n) == 1:
        e = i

for i in range(1, 10):
    d = int((1 + i*totient_n)/e)
    if d % e == 0:
        d = int(d/e)
        break

print("Public Encryption key: ({}, {})".format(e, n))
print("Private Encryption key: ({}, {})".format(d, n))

c = int(math.pow(m, e) % n)
m = int(math.pow(c, d) % n)

print("Encrypted: {}".format(c))
print("Decrypted: {}".format(m))
