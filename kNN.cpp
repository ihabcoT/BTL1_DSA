#include "kNN.hpp"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    Node* head = NULL;
    Node* tail = NULL;
    count = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void DoublyLinkedList<T>::push_back(T value) {
    Node* newNode = new Node(value);
    
    if (!head) head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    count++;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T value) {
    Node* newNode = new Node(value);
    
    if (!head) head = tail = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    count++;              
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, T value) {
    if (index < 0 || index > count) return;
    
    if (index == 0) push_front(value);
    else if (index == count) push_back(value);
    else {
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
    }
    
    count++;
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= count) throw std::out_of_range("out of range");

    T value;
    Node* tmp;

    // Remove the first node
    if (index == 0) {
        tmp = head;
        head = head->next;
        if (head != nullptr)
            head->previous = nullptr;
            else tail = nullptr;  // If the list becomes empty
    } 
    else if (index == count - 1) {
        // Remove the last node
        tmp = tail;
        tail = tail->previous;
        tail->next = nullptr;
    } 
    else {
        // Remove a node in the middle
        tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
    }

    value = tmp->data;
    delete tmp;
    count--;

    return value;
}

template<typename T>
T& DoublyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) throw std::out_of_range("out of range");
    // Give the data of the element at given index in the list
    
    Node* tmp = nullptr;
    // Start traversal from the head if index is closer to the head
    if (index < count / 2) {  
        tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }
    } 
    // Otherwise, start traversal from the tail
    else {  
        tmp = tail;
        for (int i = count - 1; i > index; --i) {
            tmp = tmp->previous;
        }
    }
    return tmp->data;
}

template<typename T>
int DoublyLinkedList<T>::length() const {
    return count;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while (count) {
        remove(0);
    }
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    Node* current = head;
    
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    
    cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::reverse() {
    Node* current = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    while (current) {
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        prevNode = current;
        current = nextNode;
    }
    tail = head;
    head = prevNode;
}

Dataset::Dataset(){
    List<List<int>*>* data = NULL;
}

Dataset::~Dataset(){
    
}

Dataset::Dataset(const Dataset& other) {


}
    
Dataset& Dataset::operator=(const Dataset& other) {
    
}
    
bool Dataset::loadFromCSV(const char* fileName) {
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        DoublyLinkedList<DoublyLinkedList<int>> *CSV_data = new DoublyLinkedList<DoublyLinkedList<int>>();
        while(getline(file,line))
        {
            stringstream lineStream(line);
            string cell;
            DoublyLinkedList<int> parsedRow;
            while(getline(lineStream,cell,','))
            {
                parsedRow.push_back(stoi(cell));
            }

            CSV_data->push_back(parsedRow);
        }
        data = CSV_data;
        return true;
    }
    return false;

}
    
void Dataset::printHead(int nRows = 5, int nCols = 5) const {

}
    
void Dataset::printTail(int nRows = 5, int nCols = 5) const {

}
    
void Dataset::getShape(int& nRows, int& nCols) const {

}
    
void Dataset::columns() const {

}
    
bool Dataset::drop(int axis = 0, int index = 0, std::string columns = "") {

}
    
Dataset Dataset::extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const {

}
    
List<List<int>*>* Dataset::getData() const {

}