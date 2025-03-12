#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


//void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
// ok so i have to track the tail pointets
// and in ordet to do that while keeping llpivot the same, i need to creatre a helper function
// (kind of a clue to do that in the test.cpp)
void llpivotHelperFunction(Node *&head, Node *&smaller, Node *&smallerTail, Node *&larger, Node *&largerTail, int pivot) // so that i dont confuse myself: smallerTail and largerTail are where i am tracking the tail pounter of the smaller and larger lists 
{
 // if(head == nullptr) // this is the base case! 
 // {
    //smaller = nullptr;
    //larger = nullptr;
   // return; // just return instead of return 0 since the function is void
 // }
 if(head==nullptr) // base case stays the same in the helper
 {
   // smaller=nullptr;
    //larger=nullptr;
    return;
 }
 // Node* newNode = head->next; // this creates a new node to store the 'next' node 
 // head->next = nullptr;
  Node* currentPtr = head;
  head = head->next; // this is all the same logic 

  // so, pivot is the pivot value its what we compare the rest to
  // so first we compare the value of head
  // smaller stores nodes smaller (or equal to) than the pivot value
  //if(head->val <= pivot)
  if(currentPtr->val <= pivot)
  {
  //if(smaller == nullptr)
    //{
     // smaller = head;
   // }
   // else
   // {
     // Node* temp = smaller;
      //while(temp->next != nullptr)
      //{
       // temp = temp->next;
     // }
     // temp->next = head;
   // }
   // head->next = smaller; // this makes head now point to the head of the smaller list
  // currentPtr->next = nullptr;
     if(smaller == nullptr)
        {
          smaller = currentPtr;
          smallerTail = currentPtr; // only thing we add in the helper function is the tailptrs
        }
      else
        {
         // Node* temp = smaller;
         // while(temp->next!=nullptr)
         // {
          //  temp = temp->next;
         // }
          //temp->next = currentPtr;
          smallerTail->next = currentPtr;
          smallerTail=currentPtr;
         }
        currentPtr->next = nullptr;
  // currentPtr->next = smaller;
   //smaller = head; // and then this part updates smaller to now point to the new head of the smaller list
   //temp->next = head;
  // smaller = currentPtr;
  } 
  else
  {
  //  if(larger == nullptr)
  //  {
    //  larger = head;
   // }
   // else{
   //   Node* temp = larger;
    //  while(temp->next != nullptr)
    //  {
       // temp = temp->next;
     // }
     // temp->next = head;
    //}
   // head->next = larger;
  // currentPtr->next = nullptr;
  if(larger == nullptr)
 {
   larger = currentPtr;
   largerTail = currentPtr;
  }
  else
  {
    largerTail->next = currentPtr;
    largerTail = currentPtr;
  }
 // else
 // {
 //  Node* temp = larger;
 //  while(temp->next != nullptr)
  // {
  //  temp = temp->next;
  //  }
   // temp->next = currentPtr;
   //}
  //currentPtr->next = larger;
   // larger = head; // same thing just with larger
   //larger = currentPtr;
   currentPtr->next = nullptr;
  }

  // but then we have to update head which just means move to the next value in the list
  //head = newNode;
  //head = nullptr; // we have to detatch head 
 // head = newNode;
  // call recursively
  //llpivot(head, smaller, larger, pivot); OHHH you werent calling the new newNode you were calling head
  llpivotHelperFunction(head, smaller, smallerTail, larger, largerTail, pivot);  // ok so where we originally recursively called llpivot, lets recursivley call the helper 

  //if(head==nullptr)
 // {
   // head==nullptr;
  //}


}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) // NOW we define llpivot in a much simpler way
{
  // set them to nullptr HERE!! 
  smaller=nullptr;
  larger=nullptr; // ah!!!! this is why it wasnt working originally when i would take smaller and larger = nullptr out of the base case of llpivot
  Node* smallerTail = nullptr;
  Node* largerTail = nullptr; // set everything to nullptr

  llpivotHelperFunction(head, smaller, smallerTail, larger, largerTail, pivot); // call llpivot helper function again

  head = nullptr; // detatch from the original list!
}