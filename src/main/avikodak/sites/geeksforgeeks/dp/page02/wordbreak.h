/****************************************************************************************************************************************************
 *  File Name   		: wordbreak.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\wordbreak.h
 *  Created on			: Jan 12, 2015 :: 7:05:51 PM
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

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

bool checkWordDictionary(string word){
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for(unsigned int counter = 0;counter < size;counter++){
		if(word.compare(dictionary[counter]) == 0){
			return true;
		}
	}
	return false;
}

bool wordBreakMain(string userInput){
	if(userInput.size() == 0){
		return false;
	}
	for(unsigned int lengths = 1;lengths <= userInput.size();lengths++){
		if(checkWordDictionary(userInput.substr(0,lengths)) && wordBreakMain(userInput.substr(lengths,userInput.size() - lengths))){
			return true;
		}
	}
	return false;
}

bool wordBreakDP(string userInput){
	if(userInput.size() == 0){
		return true;
	}
	vector<bool> auxSpace(userInput.size()+1,false);
	for(unsigned int lengthCounter = 1;lengthCounter <= userInput.size();lengthCounter++){
		if(!auxSpace[lengthCounter] && checkWordDictionary(userInput.substr(0,lengthCounter))){
			auxSpace[lengthCounter] = true;
		}
		if(auxSpace[lengthCounter]){
			for(unsigned int innerCounter = lengthCounter+1;innerCounter <= userInput.size();innerCounter++){
				if(!auxSpace[innerCounter] && checkWordDictionary(userInput.substr(lengthCounter,innerCounter-lengthCounter))){
					auxSpace[innerCounter] = true;
				}
				if(innerCounter == userInput.size() && auxSpace[innerCounter]){
					return true;
				}
			}
		}
	}
	return false;
}

#endif /* WORDBREAK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
