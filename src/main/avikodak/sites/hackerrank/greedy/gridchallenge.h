/****************************************************************************************************************************************************
 *  File Name                   : gridchallenge.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\gridchallenge.h
 *  Created on                  : Jul 17, 2015 :: 2:43:17 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/grid-challenge
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

#ifndef GRIDCHALLENGE_H_
#define GRIDCHALLENGE_H_

//Tested
void isLexicographicallySorted(){
	unsigned int testCases,inputSize;
	scanf("%u",&testCases);
	vector<string> userInput;
	string input;
	bool flag;
	while(testCases--){
		userInput.clear();
		scanf("%u",&inputSize);
		while(inputSize--){
			cin >> input;
			sort(input.begin(),input.end());
			userInput.push_back(input);
		}
		flag = false;
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size();columnCounter++){
			for(unsigned int rowCounter = 0;rowCounter < userInput.size()-1;rowCounter++){
				if(userInput[rowCounter][columnCounter] > userInput[rowCounter+1][columnCounter]){
					printf("NO\n");
					flag = true;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			printf("YES\n");
		}
	}
}

#endif /* GRIDCHALLENGE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
