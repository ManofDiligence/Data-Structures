#include <string>
#include <iostream>
using namespace std;
class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



Node* reverseList(Node* head) {
  // todo
  
  Node* current = head, *prev=NULL, *nextNode;// a
  // node a point to null( set it to be tail)
 
  while(current!=NULL)
  {
    
    nextNode = current->next;// node b
    current->next=prev;// a point to null
    prev = current;
    current = nextNode;
  }
  head = prev;
  return head;
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
    cout<<"\n";
}

void run() {
  Node a("a");
Node b("b");
Node c("c");
Node d("d");
Node e("e");
Node f("f");

a.next = &b;
b.next = &c;
c.next = &d;
d.next = &e;
e.next = &f;

// a -> b -> c -> d -> e -> f
print(&a);
reverseList(&a); // f -> e -> d -> c -> b -> a
print(&f);
}
int main()
{
    run();
}