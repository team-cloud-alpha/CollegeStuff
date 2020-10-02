
ip1, ip2, ip3, ip4 = input("Enter the ip address in Decimal Form\n").split(".")
print("The IP Address id: {}.{}.{}.{}".format(ip1, ip2, ip3,ip4))
print("Decimal Form: {}.{}.{}.{}".format(bin(int(ip1)).replace("0b", ""), bin(int(ip2)).replace("0b", ""),
                                        bin(int(ip3)).replace("0b", ""),bin(int(ip4)).replace("0b", "") ))
ip1 = int(ip1)
ip2 = int(ip2)
ip3 = int(ip3)
ip4 = int(ip4)

# print("\n\nThe given IP Address belongs to :")
# if(ip1 >= 0 and ip1 <= 127):
#     print("Class A")
#     print("Default Mask: 255.0.0.0")
# elif(ip1 > 127 and ip1 <= 191):
#     print("Class B")
#     print("Default Mask: 255.255.0.0")
# elif(ip1 > 191 and ip1 <= 223):
#     print("Class C")
#     print("Default Mask: 255.255.255.0")
# elif(ip1 > 223 and ip1 <= 239):
#     print('Class D')
#     print("No Default Mask")
# elif(ip1 > 239 and ip1 <= 255):
#     print('Class E')
#     print("No Default Mask")

n = int(input("\nHow many Subnet do you want?"))

nb = bin(n).replace("0b", "")

list1 = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,
            65536, 131072, 262144, 524288, 1048576, 2097152, 4194304]

nblen = len(nb)
if n not in list1:
    nblen = nblen + 1

print("nblen = {}".format(nblen))

if nblen  >= 0:
    nblen1 = nblen-1
else:
    pass

if (nblen  > 0 and nblen <9 ):
    pow = 7
    sub_mask_d = 0
    for i in range(0, (nblen -1) ):
        sub_mask_d = sub_mask_d + (2**pow)
        pow = pow - 1
elif (nblen > 8 and nblen  < 17):
    pow = 7
    sub_mask_d = 0
    for i in range(0, (nblen -1) - 8 ):
        sub_mask_d = sub_mask_d + (2**pow)
        pow = pow - 1
elif(nblen > 16 and nblen < 25):
    pow = 7
    sub_mask_d = 0
    for i in range(0, (nblen -1) - 16 ):
        sub_mask_d = sub_mask_d + (2**pow)
        pow = pow - 1


# print("\n\nThe Default Subnet Mask is :")
# if(ip1 >= 0 and ip1 <= 127):
#     # print("Class A")
#     if nblen  > 0 and nblen  < 9:
#         print("Subnet Mask:")
#         print("255.", end= '')
#         print(sub_mask_d, end = '')
#         print(".0.0")

#         print("Binary Form:")
#         print("11111111.", end='')
#         print(bin(sub_mask_d).replace("0b", ""), end='')
#         print(".0.0")
#     elif nblen  > 8 and nblen  < 17:
#         print("Subnet Mask:")
#         print("255.255.", end= '')
#         print(sub_mask_d, end = '')
#         print(".0")

#         print("Binary Form:")
#         print("11111111.11111111.", end='')
#         print(bin(sub_mask_d).replace("0b", ""), end='')
#         print(".0")
#     elif(nblen > 16 and nblen < 25):
#         print("Subnet Mask:")
#         print("255.255.255.", end= '')
#         print(sub_mask_d, end = '')

#         print("Binary Form:")
#         print("11111111.11111111.11111111.", end='')
#         print(bin(sub_mask_d).replace("0b", ""), end='')
#         # print("0.0")
#         # print(".0")

# elif(ip1 > 127 and ip1 <= 191):
#     # print("Subnet Mask:")
#     if nblen  > 0 and nblen  < 9:
#         print("Subnet Mask:")
#         print("255.255.", end= '')
#         print(sub_mask_d, end = '')
#         print(".0")
#     elif nblen  > 8 and nblen  < 17:
#         print("Subnet Mask:")
#         print("255.255.255.", end= '')
#         print(sub_mask_d, end = '')
#         # print(".0")

# elif(ip1 > 191 and ip1 <= 223):
#     if nblen  > 0 and nblen  < 9:
#         print("Subnet Mask:")
#         print("255.255.255.", end= '')
#         print(sub_mask_d, end = '')
#         # print(".0")
#     else:
#         print("Not Possible")
# elif(ip1 > 223 and ip1 <= 239):
#     print('Class D')
#     print("No Subnet Mask")
# elif(ip1 > 239 and ip1 <= 255):
#     print('Class E')
#     print("No Subnet Mask")

# Subnetting
na = 1

for j in list1:
    if j >= n:
        na = j
        break
    
