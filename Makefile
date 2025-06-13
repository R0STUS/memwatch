CC = cc
CFLAGS = -std=c90 -pedantic -Wall -Wextra
TARGET = memwatch
SRC = memwatch.c
PREFIX = /usr
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man
.PHONY: all clean install uninstall install-man uninstall-man
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
install: $(TARGET)
	install -Dm755 $(TARGET) $(BINDIR)/$(TARGET)
uninstall:
	rm -f $(BINDIR)/$(TARGET)
clean:
	rm -f $(TARGET)
install-man:
	mkdir -p $(DESTDIR)$(MANDIR)/man1
	cp memwatch.1 $(DESTDIR)$(MANDIR)/man1/
uninstall-man:
	rm -f $(DESTDIR)$(MANDIR)/man1/memwatch.1
