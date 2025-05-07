#include"vector_impl.h"
using namespace std;
template<typename T>
void Vector<T>::reallocate(int new_capacity){
    int*tmp=new int[new_capacity];
    for(int i=0;i<m_size;i++){
        tmp[i]=m_data[i];
    }
    delete []m_data;
    m_data=tmp;

}
template<typename T>
int Vector<T>::at( int index)const{
    if(index>=m_size){
         cout<<"there is no such a index";
           exit(0);
    }
    return m_data[index];
}
template <typename T>
void Vector<T>::push_back(T index){
    if(m_capacity==0){
        m_capacity=2;
        reallocate(m_capacity);
        m_data[m_size]=index;
    }
    if(m_size==m_capacity){
        m_capacity=m_capacity*2;
        reallocate(m_capacity);
        m_data[m_size]=index;
    }
    else{
        m_data[m_size]=index;
    }
    m_size++;
}
template<typename T>
void Vector<T>::pop_back(){
    m_size=m_size-1;
}
template<typename T>
int Vector<T>::getSize()const{
 return m_size;
} 
template<typename T>
int Vector<T>::getCap()const{
    return m_capacity;
}
template<typename T>
void Vector<T>:: resize(int new_size){
    if(new_size<m_capacity){
        m_size=new_size;
    }  
    else{ reallocate(new_size);
          m_capacity=new_size;
          m_size=new_size;

    }
}

template<typename T>
    void Vector<T>:: reserve(int new_cap){
               reallocate(new_cap);
               m_capacity=new_cap;
               if(new_cap<m_size){
                m_size=new_cap;
                m_capacity=new_cap;
               }
               }
template<typename T>
T Vector<T>::front()const{
    if(m_size==0){
        cout<<"there is no element";
        exit(0);
    }
    return m_data[0];
    
}
     template<typename T>
    T Vector<T>::back()const{
        if(m_size==0){
            cout<<"there is no element"; 
    }    
    return m_data[m_size];    
   
    }
   template<typename T>
    bool Vector<T>:: isEmpty()const{
            if(m_size==0){
                return false;
            }
            return true;
    }
    template<typename T>
    void Vector<T>:: shrink_to_fit(){
        m_capacity=m_size;
        reallocate(m_size);

    }
    template<typename T>
   void Vector<T>::insert(int index,T value){
    
    if(m_size==m_capacity){
        m_capacity=m_capacity*2;
        reallocate(m_capacity);
    }
    m_size++; 
    for(int i=m_size-1;i>index;i--){
        m_data[i]=m_data[i-1];
    }
    m_data[index]=value;

   }
   template<typename T> 
   void Vector<T>::erase(int index){
    if(index>=m_size){
        exit(0);
    }
    for(int i=index;i<m_size-1;i++){
        m_data[i]=m_data[i+1];
    }
    m_size--;
   }
   template<typename T>
   void Vector<T>::clear(){
    m_size=0;
    m_capacity=0;
    delete[] m_data;
   }
   template<typename T>
   void Vector<T>::print(){
    for(int i=0;i<m_size;i++){
        cout<<m_data[i]<<"\t";
    }

   }

