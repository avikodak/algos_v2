/****************************************************************************************************************************************************
 *  File Name                   : squaredigitchains.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\squaredigitchains.h
 *  Created on                  : Aug 19, 2015 :: 11:29:38 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=92
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

#ifndef SQUAREDIGITCHAINS_H_
#define SQUAREDIGITCHAINS_H_

//Tested
bool reachedGoal(unsigned long long int userInput,map<unsigned long long int,unsigned long long int> digitSquareMap,unsigned long long int target = 89){
	unsigned int outerCounter = userInput,innerCounter;
	while(outerCounter != 1 && outerCounter != 89){
		innerCounter = 0;
		while(outerCounter){
			innerCounter += digitSquareMap.find(outerCounter%10)->second;
			outerCounter /= 10;
		}
		outerCounter = innerCounter;
	}
	return outerCounter == target;
}

//Tested
map<unsigned long long int,unsigned long long int> getDigitSquareMap(){
	map<unsigned long long int,unsigned long long int> digitSquareMap;
	for(unsigned long long int counter = 0;counter < 10;counter++){
		digitSquareMap.insert(pair<unsigned long long int,unsigned long long int>(counter,counter*counter));
	}
	return digitSquareMap;
}

//Tested
//Ans : 8581146
void getTotalThatArriveTo89(){
	unsigned long long int total = 0;
	map<unsigned long long int,unsigned long long int> digitSquareMap = getDigitSquareMap();
	for(unsigned long long int counter = 2;counter < 10000000;counter++){
		if(reachedGoal(counter,digitSquareMap)){
			total++;
		}
	}
	cout << total << endl;
}

#endif /* SQUAREDIGITCHAINS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
