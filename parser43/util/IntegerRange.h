#pragma once
#include <array>

class IntegerRange final {
public:
	const std::array<int, 2> mRange;
	IntegerRange(const int min, const int max) : mRange{ min,max } {}
	IntegerRange(const std::array<int, 2>& range) : mRange{ range } {}

	class Iterator final {
	public:
		int operator*() const { return mValue; }
		Iterator operator++() { const auto result = *this; mValue++; return result; }
		Iterator& operator++(int) { mValue++; return *this; }
	private:
		friend class IntegerRange;
		Iterator(const int value) : mValue(value) {}
		int mValue;
	};
	Iterator begin() const { return Iterator(mRange[0]); }
	Iterator end() const { return Iterator(mRange[1] + 1); }
};

bool operator!=(const IntegerRange::Iterator& iterator0, const IntegerRange::Iterator& iterator1)
{
	return *iterator0 != *iterator1;
}
