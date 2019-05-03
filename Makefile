CXX = g++
CXXFLAGS += -Wall -O0 -g -std=c++11


ex: interface_main.o interface.o chat_client.o
	$(CXX) -o superchat chat_client.o interface.o -lpthread -lncurses



interface.o: interface.cpp interface.hpp
	$(CXX) -c interface.cpp -lpthread -lncurses

chat_client.o: chat_client.cpp chat_message.hpp interface.hpp
		$(CXX) -c chat_client.cpp -lpthread -lncurses -I/mnt/c/Users/Phillip/Downloads/asio-1.12.2/asio-1.12.2/include

#client.o: client.cpp client.hpp
#	$(CXX) -c client.cpp

clean:
	-rm -f inerface.o chat-client.o superchat chat_server.o chat_server
