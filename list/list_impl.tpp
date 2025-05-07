#pragma once
#include"list_impl.h"
using namespace std;
template<typename T>
List<T>::List(int size1){
	if(size1<=0){
		head=tail=nullptr;
	}
    this->size=size1;
	head=new Node(0);
	tail=head;
	--size1;
	while(size1>0){
		tail->next=new Node(0);
		tail->next->prev=tail;
		tail=tail->next;
		size1--;
	}
}
  template<typename T>
  void List<T>::push_back(const T& value){
	if(head==nullptr){
		head=tail=new Node(value);
		size++;

	}
	else{tail->next=new Node(value);
	tail->next->prev=tail;
	tail=tail->next;
	size++;
	}
  }
  template<typename T>
  void List<T>::push_front(const T& value){
  head->prev=new Node(value);
  head->prev->next=head;
  head=head->prev;
  size++;
  }
  template<typename T>
  void List<T>::pop_back(){
	if(!tail){
		return;
	}
	if(tail==head){
     delete head;
	 head=tail=nullptr;
	 size--;

	}
	 else{tail=tail->prev;
	 delete tail->next;
	 tail->next=nullptr;
	 size--;
	 }
  }
  template<typename T>
  void List<T>::pop_front(){
     if(!tail){
		return;
	 }
	 if(tail==head){
	    delete head;
		head=tail=nullptr;
		size--;
	 }
	 else{
        head=head->next;
		delete head->prev;
		head->prev=nullptr;
		size--;
	 }
  }
  template<typename T>
  void List<T>::clear(){
	while(head){
		pop_front();
	}
  }
  template<typename T>
  bool List<T>::empty(){
	return size==0;
  }
  template<typename T>
  void List<T>::print_forward(){
	Node* current=head;
	while(current){
		cout<<current->data<<endl;
		current=current->next;
	}
  }
  template<typename T>
  void List<T>::print_backward(){
       Node*current=tail;
	   while(current){
		cout<<current->data;
		current=current->prev;
	   }
  }
  template<typename T>
  int List<T>::get_size(){
     return size;
  }


		









	

