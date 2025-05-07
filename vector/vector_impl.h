#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Vector{
private:
    T* m_data;
    int m_size;
    int m_capacity;
    void reallocate(int new_capacity);
    public: 
    class const_iterator{
       const T* ptr;
       public:
       using value_type=const T;
       using difference_type=std::ptrdiff_t;
       using reference=const T&;
       using pointer=const T*;
       using iterator_category=std::random_access_iterator_tag;
       explicit const_iterator(const T* p=nullptr){ptr=p;}
       const_iterator(const const_iterator& other){this->ptr=other.ptr;}
       reference operator*();
       pointer operator->();
       const_iterator& operator++();
       const_iterator operator++(int);
       const_iterator& operator--();
       const_iterator operator--(int);
       const_iterator operator+(difference_type value);   
       const_iterator operator-(difference_type value);
       const_iterator& operator+=(difference_type value);
       const_iterator& operator-=(difference_type value);
       reference operator[](difference_type value);
       bool operator==(const_iterator& other);
       bool operator!=(const const_iterator& other);
       bool operator<(const_iterator& other);
       bool operator<=(const_iterator& other);
       bool operator>=(const_iterator& other);
       difference_type operator-(const_iterator& other);
    };
    class iterator{
        private:
        T* ptr; 
        public:
        using value_type= T;
        using difference_type=std::ptrdiff_t;
        using reference=T&;
        using pointer=T*;
        using iterator_category=std::random_access_iterator_tag;
        iterator(T* p=nullptr):ptr(p){}
        iterator(iterator& other):ptr{other.ptr}{}
       reference operator*();
       pointer operator->();
       iterator& operator++();
       iterator operator++(int);
       iterator& operator--();
       iterator operator--(int);
       iterator operator+(difference_type value);   
       iterator operator-(difference_type value);
       iterator& operator+=(difference_type value);
       iterator& operator-=(difference_type value);
       reference operator[](difference_type value);
       bool operator==(iterator& other)const;
       bool operator!=(const iterator& other)const ;
       bool operator<(iterator& other);
       bool operator<=(iterator& other);
       bool operator>=(iterator& other);
       difference_type operator-(iterator& other);
    };
     template<typename Iterator>
     class reverse_iterator{
     Iterator current; 
     public:
     using iterator_type=Iterator;
     using value_type= typename Iterator::value_type;
     using difference_type= typename Iterator::difference_type;
     using reference=typename Iterator::reference;
     using pointer=typename Iterator::pointer;
     reverse_iterator(Iterator other):current{other}{};
     template<typename other_iter>
     reverse_iterator(other_iter other){current=other.current;}
     pointer operator->();
     reference operator*();
     reverse_iterator& operator=(const reverse_iterator& other){current=other.current;}
     Iterator base()const{return current;}
     reference operator[](difference_type value){return current[value];}
     reverse_iterator& operator++();
     reverse_iterator operator++(int);
     reverse_iterator& operator--();
     reverse_iterator operator--(int);
     reverse_iterator& operator+=(difference_type value){return current-=value;}
     reverse_iterator& operator-=(difference_type value){return current+=value;}
     friend bool operator==(reverse_iterator& obj,reverse_iterator& other){return obj.current==other.current;}
     friend bool operator!=(const reverse_iterator& obj,const reverse_iterator& other){return obj.current!=other.current;}
     friend bool operator>=(reverse_iterator& obj, reverse_iterator& other){return obj.current>=other.current;}
     friend bool operator<=(reverse_iterator& obj, reverse_iterator& other){return obj.current<=other.current;}
     friend reverse_iterator operator+(reverse_iterator& other,difference_type value){return other.current-value;}
     friend reverse_iterator operator-( reverse_iterator& obj,difference_type value){return obj.current+value;} 
    };
    
    Vector():m_size(0),m_capacity(0),m_data(nullptr){};
    Vector(int size):m_size(0),m_capacity(size){
        m_data=new int[m_capacity];
    }
    int at(int index)const;
    void push_back(T index);
    void pop_back();
    int getSize()const;
    int getCap()const;
    void resize(int new_size);
    void reserve(int new_cap);
    T front()const;
    T back()const;
    bool isEmpty()const;
    void shrink_to_fit();
    void insert(int index,T value);
    void erase(int index);
    void clear();
    void print();
    const_iterator cbegin();
    const_iterator cend();
    iterator begin();
    iterator end();
    reverse_iterator<iterator> rend(){
        return reverse_iterator<iterator>(begin());
    }
    reverse_iterator <iterator> rbegin(){
        return reverse_iterator<iterator>(end());
    }
    
    ~Vector(){
        delete[]m_data;
     m_data=nullptr;
    }
};
#include"vector_impl.tpp"
#include "const_iterator_impl.tpp"
#include"iterator.tpp"
#include"reverse_iterator.tpp"
