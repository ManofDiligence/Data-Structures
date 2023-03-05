#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Node {
  public:
    string val;
    Node* next;

    Node(string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



vector<string> linkedListValues(Node* head) {
  // todo
  vector<string> arr;
  Node* node = head;
  while(node!=NULL)
  {
    arr.push_back(node->val);
    node = node->next;
  }
  return arr;
}
void print(Node* head)
{
    Node* current = head;
    while(current!=nullptr)
    {
        if(current->next==nullptr)
            cout<<current->val;
        else cout<<current->val<<"->";
        current = current->next;
    }
}

void run() {
Node a("a");
Node b("b");
Node c("c");
Node d("d");

a.next = &b;
b.next = &c;
c.next = &d;

// a -> b -> c -> d

linkedListValues(&a); // -> [ "a", "b", "c", "d" ]
print(&a);
}

int main()
{
    run();
}