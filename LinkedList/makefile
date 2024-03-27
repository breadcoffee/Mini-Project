/*
File: makefile
Created: 24-03-27(3파일 날짜)
Author: 이주원
*/

librarySystem2:librarySystem2_main.o librarySystem2_struct.o librarySystem2_function.o
  gcc -o librarySystem2 librarySystem2_main.c librarySystem2_struct.c librarySystem2_function.c

librarySystem2_main.o: librarySystem2_main.c
  gcc -c librarySystem2_main.c

librarySystem2_struct.o: librarySystem2_struct.c
  gcc -c librarySystem2_struct.c

librarySystem2_function.o: librarySystem2_function.c
  gcc -c librarySystem2_function.c

clean:
  rm *.o librarySystem2
