/****************************************************************************************************************************************************
 *  File Name                   : priyankaandtoys.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\priyankaandtoys.h
 *  Created on                  : Jul 17, 2015 :: 1:43:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/priyanka-and-toys
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

#ifndef PRIYANKAANDTOYS_H_
#define PRIYANKAANDTOYS_H_

//Tested
void getMinimumUnits(){
	unsigned int inputSize,input;
	scanf("%u",&inputSize);
	vector<unsigned int> weights;
	for(unsigned int counter = 0;counter < inputSize;counter++){
		scanf("%u",&input);
		weights.push_back(input);
	}
	sort(weights.begin(),weights.end());
	unsigned int minimumUnits = 0;
	unsigned int outerCounter = 0,innerCounter;
	while(outerCounter < weights.size()){
		minimumUnits++;
        innerCounter = outerCounter;
		while(innerCounter < weights.size() && weights[outerCounter] <= weights[innerCounter] && weights[outerCounter]+4 >= weights[innerCounter]){
			innerCounter++;
		}
		outerCounter = innerCounter;
	}
	cout << minimumUnits;
}

#endif /* PRIYANKAANDTOYS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
