/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL) {
		std::cout << "in NULL" << std::endl;
    return;
  }
	Node* temp = in;
	Node* temp2;
  if (in->value % 2 == 1) {
		odds = temp;
		temp2 = in->next;
		odds->next = NULL;
		split(temp2, odds->next, evens);
		//std::cout << "odd " << odds->value << std::endl;
		return;
  }
  else {
		evens = temp;
		temp2 = in->next;
    evens->next = NULL;
		split(temp2, odds, evens->next);
		//std::cout << "even " << evens->value << std::endl;
		return;
  }
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE