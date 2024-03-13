all: lib_public.a lib_public.so libftp.a libmyftp.so

lib_public.a:_public.h _public.cpp
	g++ -c -o lib_public.a _public.cpp

lib_public.so:_public.h _public.cpp
	g++ -fPIC -shared -o lib_public.so _public.cpp

libftp.a:ftplib.h ftplib.c
	gcc -c -o libftp.a ftplib.c

libmyftp.so:ftplib.h ftplib.c
	gcc -fPIC -shared -o libmyftp.so ftplib.c

clean:
	rm -f lib_public.a lib_public.so libftp.a libmyftp.so
