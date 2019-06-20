#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <array>
#include "Node.h"
#include <iostream>
#include "Mountain.h"

using namespace std;

template <class Type>
class MaxHeap {
private:
    vector<Node<Type>*>* array;
    
public:
    /**
     * MaxHeap constructor
     */
    MaxHeap() {
        this->array = new vector<Node<Type>*>(); 
    }
    
    /**
     * MaxHeap copy constructor
     * @param orig MaxHeap object to copy
     */
    MaxHeap(const MaxHeap& orig) {
        this->array = new vector<Node<Type>*>(*orig.array);
    }
    
    virtual ~MaxHeap() {
        cout << "MaxHeap destruït" << endl;
    }
    
    /**
     * Get the current size
     * @return current size
     */
    int size() const {
        
        int i = 0;
        
        typename vector<Node<Type>*>::iterator it = array->begin();
        
        while (it != array->end()) {
            it++; i++;
        }
        
        return i;
    }
    
    /**
     * Is the maxheap empty
     * @return true if is empty
     */
    bool empty() const {
        return size() == 0;
    }
    
    /**
     * Insert an element to the maxheap
     * @param elem element to insert
     */
    void insert(const Type& elem) {
        // Implementation explained on the next method insert(int, Type*)
        Node<Type>* temp = new Node<Type>(elem);
        array->push_back(temp);
        
        int i = size()-1;
        
        Node<Type>* parent;
        Node<Type>* actual;
        while (i) {
            parent = array->at((i-1)/2);
            actual = array->at(i);
            if (parent->getValue() < actual->getValue()) {
                swap(array->at(i), array->at((i-1)/2));
            }
            
            i = ((i-1)/2);
        }
    }
    
    /**
     * Insert an element to the maxheap
     * @param key key of the element
     * @param elem element to be inserted
     */
    void insert(const int key, const Type* elem) {
        Node<Type>* temp = new Node<Type>(key, *elem);
        array->push_back(temp); // Push back on the vector
        
        int i = size()-1;
        
        Node<Type>* parent;
        Node<Type>* actual;
        
        // While i != 0
        while (i) {
            parent = array->at((i-1)/2); // Set parent node
            actual = array->at(i); // Set current node
            if (parent->getValue() < actual->getValue()) { // If parent < current
                swap(array->at(i), array->at((i-1)/2)); // Swap them on the vector
            }
            
            i = ((i-1)/2); // Increment i to the parent
        }
    }
    
    /**
     * Get max key on the heap
     * @return max key
     */
    int max() const {
        Node<Type>* temp = array->at(0); // Get first elem on the vector
        return temp->getKey();
    }
    
    /**
     * Get max value on the heap
     * @return max value on the heap
     */
    Node<Type>* maxValues() const {
        return array->at(0);
    }
    
    /**
     * Remove max element on the heap
     */
    void removeMax() {
        // If size > 1 we will swap the max value to the bottom of the tree
        if (size() > 1) swap(array->at(0), array->at(size()-1));
        
        array->pop_back(); // We pop the last element (the max)
        
        // In the case we have more than 2 elements
        if (size() > 2) {
            int i = 0;

            Node<Type>* left = array->at((2*i)+1); // Left node
            Node<Type>* right = array->at((2*i)+2); // Right node
            Node<Type>* actual = array->at(i); // Current node

            /**
             * While i doesn't exceed the max of the vector
             * and actual value < left value or actual value < right value
             */
            while(
                    ((2*i)+2 < size())
                    && ((actual->getValue() < left->getValue() || (actual->getValue() < right->getValue()))
                    )){

                if (left->getValue() > right->getValue()) {
                    // Swap current node for left one
                    swap(array->at(i), array->at((2*i)+1));
                    i = (2*i)+1; // i = left index
                } else {
                    // Swap current node for right one
                    swap(array->at(i), array->at((2*i)+2));
                    // i = right index
                    i = (2*i)+2;
                }

                // If we don't exceed the limit we reset the 3 new nodes
                if ((2*i)+2 < size()) {
                    right = array->at((2*i)+2);
                    left = array->at((2*i)+1);
                    actual = array->at(i);
                // If right exceed the limits, but left not, we reset only left and actual nodes
                } else if ((2*i)+1 < size()) {
                    left = array->at((2*i)+1);
                    actual = array->at(i);
                }
            }
        // In the case we only have 2 nodes
        } else if (size() == 2) {
            Node<Type>* first = array->at(0);
            Node<Type>* second = array->at(1);
            
            // We check if the first is bigger, if not we swap them
            if (first->getKey() < second->getKey()) {
                swap(array->at(0), array->at(1));
            }
        }
    }
    
    /**
     * Print the full heap
     */
    void printHeap() const {
        char opt;
        bool finalize = false;
        // We make a copy of the maxheap
        MaxHeap<Type> temp = MaxHeap<Type>(*this);
        
        int i = 0;
        
        /*
         * We iterate until the maxheap is empty or we call for finalize
         */
        while (!temp.empty() && !finalize) {
            cout << temp.maxValues()->getValue() << endl; // Print max
            i++;
            temp.removeMax(); // Remove max
            if (i%40 == 0) {
                do {
                    cout << "Vols continuar? (Y/N)" << endl;
                    cin >> opt;
                } while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n');
                
                if (opt == 'N' || opt == 'n') {
                    finalize = true;
                }
            }
        }
    }

    /**
     * Search an element on the heap
     * @param clau Key of the element
     * @return element with key != -1 if found
     */
    Type search (const int clau) const {
        MaxHeap<Type> temp = MaxHeap<Type>(*this); // Maxheap copy
        Mountain mnt = Mountain(-1, "error", -1); // Mountain to return for not found
        
        /*
         * We iterate while copy heap is not empty
         */
        while (!temp.empty()) {
            int key_to_compare = temp.maxValues()->getKey();
            if(key_to_compare == clau) { // We compare the keys
                return temp.maxValues()->getValue();
            }
            else temp.removeMax();
        }
        
        return mnt;
    }
    
    /**
     * Get the maxheap depth
     * @return depth
     */
    int depth() {
        int i = 0;
        int cnt = 0;
        
        // Left node will be allways the max depth
        while ((2*i)+1 < size()) {
            cnt++;
            i = (2*i)+1;
        }
        return cnt;
    }
};

#endif /* MAXHEAP_H */

