#include <stdio.h>
//#include <stlib.h>
#include <strings.h>
#define MAKS_INPUT 100000

typedef struct lc{
	char dat;
	struct lc *nxt, *prev;
} lisc;

lisc* in(lisc *list, char c){
	lisc *tmp=new lisc();
	tmp->dat=c;
	tmp->nxt=list->nxt;
	list->nxt->prev=tmp;

	list->nxt=tmp;
	tmp->prev=list;
	return tmp;
}

void display(lisc *head){
	lisc *tmp=head;
	while (tmp->dat){
		putchar(tmp->dat);
		tmp=tmp->nxt;
	}
	printf("\n");
}

int main (){
	
	char input[MAKS_INPUT];
	while(gets(input)){
		int i;
		lisc *depan=new lisc();
		lisc *belakang=new lisc();
		belakang->prev=depan;
		depan->nxt=belakang;
		belakang->nxt=NULL;
		depan->prev=NULL;
		lisc *cur=depan;
		belakang->dat=0;
		
		for(i=0;i<strlen(input); i++){
			if(input[i]=='['){
				cur=depan;
				continue;
			}
			if(input[i]==']'){
				cur=belakang->prev;
				continue;
			}
			cur=in(cur, input[i]);
		}
		display(depan);
	
	} 
}
