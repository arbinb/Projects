#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include <ostream>
#include <string>
#include <sstream>
#include "math.h"
#include "algorithm"

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    this-> clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	if(source.head == nullptr) {
		return;
	}
	Node* copy = source.head;
	while (copy != nullptr) {
		this->insert(copy->data.id, copy->data.year, copy->data.month, copy->data.temperature);
		copy = copy->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	if (this != &source) {
		this->clear();
		Node* copy = source.head;
		while (copy != nullptr) {
			this->insert(copy->data.id, copy->data.year, copy->data.month, copy->data.temperature);
			copy = copy->next;
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* newNode = new Node(location, year, month, temperature);
	Node* cur = head;
	Node* specialNode = head;
	bool foundSpot = false;
	int stepsAwayFromHead = 0;
	while (!foundSpot) {
        if (head == nullptr && tail == nullptr) {
            foundSpot = true;
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;// only node is both head and tail
        }
        else if (newNode->data.operator<(cur->data)) {
            if (cur == head) {
                newNode->next = head;
                head = newNode;
                foundSpot = true;
            }
            else {
                foundSpot = true;
                for (int i = 1; i < stepsAwayFromHead; ++i) {
                    specialNode = specialNode->next;
                }
                newNode->next = specialNode->next;
                specialNode->next = newNode;
            }
        }
        else if (cur->next == nullptr) {
            foundSpot = true;
            newNode->next = nullptr;
            cur->next = newNode;
            tail = newNode;
        }
        else {
            stepsAwayFromHead += 1;
            cur=cur->next;
        }
	}
}

vector<double> LinkedList::sortTemps(std::string location, int year_start, int year_end) {
    vector<double> temps;
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data.id == location) {
            if (cur->data.year >= year_start && cur->data.year <= year_end) {
                temps.push_back(cur->data.temperature);
            }
        }
        cur = cur->next;
    }
    if (!temps.empty()) {
        sort(temps.begin(), temps.end());
    }
    return temps;
}

void LinkedList::clear() {
	Node* temp;
	while (head != nullptr) {
		temp = head->next;
		delete(head);
		head = temp;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	return this->head;// Implement this function it will be used to help grade other functions
}

string LinkedList::print() const {
	string outputString;
	ostringstream os;
	Node* cur = head;
	while (cur != nullptr) {
        os << cur->data.id;
        os << " ";
		os << cur->data.year;
		os << " ";
		os << cur->data.month;
		os << " ";
		os << cur->data.temperature;
		os << endl;
		cur = cur->next;
	}
	outputString = os.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
