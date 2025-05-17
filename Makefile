
CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra
TARGET = memwatch
SRC = memwatch.c
PREFIX = /usr
BINDIR = $(PREFIX)/bin
.PHONY: all clean install uninstall
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
install: $(TARGET)
	install -Dm755 $(TARGET) $(BINDIR)/&(TARGET)
uninstall:
	rm -f $(BINDIR)/$(TARGET)
clean:
	rm -f $(TARGET)
