/****************************************************************************************************************************************************
 *  File Name                   : flowers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\flowers.h
 *  Created on                  : Jul 17, 2015 :: 10:57:07 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/flowers
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

#ifndef FLOWERS_H_
#define FLOWERS_H_

//Tested
bool sortFunc(unsigned int first,unsigned int second){
	return first > second;
}

//Tested
void findMinimumAmountMoney(){
	unsigned int inputSize,friendsCount,input;
	scanf("%u %u",&inputSize,&friendsCount);
	vector<unsigned int> userInput;
	for(unsigned int counter = 0;counter < inputSize;counter++){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	sort(userInput.begin(),userInput.end(),sortFunc);
	unsigned int friendLoopCount = 0;
	unsigned int minSum = 0;
	for(unsigned int counter = 0;counter < inputSize;counter++){
		minSum += (((friendLoopCount/friendsCount)+1)*userInput[counter]);
        friendLoopCount++;
	}
	cout << minSum << endl;
}

#endif /* FLOWERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
