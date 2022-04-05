#include "MaxItem.h"

// The class definition for StackType using templates 
class FullStack
// Exception class thrown by Push when stack is full.
{};

template<class ItemType>		
class DoubleStack {
public:
    DoubleStack();
    // Class constructor.
    bool IsFull() const;
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsEmpty() const;
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //       otherwise, newItem is at the top of the stack.
    void Print() const;
           
private:
    int small_top;
    int big_top;
    ItemType  items[MAX_ITEMS];	
};


template<class ItemType>
DoubleStack<ItemType>::DoubleStack()
{
  small_top = -1;
  big_top = MAX_ITEMS;
}

template<class ItemType>
bool DoubleStack<ItemType>::IsEmpty() const
{
  return (small_top == -1) && (big_top == MAX_ITEMS);
}

template<class ItemType>
bool DoubleStack<ItemType>::IsFull() const
{
  return (big_top - small_top == 1);
}

template<class ItemType>
void DoubleStack<ItemType>::Push(ItemType newItem)
{
  if (IsFull())
    throw FullStack();
  if (newItem <= 1000)
  {
    items[++small_top] = newItem;
  }
  else
  {
    items[--big_top] = newItem;
  }
}

template<class ItemType>
void DoubleStack<ItemType>::Print() const
{
  std::cout << "stack smaller or equal than 1000\n";
  for (int i = small_top; i >= 0; i--)
    std::cout << items[i] << " ";

  std::cout << "\nstack larger than 1000\n";
  for (int i = big_top; i < MAX_ITEMS; i++)
    std::cout << items[i] << " ";
  std::cout << "\n";
}
