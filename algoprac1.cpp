// algoprac1.cpp : Algo that finds all possible combinations of numbers from 1-9 in that order with a plus or minus or nothing (joined) to give  value of 100.
// Ex: 123+45-6+8-9 = 100
// 0 -> NO SPACE 1 -> PLUS 2 -> MINUS
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double checkfor(int spaces[8]) {		//function checks value obtained for given combination of spaces
	double ans = 0;
	char spacesCh[8];
	if (spaces[0] != 0)
		ans++;
	else

	int i = 0;

	for (int i = 0; i < 8; i++) {
		if (spaces[i] == 0) {						//only really accessed if the first space(1_2) is nothing
			int re = 0;
			for (int j = i + 1; spaces[j] == 0; j++)			//for loop counts number of attached digits (no spaces) at and after position i
				re++;
			for (int j = re; j > 0; j--) {						//slightly different from other conditions due to '1'
				double temp = (i + 1 + (re - j))*pow(10, i + j);	//Ex: 123 -> (0 + 1 + 0) * 10^2 + (0 + 1 + 1) * 10^1 + (0 + 1 + 2) * 10^0
					ans += temp;
				//cout << temp << endl;
			}			
			i = i + (re);
		}
		else if (spaces[i] == 1) {
			if (spaces[i + 1] != 0)
				ans += (i + 2);							//direct correspondence between position of space and number value => space[i] lies between i+1 and i+2 
			else {
				int re = 0;
				for (int j = i + 1; spaces[j] == 0; j++)
					re++;
				for (int j = re; j >= 0; j--) {
					double temp = (i + 2 + (re - j))*pow(10, j);
					ans += temp;
					//cout << temp << endl;
				}
				i = i + (re);
			}
		}
		else if (spaces[i] == 2) {
			if (spaces[i + 1] != 0)
				ans -= (i + 2);
			else {
				int re = 0;
				for (int j = i + 1; spaces[j] == 0; j++)
					re++;
				for (int j = re; j >= 0; j--) {
					double temp = (i + 2 + (re - j))*pow(10, j);
					ans -= temp;
					//cout << temp << endl;
				}
				i = i + (re);
				re = 1;
			}
		}
		else {
			cout << "Invalid space element...";
			return 0;
		}
		//cout << ans << " " << i <<  endl;
	}
	if (ans == 100) {
		for (int i = 0; i < 8; i++) {
			if (spaces[i] == 0)
				spacesCh[i] = '\0';
			else if (spaces[i] == 1)
				spacesCh[i] = '+';
			else
				spacesCh[i] = '-';
		}
		printf("1%c2%c3%c4%c5%c6%c7%c8%c9\n", spacesCh[0], spacesCh[1], spacesCh[2], spacesCh[3], spacesCh[4], spacesCh[5], spacesCh[6], spacesCh[7]);
	}
	return ans;
}
int findallposs(int (&spaces)[8], int n = 0) {
	if (n > 7)
		return 0;
	spaces[n] = 0;
	findallposs(spaces, n + 1);
	checkfor(spaces);
	spaces[n] = 1;
	findallposs(spaces, n + 1);
	checkfor(spaces);
	spaces[n] = 2;
	findallposs(spaces, n + 1);
	checkfor(spaces);
	//cout << spaces[0] << endl;
	return 0;
}
using namespace std;
int main(){
	int spaces[8] = { 0,0,0,0,0,0,0,0 };
	findallposs(spaces);
	return 0;
}

