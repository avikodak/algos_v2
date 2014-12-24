/****************************************************************************************************************************************************
 *  File Name   		: positiveinfunction.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\positiveinfunction.h
 *  Created on			: Dec 22, 2014 :: 6:07:04 PM
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

#ifndef POSITIVEINFUNCTION_H_
#define POSITIVEINFUNCTION_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 															    	*/
/****************************************************************************************************************************************************/
//Tested
int functionalValue(int x){
	return (x*x - 10*x - 20); ;
}

//Tested
int getValueWhereFuncIsPositive(){
	int counter = 1;
	while(functionalValue(counter) <= 0){
		counter *= 2;
	}
	return counter;
}

//Tested
int firstValFuncIsPositiveBinarySearchMain(int startVal,int endVal){
	if(startVal > endVal){
		return INT_MIN;
	}
	int middleVal = (startVal + endVal)/2;
	if(functionalValue(middleVal) > 0){
		if(middleVal-1 > startVal && functionalValue(middleVal-1) > 0){
			return firstValFuncIsPositiveBinarySearchMain(startVal,middleVal-1);
		}else{
			return middleVal;
		}
	}else{
		return firstValFuncIsPositiveBinarySearchMain(middleVal+1,endVal);
	}
}

//Tested
int firstValFuncIsPositiveBinarySearch(){
	int value = getValueWhereFuncIsPositive();
	return firstValFuncIsPositiveBinarySearchMain(value/2,value);
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int firstPointFuncPositive(){
	unsigned int counter;
	for(counter = 1;functionalValue(counter) <= 0;counter++);
	return counter;
}

#endif /* POSITIVEINFUNCTION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
