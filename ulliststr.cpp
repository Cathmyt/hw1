#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
	//Adds a new value to the back of the list
	size_ += 1;
	if (size_ == 1) { //when no existing list
		Item* new_Item = new Item(); //create a new list
		new_Item->last = 1;
		new_Item->val[0] = val;
		head_ = new_Item;
		tail_ = new_Item;
		return;
	}
	if (tail_->last==ARRSIZE) { //when current is full
		Item* new_Item = new Item(); //create a new list
		tail_->next = new_Item;
		new_Item->prev = tail_;
		tail_ = new_Item;
		new_Item->last = 1;
		new_Item->val[0] = val;
	}
	else {
		tail_->val[tail_->last] = val;
		tail_->last += 1;
	}
	return;
}

void ULListStr::push_front(const std::string& val)
{
	//Adds a new value to the front of the list.
	size_ += 1;
	if (size_ == 1) { //when no existing list
		Item* new_Item = new Item(); //create a new list
		new_Item->last = ARRSIZE;
		new_Item->first = ARRSIZE-1;
		new_Item->val[ARRSIZE-1] = val;
		head_ = new_Item;
		tail_ = new_Item;
		return;
	}
	if (head_->first==0) { //when no space
		Item* new_Item = new Item(); //create a new list
		head_->prev = new_Item;
		new_Item->next = head_;
		head_ = new_Item;
		new_Item->last = ARRSIZE;
		new_Item->first = ARRSIZE-1;
		new_Item->val[new_Item->first] = val;
	}
	else {
		head_->val[head_->first-1] = val;
		head_->first -= 1;
	}
	return;
}

void ULListStr::pop_back()
{
	//Removes a value from the back of the list
	if (size_ == 0) {} // when empty list
	else {
		size_ -= 1;
		tail_->last -= 1;
		if (tail_->first == tail_->last) {//when end up empty
			if (head_ == tail_) {//all list empty
				delete tail_;
				head_ = NULL; //update public head_, tail_
				tail_ = NULL;
			}
			else if (head_ != tail_) {//only tail empty
				Item* temp = tail_; //store empty tail_
				tail_ = tail_->prev;
				tail_->next = NULL;
				delete temp;
			}
		}
	}
	return;
}

void ULListStr::pop_front()
{
	//Removes a value from the front of the list
	if (size_ == 0) {} // when empty list
	else {
		size_ -= 1;
		head_->first += 1;
		if (tail_->first == tail_->last) {//when end up empty
			if (head_ == tail_) {//all list empty
				delete head_;
				head_ = NULL; //update public head_, tail_
				tail_ = NULL;
			}
			else if (head_ != tail_) {//only head empty
				Item* temp = head_; //store empty head_
				head_ = head_->next;
				head_->prev = NULL;
				delete temp;
			}
		}
	}
	return;
}

std::string const & ULListStr::back() const
{
	//Returns a const reference to the back element
	int loc_back = tail_->last - 1;
	return tail_->val[loc_back];
}

std::string const & ULListStr::front() const
{
	//Returns a const reference to the front element
	int loc_front = head_->first;
	return head_->val[loc_front];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	//Returns a pointer to the item at index, loc,
	//if loc is valid and NULL otherwise
	if (loc >= size_) {//loc invalid
		return NULL;
	}
	else if (loc < 0) {
		return NULL;
	}
	else {//loc valid
		Item* temp = head_;
		unsigned int size_list = temp->last - temp->first;
		while (loc+1 > size_list) {
			loc -= size_list;
			temp = temp->next;
			size_list = temp->last - temp->first;
		}
		return temp->first+loc+temp->val;
	}
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
