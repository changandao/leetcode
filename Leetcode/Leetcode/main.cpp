//
//  main.cpp
//  Leetcode
//
//  Created by Sam Wang on 11.11.19.
//  Copyright © 2019 Sam Wang. All rights reserved.
//

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
//#include <stdio.h>
//#include <stdlib.h>
//#include<iostream>
//    using namespace std;
//    /* Link list Node */
//    struct Node
//    {
//        int data;
//        struct Node* next;
//    };
//    void append(struct Node** head_ref, struct Node **tail_ref,
//        int new_data)
//    {
//        struct Node* new_node = new Node;
//        new_node->data = new_data;
//        new_node->next = NULL;
//        if (*head_ref == NULL)
//            *head_ref = new_node;
//        else
//            (*tail_ref)->next = new_node;
//        *tail_ref = new_node;
//    }
//    /* Function to get the middle of the linked list*/
//    struct Node* deleteNode(struct Node *head, int);
//    void printList(Node *head)
//    {
//        while (head != NULL)
//        {
//            cout << head->data << " ";
//            head = head->next;
//        }
//    }
    /* Driver program to test above function*/
//    int main()
//    {
//        int T, i, n, l;
//        // TO BE REMOVED
//        for (int i = 0; i<2000; i++);
//        cin >> T;
//        while (T--){
//            struct Node *head = NULL, *tail = NULL;
//            cin >> n;
//            for (i = 1; i <= n; i++)
//            {
//                cin >> l;
//                append(&head, &tail, l);
//            }
//            int kk;
//            cin >> kk;
//            head = deleteNode(head, kk);
//            printList(head);
//        }
//        return 0;
//    }
//    /*Please note that it's Function problem i.e.
//    you need to write your solution in the form of Function(s) only.
//    Driver Code to call/invoke your function is mentioned above.*/
//
//    /* Link list Node
//    struct Node
//    {
//    int data;
//    Node* next;
//    };*/
//    /*You are required to complete below method*/
//    Node* deleteNode(Node *head, int x)
//    {
//        //Your code here
//        struct Node* tmp = NULL;
//        // newlist = head;
//        if (head->data == x)
//        {
//            tmp = head;
//            head = head->next;
//            delete tmp;
//            return head;
//        }
//
//        tmp = head->next;
//        while (tmp != NULL && tmp->data != x)
//        {
//            head = head->next;
//        }
//        if (tmp == NULL)
//            return head;
//        else{
//            head->next = tmp->next;
//            delete tmp;
//            return head;
//        }


//    }
//
//#include <iostream>
//using namespace std;
//int main(){
//    int n{0},a{0},b{0};
//    cin >> n;
//    for(int i = 0; i < n; i++)
//    {
//
//        cin >> a >>b;
//        cout << a+b<<endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main(){
//    int a{0},b{0};
//    while(1)
//    {
//        
//        scanf("%d%d", &a, &b);
//        if (a==0 && b==0) break;
//        else cout << a+b<< endl;
//                
//    }
//      
//    return 0;
//}

