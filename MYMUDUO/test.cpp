#include <vector>
#include <iostream>
using namespace std;
class A
{
	public:
		A()
		:event(16)
		{

		}
	using EventList = vector<char>;
	EventList event;
};

int main()
{
	A a;
	return 0;
}
