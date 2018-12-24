#include <iostream>
#include "Queue.h"
using namespace std;

main(){
	int n;
	cout<< "How many numbers would you like? "<<endl;
	cin>>n; Queue q1;
	for(int i=0;i<n;i++){
		q1.enqueue(i);
	
	q1.display(cout);
	}
	while(!q1.empty()){
		cout<<q1.front()<<endl;
		q1.dequeue;   
	}
	
}
