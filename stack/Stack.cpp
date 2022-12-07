#include <iostream>
using namespace std;

template <typename T>
class Node {
  public:
    Node* next;
    T value;
    Node(T v) { 
      value = v; 
      next = NULL;
    }
};

template <typename T>
class Stack {
  private:
    Node<T>* head = NULL;
    size_t size = 0;
  public:
    bool empty() {
      return head == NULL;
    }

    void push(T value) {
      Node<T>* newNode = new Node<T>(value);
      newNode->next = head;
      head = newNode;
      size += 1;
    }

    T top() {
      if (head == NULL) {
        throw "Stack is empty!";
      }
      return head->value;
    }

    void pop() {
      if (head == NULL) {
        throw "Stack is empty!";
      }
      Node<T>* newHead = head->next;
      delete head;
      head = newHead;
      size -= 1;
    }

    size_t getSize() {
      return size;
    }
};

int main() {
  Stack<int> stack;

  stack.push(1);
  stack.push(2);
  int top = stack.top();
  cout << top << endl;
  stack.pop();
  cout << stack.top() << endl;
  cout << stack.getSize() << endl;
  return 0;
}