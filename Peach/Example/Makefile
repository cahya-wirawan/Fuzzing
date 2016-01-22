
OPTIONS=-fno-stack-protector -D_FORTIFY_SOURCE=0 -g

all: BeefGenerator read BeefReader

BeefGenerator: BeefGenerator.c
	gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 BeefGenerator.c -o BeefGenerator

read: read.c
	gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 read.c -o read

BeefReader: BeefReader.c
#	gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 BeefReader.c -o BeefReader
	gcc ${OPTIONS} BeefReader.c -o BeefReader
  
clean:
	rm -f read BeefGenerator BeefReader
