#include "OList.h"

OList::OList(){
    head = nullptr;
}

OList::~OList(){
    Node *walker = head;
    Node *trailer = nullptr;
    while(walker != nullptr){
        trailer = walker;
        walker = walker -> getNext();
        delete trailer;
        trailer = nullptr;
    }
    delete walker;
    walker = nullptr;
}

/*
    Int Value - Value to be inserted into the List
    Function - Inserts the Value to the beginnging of the List
*/
void OList::insert(std::string value){
    Node *tmp = new Node(value);
    tmp -> setNext(head);
    head = tmp;
}

/*
    Returns all the Data within the Nodes as a string
*/
std::string OList::toString(){
    std::string result = "";
    Node *tmp = head;
    while(tmp != nullptr){
        result += tmp -> getData();
        tmp = tmp -> getNext();
        result += " --> ";
    }
    result += "nullptr";
    return result;
}

/*
    Std::string Value - the value that is being checked if it is in the List
    Returns True or False if the value is in or not in the List
*/
bool OList::contains(std::string value){
    Node *tmp = head;
    while(tmp != nullptr){
        if(tmp -> getData() == value)
            return true;
        tmp = tmp -> getNext();
    }
    return false;
}

/*
    Int Location - the index within the List (starting with 0)
    Returns the value at the index
*/
std::string OList::get(int location){
    Node *tmp = head;
    while(location > 0 && tmp != nullptr){
        tmp = tmp -> getNext();
        location --;
    }

    if(tmp == nullptr)
        return "Invalid Index";
    return tmp -> getData();
}

/*
    Int Location - index in the List
    Function - removes a Node within the index of the List
*/
void OList::remove(int location){
    Node *walker = head;
    Node *trailer = nullptr;
    while(location > 0 && walker != nullptr){
        trailer = walker;
        walker = walker -> getNext();
        location--;
    }

    if(walker == nullptr)
        return;
    
    if(location == 0 && trailer == nullptr){
        head = walker -> getNext();
    }
    else
        trailer -> setNext(walker -> getNext());

    delete walker;
}

/*
    Function reverses the order of the Nodes
*/
void OList::reverse(){
    Node *walker = head;
    Node *tmp;
    Node *trailer = nullptr;
    Node *follower = nullptr;
    Node *end = head;

    while(end != nullptr){
        end = end -> getNext();
    }

    while(walker != nullptr){
        tmp = walker -> getNext();
        if(trailer != nullptr){
            walker -> setNext(trailer);
            if(follower == nullptr)
                trailer -> setNext(end);
            else
                trailer -> setNext(follower);
        }
        follower = trailer;
        trailer = walker;
        walker = tmp;
    }

    head = trailer; 
    return;
}

Node* OList::getHead(){
    return head;
}