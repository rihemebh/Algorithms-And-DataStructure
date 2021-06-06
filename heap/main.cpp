#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct {
	int e ;
	int prior;
} element;

typedef struct {
	element* e ; 
	int length;
	
} heap ;

//typedef  tas* heap;

heap create(){
	heap t;
	element* e = (element*) malloc(sizeof(element));
	t.length =0;
	t.e = e;
	
	return t; 
}





void insert(heap h , element x){
	
// we add the element at the end 
h.e[h.length] = x;

int i = h.length;
element y;

while((i>0)&&(h.e[(i-1)/2].prior<x.prior)){
	// permut dad with son hh 
	y= h.e[(i-1)/2];
	h.e[(i-1)/2] = h.e[i];
    h.e[i] = y;
    //end permut 
    i= (i-1)/2;
}

h.length++;	
}

// we can only remove the element with the lowest priority = root elemnt 
heap deleteElement(heap h){
	
	//put the last elment in the root 
	int i = h.length-1;
	h.e[0]= h.e[i];
	//delete the last element 
	h.length--;
	//permut with the child with the lowest priority 
	i=0;
	int j;
	element y;
	while (i<h.length){
		if(h.e[2*i+1].prior<h.e[i].prior){
			j = 2*i+1;
		}else{
			j= 2*i+2;
		}
			y= h.e[i];
			h.e[i] = h.e[j];
    		h.e[j] = y;
		
		i= j;
	}
	
	return h;
	
}
int main(int argc, char** argv) {
	return 0;
}
