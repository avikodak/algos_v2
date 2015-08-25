/****************************************************************************************************************************************************
 *  File Name   		: manasaandstones.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\manasaandstones.h
 *  Created on			: Feb 6, 2015 :: 6:46:18 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/manasa-and-stones
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

#ifndef MANASAANDSTONES_H_
#define MANASAANDSTONES_H_

//Tested
void printPossibilites(unsigned int nValue,unsigned int firstUserInput,unsigned int secondUserInput){
	unsigned int minValue = min(firstUserInput,secondUserInput);
	unsigned int maxValue = max(firstUserInput,secondUserInput);
	unsigned int difference = maxValue - minValue;
	unsigned int lowValue = minValue * (nValue-1);
	unsigned int highValue = (nValue-1) * maxValue;
	while(lowValue <= highValue){
		cout << lowValue << " ";
		lowValue += difference;
        if(difference == 0){
            return;
        }
	}
}

//Tested
void getPossibilitesForInput(){
	unsigned int testCases;
	scanf("%u",&testCases);
	unsigned int nValue,firstUserInput,secondUserInput;
	while(testCases--){
		scanf("%u %u %u",&nValue,&firstUserInput,&secondUserInput);
		printPossibilites(nValue,firstUserInput,secondUserInput);
		printf("\n");
	}
}

//Tested
//Not Optimized
void printPossibilites(int value,int nValue,int firstUserInput,int secondUserInput,int &prevValue){
	if(nValue == 1){
		if(prevValue != value){
			printf("%d\t",value);
			prevValue = value;
		}
		return;
	}
	printPossibilites(value+firstUserInput,nValue-1,firstUserInput,secondUserInput,prevValue);
	printPossibilites(value+secondUserInput,nValue-1,firstUserInput,secondUserInput,prevValue);
}

#endif /* MANASAANDSTONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
