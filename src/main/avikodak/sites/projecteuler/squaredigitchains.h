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
