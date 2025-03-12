#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************

template <typename Comp> // remember: this syntax is generic so its like a blueprint for a function that can work with any data type! 
Node* llfilter(Node* head, Comp pred)
{
    //*********************************************
    // Provide your implementation below
    //*********************************************
  // from video: you could use head or tail recursion but would be harder unless you used a helper function
  // most straightforward way: recurse down the list passing in head or next and each parameter is its own pointer - each recursion gets its own head pointer
  // think going back and "oh youre not going to be filtered out so i can return some information primarily your address back through until someone can use it"
  // just recurse on and on until you get to base case
  // return a pointer - an address in case someone needs it?
  // if someone frees themself - pass back whoever came after - who is still alive - either yours or the item after you

  if(head == nullptr) // base case obv
  {
    return nullptr; // returns null since is not void
  }
  // pred is: predicate object implementing bool operator() (int value) which is a functor i think - that returns true
  // if a node SHOULD be removed

  // so we have to call pred like a function because its an object that has overloaded operator() to act like a function!!! aka... a functor
  if(pred(head->val)) // so this if statment is true if the value of the head (current item) needs to be removed
  {
    Node* newNode = head->next; // so just like in pivot, this is creating a new node to store the value of the next node
    delete head; // this deletes head since we know it needs to be deleted since its in the if statement
    // and then just recur i think?
    return llfilter(newNode, pred);
  }
  else
  {
    // this handles the case in which the item doesnt need to be deleted
    // so we just call the recursion? on the next node? and return the current value?
    //llfilter(head->next, pred); oh wait dur this needs to be caught by a val
    head->next = llfilter(head->next, pred);
    return head;
  }
  


}

#endif
