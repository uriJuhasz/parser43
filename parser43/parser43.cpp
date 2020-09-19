#include "util/IntegerRange.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(const int argc, const char* const argv[])
{
	const vector<string> args(argv, argv + argc);
	cout << "Start" << endl;
	cout << " Arguments:" << endl;
	const IntegerRange argRange{0,argc-1};
	for (const auto index : argRange) {
		cout << "  " << index << " : " << args[index] << endl;
	}
	cout << "End" << endl;
	return 0;
}
