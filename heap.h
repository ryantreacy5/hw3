#ifndef HEAP_H
#define HEAP_H
#include <vector> // when run before it said that the declaration didnt work so i think i just have to include this
#include <functional>
#include <stdexcept>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument hasw
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()); // this initializes the heap

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  // heapify!!!!!!!!
  // need to add one to heapify up and one to heapify down
  // reminder.. heapify is maintaining the property of the heap after insertion or deletion
  // so we need to heapify up and down since were calling pop (remove) and push (insert)
  void down(size_t index);
  void up(size_t index);

  std::vector<T> heap; // stores the heap elements
  int mHeap; // this keeps the arity which is the number of children of each node
  PComparator comparator; // this object is for comparing the elements of the heap

};

// Add implementation of member functions here
// construct it
// so just have to do the usual template....> and then call the heap constructor with initial values
// see ur notes for the constrictor initialization stuff u wrote for the test
template <typename T, typename PComparator> 
Heap<T, PComparator>::Heap(int initial, PComparator pc) : mHeap(initial), comparator(pc) {} 


// destruct it hehe
// so just same template thing and then the squiggle
template <typename T, typename PComparator> 
Heap<T, PComparator>::~Heap() {}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  //  its returning the first element like index 0? because index 0 is the highest priority and we cant use priotirty_queue
  return heap[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty."); 
  }

  // ok pop removes the top item
  // need to swap the first element with the last element
  std::swap(heap[0], heap.back()); 
  // then we need to remove the last element
  heap.pop_back();
  // after its removed we need to check if its now empty or not and if its not we need to restruvture it to keep its form 
  // so we can do that with heapifying down
  if(!empty())
  {
    down(0);
  }

}

// forgot to implement push 
// void push(const T& item);
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& pushback){ // pushback is the val were adding
// need to just call push_back to add it to the end
  heap.push_back(pushback); // adds it as the last leaf
  // then again since we added something we need to heapify to make sure the structurw is the same
  up(heap.size()-1); // we need to use size-1 since the new element is in the las tpoisiton and we compare it moving up with its parents
}


// add implementation of empty functor template thing 
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const { // bool tells us if it is empty or not
  return heap.empty(); // just return
}

// need to add size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap.size();
}

// heapify up and heapify down are in the private helper functions and are necessary for our other functions to work
template <typename T, typename PComparator>
void Heap<T, PComparator>::up(size_t index){
  // we need to make sure there is a parent 
  while(index > 0)
  {
    // then we need to FIND the parent 
    //size_t otherIndex = index-1
    size_t otherIndex = (index-1)/mHeap;
    // then we have to check to see if the heap property was violated 
    // have to call the comparator function we made to check
    if(comparator(heap[index], heap[otherIndex]))
    {
      std::swap(heap[index], heap[otherIndex]); // depeneding on the if statement we swap 
      // and then we just change the index to its parent to go through the rest of the vector
      index = otherIndex;
    }
    else 
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::down(size_t index)
{
  while(true)
  {
    // we will assume the current node is the best (think like when were comparing numbers largest to greatest)
    size_t best = index;
    // then we loop over all the children
    for(int i = 1; i <= mHeap; ++i)
    {
      // as we loop we need to find the index of the i-th child
      // remember that child = number of children times the index of its parent plus the child were trying to get to
      size_t child = mHeap*index+i; 
      // then we check if the child has a higher or lower priority than the node at best
      //if(comparator(heap[child], heap[best]))
     // {
       // best = child;
      //}
      // also need to make sure the child is in the heap range
      if(child < heap.size() && comparator(heap[child], heap[best]))
      {
        best = child;
      }
    }
    // after the loop if best is still equal to the index then it was already good
    if(best == index)
    {
      break;
    }
    // if best ISNT still equaL to the index we need to restore the property by swapping and changing index to the new position of node
    std::swap(heap[index], heap[best]);
    index = best;
  }
}


#endif

