#include <iostream>
#include <malloc.h>
using namespace std;
#define N  3

typedef struct Btree{
	int nb;
	Btree* children [2* N] ;
	int keys [2* N-1] ;
	
}Btree;

typedef struct Btree* btree; 

btree create(){
	btree t  = (btree)malloc(sizeof(Btree));
	t->nb=0;
	  for (int i = 0; i < 2*N; i++){
        t->children[i] = NULL;
    }
	return t;
}

//************************* Search ***********************

btree search(btree t , int x ){
	if(t == NULL){
		return NULL;
	}
	int i;
	for( i =0; i<t->nb; i++){
		if(t->keys[i]==x){
			return t;
		}
		if(t->keys[i]>x){
			break;
		}
	
	}
	return	search(t->children[i],x);
}

//************************* Insert ***********************

void splitNode(btree t , int i ){
	btree t1 = create();
	btree child = t->children[i];
	//decalage des cles et des pointeurs de t 
	for(int j=t->nb; j>i ; j--){
		t->keys[j]=t->keys[j-1];
		t->children[j+1]= t->children[j];
	}
	t->children[i-1]= t->children[i-2];
	t->nb++;
	// adding the child median to t 
	t->keys[i]= child->keys[N]; 
	// adding the new node as a children 
	t->children[i+1]= t1;
	
	
	//fill t1 keys 
	for(int j = N , j< 2*N-1 ; j++  ){
		t1->keys[j-N]= child->keys[j];
		t1->children[j-N]= child->children[j];
		}
		if(child->children[0]!= NULL ){
		for(int j = N , j< 2*N ; j++  ){
	
		    t1->children[j-N]= child->children[j];
		}
	
		}
		t1->nb= N-1;
		
 	//delete the rest from the child 
		child->nb= N-1;
		
}

void insertNode(btree t, int x){
	
	int i = t->nb-1;
    if(t->children[0]==NULL){

	while(t->keys[i]>x && i>=0){
		t->keys[i+1]=t->keys[i];
		t->children[i+2]= t->children[i+1];
		i--;
	}
	
		
	 t->keys[i+1] = x;
	 t->nb++;
	
	}else{
	    for(t->nb-1; i>0; i--){
		if(t->keys[i]<x){
			if(t->children[i+1]->nb=2*N-1){
				split(t,i+1);
				break;		
			}
		}
	}
	 if(x<t->keys[i+1]) i++;
	 insertNode(t->children[i+1],x);
		
	}
	
 void insert(btree t, int x) {
 	if (t == null){
 		btree t1 = create();
 		t1->keys[0]=x;
	 }
	 else{
	 	if(t->nb == 2*N-1){
	 		btree t1 = create();
	 		t1.children[0]=t;
	 		split(t1,0);
		 }
	 
	 	t = insertNode(t,x);
	 }
 }
}
//************************* Delete ***********************
/**
take the last element fom the Left child we replace the key to be deleted with this pred 
delete the pred 

*/
btree borrowLeft(btree t , int i)
{	
	btree leftchild = t->children[i-1];
	int x = leftchild->keys[leftsibling->nb-1];
	
	btree child = leftchild->children[leftsibling->nb];
	leftchild->nb--;

	for(int j = t->children[i]->nb ; j>=0;j++){
			t->children[i]->children[j+1] = t->children[i]->children[j];
			
	}
		for(int j = t->children[i]->nb ; j>0;j++){
			t->children[i]->keys[j] = t->children[i]->keys[j-1];
	}
	
	t->children[i]->keys[0]= t->keys[i-1];

	t->keys[i-1]= x;
	t->children[i]->children[0]= child;
	t->children[i]->nb++;
	
}

/**

this function get the left child as parameter 
we keep moving until we find the leaf then we return its last element which we called the predecessor
when we find it we delete it and return its value

*/

