#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Mountain {
public:
    /**
     * Empty mountain constructor.
     */
    Mountain()
    {
    }
    
    /**
     * Mountain constructor with params.
     * @param id Mountain ID.
     * @param name Mountain name.
     * @param height Mountain height.
     */
    Mountain(int id, string name, int height) {
        this->id = id;
        this->name = name;
        this->height = height;
    }
    
    /**
     * Mountain destructor.
     */
    ~Mountain()
    {
        cout << "Muntanya " << name << " destruïda!" << endl;
    }
    
    /* Consultants */
    /**
     * Height getter.
     * @return Mountain height.
     */
    int getHeight() const {
        return height;
    }
    
    /**
     * Name getter.
     * @return Mountain name.
     */
    string getName() const {
        return name;
    }

    /**
     * Id getter.
     * @return Mountain id.
     */
    int getId() const {
        return id;
    }
    
    /* Modifiers */
    
    /**
     * Height setter.
     * @param height Mountain height.
     */
    void setHeight(int height) {
        this->height = height;
    }

    /**
     * Id setter.
     * @param id Mountain id.
     */
    void setId(int id) {
        this->id = id;
    }

    /**
     * Name setter.
     * @param name Mountain name.
     */
    void setName(string name) {
        this->name = name;
    }
    
    /* Consultant */
    
    /**
     * Mountain object to string.
     * @return 
     */
    string to_String() const
    {
        stringstream ss;
        ss << "Id: " << getId() << endl;
        ss << "Name: " << getName() << endl;
        ss << "Height: " << getHeight() << endl;
        return ss.str();
    }
    
    /* Operators */
    bool operator!=(const Mountain& right) const {
        bool result = !(this->id == right.getId());
        return result;
    }

    bool operator<(const Mountain& right) const {
        return right.getId() > this->id;
    }

    bool operator<=(const Mountain& right) const {
        return !(this->id > right.getId());
    }

    bool operator==(const Mountain& right) const {
        bool result = this->id == right.getId();
        return result;
    }

    bool operator>(const Mountain& right) const {
        return right.getId() < this->id;
    }

    bool operator>=(const Mountain& right) const {
        return !(this->id < right.getId());
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Mountain& obj);
    
private:
    /* Attributes */
    int id, height;
    string name;
};

#endif /* MOUNTAIN_H */