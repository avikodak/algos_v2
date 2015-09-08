/****************************************************************************************************************************************************
 *  File Name                   : lediv.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\lediv.h
 *  Created on                  : Sep 6, 2015 :: 12:43:38 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LEDIV
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LEDIV_H_
#define LEDIV_H_

//Tested
int gcd(int a,int b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}

//Tested
void printResults(){
	int testCases,size,input,gcdResult;
	vector<int> userInput;
	cin >> testCases;
	bool flag = false;
	while(testCases--){
		cin >> size;
		userInput.clear();
		while(size--){
			cin >> input;
			userInput.push_back(input);
		}
		gcdResult = userInput[0];
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			gcdResult = gcd(gcdResult,userInput[counter]);
		}
		if(gcdResult == 1){
			cout << "-1" << endl;
		}else{
			flag = false;
			for(int counter = 2;counter*counter <= gcdResult;counter++){
				if(gcdResult%counter == 0){
					cout << counter << endl;
					flag = true;
					break;
				}
			}
			if(!flag){
				cout << gcdResult << endl;
			}
		}
	}
}

#endif /* LEDIV_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
