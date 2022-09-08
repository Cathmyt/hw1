#include "split.h"
#include <cstddef>
#include <iostream>


int main() {
	Node* odds = NULL;
	Node* evens = NULL;
	Node* first = new Node(1, NULL);
	Node* second = new Node(2, NULL);
	Node* third = new Node(3, NULL);
	Node* fourth = new Node(4, NULL);
	first->next = second;
	second->next = third;
	third->next = fourth;

	split(first, odds, evens);

	Node* next;
	Node* temp = odds;
	while (temp != NULL) {
		std::cout << "odd " << temp->value << std::endl;
		next =  temp->next;
		temp = next;
	}
	while (odds != NULL) {
		next = odds->next;
		delete odds;
		odds = next;
	}
	Node* tem = evens;
	while (tem != NULL) {
		std::cout << "even " << tem->value << std::endl;
		next = tem->next;
		tem = next;
	}
	while (evens != NULL) {
		next = evens->next;
		delete evens;
		evens = next;
	}
	return 0;
}
