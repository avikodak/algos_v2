/****************************************************************************************************************************************************
 *  File Name                   : digitfactorialchains.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitfactorialchains.h
 *  Created on                  : Aug 19, 2015 :: 11:43:17 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=74
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

#ifndef DIGITFACTORIALCHAINS_H_
#define DIGITFACTORIALCHAINS_H_

//Tested
unsigned long long int factorial(unsigned long long int userInput){
	return userInput <= 1?1:userInput*factorial(userInput-1);
}

//Tested
map<unsigned long long int,unsigned long long int> getDigitFactorialMap(){
	map<unsigned long long int,unsigned long long int> digitFactorialMap;
	for(unsigned long long int counter = 0;counter < 10;counter++){
		digitFactorialMap.insert(pair<unsigned long long int,unsigned long long int>(counter,factorial(counter)));
	}

	return digitFactorialMap;
}

//Tested
unsigned long long int getNumberValue(unsigned long long int userInput,map<unsigned long long int,unsigned long long int> digitFactorialMap){
	unsigned long long int result = 0;
	while(userInput){
		result += digitFactorialMap.find(userInput%10)->second;
		userInput /= 10;
	}
	return result;
}

//Tested
bool hasReachedTargestLength(unsigned long long int userInput,map<unsigned long long int,unsigned long long int> digitFactorialMap){
	map<unsigned long long int,bool> visitedNumbers;
	visitedNumbers.insert(pair<unsigned long long int,bool>(userInput,true));
	unsigned long long int chainLength = 1,result;
	while(chainLength <= 60){
		result = getNumberValue(userInput,digitFactorialMap);
		if(visitedNumbers.find(result) != visitedNumbers.end()){
			break;
		}else{
			visitedNumbers.insert(pair<unsigned long long int,bool>(result,true));
		}
		chainLength++;
		userInput = result;
	}
	return chainLength == 60;
}

//Tested
//Ans : 402
void getChainLength60(){
	unsigned long long int total = 0;
	map<unsigned long long int,unsigned long long int> digitFactorialMap = getDigitFactorialMap();
	for(unsigned long long int counter = 2;counter < 1000000;counter++){
		if(hasReachedTargestLength(counter,digitFactorialMap)){
			total++;
		}
	}
	cout << total << endl;
}

#endif /* DIGITFACTORIALCHAINS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
