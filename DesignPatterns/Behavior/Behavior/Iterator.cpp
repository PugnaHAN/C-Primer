#include "Iterator.h"

using namespace std;

bool operator==(const Stack &l, const Stack &r)
{
	StackIter itl(l), itr(r);
	for (; itl(); ++itl, ++itr)
		if (*itl != *itr)
			break;
	return !itl() && !itr();
}

void testIterator()
{
	Stack s1;
	for (int i = 0; i < 5; ++i)
		s1.push(i);
	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();
	s5.pop();
	s4.push(2);
	s5.push(9);
	cout << "1 == 2 is " << (s1 == s2) << endl;
	cout << "1 == 3 is " << (s1 == s3) << endl;
	cout << "1 == 4 is " << (s1 == s4) << endl;
	cout << "1 == 5 is " << (s1 == s5) << endl;
}