/****************************************************************************************************************************************************
 *  File Name                   : combinatoricselections.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\combinatoricselections.h
 *  Created on                  : Aug 17, 2015 :: 9:38:18 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=53
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
#define MILLION_MARKER 1000000

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef COMBINATORICSELECTIONS_H_
#define COMBINATORICSELECTIONS_H_

//Tested
//Ans : 4075
void getCombinationsUnderMillion(){
	unsigned int total = 0,currentSum;
	unsigned int innerCounter;
	vector<unsigned int> prevValues;
	vector<unsigned int> currentValues;
	prevValues.push_back(1);
	prevValues.push_back(2);
	prevValues.push_back(1);
	for(unsigned int outerCounter = 3;outerCounter <= 100;outerCounter++){
		currentValues.clear();
		currentValues.push_back(1);
		for(innerCounter = 0;innerCounter < prevValues.size()-1;innerCounter++){
			if(prevValues[innerCounter] == MILLION_MARKER || prevValues[innerCounter+1] == MILLION_MARKER){
				total++;
				currentValues.push_back(MILLION_MARKER);
			}else{
				currentSum = prevValues[innerCounter] + prevValues[innerCounter+1];
				if(currentSum < MILLION_MARKER){
					currentValues.push_back(currentSum);
				}else{
					total++;
					currentValues.push_back(MILLION_MARKER);
				}
			}
		}
		currentValues.push_back(1);
		prevValues = currentValues;
	}
	cout << total << endl;
}

#endif /* COMBINATORICSELECTIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
