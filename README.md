## TCP BASED CHAT APPLICATION ON AN AD HOC NETWORK

**This is a [TCP](https://www.tutorialspoint.com/data_communication_computer_network/transmission_control_protocol.htm) based application program which allows to connect two machines on an [ad hoc network](https://en.wikipedia.org/wiki/Wireless_ad_hoc_network), and transfer text messages
using the [Socket Programming in C](https://www.geeksforgeeks.org/socket-programming-cc)**


## Usage

* Create an ad hoc network using the script file as:
	1) Make changes in IP addresses in the script file when using on two different machines on same network.
	2) Make sure the network essid is same for both the machines to be connected in one ad hoc network.
	3) Save the file and run the script file using ./script
	
* To test on one machine:
	1) Open two different terminals in the same directory.
	2) In one compile the chatServer.c program using the command:
		>gcc chatServer.c -o server

	3) In another compile chatClient.c program using the command:
		>gcc chatClient.c -o client

 	4) Now in the first terminal run server program using,
		>./server

	5) Run the client program in second terminal using
		>./client 127.0.0.1

	   Here 127.0.0.1 is the localhost address
	6) Enter the messages and press enter to send the messages to other side.
	7) Enter the 'exit' keyword to stop sending messages

* Using programs in an ad hoc network:
	1) Run the server program as in the above given description on one of the machines.
	2) Run the client program on the another machine and while entering the IP address instead of 127.0.0.1 use the IP
	   address of the server machine used in the ad hoc network.

## Limitations

Can transfer only single line text messages of size upto 5000 characters.
