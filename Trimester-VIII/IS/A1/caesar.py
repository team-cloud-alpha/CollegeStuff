def main():
    # Input
    text = input('Enter the string: ')
    shift = int(input('Enter the shift: '))
    print('1. Encrypt \n2. Decrypt')
    choice = int(input())
    if(choice == 1):
        # Call function
        result = encrypt(text, shift)
        # Output
        print("Encrypted string: " + result)
    elif(choice == 2):
        # Call function
        result = decrypt(text, shift)
        # Output
        print("Decrypted string: " + result)
    else:
        print('Invalid option')


def encrypt(text, shift):
    result = ""
    # traverse the string to encrypt
    for i in range(len(text)):
        alphabet = text[i]
        # Encrypt upper characters
        if(alphabet.isupper()):
            result += chr((ord(alphabet) + shift - 65) % 26 + 65)
        # Enccrypt lower characters
        else:
            result += chr((ord(alphabet) + shift - 97) % 26 + 97)
    return result


def decrypt(text, shift):
    result = ""
    # traverse the string to encrypt
    for i in range(len(text)):
        alphabet = text[i]
        # Encrypt upper characters
        if(alphabet.isupper()):
            result += chr((ord(alphabet) - shift - 65) % 26 + 65)
        # Enccrypt lower characters
        else:
            result += chr((ord(alphabet) - shift - 97) % 26 + 97)
    return result


main()
