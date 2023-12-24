#pragma once
#include <string>
auto makeLooper(const std::string& str);
class LazyRepeater {
	std::string str;
	int pos{ 0 };
	public:
		LazyRepeater(std::string str) {
			this->str = str;
		}
		char operator() () {
			char ch = this->str[this->pos];
			this->pos++;
			this->pos %= this->str.length();
			return ch;
		}
};
auto makeLooper(const std::string& str){
	return LazyRepeater(str);
}

