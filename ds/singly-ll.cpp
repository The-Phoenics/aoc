#include <exception>
#include <initializer_list>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next = nullptr;
  Node(int n) : data(n){};
  ~Node() = default;
};

size_t get_size(Node *head) {
  if (head == nullptr)
    return 0;
  Node *tmp = head;
  size_t count = 0;
  while (tmp->next != nullptr) {
    count++;
    tmp = tmp->next;
  }
  return ++count;
}

void print(Node *head) {
  Node *tmp = head;
  while (tmp->next != nullptr) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << tmp->data << "\n";
}

void push_back(Node *head, int n) {
  Node *node = new Node(n);
  node->next = nullptr;
  Node *tmp = head;
  while (tmp->next != nullptr) {
    tmp = tmp->next;
  }
  tmp->next = node;
}

void push_back(Node *head, std::initializer_list<int> data) {
  Node *last_node = head;
  while (last_node->next != nullptr) {
    last_node = last_node->next;
  }

  for (int n : data) {
    Node *node = new Node(n);
    last_node->next = node;
    last_node = node;
  }
}

void insert_at(Node *head, int index, int data) {
  size_t size = get_size(head);
  if (index >= size) {
    cerr << "Index out of bound";
  }
  Node *new_node = new Node(data);
  Node *tmp = head;
  for (size_t i = 0; i < index - 1; i++) {
    tmp = tmp->next;
  }
  Node *next_node = tmp->next;
  tmp->next = new_node;
  new_node->next = next_node;
}

void push_front(Node *head, int data) {
  Node *new_node = new Node(data);
  Node *tmp = head;
  head = new_node;
  new_node->next = tmp;
}

void reverse(Node *head) {
  if (head->next == nullptr)
    return;
  
  Node *prev = head;
  Node *curr = head;
  Node *next = head->next;
  head->next = nullptr;

  while (next != nullptr) {
    next = next->next;
    prev = curr;
    curr = next;

    curr->next = prev;
  }
}

int main() {
  Node *head = new Node(0);
  push_back(head, {1, 2, 3, 4, 5, 6});
  print(head);
  insert_at(head, 2, 7);
  // push_front(head, 9);
  reverse(head);
  print(head);
  
}
