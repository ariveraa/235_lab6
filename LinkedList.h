//
// Created by Adrian Rivera on 11/8/18.
//

#ifndef LAB6_LINKEDLIST_H
#define LAB6_LINKEDLIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename listElem>

class LinkedList {

public :

    struct Node {
        listElem value;
        Node * next;
        Node(listElem val) {
            value = val;
            next = NULL;
        }
    };

LinkedList(){
    head = NULL;
    length = 0;
}

~LinkedList(){

}
void insertHead(listElem value){
    if(!duplicateCheck(value)){
        return;
    }
    Node* temp = head;
    if (head == NULL){
        head = new Node(value);
        length++;
    }
    else{
        head = new Node(value);
        head -> next = temp;
        length++;
    }
}

void insertTail(listElem value){
    if(!duplicateCheck(value)){
        return;
    }
    Node* temp = head;
    if (head == NULL){
        head = new Node(value);
        length++;
    }

    else{
        for(int i = 0; i < length -1; i++){
            temp = temp-> next;
        }
        temp -> next = new Node(value);
        length++;
    }
}

void insertAfter(listElem value, listElem insertionNode){
    if(!duplicateCheck(value)){
        return;
    }
    Node* temp = head;
    bool check = false;
    for(int i = 0 ; i < length  ; i++){
        if(temp -> value == insertionNode){
            cout << "found it " << endl;
            Node* curr = temp;
            Node* next = temp ->next;
            temp = new Node(value);
            curr -> next = temp;
            temp ->next = next;
            check = true;
        }
        temp = temp -> next;
    }
    if (check){
        length++;
    }



}

void remove(listElem value){

}

void clear(){

}

listElem at(int index){

}

int size(){
    return length;
}

string toString(){
    stringstream ss;
    Node* temp = head;
    for(int i = 0; i < length; i ++){
       cout << temp -> value << endl;
        if (i < length ){
            ss <<  temp ->value << " ";
        }
        else{
            ss << temp ->value << endl;
        }
        temp = temp->next;
    }
    return ss.str();

}

bool duplicateCheck(listElem value){
    Node* temp = head;
    bool check = true;
    for(int i = 0; i < length - 1; i++) {
        if (temp->value == value) {
            cout << "no duplicates allowed" << endl;
            check = false;
        }
        temp = temp->next;
    }
    return check;
}

private :
    Node * head;
    int length;
};


#endif //LAB6_LINKEDLIST_H
