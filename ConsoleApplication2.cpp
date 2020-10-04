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
	string card_color[] = { "����", "���", "����", "�®�" };
	vector<vector<int>> cards(10, vector<int>(5));
	vector<int> hand_cards;
	vector<int> cardqueue;
	
	//�P�ժ�l��
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

	//��Q�ƵP
	for (int i = 0; i < 10; ++i){
		cardqueue = shuffle(); //�~���P�A��
		for (int j = 0; j < 5; ++j){ //�@��P5�i
			cards[i][j] = cardqueue[j];
		}
	}
	
	for (int i = 0; i < 10; ++i){
		std::cout << "��" << i + 1 << "���G";
		for (int j = 0; j < 5; ++j){
			std::cout << card_pair[cards[i][j]] << ' ';
		}
		std::cout << endl;
	}
	int card_compare_count=0;
	for (int k = 0; k <= 100000; ++k){
		if (k % 10000 == 0 && k != 0) std::cout << "�ثe������" << k << "��" << endl;
		cardqueue = shuffle(); //�~���P�A��
		for (int j = 0; j < 5; ++j){ //�@��P5�i
			//��J��e��P
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
				std::cout << endl << "�H����" << k << "�� ��e��P�G";
				for (int j = 0; j < 5; ++j){
					std::cout << card_pair[hand_cards[j]] << ' ';
				}
				std::cout << endl << "�ŦX��" << i + 1 << "���G " << count << " �i�A���o�ǵP�ŦX�G";
				for (int it : card_compare){
					std::cout << card_pair[it] << ' ';
				}
				std::cout << endl;
			}
			//else cout << "can not find" << endl;
		}
		hand_cards.clear();
	}

	std::cout << endl << "�`�@���G" << card_compare_count << "�ղŦX�W�L5�i" << endl;
	std::cout << "����ɶ��G" << (double)clock() / CLOCKS_PER_SEC << endl;
	std::system("pause");
	return 0;
}

