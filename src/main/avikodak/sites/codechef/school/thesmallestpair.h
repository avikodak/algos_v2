/****************************************************************************************************************************************************
 *  File Name                   : thesmallestpair.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\thesmallestpair.h
 *  Created on                  : Aug 24, 2015 :: 8:28:11 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SMPAIR
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

#ifndef THESMALLESTPAIR_H_
#define THESMALLESTPAIR_H_

//Tested
void printTheSmallestPairSum(vector<unsigned int> userInput){
	unsigned int smallestSum = UINT_MAX,runningMin = userInput[userInput.size()-1];
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		smallestSum = min(smallestSum,userInput[counter]+runningMin);
		if(runningMin > userInput[counter]){
			runningMin = userInput[counter];
		}
	}
	cout << smallestSum << endl;
}

//Tested
void getSmallestPairs(){
	unsigned int testCases,input,inputSize;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	while(testCases--){
		userInput.clear();
		scanf("%u",&inputSize);
		while(inputSize--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		printTheSmallestPairSum(userInput);
	}
}

#endif /* THESMALLESTPAIR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
