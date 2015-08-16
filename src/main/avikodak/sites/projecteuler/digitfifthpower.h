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
