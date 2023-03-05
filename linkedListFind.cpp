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



bool linkedListFind(Node* head, string target) {
  // todo
  if(head==NULL) return 0;
  if(head->val==target) return 1;
  else return linkedListFind(head->next, target);

}
void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}