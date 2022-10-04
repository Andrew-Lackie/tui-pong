CC = g++
CFLAGS = -g
LDFLAGS = -lncurses 
SRCS = src/main.cpp
TARGET = pong

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) *~


