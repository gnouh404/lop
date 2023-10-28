#include<bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;
template<class T>
class node{
	T data;
	node *next;
	public:
		node(){

		}
		node(T data, node<T> *N = NULL){
			this->data = data;
			next = N;
		}
		void setelem(T x){
			data = x;
		}
		void setnext(node<T> *N ){
			next = N;
		}
		T &getelem(){
			return data;
		}
		node<T> *&getnext(){
			return next;
		}
		~node(){
			delete next;
		}
		 
		
};
#endif


