/****************************************************************************************************************************************************
 *  File Name                   : digitfifthpower.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitfifthpower.h
 *  Created on                  : Aug 13, 2015 :: 3:42:56 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=30
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

#ifndef DIGITFIFTHPOWER_H_
#define DIGITFIFTHPOWER_H_

//Tested
unsigned int getDigitSum(unsigned int userInput,map<unsigned int,unsigned int> digitPowerMap){
	unsigned int sum = 0;
	while(userInput){
		sum += digitPowerMap.find(userInput%10)->second;
		userInput /= 10;
	}
	return sum;
}

//Tested
//Ans : 443839
unsigned int getSumOfDigitFifthPowers(){
	map<unsigned int,unsigned int> digitPower;
	for(unsigned int counter = 0;counter < 10;counter++){
		digitPower.insert(pair<unsigned int,unsigned int>(counter,pow(counter,5)));
	}
	unsigned int sum = 0;
	for(unsigned int int counter = 2;counter <= 354295;counter++){
		if(counter == getDigitSum(counter,digitPower)){
			sum += counter;
		}
	}
	return sum;
}

#endif /* DIGITFIFTHPOWER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