//#include <iostream>
//using namespace std;
//const int max_n = 100;
////int a[max_n];
//int main(){
//    int n{0}, pre_b{0};
//    while(1)
//    {
//        int b{0};
//        cin>> n;
//        if(n==0) break;
//        else{
//        for (int i =0; i < n; i++)
//        {
//
//            cin >> pre_b;
//            b += pre_b;
//        }
//        cout << b<<endl;
//        }
//    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int main(){
//    int n{0},m{0};
//    cin>> m;
//    for(int i=0; i < m; i++)
//    {
//        cin>> n;
//        int b{0}, pre_b{0};
//        for (int i =0; i < n; i++)
//        {
//            cin >> pre_b;
//            b += pre_b;
//        }
//        cout << b<< endl;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main(){
//    int n{0};
//    while(cin >> n)
//    {
//        int b{0}, pre_b{0};
//        for (int i =0; i < n; i++)
//        {
//            cin >> pre_b;
//            b += pre_b;
//        }
//        cout << b<< endl;
//    }
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int main(){
//    int pre_b{0};
//    int sum{0};
//    while(cin >> pre_b)
//    {
//
//        sum += pre_b;
//        if(cin.get()=='\n')
//        {
//            cout << sum<< endl;
//            sum = 0;
//        }
//    }
//    return 0;
//}

//#include <bits/stdc++.h>
//
////using namespace std;
//int main(){
//    int n{0};
//    string str;
//    vector<string> strs;
//    cin >> n;
//    strs.reserve(n);
//    for (int i = 0; i <n; i++)
//    {
//        cin >>str;
//        strs.push_back(str);
//    }
//    sort(strs.begin(), strs.end());
//
//    for (auto x : strs)
//        cout << x << " ";
//
//    return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//const int max_n = 100;
//int main(){
//    string str;
//    vector<string> strs;
//    strs.reserve(max_n);
//    while(cin>>str)
//    {
//        strs.push_back(str);
//        if(cin.get() == '\n')
//        {
//            sort(strs.begin(), strs.end());
//            for (auto x : strs)
//                cout << x << " ";
//            cout<<endl;
//            strs.clear();
//        }
//    }
//    return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//const int max_n = 100;

//
//template <class myType>
//void sort_and_output(vector<myType>& vec)
//{
//    sort(vec.begin(), vec.end());
//    for(auto it = vec.begin(); it!=vec.end();++it) {
//        if(std::next(it) == vec.end())
//            cout<<*it<<endl;
//        else
//            cout << *it << ",";
//    }
//}
//
//template <class myType>
//vector<myType> splitSentence(string& s, const string& delimiter)
//{
//    vector<myType> vec;
//    size_t pos=0;
//    myType token;
//    while ((pos = s.find(delimiter)) != std::string::npos) {
//        token = s.substr(0, pos);
//        vec.push_back(token);
//        s.erase(0, pos + delimiter.length());
//    }
//    vec.push_back(s);
//
//    return vec;
//}
//
//int main(){
//    vector<string> strs;
//    string s;
//    string delimiter(",");
//    size_t pos;
//    while(getline(cin, s))
//    {
//        strs = splitSentence<string>(s,",");
//        sort_and_output<string>(strs);
//
//    }
//    return 0;
//}


//        对输入的字符串进行排序后输出
//输入描述:
//
//多个测试用例，每个测试用例一行。
//每行通过,隔开，有n个字符，n＜100
//
//输出描述:
//
//对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
//a,c,bb
//        f,dddd
//nowcoder
//
//        a,bb,c
//dddd,f
//        nowcoder


//using namespace std;
//
//int main(){
//    string s;
//    while(getline(cin,s)){
//        vector<string> vec;
//        stringstream ss;
//        ss<<s;
//        string temp;
//        while(getline(ss,temp,',')){
//            vec.push_back(temp);
//        }
//        sort(vec.begin(),vec.end());
//        for(int i=0;i<vec.size();i++){
//            if(i!=vec.size()-1)
//                cout<<vec[i]<<",";
//            else
//                cout<<vec[i]<<endl;
//        }
//    }
//    return 0;
//}


// 写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//#include <bits/stdc++.h>
//using namespace std;
//
//std::string lower_string(const std::string& str)
//{
//    string lower;
//    transform(str.begin(), str.end(), std::back_inserter(lower), ::tolower);
//    return lower;
//}
//
//int main()
//{
//    string strs;
//    string str;
//    cin>>strs;
//    cin>>str;
//    strs = lower_string(strs);
//    str = lower_string(str);
//    size_t pos =-1;
//    int count = 0;
//    while(1)
//    {
//        pos = strs.find(str, pos+1);
//        if(pos != std::string::npos)
//            ++count;
//        else break;
//    }
//    cout<<count<<endl;
//}

//题目描述
//        计算字符串最后一个单词的长度，单词以空格隔开。
//输入描述:
//
//一行字符串，非空，长度小于5000。
//
//输出描述:
//
//整数N，最后一个单词的长度。
//
//示例1
//        输入
//        hello world
//
//        输出
//5



//#include <bits/stdc++.h>
//using namespace std;

//int main(){
//    string s;
//    getline(cin, s);
//    size_t pos = 0;
//    pos = s.find_last_of(" ");
//    cout<< s.substr(pos+1).length()<<endl;
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

const int max_n = 200;
int main()
{
    char ch;
    size_t count=0;
    while(cin>>ch)
    {
        if(cin.get() == '\n') break;
        if(ch>=0 && ch<=127)
            count++;
    }

    cout << count <<endl;
}