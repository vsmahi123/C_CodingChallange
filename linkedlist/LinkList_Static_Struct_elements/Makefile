a.out : main.o LinkListApi.o
	gcc main.o LinkListApi.o
main.o : main.c
	gcc -c main.c
LinkListApi.o : LinkListApi.c LinkListApi.h
	gcc -c LinkListApi.c  LinkListApi.h
delete :
	-rm -r *.o

