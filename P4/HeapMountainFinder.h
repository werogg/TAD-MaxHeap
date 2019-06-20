#ifndef HEAPMOUNTAINFINDER_H
#define HEAPMOUNTAINFINDER_H

#include "MaxHeap.h"
#include "Mountain.h"
#include <fstream>

class HeapMountainFinder {
public:
    
    // BSTMountainFinder constructor without params
    HeapMountainFinder()
    {
        m_tree = new MaxHeap<Mountain>();
    }
    
    // BSTMountainFinder copy constructor
    HeapMountainFinder(const HeapMountainFinder &orig)
    {
        m_tree = orig.m_tree;
    }
    
    // BSTMountainFinder constructor with string filename as param
    HeapMountainFinder(string filename)
    {
        m_tree = new MaxHeap<Mountain>();
        appendMountains(filename);
    }
    
    // BSTMountainFinder destructor
    ~HeapMountainFinder()
    {
        delete m_tree; // Calls m_tree destructor
    }
    
    /**
     * Insert a mountain delegation.
     * @param id Mountain id.
     * @param name Mountain name.
     * @param height Mountain height.
     */
    void insertMountain(int id, string name, int height)
    {
        Mountain* mountain = new Mountain(id, name, height);
        m_tree->insert(id, mountain);
    }
    
    /**
     * Append mountains from file to tree.
     * @param filename The filename.
     */
    void appendMountains(string filename)
    {
        istringstream iss;
        int id, height;
        string id_str, height_str;
        string name, useless;
        ifstream myfile(filename);
        if (myfile.is_open()) {
            while (!myfile.eof()) {
                getline(myfile, id_str, ':');
                getline(myfile, useless, ':');
                getline(myfile, name, ':');
                getline(myfile, useless, ':');
                getline(myfile, height_str);
                iss = istringstream(id_str);
                iss >> id;
                iss = istringstream(height_str);
                iss >> height; 
                insertMountain(id, name, height);
            }
        }
        myfile.close();
    }
    
    /**
     * Search if mountain is on the tree.
     * @param element Mountain element to search.
     * @return True if Mountain element is in the tree.
     */
    void showMountain(const int& id)
    {
        if (m_tree->search(id).getId() != -1) {
            cout << m_tree->search(id).to_String() << endl;
        }
    }
    
    /**
     * Get maxheap depth
     * @return tree depth
     */
    int depth() {
        return m_tree->depth();
    }
    
    /**
     * Search how many mountains exists on a file.
     * @param filename The file name.
     * @return How many mountains exists in int.
     */
    int searchCounter(string filename) {
        int cnt = 0;
        istringstream iss;
        int id;
        string id_str;
        ifstream myfile(filename);
        if (myfile.is_open()) {
            while (!myfile.eof()) {
                getline(myfile, id_str);
                iss = istringstream(id_str);
                iss >> id;
                if (m_tree->search(id).getId() != -1) cnt++;
            }
        }
        myfile.close();
        
        return cnt;
    }
    
    /**
     * Print the full heap
     */
    void printHeap() {
        m_tree->printHeap();
    }
    
private:
    MaxHeap<Mountain>* m_tree;
};

#endif /* HEAPMOUNTAINFINDER_H */