print("na = {}".format(na))
if(ip1 >= 0 and ip1 <= 127):
    if nblen  > 0 and nblen  < 9:
       sub = 0
      
       print("Range of each Subnets")
       for i in range(0, n):
            print(ip1, end='')
            print(".",end = '')
            print(int(sub), end = '')
            print(".0.0", end='')

            print(" - ", end='')

            print(ip1, end='')
            print(".", end='')
            print(int(sub+ (256/na)-1), end='')
            print(".255.255")
            sub = sub + (256/na)
       print("\nClass : A")
       print("Default Mask: 255.0.0.0")
       print("Network ID: {}.0.0.0".format(ip1))
       print("Broadcaster ID: {}.0.0.0".format(ip1))
       print("Total Bits Borrowed/Fixed: {}".format(nblen1))
       print("Range of Each Subnet: {}".format((2**(16+(8-nblen1))) ))
       print("Total Avalable Id: {}".format( (2**(16+(8-nblen1))) -2) )
       print("Subnet Mask: ", end='')
       print("255.", end= '')
       print(sub_mask_d, end = '')
       print(".0.0")
    elif nblen  > 8 and nblen  < 17:
       print("\nClass : A")
       print("Default Mask: 255.0.0.0")
       print("Network ID: {}.0.0.0".format(ip1))
       print("Broadcaster ID: {}.0.0.0".format(ip1))
       print("Total Bits Borrowed/Fixed: {}".format(nblen1))
       print("Range of Each Subnet: {}".format((2**(16+(8-nblen1))) ))
       print("Total Avalable Id: {}".format( (2**(16+(8-nblen1))) -2) )
       print("Subnet Mask: ", end='')
       print("255.255.", end= '')
       print(sub_mask_d, end = '')
       print(".0")

           
    elif(nblen > 16 and nblen < 25):
       print("\nClass : A")
       print("Default Mask: 255.0.0.0")
       print("Network ID: {}.0.0.0".format(ip1))
       print("Broadcaster ID: {}.0.0.0".format(ip1))
       print("Total Bits Borrowed/Fixed: {}".format(nblen1))
       print("Range of Each Subnet: {}".format((2**(16+(8-nblen1))) ))
       print("Total Avalable Id: {}".format( (2**(16+(8-nblen1))) -2) )
       print("Subnet Mask: ", end='')
       print("255.255.255.", end= '')
       print(sub_mask_d)
    #    print(".0")
        # print(".0")
elif(ip1 > 127 and ip1 <= 191):
    if nblen  > 0 and nblen  < 9:
        sub = 0
        print("Range of each Subnets")
        for i in range(0, n):
            print(ip1, end='')
            print(".",end = '')
            print(ip2, end='')
            print(".",end = '')
            print(int(sub), end = '')
            print(".0", end='')

            print(" - ", end='')

            print(ip1, end='')
            print(".", end='')
            print(ip2, end='')
            print(".", end='')
            print(int(sub+ (256/na)-1), end='')
            print(".255")
            sub = sub + (256/na)
        print("\nClass : B")
        print("Default Mask: 255.255.0.0")
        print("Network ID: {}.{}.0.0".format(ip1, ip2))
        print("Broadcaster ID: {}.{}.255.255".format(ip1, ip2))
        print("Total Bits Borrowed/Fixed: {}".format(nblen1))
        print("Range of Each Subnet: {}".format((2**(8+(8-nblen1))) ))
        print("Total Avalable Id: {}".format( (2**(8+(8-nblen1))) -2) )
        print("Subnet Mask:")
        print("255.255.", end= '')
        print(sub_mask_d, end = '')
        print(".0", end= '')
        # print(".0")
    elif nblen  > 8 and nblen  < 17:
       print("\nClass : B")
       print("Default Mask: 255.0.0.0")
       print("Network ID: {}.0.0.0".format(ip1))
       print("Broadcaster ID: {}.0.0.0".format(ip1))
       print("Total Bits Borrowed/Fixed: {}".format(nblen1))
       print("Range of Each Subnet: {}".format((2**(8+(8-nblen1))) ))
       print("Total Avalable Id: {}".format( (2**(8+(8-nblen1))) -2) )
       print("Subnet Mask: ", end='')
       print("255.255.", end= '')
       print(sub_mask_d, end = '')
       print(".0")
elif(ip1 > 191 and ip1 <= 223):
    if n == 256:
        print("Not Possible")
    else:
        if nblen  > 0 and nblen  < 9:
            sub = 0
      
            print("Range of each Subnets")
            for i in range(0, n):
                    print(ip1, end='')
                    print(".",end = '')
                    print(ip2, end='')
                    print(".",end = '')
                    print(ip3, end='')
                    print(".",end = '')
                    print(int(sub), end = '')
                    # print(".0", end='')

                    print(" - ", end='')

                    print(ip1, end='')
                    print(".", end='')
                    print(ip2, end='')
                    print(".", end='')
                    print(ip3, end='')
                    print(".", end='')
                    print(int(sub+ (256/na)-1), end='')
                    print("")
                    sub = sub + (256/na)


                    # print("\n\n Subnet ID:  ")
                    # print(ip1, end='')
                    # print(".",end = '')
                    # print(ip2, end='')
                    # print(".",end = '')
                    # print(ip3, end='')
                    # print(".",end = '')
                    # print(int(sub))
                    # # print(".0", end='')

                    # print("Broadcaster ID:  ")
                    # print(ip1, end='')
                    # print(".", end='')
                    # print(ip2, end='')
                    # print(".", end='')
                    # print(ip3, end='')
                    # print(".", end='')
                    # print(int(sub+ (256/na)-1), end='')
                    # print("/n/n")


            print("\nClass : C")
            print("Default Mask: 255.255.255.0")
            print("Network ID: {}.{}.{}.0".format(ip1, ip2, ip3))
            print("Network ID: {}.{}.{}.255".format(ip1, ip2, ip3))
            print("Total Bits Borrowed/Fixed: {}".format(nblen1))
            print("Range of Each Subnet: {}".format(int(256/na) ))
            print("Total Avalable Id: {}".format((int(256/na)-2)) )
            print("Subnet Mask: ", end='')
            print("255.255.255.", end= '')
            print(sub_mask_d, end = '')

            
elif(ip1 > 223 and ip1 <= 239):
    print("Error")  
elif(ip1 > 239 and ip1 <= 255):
    print("Error")
   