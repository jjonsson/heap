#ifndef MINHEAP_H
#define MINHEAP_H

namespace jjonsson {

  //! A data structure that provides efficient insert and find-min operations.
  //! Requires that type T has a function operator< defined.
  template <typename T>
  class MinHeap {
  public:
    //! Default constructor.
    MinHeap();
  
    //! Destructor.
    ~MinHeap();
  
    //! Insert an element into the heap.
    void push(const T&);
  
    //! Find the minimum element in the heap.
    T peek();
  
    //! Delete the minimum element in the heap.
    void pop();
    
    //! Is the heap empty?
    bool empty();
  
  private:
    T* data_;
    int length_;
    int arraySize_;
    static const int INITIAL_SIZE = 1;
    void resize(int);
  };

};

#include "minheap-private.h"

#endif