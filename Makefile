all: exe

exe: knight.c
	gcc -o exe knight.c

.PHONY: clean
clean:
	rm exe
