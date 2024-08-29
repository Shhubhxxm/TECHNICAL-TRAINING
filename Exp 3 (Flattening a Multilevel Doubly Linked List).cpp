#include <iostream>

// Definition for a Node.
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        flattenDFS(head);
        return head;
    }

private:
    Node* flattenDFS(Node* node) {
        Node* current = node;
        Node* last = nullptr;

        while (current) {
            Node* next = current->next;
            if (current->child) {
                Node* childTail = flattenDFS(current->child);

                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }
                last = childTail;
            } else {
                last = current;
            }
            current = next;
        }
        return last;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Example usage
int main() {
    // Creating the example multilevel doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->next->next->prev = head->next->next->child->next->next;

    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->child->next->prev = head->next->next->child->next->child;

    // Flattening the list
    Solution sol;
    head = sol.flatten(head);

    // Printing the flattened list
    printList(head);

    // Free allocated memory (not shown here for brevity)
    return 0;
}
