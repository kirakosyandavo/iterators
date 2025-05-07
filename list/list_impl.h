#pragma once
#include<iostream>
using namespace std;
template<typename Iter>
int distance(Iter first,Iter second){
          int number=0;
          if(first==second){
            return number;
          }
       while(first!=second){
           first++;
           number++;
       }
       return number;
}
template<typename T>
class List {
  struct Node{
    T data;
    Node* prev;
    Node* next;
    Node(const T& value):data{value},prev{nullptr},next{nullptr}{}
  };
  Node* head;
  Node* tail;
  int size;
  public:
  class iterator;
  class const_iterator{
    private:
     Node* current;
    public:
    using value_type=const T;
    using difference_type=std::ptrdiff_t;
    using reference=const T&;
    using pointer=const T*;
    using iterator_category=std::bidirectional_iterator_tag;
    explicit const_iterator(Node* obj){current=obj;}
    explicit const_iterator(const iterator& it){current=it.current;}
    const_iterator(const const_iterator& other){current=other.current;}
    reference operator*();
    pointer operator->();
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);
    bool operator!=(const const_iterator& other);
    bool operator==(const const_iterator& other);
  };
  class iterator{
    private:
     Node* current;
    public:
    using value_type=T;
    using difference_type=std::ptrdiff_t;
    using reference=T&;
    using pointer=T*;
    using iterator_category=std::bidirectional_iterator_tag;
    explicit iterator(Node* obj){current=obj;}
    iterator(const iterator& other){current=other.current;}
    reference operator*();
    pointer operator->();
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    bool operator!=(const iterator& other)const;
    bool operator==(const iterator& other)const;
  };
  template<typename Iter>
  class reverse_iterator{
  Iter iterat; 
  public:
  using value_type=T;
  using difference_type=std::ptrdiff_t;
  using reference=T&;
  using pointer=T*;
  using iterator_category=std::bidirectional_iterator_tag;
  reverse_iterator(Iter other):iterat{other}{};
  template<typename other_iter>
  reverse_iterator(other_iter other){iterat=other.current;}
  pointer operator->();
  reference operator*();
  reverse_iterator& operator=(const reverse_iterator& other);
  Iter base()const{return iterat;}
  reverse_iterator& operator++();
  reverse_iterator operator++(int);
  reverse_iterator& operator--();
  reverse_iterator operator--(int);
  bool operator==(const reverse_iterator& other) const {
    return iterat == other.iterat;
}

bool operator!=(const reverse_iterator& other) const {
    return iterat != other.iterat;
}
  };

  List():head{nullptr},tail{nullptr},size{0}{}
  List(int size1);
  void push_back(const T& value);
  void push_front(const T& value);
  void pop_back();
  void pop_front();
  void clear();
  bool empty();
  void print_forward();
  void print_backward();
  int get_size();
  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();
  reverse_iterator<iterator> rbegin(){return reverse_iterator<iterator>(iterator(tail));}
  reverse_iterator <iterator> rend(){return reverse_iterator<iterator>(iterator(nullptr));}
};
 #include"list_impl.tpp"
 #include"const_iterator.tpp"
 #include"iterator.tpp"
 #include"reverse_iterator.tpp"

