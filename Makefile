CC=gcc
TARGET=obj 
 
one:
	$(CC) unshadowprg1.c -o $(TARGET)
 
two:
	$(CC) top250tohash2.c -lcrypt -o $(TARGET)

three:
	$(CC) crackingpasswd3.c  -o $(TARGET) 
clean:
	rm $(TARGET)