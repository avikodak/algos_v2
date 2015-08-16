/****************************************************************************************************************************************************
 *  File Name                   : pentagonnumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pentagonnumbers.h
 *  Created on                  : Aug 16, 2015 :: 11:03:49 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=44
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

#ifndef PENTAGONNUMBERS_H_
#define PENTAGONNUMBERS_H_

//Tested
unsigned int getPentagonNumber(unsigned int userInput) {
	return ((userInput) * ((3 * userInput) - 1)) / 2;
}

//Tested
struct pentagonnumber {
	unsigned int firstValue;
	unsigned int secondValue;

	pentagonnumber(){}

	pentagonnumber(unsigned int firstValue,unsigned int secondValue){
		this->firstValue = firstValue;
		this->secondValue = secondValue;
	}
};

//Tested
//Ans : 5482660
void getMinimizedValue() {
	unsigned int outerCounter = 2, currentValue,currentSum;
	vector<unsigned int> values;
	values.push_back(1);
	map<unsigned int,bool> pentagonValueMap;
	map<unsigned int,bool>::iterator itToPentagonValueMap;
	pentagonValueMap.insert(pair<unsigned int,bool>(1,true));
	queue<pentagonnumber *> potentialSums;
	pentagonnumber *userInput,*firstValue;
	while (true) {
		currentValue = getPentagonNumber(outerCounter);
		firstValue = potentialSums.empty()?null:potentialSums.front();
		while(!potentialSums.empty()){
			userInput = potentialSums.front();
			currentSum = userInput->firstValue + userInput->secondValue;
			potentialSums.pop();
			if(currentSum == currentValue || pentagonValueMap.find(currentSum) != pentagonValueMap.end()){
				cout << userInput->secondValue - userInput->firstValue << endl;
				return;
			}else if(currentSum > currentValue){
				potentialSums.push(userInput);
			}
			if(userInput->firstValue == firstValue->firstValue && userInput->secondValue == firstValue->secondValue){
				break;
			}
		}
		for(unsigned int counter = 0;counter < values.size();counter++){
			if((pentagonValueMap.find(currentValue-values[counter])) != pentagonValueMap.end()){
				userInput = new pentagonnumber(values[counter],currentValue);
				potentialSums.push(userInput);
			}
		}
		pentagonValueMap.insert(pair<unsigned int,bool>(currentValue,true));
		values.push_back(currentValue);
		outerCounter++;
	}
}

#endif /* PENTAGONNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
