#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <sstream>
using namespace std;

template <class Type>
class Node {
public:
    
    /* Constructors i Destructors */
    
    /**
     * Node copy constructor.
     * @param orig Node to be copied.
     */
    Node(Node& orig)
    {
        value = orig.getValue();
        key = orig.getKey();
        
        cout << "Node copiat!" << endl;
    }
    
    /**
     * Node constructor with data.
     * @param data Data to be saved.
     */
    Node(const Type& data)
    {
        value = data;
    }
    
    /**
     * Node constructor with multi params.
     * @param id Node id.
     * @param data Node data.
     */
    Node(const int& id, const Type& data)
    {
        value = data;
        key = id;
    }
    
    /**
     * Node destructor.
     */
    virtual ~Node()
    {
        cout << "Node "<< key << " eliminat!" << endl;
    }
    
    /* Consultors */
    /**
     * Node value setter
     * @param newValue New value to be setted
     */
    void setValue(const Type& newValue)
    {
        value = newValue;
    }
    
    /**
     * Node key setter
     * @param newKey New key to be setted
     */
    void setKey(int newKey)
    {
        key = newKey;
    }
    
    /* Consultants */
    
    /**
     * Node key getter
     * @return The Node key
     */
    const int getKey() const
    {
        return key;
    }
    
    /**
     * Node value getter
     * @return The value of Node
     */
    const Type& getValue() const
    {
        return value;
    }
    
    string to_String() const
    {
        stringstream ss;
        ss << "Id: " << getKey() << endl;
        return ss.str();
    }
    
private:
    /* Atributtes */
    int key;
    Type value;
};

#endif /* NODE_H */