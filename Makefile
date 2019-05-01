CXX = g++
CXXFLAGS += -Wall -O0 -g -std=c++11 -I/mnt/c/Users/Phillip/Downloads/asio-1.12.2/asio-1.12.2/include/


ex: interface_main.o interface.o chat_server.o chat_client.o
	$(CXX) -o superchat chat_client.o interface.o -lpthread -lncurses

interface_main.o: interface_main.cpp interface.hpp
	$(CXX) -c interface_main.cpp

interface.o: interface.cpp interface.hpp
	$(CXX) -c interface.cpp -lpthread -lncurses

chat_client.o: chat_client.cpp chat_message.hpp interface.hpp
		$(CXX) -c chat_client.cpp chat_message.cpp -lpthread -lncurses

chat_server.o: chat_server.cpp chat_message.hpp
		$(CXX) -c chat_server.cpp -lpthread

#client.o: client.cpp client.hpp
#	$(CXX) -c client.cpp

clean:
	-rm -f interface_main interface client interface_main.o interface.o chat_client.o chat_server.o
