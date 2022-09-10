/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"

int main(int argc, char* argv[])
{
  cout << "getValAtLoc is tested within the public functions" << endl;
	cout << "back and front's tests are involved in push and pop tests" << endl << endl;
	//push_back
	cout << "Test1: push_back, push to empty list" << endl;
	ULListStr test1;
	cout << "push 0 to the back" << endl;
	test1.push_back("0");
	cout << "	Test on back and front:" << endl;
	cout << "		Expected back: 0 \n		Output back: " << test1.back() << endl;
	cout << "		Expected front: 0 \n		Output front: " << test1.front() << endl;
	cout << "push 1 to the back" << endl;
	test1.push_back("1");
	cout << "Expected: 0 1" << endl;
	cout << "Output: " << test1.get(0) << " " << test1.get(1) << endl << endl;
	//push_back
	cout << "Test2: push_back, push to full list" << endl;
	ULListStr test2;
	cout << "Create a full list containing 0 to 9: ";
	for (int i=0; i<10; i++) {
		test2.push_back(to_string(i));
	}
	for (int i=0; i<10; i++) {
		cout << test2.get(i) << " ";
	}
	cout << endl;
	cout << "Total size is " << test2.size() << endl;
	cout << "push 10 to the back, create a new list" << endl;
	test2.push_back("10");
	cout << "Expected: 0 1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "Output: ";
	for (int i=0; i<11; i++) {
		cout << test2.get(i) << " ";
	}
	cout << endl;
	cout << "The new total size is " << test2.size() << endl << endl;
	//push_front
	cout << "Test3: push_front, push to empty list" << endl;
	ULListStr test3;
	cout << "push 0 to the front" << endl;
	test3.push_front("0");
	cout << "push 1 to the front" << endl;
	test3.push_front("1");
	cout << "Expected: 1 0" << endl;
	cout << "Output: " << test3.get(0) << " " << test3.get(1) << endl << endl;
	//push_front
		cout << "Test4: push_front, push to full list" << endl;
	ULListStr test4;
	cout << "Create a full list containing 0 to 9: ";
	for (int i=0; i<10; i++) {
		test4.push_back(to_string(i));
	}
	for (int i=0; i<10; i++) {
		cout << test4.get(i) << " ";
	}
	cout << endl;
	cout << "Total size is " << test4.size() << endl;
	cout << "push 10 to the front, create a new list" << endl;
	test4.push_front("10");
	cout << "Expected: 10 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "Output: ";
	for (int i=0; i<11; i++) {
		cout << test4.get(i) << " ";
	}
	cout << endl;
	cout << "The new total size is " << test4.size() << endl;
	cout << "	Test on back and front:" << endl;
	cout << "		Expected back: 9 \n		Output back: " << test4.back() << endl;
	cout << "		Expected front: 10 \n		Output front: " << test4.front() << endl << endl;
	//pop_back
	cout << "Test5: pop_back, normal case" << endl;
	cout << "Create a list containing 0 to 3" << endl;
	ULListStr test5;
	for (int i=0; i<4; i++) {
		test5.push_back(to_string(i));
	}
	cout << "Current list: ";
	for (int i=0; i<4; i++) {
		cout << test5.get(i) << " ";
	}
	cout << endl;
	cout << "pop on the back for once" << endl;
	test5.pop_back();
	cout << "Expected list: 0 1 2" << endl << "Output: ";
	for (int i=0; i<3; i++) {
		cout << test5.get(i) << " ";
	}
	cout << endl << "Total size: " << test5.size() << endl;
	cout << "	Test on back and front:" << endl;
	cout << "		Expected back: 2 \n		Output back: " << test5.back() << endl;
	cout << "		Expected front: 0 \n		Output front: " << test5.front() << endl << endl;
	//pop_back
	cout << "Test6: pop_back, pop on an empty list" << endl;
	ULListStr test6;
	cout << "Create an empty list" << endl;
	cout << "Current size: " << test6.size() << endl;
	cout << "pop on the back for once" << endl;
	test6.pop_back();
	cout << "Expected size: 0" << endl;
	cout << "Output size: " << test6.size() << endl << endl;
	//pop_back
	cout << "Test7: pop_back, pop on a non-empty list but end up empty" << endl;
	ULListStr test7;
	cout << "Create a list containing 0 and 1" << endl;
	test7.push_back("0");
	test7.push_back("1");
	cout << "Current list: " << test7.get(0) << " " << test7.get(1) << endl;
	cout << "pop on the back for once" << endl;
	test7.pop_back();
	cout << "Current list size: " << test7.size() << endl;
		cout << "Current list: " << test7.get(0) << endl;
	cout << "pop on the back for once" << endl;
	test7.pop_back();
	cout << "Expected list size: 0 (empty)" << endl;
	cout << "Output size: " << test7.size() << endl << endl;
	//pop_front
	cout << "Test8: pop_front, normal case" << endl;
	cout << "Create a list containing 0 to 3" << endl;
	ULListStr test8;
	for (int i=0; i<4; i++) {
		test8.push_back(to_string(i));
	}
	cout << "Current list: ";
	for (int i=0; i<4; i++) {
		cout << test8.get(i) << " ";
	}
	cout << endl;
	cout << "pop on the front for once" << endl;
	test8.pop_front();
	cout << "Expected list: 1 2 3" << endl << "Output: ";
	for (int i=0; i<3; i++) {
		cout << test8.get(i) << " ";
	}
	cout << endl << "Total size: " << test8.size() << endl << endl;
	//pop_front
	cout << "Test9: pop_front, pop on an empty list" << endl;
	ULListStr test9;
	cout << "Create an empty list" << endl;
	cout << "Current size: " << test9.size() << endl;
	cout << "pop on the back for once" << endl;
	test9.pop_back();
	cout << "Expected size: 0" << endl;
	cout << "Output size: " << test9.size() << endl << endl;
	//pop_front
	cout << "Test10: pop_front, pop on a non-empty list but end up empty" << endl;
	ULListStr test10;
	cout << "Create a list containing 0 and 1" << endl;
	test10.push_back("0");
	test10.push_back("1");
	cout << "Current list: " << test10.get(0) << " " << test10.get(1) << endl;
	cout << "pop on the front for once" << endl;
	test10.pop_front();
	cout << "Current list size: " << test10.size() << endl;
	cout << "Current list: " << test10.get(0) << endl;
	cout << "pop on the front for once" << endl;
	test10.pop_front();
	cout << "Expected list size: 0 (empty)" << endl;
	cout << "Output size: " << test10.size() << endl << endl;
	//all together
	cout << "Test0: push_back, push_front, pop_back, pop_front" << endl;
	ULListStr test0;
	cout << "Create an empty list" << endl;
	cout << "push_back Autumn" << endl;
	test0.push_back("Autumn");
	cout << "push_front Mid" << endl;
	test0.push_front("Mid");
	cout << "push_front Happy" << endl;
	test0.push_front("Happy");
	cout << "push_back Festival" << endl;
	test0.push_back("Festival");
	cout << "Output: ";
	for (int i=0; i<4; i++) {
		cout << test0.get(i) << " ";
	}
	cout << endl << "pop_front" << endl;
	test0.pop_front();
	cout << "pop_back" << endl;
	test0.pop_back();
	cout << "Output: ";
	for (int i=0; i<2; i++) {
		cout << test0.get(i) << " ";
	}
	cout << endl;

  return 0;
}
