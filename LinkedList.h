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
    Node *temp = head;
    for(int i = 0; i < length; i++){
        head = head-> next;
        delete temp;
        temp = head;
    }
    length = 0;
    delete head;


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
    Node *temp = head;
    Node *curr = head;
    int index = -1;
    for(int i = 0; i < length ; i ++){
        if (temp ->value == value){
            index = i;
            curr = temp;
        }
        temp = temp->next;
    }
    if(index == 0 ){
        head = curr ->next;
        delete curr;
        length --;
    }
    if (index > 0){
        temp = head;
        for(int i = 0 ; i < index -1; i ++){
        temp = temp -> next;
        }
        temp->next = curr ->next;
        delete curr;
        length --;
    }

}

void clear(){
    Node *temp = head;
    for(int i = 0; i < length; i++){
        head = head-> next;
        delete temp;
        temp = head;
    }
    length = 0;

}

listElem at(int index){
    if ((index < 0) || (index >= length)) {
        cout << "index is out of bounds" << endl;
        throw out_of_range("index");
    }
    else {
        Node *temp = head;
        for (int i = 0; i < index ; i++) {
            temp = temp->next;
        }
        return temp->value;
    }

}

int size(){
    return length;
}

string toString(){
    stringstream ss;
    Node* temp = head;
    for(int i = 0; i < length; i ++){

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
    for(int i = 0; i < length ; i++) {
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
