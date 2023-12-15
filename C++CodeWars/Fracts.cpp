#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace Kata5 {
	
	unsigned long long gcd(unsigned long long n1, unsigned long long n2);
	
	string convertFrac(vector<vector<unsigned long long>> &lst) {
		unsigned long long allGCD = 1;
		for (vector<unsigned long long> i : lst)
			allGCD = (allGCD*i[1]) / gcd(allGCD, i[1]);
		string res = "";
		for (vector<unsigned long long> i : lst)
			res+="("+to_string(allGCD/i[1]*i[0])+","+to_string(allGCD)+")";
		return res;
	}

	unsigned long long gcd(unsigned long long n1, unsigned long long n2) {
		while (n1 != 0 and n2 != 0) {
			if (n1 > n2)
				n1 %= n2;
			else
				n2 %= n1;
		}
		return n1 > n2 ? n1 : n2;
	}
}
/*
����� �����������

� ��� ����� ������ ������������ ����� � ����

{ {numer_1, denom_1} , ... {numer_n, denom_n} }
or
[ [numer_1, denom_1] , ... [numer_n, denom_n] ]
or
[ (numer_1, denom_1) , ... (numer_n, denom_n) ]
��� ��� ����� �������� �������������� ������ �������. ��� ���������� �������� ��������� � ����:

(N_1, D) ... (N_n, D)
or
[ [N_1, D] ... [N_n, D] ]
or
[ (N_1', D) , ... (N_n, D) ]
or
{{N_1, D} ... {N_n, D}}
or
"(N_1, D) ... (N_n, D)"
� ����������� �� ����� (��. ������� ������), � ������� D ���������� �������� �

N_1/D == numer_1/denom_1 ... N_n/D == numer_n,/denom_n.
������:
convertFracs [(1, 2), (1, 3), (1, 4)] `shouldBe` [(6, 12), (4, 12), (3, 12)]
*/
