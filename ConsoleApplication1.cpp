// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "test_class.h"
#include <string>
#include <unordered_map>
#include <vector>
#include "_1_1.h"
#include "vectorGuess.h"
#include "callbyVAR.h"
#include <fstream>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <random>
#define XPROC(x) x*x
#define target_count 100
using namespace std;
using namespace N;


int fibonacci(int);
bool fibon_elem(int, int &);
void swap(int &, int &);
void printf();
void bubble_sort(vector<int>& vec);
void display(vector<int>);



void display(vector<int> vec){
	for (int ix : vec){
		cout << ix << ' ';
	}
	cout << endl; 
}

bool fibon_elem(int pos, int &elem){
	if (pos <= 0 || pos > 1024){
		elem = 0; return false;
	}
	elem = fibonacci(pos);
	return true;
}

int fibonacci(int elem){
	if (elem == 1 || elem == 2) return 1;
	return fibonacci(elem - 1) + fibonacci(elem - 2);
}

void swap(int &a, int &b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void bubble_sort(vector<int>& vec, ofstream *ofil = 0){
	for (int ix = 0; ix < vec.size(); ++ix){
		for (int jx = ix + 1; jx < vec.size(); ++jx){
			if (vec[ix] > vec[jx]) {
				if (ofil!=0)
				(*ofil) << "about to call swap!" << "ix:" << ix << " jx:" << jx << '\t'
					<< "swapping: " << vec[ix] << "with " << vec[jx] << endl;
				//OK:change two element
				swap(vec[ix], vec[jx]);
				
			}
		}
	}
}

int plus_(int *getv){
	++(*getv);
	return *getv;
}

class card{
private:
	int weight;
	int num;
	string color;
public:
	card(int num, string color, int weight){ 
		card::num = num; 
		card::color = color; 
		card::weight = weight;
	}
	~card(){}
	void printcard_num_color();
	int getwight(){ return weight; }
	bool operator <(const card & other) const{
		return weight < other.weight;
	}
	bool operator >(const card & other) const{
		return weight > other.weight;
	}
};

void card::printcard_num_color(){
	cout << color << ':' << num << ':' << weight << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	double START, END, calc;
	

	string str = "You Need Give Me a number:";
	int num;
	cout << str;
	cin >> num;
	if (num <= 0 || num > 10) return 0;

	long long sum(1),divisor(1);
	for (int i = 1; i <= num; ++i){
		sum *= 52 - i + 1;
		divisor *= i;
	}

	cout << sum / divisor << endl;
	calc = 1.0 / (sum / divisor);

	ostringstream oss;
	oss << calc*calc;
	cout << oss.str() << endl;
	
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(0, 51);
	uniform_int_distribution<int> cardnum(1, 13);
	uniform_int_distribution<int> cardcolor(0, 3);
	START = clock();
	vector<int> total(52);
	for (int i = 0; i < target_count; ++i){
		total[dis(gen)]++;
	}

	int count(0); 
	for (int i : total){
		cout << "choose：" << ++count << '\t'<< i << endl;

	}
	END = clock();
	
	//char A[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
	//string COLOR[] = { "梅花", "方塊", "紅心", "黑桃" };

	//vector<vector<card>>cards(10, vector<card>());
	//for (int i = 0; i < 10; ++i){
	//	for (int j = 0; j < 5; j++){
	//		int n = cardnum(gen);
	//		int w = cardcolor(gen);
	//		cards[i].push_back(card(n, COLOR[w], n*(w+1)));
	//	}
	//}

	//for (int i = 0; i < 10; ++i){
	//	sort(cards[i].begin(), cards[i].end());
	//	for (int j = 0; j < 5; j++){
	//		cards[i][j].printcard_num_color();
	//	}
	//	cout << endl;
	//}
	//

	//int *pi = new int(0);
	//int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	//vector<int> vec(ia, ia + 8);
	//
	//cout << "vec before sort:";
	//display(vec);
	//ofstream ofil("value_data.txt");
	//bubble_sort(vec, &ofil);
	//sort(vec.begin(), vec.end());
	//reverse(vec.begin(), vec.end());
	//cout << "vec after  sort:";
	//display(vec);


	//_1_1();
	//vectorGuess();
	//vallbyVAR();
	//int value = 0;
	//int *fi_sum = &value;

	//int arrFib[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
	//vector<int> fibvec(arrFib, arrFib + 8);
	//for (;;){
	//	cout << "input something:";
	//	int something(0);
	//	cin >> something;

	//	if (fibon_elem(something, *fi_sum)){
	//		cout << *fi_sum << endl;
	//	}
	//	else{
	//		cout << "is wrong input!" << endl;
	//		break;
	//	}
	//}

	

	//int A = 1, B = 2;
	//int *p1 = &A, *p2 = &B;
	//cout << *p1 << ":" << p1 << '\t' << *p2 << ":" << p2 << endl;
	//swap(*p1, *p2);
	//cout << *p1 << ":" << p1 << '\t' << *p2 << ":" << p2 << endl;

	cout << "程式執行時間：" << (double)clock() / CLOCKS_PER_SEC << "S" << endl;
	cout << "程式運行時間：" << (END - START) / CLOCKS_PER_SEC << "S" << endl;
	system("pause");
	return 0;
}



