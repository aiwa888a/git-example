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

long F(int); //階層遞迴
int Fibonacci(int); //費氏數列
string reverseWords(string); //字串反轉 部分單字
int GCD(int, int);//最大公因數
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

	//printf("%c", *p++);    //輸出0 目前為 s[0] 會在顯示0後將指標向後推1 s[1]
	//printf("%c", *(p++));  //輸出1 目前為 s[1] 會在顯示1後將指標向後推1 變為s[2]
	//printf("%c", (*p)++);  //輸出1 目前為 s[2] 後對值s[2]加1，s[2]變為1+1=2
	//printf("%c", *++p);    //輸出3 直接將 s[2] 推至s[3]再輸出值
	//printf("%c", *(++p));  //輸出2 直接將 s[3] 推至s[4]再輸出值
	//printf("%c", ++*p);    //輸出3 目前為 s[4] 先將s[4]值加1再輸出，s[4]變為2+1=3
	//printf("%c", ++(*p));  //輸出4 目前為 s[4] 先將s[4]值加1再輸出，s[4]變為3+1=4

	//printf("\n");
	//printf(s); //0123456 從上判斷各s[]值
}