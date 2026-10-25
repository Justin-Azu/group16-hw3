CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SOURCES = main.cpp address.cpp credit_card.cpp person.cpp product.cpp transaction.cpp store.cpp
TARGET = store.exe

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	del $(TARGET)