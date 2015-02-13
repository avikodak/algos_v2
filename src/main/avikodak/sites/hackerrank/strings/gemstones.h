/****************************************************************************************************************************************************
 *  File Name   		: gemstones.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\strings\gemstones.h
 *  Created on			: Feb 13, 2015 :: 9:17:08 AM
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

#ifndef GEMSTONES_H_
#define GEMSTONES_H_

//Tested
void printLettersInAllGemStones(){
	long int testSize;
	string userInput;
	scanf("%ld",&testSize);
	vector<bool> flags;
	vector<long int> alphaCounter(26,0);
	for(long int counter = 0;counter < testSize;counter++){
		cin >> userInput;
		flags.clear();
		flags.assign(26,false);
		for(unsigned int strCounter = 0;strCounter < userInput.size();strCounter++){
			if(!flags[userInput[strCounter]-'a']){
				flags[userInput[strCounter]-'a'] = true;
				alphaCounter[userInput[strCounter]-'a'] += 1;
			}
		}
	}
	int total = 0;
	for(unsigned int counter = 0;counter < 26;counter++){
		if(alphaCounter[counter] == testSize){
			total+=1;
		}
	}
	printf("%d",total);
}

#endif /* GEMSTONES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