int deletepred(btree t){
	
	if(t->children[i]==NULL){
		
	
			int x =  t->keys[t->nb-1];
			t->nb--;
			return x;
	
	}

	if(t->children[t->nb] == N-1 ){
	 if (t->children[t->nb-1] == N-1 ){
	 fusionLeft(t,t->nb);
	}
	
	if (t->children[t->nb-1]>=N){
			borrowLeft(t,t->nb);
	}
}
	return deletepred(t->children[t->nb]);
	
	
}

/** we take the key [i] from the father 
	 we add it to the sibling 
	 we add the rest childand we add it to the sibling 
	free child
	 we delete the key from the father 
**/

void fusionLeft (btree t, int i){
	btree sibling= t->children[i-1];
	btree node = ->children[i];
	sibling->keys[N-1]=t->keys[i];
	sibling->children[N]= t-> childre[i+1];
	for(int j = N ; j< 2*N-1 ; j++){
		
		sibling->keys[j]= node->keys[j-N];
		
	}
	sibling ->nb = 2*N-1;
	free(node);
	
	for(int j=i-1;i<t->nb-1;i++){
		t->keys[j]=t->keys[j+1];
	}
		for(int j=i;i<t->nb;i++){
		t->children[j]=t->children[j+1];
	}
	t->nb ++;
}

/**
If the root has only one key+
its 2 children have N-1 keys => the root becomes the **fusion** of children
     
       else the same as an internal node 

*/
btree deletroot( btree t , int x){
	if(t->nb == 1){
		if(t->children[0] != NULL)
		if(t->children[0]->nb == N-1 && t->children[1]->nb == N-1 ){
				fusionLeft(t,1);
			btree x = t->children[0];
		
			
			return deleteKey(x,k);
		}
		return	deleteKey(t,x);
	}
}


btree deleteKey( btree t , int x){
// if it is a Leaf
	if(t->children[0]==NULL){
			int i = 0;
			while( i<t->nb )
			{ if(t->keys[i] == x) {
			
				break;
			}
			  
				i++;
			}
			
			 
			 	
			 			for(int j = i ; i<t->nb ; i++){
			 				t->keys[j]=t->keys[j+1];
			 			
						 }
						 t->nb--;
				
				 return t;
	}
// if it is an internal node
	
			int i = 0;
			bool found = false;
			while( i<t->nb )
			{ if(t->keys[i] == x) {
				found = true;
				break;
			}
			  if(t->keys[i]>x) break;
				i++;
			}
			 if(found){
			 
		
				 		if(t->children[i]->nb>=N){
			 	t->keys[i]= deletepred(t->children[i]);
			 	return t;
				 }
				 
				 	 		if(t->children[i+1]->nb>=N){
			 				t->keys[i]= deleteright(t->children[i]);
			 	return t;
				 }
				 
				 //if the 2 children have N-1 keys
				 fusionLeft(t,i+1);
				 return deleteKey(t->children[i],k);
		}
		
		// if we didn't find it 
		
		if(t->children[i]->nb >= N){
			return deleteKey(t->children[i],x);
		}
		//if we have a left sibling 
			 		 	if(i>0){
			 		 		if(t->children[i-1]->nb>=N){
			 		 			borrowleft(t,i);
			 		 			return deleteKey(t->children[i],x);
							  }
							  }
							  
		//if we have right sibling 
						if(i<t->nb){
								if(t->children[i+1]->nb>=N){
			 		 			borrowright(t,x);
			 		 				return deleteKey(t->children[i],x);
							  }	
						}
		// in case the children have N-1 Keys 
		//if we have the left sibling 
						if(i>0){
							fusionLeft(t,i);
							return deleteKey(t->children[i-1],x);
						}
			//if we have the right sibling 
							if(i<t->nb){
							
							fusionRight(t,i);
							return deleteKey(t->children[i],x);
						}
					
			 		 			
		
	
}


int main(int argc, char** argv) {
	
	btree t =create();
	return 0;
}
