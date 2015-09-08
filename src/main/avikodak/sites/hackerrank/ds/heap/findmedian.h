/****************************************************************************************************************************************************
 *  File Name                   : findmedian.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\heap\findmedian.h
 *  Created on                  : Jul 14, 2015 :: 9:35:56 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef FINDMEDIAN_H_
#define FINDMEDIAN_H_

void maxHeapify(vector<int> &userInput,int index){
	while(index > 0 && userInput[index/2] < userInput[index]){
		swap(userInput[index/2],userInput[index]);
		index /= 2;
	}
}

void minHeapify(vector<int> &userInput,int index){
	while(index > 0 && userInput[index/2] > userInput[index]){
		swap(userInput[index/2],userInput[index]);
		index /= 2;
	}
}

void insertIntoMaxHeap(vector<int> &userInput,int value){
	userInput.push_back(value);
	maxHeapify(userInput,userInput.size()-1);
}

void insertIntoMinHeap(vector<int> &userInput,int value){
	userInput.push_back(value);
	minHeapify(userInput,userInput.size()-1);
}

#endif /* FINDMEDIAN_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
