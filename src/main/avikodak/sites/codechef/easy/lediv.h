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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
