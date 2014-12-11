/****************************************************************************************************************************************************
 *  File Name   		: fibonnacinumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\fibonnacinumbers.h
 *  Created on			: Dec 9, 2014 :: 7:38:50 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef FIBONNACINUMBERS_H_
#define FIBONNACINUMBERS_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
unsigned int getNthFibonnaciNumber(unsigned int number){
	if(number == 0){
		return 0;
	}
	if(number == 1){
		return 1;
	}
	return getNthFibonnaciNumber(number-1) + getNthFibonnaciNumber(number-2);
}

//Tested
unsigned int getNthFibonnaciNumberMemoization(unsigned int number){
	if(number == 0){
		return 0;
	}
	static vector<unsigned int> auxSpace(number+1);
	static bool isInit = false;
	if(!isInit){
		for(unsigned int counter = 0;counter < auxSpace.size();counter++){
			auxSpace[counter] = 0;
		}
		isInit = true;
		auxSpace[0] = 0;
		auxSpace[1] = 1;
	}
	if(number == 1){
		return 1;
	}
	if(auxSpace[number] != 0){
		return auxSpace[number];
	}else{
		if(number - 1 != 0){
			if(auxSpace[number-1] != 0){
				auxSpace[number] += auxSpace[number-1];
			}else{
				auxSpace[number] += getNthFibonnaciNumberMemoization(number-1);
			}
		}
		if(number - 2 != 0){
			if(auxSpace[number-2] != 0){
				auxSpace[number] += auxSpace[number-2];
			}else{
				auxSpace[number] += getNthFibonnaciNumberMemoization(number-2);
			}
		}
	}
	return auxSpace[number];
}

//Tested
unsigned int getNthFibonnaciNumberBottomUp(unsigned int number){
	if(number == 0){
		return 0;
	}
	if(number == 1){
		return 1;
	}
	vector<unsigned int> auxSpace(number+1);
	auxSpace[0] = 0;
	auxSpace[1] = 1;
	for(unsigned int counter = 2;counter <= number;counter++){
		auxSpace[counter] = auxSpace[counter-1] + auxSpace[counter-2];
	}
	return auxSpace[number];
}

//Tested
unsigned int getNthFibonnaciNumberBottomUpSpace(unsigned int number){
	if(number == 0){
		return 0;
	}
	if(number == 1){
		return 1;
	}
	int firstValue = 1,secondValue = 0,result;
	for(unsigned int counter = 2;counter <= number;counter++){
		result = firstValue + secondValue;
		secondValue = firstValue;
		firstValue = result;
	}
	return result;
}

#endif /* FIBONNACINUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
