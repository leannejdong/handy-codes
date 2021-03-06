#include <iostream>
#include <array>

using std::cout;


struct node {
    int data;
    node* next;
};


int main()
{
    std::array<node,3> nodes;
    nodes[0].data = 5;
    nodes[1].data = 7;
    nodes[2].data = 4;
    nodes[1].next = &nodes[0];
    nodes[0].next = &nodes[2];
    nodes[2].next = &nodes[1];
    node *first_ptr = &nodes[1];
    node *current_ptr = first_ptr;

    for (;;) {
        cout << current_ptr->data << "\n";
        current_ptr = current_ptr->next;
        if (current_ptr == first_ptr) {
            break;
        }
    }
}


