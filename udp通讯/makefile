all:MyUdpServer MyUdpClient

MyUdpServer:MyUdpServer.cpp
	g++ -g -o MyUdpServer MyUdpServer.cpp UdpServer.cpp

MyUdpClient:MyUdpClient.cpp
	g++ -g -o MyUdpClient MyUdpClient.cpp UdpClient.cpp

clean:
	rm -rf MyUdpServer MyUdpClient
