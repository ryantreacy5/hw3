#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
//class Stack // im so confused am i supposed to just implement it here 
// oh wait yes... when its template<typename T> you can implement right in the header file like in lab
// From guide: Important Note: To call a base class function that has the same name you cannot use this->member_func() 
//since both classes have that function and it will default to the derived version and lead to an infinite recursion. 
//Instead, scope the call (e.g. LList<T>::size()).
class Stack : private std::vector<T>
{
public:
    //Stack();
    Stack() : std::vector<T>() {}
   // ~Stack();
   ~Stack() {}
    //bool empty() const;
    bool empty() const{
      return std::vector<T>::empty();
    }
   // size_t size() const;
   size_t size() const{
    return std::vector<T>::size();
   }
    //void push(const T& item);
    void push(const T& item){
      std::vector<T>::push_back(item);
    }
   // void pop();  // throws std::underflow_error if empty
   void pop(){
    if(empty())
    {
      throw std::underflow_error("pop called on an empty stack");
    }
    std::vector<T>::pop_back();
   }
    //const T& top() const; // throws std::underflow_error if empty
    const T& top() const{
      if(empty())
      {
        throw std::underflow_error("top called on an epty stack");
      }
      //std::vector<T>::back(); // forgot return
      return std::vector<T>::back();
    }
    // Add other members only if necessary
};


#endif