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



Node* zipperLists(Node* head1, Node* head2) {
  // todo
  // two pointer for traverse the list
  Node* currentOne = head1, *currentTwo = head2;
  Node* newHead = currentOne;
  // two pointer for counting the length of two linked list
  Node* new1 = head1, *new2= head2;
  int lenOfList1=0, lenOfList2=0;
  while(new1!=nullptr)
  {
    new1=new1->next;
    lenOfList1++;
  }
  while(new2!=nullptr)
  {
    new2=new2->next;
    lenOfList2++;
  }
  // case 1: list1 length >= list2 length
  if(lenOfList1>=lenOfList2)
  {
    // when we done inserting the element of shorter list
    // we dont need to care about the remaining element of longer list
    // because it is connected as the start
      
      while(currentTwo!=nullptr)
      {
        Node* temp1 = currentOne->next;
        Node* temp2 = currentTwo->next;
        currentOne->next = currentTwo; 
        currentTwo->next = temp1;
        currentOne = temp1;
        currentTwo = temp2;
      }
  
  }
  // case 2: list2 length > list1 length
  else{
       while(currentOne!=nullptr)
      {
         Node* temp1 = currentOne->next;
          Node* temp2 = currentTwo->next;
          currentOne->next = currentTwo;
         // point to the remaining node of the longer list
         
         // same logic as list1's len>list2's len
         // but when visit to the tail of shorter list
         // just done inserting
         // instead of pointing to the tail of the shorter list (null)
         // since the longer list is still connected
         if(temp1!=nullptr) currentTwo->next = temp1;
         else break;
          currentOne = temp1;
          currentTwo = temp2;
      }
  }
  return newHead;
}
void print(Node* head)
{
  Node* current = head;
  while(current!=nullptr)
  {
    if(current->next==nullptr)
      cout<<current->val<<" ";
    else cout<<current->val<<" -> ";
    current=current->next;
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

Node x("x");
Node y("y");
Node z("z");
x.next = &y;
y.next = &z;
// x -> y -> z


// a -> x -> b -> y -> c -> z -> d -> e -> f
Node* head= zipperLists(&a, &x);
print(head);

Node s("s");
Node t("t");
s.next = &t;
// s -> t

Node one("1");
Node two("2");
Node three("3");
Node four("4");
one.next = &two;
two.next = &three;
three.next = &four;
// 1 -> 2 -> 3 -> 4

Node* newhead= zipperLists(&s, &one);;
print(newhead);
// s -> 1 -> t -> 2 -> 3 -> 4
}

int main()
{
    run();
}