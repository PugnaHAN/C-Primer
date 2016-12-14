#include "RespChain.h"

using namespace std;

void testRespChain()
{
	srand(time(0));                 // 1
	Primitive seven(7);             // |
	Primitive six(6, &seven);       // +-- 2
	Composite three(3, &six);       // |   |
	three.add(&six);
	three.add(&seven);              // |   +-- 4 5
	Primitive five(5, &three);      // |
	Primitive four(4, &five);       // +-- 3
	Composite two(2, &four);        // |   |
	two.add(&four);
	two.add(&five);                 // |   +-- 6 7
	Composite one(1, &two);         // |
	Primitive nine(9, &one);        // +-- 8 9
	Primitive eight(8, &nine);
	one.add(&two);
	one.add(&three);
	one.add(&eight);
	one.add(&nine);
	seven.setNext(&eight);
	cout << "traverse: ";
	one.traverse();
	cout << '\n';
	for (int i = 0; i < 8; i++)
	{
		one.volunteer();
		cout << '\n';
	}
}