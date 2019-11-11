#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		length = A.size();
		int even_ind = 0;
		int odd_ind = length / 2;
		vector<int> newA;
		for (int i = 0; i < length; i++)
		{
			if (A.at(i) % 2 == 0)
			{
				newA.at(even_ind) = A.at(i);
				even_ind++;
			}
			else{
				newA.at(odd_ind) = A.at(i);
				odd_ind++;
			}
		}
		return newA;
	}
	int length;
private:


};

int main()
{
	Solution A;
	vector<int> B = { 1, 2, 34, 4, 5, 6, 67, 78, 9, 90, 10 };
	vector<int> newA = A.sortArrayByParity(B);
	copy(newA.begin(), newA.end(), ostream_iterator<int>(cout, "\n"));
}
