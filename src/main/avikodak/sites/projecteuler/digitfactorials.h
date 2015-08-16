/****************************************************************************************************************************************************
 *  File Name                   : digitfactorials.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitfactorials.h
 *  Created on                  : Aug 13, 2015 :: 4:25:51 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=34
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

#ifndef DIGITFACTORIALS_H_
#define DIGITFACTORIALS_H_

//Tested
unsigned int getDigitFactorials(unsigned int userInput,map<unsigned int,unsigned int> digitFactorialMap){
	unsigned int sum = 0;
	while(userInput){
		sum += digitFactorialMap.find(userInput%10)->second;
		userInput /= 10;
	}
	return sum;
}

//Tested
//Ans : 40730
unsigned int getSumOfDigitFactorials(){
	unsigned int sum = 0,product = 1;
	map<unsigned int,unsigned int> digitFactorialMap;
	digitFactorialMap.insert(pair<unsigned int,unsigned int>(0,0));
	for(unsigned int counter = 1;counter < 10;counter++){
		product *= counter;
		digitFactorialMap.insert(pair<unsigned int,unsigned int>(counter,product));
	}
	for(unsigned int counter = 3;counter < 2540161;counter++){
		if(counter == getDigitFactorials(counter,digitFactorialMap)){
			sum += counter;
		}
	}
	return sum;
}

#endif /* DIGITFACTORIALS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
