#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

static auto _____ = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

static const auto kSpeedUp = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution905 {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		length = A.size();
		int even_ind = 0;
		int odd_ind = length - 1;
		vector<int> newA (length, 0);
		for (int i = 0; i < length; i++)
		{
			if (A.at(i) % 2 == 0)
			{
				newA.at(even_ind) = A.at(i);
				even_ind++;
			}
			else{
				newA.at(odd_ind) = A.at(i);
				odd_ind--;
			}
		}
		return newA;
	}
	int length;
private:
	
};

class Solution832 {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int colums = A.size();
		length = A[0].size();
		
		for (int i = 0; i < colums; i++)
		{
			for (int j = 0; j < length/2; j++)
			{
				swap(A[i][j], A[i][length - j-1]);
				A[i][j] = 1^A[i][j];
				A[i][length - j - 1] = 1^A[i][length - j - 1];
			}
			if (length % 2 != 0)
			{
				A[i][length / 2] = 1^A[i][length / 2];
			}
		}
		return A;
	}
	int length;
};


class Solution561 {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		length = nums.size();
		int a = 0;
		for (int i = 0; i < length - 1;i += 2)
		{
			a += nums[i];
		}
		return a;
	}
	int length;
};

class Solution896 {
public:
	bool isMonotonic(vector<int>& A) {
		int length = A.size();
		bool flag_up = true, flag_down = true;
		for (int i = 0; i < length - 1; i++)
		{
			if (A[i] > A[i + 1]) flag_up = false;
			if (A[i] < A[i + 1]) flag_down = false;
		}
		return flag_down|flag_up;
	}
	
};


class Solution867 {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		
		int rows = A.size();
		int colums = A[0].size();
		vector<vector<int>> A_T(colums, vector<int>(rows, 0));
		for (int j = 0; j < colums; j++){
			for (int i = 0; i < rows; i++){
				A_T[j][i] = A[i][j];
			}
		}
		return A_T;
	}
};


class Solution566 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int rows = nums.size();
		int cols = nums[0].size();
		if (r*c != rows * cols) return nums;
		vector<vector<int>> res(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{ 
				int ori_i = (i * c + j) / cols;
				int ori_j = (i * c + j) % cols;
				res[i][j] = nums[ori_i][ori_j];

			}
		}
		return res;
	}
};


class Solution766 {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows-1; i++)
		{
			for (int j = 0; j < cols-1; j++)
			{
				if (matrix[i + 1][j + 1] != matrix[i][j]) return false;
				
			}
		}
		return true;
	}
};

class Solution283 {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				if (i != nums.size() - 1)
				{
					j = i + 1;
					while (nums[j] == 0&& j <nums.size())
						j++;
					swap(nums[j], nums[i]);

				}
				
			}
		}
	}
};


class Solution238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int length = nums.size();
		vector<int> temp(length, 0);
		int prd_all = 1;
		int num_zeros = 0;
		int zeros_ind = 0;
		for (int i = 0; i < length; i++)
		{
			if (nums[i] != 0)
				prd_all *= nums[i];
			else
			{
				num_zeros++;
				zeros_ind = i;
			}
		}
		if (num_zeros == 0)
		{
			for (int i = 0; i < length; i++)
				temp[i] = prd_all / nums[i];
		}
		else if (num_zeros == 1)
		{
			temp[zeros_ind] = prd_all;
			
		}
		return temp;
	}
};


class Solution169 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};


class Solution217 {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i-1] == nums[i]) return true;
		}
		return false;
	}
};


class Solution122 {
public:
	int maxProfit(vector<int>& prices) {
		int maxprofit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i - 1] < prices[i]) maxprofit += prices[i] - prices[i - 1];
		}
		return maxprofit;
	}
};


class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int minprice = prices[0];
		int maxprofit = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minprice) minprice = prices[i];
			else if (maxprofit < prices[i] - minprice) maxprofit = prices[i] - minprice;
		}

		return maxprofit;
	}
};


	// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
	using namespace std;
	/* Link list Node */
	struct Node
	{
		int data;
		struct Node* next;
	};
	void append(struct Node** head_ref, struct Node **tail_ref,
		int new_data)
	{
		struct Node* new_node = new Node;
		new_node->data = new_data;
		new_node->next = NULL;
		if (*head_ref == NULL)
			*head_ref = new_node;
		else
			(*tail_ref)->next = new_node;
		*tail_ref = new_node;
	}
	/* Function to get the middle of the linked list*/
	struct Node* deleteNode(struct Node *head, int);
	void printList(Node *head)
	{
		while (head != NULL)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}
	/* Driver program to test above function*/
	int main()
	{
		int T, i, n, l;
		// TO BE REMOVED
		for (int i = 0; i<2000; i++);
		cin >> T;
		while (T--){
			struct Node *head = NULL, *tail = NULL;
			cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> l;
				append(&head, &tail, l);
			}
			int kk;
			cin >> kk;
			head = deleteNode(head, kk);
			printList(head);
		}
		return 0;
	}
	/*Please note that it's Function problem i.e.
	you need to write your solution in the form of Function(s) only.
	Driver Code to call/invoke your function is mentioned above.*/

	/* Link list Node
	struct Node
	{
	int data;
	Node* next;
	};*/
	/*You are required to complete below method*/
	Node* deleteNode(Node *head, int x)
	{
		//Your code here
		struct Node* tmp = NULL;
		// newlist = head;
		if (head->data == x)
		{
			tmp = head;
			head = head->next;
			delete tmp;
			return head;
		}

		tmp = head->next;
		while (tmp != NULL && tmp->data != x)
		{
			head = head->next;
		}
		if (tmp == NULL)
			return head;
		else{
			head->next = tmp->next;
			delete tmp;
			return head;
		}


	}


