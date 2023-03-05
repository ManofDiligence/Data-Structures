#include <iostream>
#include <queue>
using namespace std;

void show_Queue(queue<int> queue)
{
    while(queue.front()!= 0)
    {
        cout<<queue.front()<<" ";
        queue.pop();

    }
}

int main(){
    queue<int> first_Queue;
    first_Queue.push(4);
    first_Queue.push(5);
    show_Queue(first_Queue);
    cout<<" "<<first_Queue.back();
}