#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

class IntegerRange final {
public:
	const array<int, 2> mRange;
	IntegerRange(const int min, const int max) : mRange{ min,max } {}
	IntegerRange(const array<int,2>& range) : mRange{ range } {}

	class Iterator final {
	public:
		int operator*() const { return mValue; }
		Iterator operator++() { cerr << "Iterator[" << this << ":" << mValue << "]++" << endl;  const auto result = *this; mValue++; return result; }
		Iterator& operator++(int) { cerr << "Iterator[" << this << ":" << mValue << "]++pre" << endl;  mValue++; return *this; }
	private:
		friend class IntegerRange;
		Iterator(const int value) : mValue(value) { cerr << "Iterator[" << this << "](" << value << ")" << endl; }
		int mValue;
	};
	Iterator begin() const { return Iterator(mRange[0]); }
	Iterator end() const { return Iterator(mRange[1]+1); }
};

bool operator!=(const IntegerRange::Iterator& iterator0, const IntegerRange::Iterator& iterator1)
{
	cerr << "Iterator!=(" << &iterator0 << ":" << *iterator0 << ", " << &iterator1 << ":" << *iterator1 << ")" << endl;
	return *iterator0 != *iterator1;
}
int main(const int argc, const char* const argv[])
{
	const vector<string> args(argv, argv + argc);
	cout << "Start" << endl;
	cout << " Arguments:" << endl;
	const IntegerRange argRange{0,argc-1};
	for (const auto index : argRange) {
		cout << "  " << index << " : " << args[index] << endl;
	}
	for (const auto& arg : args) {
		cout << "  " << arg << endl;
	}
	cout << "End" << endl;
	return 0;
}
