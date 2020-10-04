#include "stdafx.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct Account{
	string id;
	string name;
	double balance;
}acct = { "", "", 0 };

long F(int); //���h���j
int Fibonacci(int); //�O��ƦC
string reverseWords(string); //�r����� ������r
int GCD(int, int);//�̤j���]��
void printAcct(struct Account);

long F(int n){
	if (n == 1) return 1;
	return n * F(n - 1);
}

int Fibonacci(int n){
	if (n <= 2) return 1; // 1,1,2,3,5,8,13...
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

string reverseWords(string s){
	size_t front = 0;
	for (int i = 0; i <= s.length(); i++){
		if (i == s.length() || s[i] == ' '){
			reverse(&s[front], &s[i]);
			front = i + 1;
		}
	}
	return s;
}

int GCD(int a, int b){
	return (a%b == 0) ? (a%b == 1 ? 1 : b) : GCD(b, a%b);
}

void printAcct(Account acct){
	cout << acct.id << endl << acct.name << endl << acct.balance << endl;
}

void Test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (int i : v){
		cout << i << '\t';
	}
	cout << endl;

	struct Account acct;
	acct.id = "123-456";
	acct.name = "NICK";
	acct.balance = 1000;
	printAcct(acct);

	/*cout << "hello world!" << endl;
	cout << Fibonacci(7) << endl;*/

	//int UD{ 0 }, RL{ 0 };
	//
	//unordered_map<int, int> cache;
	//vector<int> answer;
	//vector<int> nums = {3,2,4};
	//int target = 6;
	//for (size_t i = 0; i < nums.size(); i++){
	//	int needed_num = target - nums[i];
	//	if (cache.find(needed_num) != cache.end()){
	//		answer.push_back(cache[needed_num]);
	//		answer.push_back(i);
	//	}
	//	else{
	//		cache.insert(make_pair(nums[i], i));
	//	}
	//}
	//cout << (4 & 0x1) << endl;
	//cout << ++RL << endl;

	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//for (int n : a){
	//	cout << n << endl;
	//}
	//cout << XPROC((2+3)) << endl;
	//my_class tclass(15);
	//tclass.do_something();
	//cout << tclass.get_a() << endl;
	//tclass.set_a(18);
	//cout << tclass.get_a() << endl;

	//cout << reverseWords("hello world !") << endl;
	//char s[] = "0113256";
	//char *p = s;

	//printf("%c", *p++);    //��X0 �ثe�� s[0] �|�b���0��N���ЦV���1 s[1]
	//printf("%c", *(p++));  //��X1 �ثe�� s[1] �|�b���1��N���ЦV���1 �ܬ�s[2]
	//printf("%c", (*p)++);  //��X1 �ثe�� s[2] ����s[2]�[1�As[2]�ܬ�1+1=2
	//printf("%c", *++p);    //��X3 �����N s[2] ����s[3]�A��X��
	//printf("%c", *(++p));  //��X2 �����N s[3] ����s[4]�A��X��
	//printf("%c", ++*p);    //��X3 �ثe�� s[4] ���Ns[4]�ȥ[1�A��X�As[4]�ܬ�2+1=3
	//printf("%c", ++(*p));  //��X4 �ثe�� s[4] ���Ns[4]�ȥ[1�A��X�As[4]�ܬ�3+1=4

	//printf("\n");
	//printf(s); //0123456 �q�W�P�_�Us[]��
}