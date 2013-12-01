namespace jjonsson {

  template <typename T>
  MinHeap<T>::MinHeap()
    : data_(NULL), length_(0), arraySize_(INITIAL_SIZE)
  {
    data_ = new T[INITIAL_SIZE];
  }
  
  template <typename T>
  MinHeap<T>::~MinHeap() {
    delete [] data_;
    data_ = NULL;
  }
  
  template <typename T>
  void MinHeap<T>::push(const T& element) {
    // Double the array size if necessary.
    if (length_ >= arraySize_) {
      resize(arraySize_ * 2);
    }
  
    // Move elements down to create a spot for the new element while maintaining
    //   the heap invariant.
    int i;
    for (i = length_; i > 0;) {
      int parent = (i - 1) / 2;
      if (element < data_[parent]) {
        data_[i] = data_[parent];
        i = parent;
      }
      else break;
    }
    
    // Place the element in the spot;
    data_[i] = element;
  
    ++length_;
  }
  
  template <typename T>
  T MinHeap<T>::peek() {
    return data_[0];
  }
  
  template <typename T>
  bool MinHeap<T>::empty() {
    return length_ == 0;
  }
  
  template <typename T>
  void MinHeap<T>::pop() {
    // Halve the array size if necessary.
    if (length_ < arraySize_ / 2 && arraySize_ > INITIAL_SIZE) {
      resize(arraySize_ / 2);
    }
  
    // Conceptually, we move the bottom element to the top and reinforce the
    //   heap invariant.
    T element = data_[length_ - 1];
    int i;
    for (i = 0; (i * 2 + 1) < length_;) {
      // Children indices of i.
      int left = i * 2 + 1;
      int right = i * 2 + 2;
      
      // If there is only one child, test it.
      if (right >= length_) {
        if (data_[left] < element) {
          data_[i] = data_[left];
          i = left;
        }
        // We've found the spot to place element.
        break;
      }
      else {
        // Compare element against the smaller of the two children.
        int child = left;
        if (data_[2 * i + 2] < data_[2 * i + 1]) {
          child = right;
        }
      
        if (data_[child] < element) {
          data_[i] = data_[child];
          i = child;
        } else {
          // We've found the spot to place element.
          break;
        }
      }
    }
    // Place the element in the spot we just made.
    data_[i] = element;

    
    // Don't let the length go below 0.
    if (length_ > 0) {
      --length_;
    }
  }

  // Create a new array of the proper size, copy over the old data,
  //   and delete the old array.
  template <typename T>
  void MinHeap<T>::resize(int newSize) {
    T* newData = new T[newSize];
    
    for (int i = 0; i < length_; ++i) {
      newData[i] = data_[i];
    }
  
    delete [] data_;
  
    data_ = newData;
    arraySize_ = newSize;
  }

};