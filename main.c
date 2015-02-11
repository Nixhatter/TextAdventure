#include <stdio.h>
#include <stdlib.h>

char c;

char* inventory(int);

void flush(){
	fflush(stdout);
	fflush(stdin);
}

int main() {
	printf("HELLO\n");
	printf("PLEASE HELP ME\n");
	printf("I HATE C\n\n");
	
	int item1=0;
	int item2=0;

	printf("Welcome to the world\n");
	area1:
	flush();
	printf("(n)do nothing, (a)go to area 2");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'a' : printf("going to area 2\n");
				   printf("Grabbed item 1\n"); 
				   item1=1;
				   goto area2;
		case 'n' : printf("doing nothing\n");
				   printf("really...\n"); break;
		default  : goto area1;
	}
	
	area2:
	flush();
	printf("(n)do nothing");
	if(item1) printf(", (a)go to final area");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'a' : printf("going to final area, grabbed item2\n");
				   item2=1; goto final;
		case 'n' : printf("do nothing\n");
		default  : goto area2;
	}
	
	final:
	flush();
	printf("(e) end this adventure (n) do nothing");
	printf("\n");
	scanf("%c", &c);
	switch(c){
		case 'n' : printf("\n");
				   printf("doing nothing again\n"); goto final;
		case 'e' : printf("ENDING!\n");
				   printf("\n"); break;
		default  : goto final;
	}
	
	if(item1 && item2){
		printf("Congratulations!");
		return end();
	} else {
		printf("You failed to get the items");
		if(!item1 && !item2) printf("You didnt get either");
		else if(!item1) printf("you forgot item1");
		else printf("you forgot item2");
		return end();
	}
}

char* inventory(int item){
	switch(item){
		case 0 : return "you have nothing\n";
		case 1 : return "you have item 1\n";
		default : return "default\n";
	}
}

int end(){
	flush();
	scanf("%c",&c);
	return 0;
}

