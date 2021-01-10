import random as rd
import sys


def cipher(inp, keys, f):
    for key in keys:
        L, R = split(inp)
        Ln = xor(L, f(key, R))
        inp = R+Ln
    return Ln+R


def split(inp):
    assert len(inp) % 2 == 0
    return inp[:int(len(inp)/2)], inp[int(len(inp)/2):]


def xor(a, b):
    output = ""
    for i in range(len(a)):
        #print(i, a, b)
        inter = int(a[i])+int(b[i])
        if inter == 2:
            inter = 0
        output = output+str(inter)
    return output


def keyGen(l, n):
    '''
    l: length of key
    n: number of keys needed
    '''
    o = []
    for i in range(n):
        k = ""
        for i in range(l):
            k = k + str(rd.randint(0, 1))
        o.append(k)
    return o


def binToHex(binary):
    res = "0x"
    hexList = [hex(int(binary[i:i+8], 2))[2:]
               for i in range(0, len(binary), 8)]
    for hexa in hexList:
        if len(hexa) == 1:
            hexa = "0"+hexa
        res = res + hexa
    return res


if __name__ == "__main__":
    # getting plain text and converting it to binary
    try:
        plainText = sys.argv[1]
    except:
        plainText = input()
    plainInts = [bin(ord(letter))[2:] for letter in plainText]
    plainBin = ""
    for integer in plainInts:
        while len(integer) != 8:
            integer = "0"+integer
        plainBin = plainBin+integer
    # generating key list
    keyList = keyGen(int(len(plainBin)/2), 16)
    # encrypting
    C = cipher(plainBin, keyList, xor)
    # reverse key list for decrypting
    keyList.reverse()
    # decrypting
    result = cipher(C, keyList, xor)
    # convertint result to ASCII string
    resultToChar = [chr(int(result[i:i+8], 2))
                    for i in range(0, len(result), 8)]
    resultText = ""
    for letter in resultToChar:
        resultText = resultText+letter
    # printing results
    print("Plain text:         {}".format(plainText))
    print('Plain text to hexa: {}'.format(binToHex(plainBin)))
    print("Cipher:             {}".format(binToHex(C)))
    print("Result as hexa:     {}".format(binToHex(result)))
    print("Result to text:     {}".format(resultText))
