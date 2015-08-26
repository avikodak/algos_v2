/****************************************************************************************************************************************************
 *  File Name                   : bouncynumbers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\bouncynumbers.h
 *  Created on                  : Aug 25, 2015 :: 4:44:50 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=112
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

#ifndef BOUNCYNUMBERS_H_
#define BOUNCYNUMBERS_H_

//Tested
bool isBouncyNumber(unsigned long long int userInput){
	vector<unsigned int> digits;
	while(userInput){
		digits.push_back(userInput%10);
		userInput /= 10;
	}
	bool isIncreasing = true;
	for(unsigned int counter = 1;counter < digits.size();counter++){
		if(digits[counter] < digits[counter-1]){
			isIncreasing = false;
			break;
		}
	}
	if(isIncreasing){
		return false;
	}
	bool isDecreasing = true;
	for(unsigned int counter = 1;counter < digits.size();counter++){
		if(digits[counter] > digits[counter-1]){
			isDecreasing = false;
			break;
		}
	}
	if(isDecreasing){
		return false;
	}
	return true;
}

//Tested
//Ans : 1587000
void getLeastNumber(){
	unsigned long long int counter = 99;
	unsigned long long int bouncyNumbersCount = 0;
	while(true){
		if(isBouncyNumber(counter)){
			bouncyNumbersCount++;
		}
		if(bouncyNumbersCount*100 >= 99*counter){
			cout << counter << endl;
			return;
		}
		counter++;
	}
}

#endif /* BOUNCYNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
