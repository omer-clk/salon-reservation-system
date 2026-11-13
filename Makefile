CC = gcc
CFLAGS = -Wall -Wextra -std=c99

kuafor: main.c
	$(CC) $(CFLAGS) main.c -o kuafor

clean:
	rm -f kuafor kuafor.exe

.PHONY: clean
