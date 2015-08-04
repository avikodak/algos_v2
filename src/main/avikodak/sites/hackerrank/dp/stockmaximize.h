/****************************************************************************************************************************************************
 *  File Name                   : stockmaximize.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\dp\stockmaximize.h
 *  Created on                  : Aug 2, 2015 :: 11:48:42 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/stockmax
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

#ifndef STOCKMAXIMIZE_H_
#define STOCKMAXIMIZE_H_

//Tested
unsigned int getMaxStock(vector<unsigned int> userInput){
	unsigned int maxIndex = userInput.size()-1;
	unsigned int totalProfit = 0,cummulativeProfit = 0,shareCount = 0;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		if(userInput[counter] > userInput[maxIndex]){
			if(cummulativeProfit != 0){
				totalProfit += (shareCount*userInput[maxIndex]) - cummulativeProfit;
			}
			maxIndex = counter;
			cummulativeProfit = 0;
			shareCount = 0;
		}else{
			cummulativeProfit += userInput[counter];
			shareCount++;
		}
	}
	if(maxIndex != 0 && cummulativeProfit != 0){
		totalProfit += (shareCount*userInput[maxIndex]) - cummulativeProfit;
	}
	return totalProfit;
}

//Tested
void printMaximizeStocks(){
	unsigned int testCases,inputSize,input;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	while(testCases--){
		scanf("%u",&inputSize);
		userInput.clear();
		while(inputSize--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		cout << getMaxStock(userInput) << endl;
	}
}

#endif /* STOCKMAXIMIZE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
