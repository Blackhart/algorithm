/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of
each node holding next and prev fields, it holds a field named both, which is an
XOR of the next node and the previous node. Implement an XOR linked list; it has
an add(element) which adds the element to the end, and a get(index) which
returns the node at index.

If using a language that has no pointers (such as Python), you can assume you
have access to get_pointer and dereference_pointer functions that converts
between nodes and memory addresses.
*/

#include <stdexcept>

using namespace std;

template <typename T> class XORLinkedList {
private:
  struct Node {
    T value;
    Node *both;
  } *head = nullptr;

public:
  void Add(T value) {
    Node *n = new Node();
    n->value = value;
    n->both = nullptr;

    if (!head)
      head = n;
    else {
      Node *current = head;
      Node *previous = nullptr;

      while (current) {
        Node *tmp = previous;
        previous = current;
        current = ((Node *)((uintptr_t)current->both ^ (uintptr_t)tmp));
      }

      current = n;
      current->both = (Node *)((uintptr_t)previous ^ (uintptr_t) nullptr);

      if (previous) {
        previous->both =
            (Node *)((uintptr_t)previous->both ^ (uintptr_t) nullptr);
        previous->both =
            (Node *)((uintptr_t)previous->both ^ (uintptr_t)current);
      }
    }
  }

  T Get(size_t index) {
    Node *current = head;
    Node *previous = nullptr;

    for (size_t i = 0; i < index && current; i++) {
      Node *tmp = previous;
      previous = current;
      current = ((Node *)((uintptr_t)current->both ^ (uintptr_t)tmp));
    }

    if (!current)
      throw new out_of_range("");

    return current->value;
  }
};