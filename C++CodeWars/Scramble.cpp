#include<string>
#include <map>

bool scramble(const std::string& s1, const std::string& s2) {
	std::map<char, int> ms1;
	std::map<char, int> ms2;
	for (char i : s1)
		++ms1[i];
	for (char i : s2)
		++ms2[i];
	for (char i : s2)
		if (ms1[i] < ms2[i])
			return false;
	return true;
}
/*
Завершите функцию scramble(str1, str2) который возвращает true если часть str1 символы можно переставлять в соответствии с str2, в противном случае возвращается false.

ПРИМЕЧАНИЯ:

Будут использоваться только строчные буквы (az). Никакие знаки препинания и цифры не будут включены..
Необходимо учитывать производительность.
Примеры
scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False
*/