#include <string>
#include <vector>
#include "CaesarCipher.h"

std::string CaesarCipher::movingShift(const std::string &s, int shift) {
	std::string a_b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string a_s = "abcdefghijklmnopqrstuvwxyz";
	std::string res = "";
	int pos{ 0 };
	for (char i : s) {
		pos = a_s.find(i);
		if (pos != std::string::npos)
			res += a_s[(pos + shift) % 26];
		else {
			pos = a_b.find(i);
			if (pos != std::string::npos)
				res += a_b[(pos + shift) % 26];
			else
				res += i;
		}
		shift++;
	}
	return res;
}
