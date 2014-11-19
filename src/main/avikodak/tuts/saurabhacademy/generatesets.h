/****************************************************************************************************************************************************
 *  File Name   		: generatesets.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\generatesets.h
 *  Created on			: Oct 29, 2014 :: 9:25:38 AM
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef GENERATESETS_H_
#define GENERATESETS_H_

//Tested
void printSetsMain(vector<int> userInput,vector<int> setGenerated,unsigned int currentIndex){
	if(userInput.size() == 0){
		return;
	}
	if(currentIndex == userInput.size()){
		if(setGenerated.size() == 0){
			printf("Empty Set");
		}else{
			for(unsigned int counter = 0;counter < setGenerated.size();counter++){
				printf("%d\t",setGenerated[counter]);
			}
		}
		PRINT_NEW_LINE;
		return;
	}
	printSetsMain(userInput,setGenerated,currentIndex+1);
	setGenerated.push_back(userInput[currentIndex]);
	printSetsMain(userInput,setGenerated,currentIndex+1);
}

//Tested
void printSet(vector<int> userInput){
	vector<int> generatedSet;
	printSetsMain(userInput,generatedSet,0);
}

//Tested
void printSetsIterative(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	int numberOfDigitsForSize = userInput.size();
	PRINT_NEW_LINE;
	for(unsigned int counter = 1;counter < pow(2,userInput.size());counter++){
		bitset<32> numbInBinary(counter);
		for(int binaryDigitCounter = numberOfDigitsForSize-1;binaryDigitCounter >= 0;binaryDigitCounter--){
			if(numbInBinary[binaryDigitCounter]){
				printf("%d\t",userInput[binaryDigitCounter]);
			}
		}
		PRINT_NEW_LINE;
	}
}

#endif /* GENERATESETS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
