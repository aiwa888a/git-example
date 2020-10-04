#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <random>
using namespace std;
vector<int> shuffle();

vector<int> shuffle(){
	random_device rd;
	default_random_engine gen = default_random_engine(rd());

	vector<int> ret(52);
	for (int i = 0; i < 52; ++i) ret[i] = i;

	for (int i = 0, n = ret.size(); i < n; ++i){
		uniform_int_distribution<int> dis(i, 51);
		swap(ret[i], ret[dis(gen)]);
	}

	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	map<int, string> card_pair;
	string card_num[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	string card_color[] = { "梅花", "方塊", "紅心", "黑桃" };
	vector<vector<int>> cards(10, vector<int>(5));
	vector<int> hand_cards;
	vector<int> cardqueue;
	
	//牌組初始化
	int count = 0;
	for (int i = 0; i < 52; ++i){
		if (i % 13 == 0 && i != 0) count++;
		card_pair.insert(make_pair(i, card_color[count] + card_num[(i%13)]));
	}

	//int count_ = 0;
	//for (int i : cardqueue){
	//	cout << i << ' ';
	//	count_++;
	//}
	//cout <<endl << count_ << endl;

	//抽十副牌
	for (int i = 0; i < 10; ++i){
		cardqueue = shuffle(); //洗完牌再抽
		for (int j = 0; j < 5; ++j){ //一手牌5張
			cards[i][j] = cardqueue[j];
		}
	}
	
	for (int i = 0; i < 10; ++i){
		std::cout << "第" << i + 1 << "筆：";
		for (int j = 0; j < 5; ++j){
			std::cout << card_pair[cards[i][j]] << ' ';
		}
		std::cout << endl;
	}
	int card_compare_count=0;
	for (int k = 0; k <= 100000; ++k){
		if (k % 10000 == 0 && k != 0) std::cout << "目前執行到第" << k << "筆" << endl;
		cardqueue = shuffle(); //洗完牌再抽
		for (int j = 0; j < 5; ++j){ //一手牌5張
			//放入當前手牌
			hand_cards.push_back(cardqueue[j]);
		}
		for (int i = 0; i < 10; ++i){
			vector<int> card_compare;
			int count = 0;
			for (int j = 0; j < 5; ++j){
				vector<int>::iterator it = find(cards[i].begin(), cards[i].end(), hand_cards[j]);
				if (it != cards[i].end()){
					card_compare.push_back(it[0]);
					++count;
				}
				else{
					break;
				}
			}
			if (count >= 5){
				++card_compare_count;
				std::cout << endl << "隨機第" << k << "筆 當前手牌：";
				for (int j = 0; j < 5; ++j){
					std::cout << card_pair[hand_cards[j]] << ' ';
				}
				std::cout << endl << "符合第" << i + 1 << "筆： " << count << " 張，有這些牌符合：";
				for (int it : card_compare){
					std::cout << card_pair[it] << ' ';
				}
				std::cout << endl;
			}
			//else cout << "can not find" << endl;
		}
		hand_cards.clear();
	}

	std::cout << endl << "總共有：" << card_compare_count << "組符合超過5張" << endl;
	std::cout << "執行時間：" << (double)clock() / CLOCKS_PER_SEC << endl;
	std::system("pause");
	return 0;
}

