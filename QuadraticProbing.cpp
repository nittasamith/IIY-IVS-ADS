#include<stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init(){
	for(int i=0;i<SIZE;i++){
		hashTable[i]=-1;
	}
}
void insert(int key){
	int index = key%SIZE;
	int i=0;
	while(hashTable[(index + i*i)%SIZE]!=-1){
	    i++;
		if(i==SIZE){
			printf("Hashtable is full !\n");
			return;
		}
	}
	int newIndex = (index + i*i) % SIZE;
	hashTable[newIndex]=key;
}
void display(){
	printf("HashIndex\tKeys\n");
	for(int i=0;i<SIZE;i++){
		printf("%d\t\t%d\n",i,hashTable[i]);
	}
}
int main(){
	int key[]={31,41,51,61,71};
	init();
	for(int i=0;i<sizeof(key)/sizeof(key[0]);i++){
		insert(key[i]);
	}
	display();
	return 0;
}
