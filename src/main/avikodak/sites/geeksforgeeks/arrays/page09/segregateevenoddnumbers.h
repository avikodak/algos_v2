/****************************************************************************************************************************************************
 *  File Name   		: segregateevenoddnumbers.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\segregateevenoddnumbers.h
 *  Created on			: Nov 26, 2014 :: 12:40:07 AM
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

#ifndef SEGREGATEEVENODDNUMBERS_H_
#define SEGREGATEEVENODDNUMBERS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void segregateEvenOddNumberQuickDivideStep(vector<int> &userInput){
	if(userInput.size() < 2){
		return;
	}
	int startIndex = 0,rearIndex = userInput.size() - 1;
	while(startIndex < rearIndex){
		while(userInput[startIndex]%2 == 0){
			startIndex++;
		}
		while(userInput[rearIndex]%2 == 1){
			rearIndex--;
		}
		if(startIndex < rearIndex){
			swap(userInput[startIndex],userInput[rearIndex]);
		}
	}
}

//Tested
void segregateEvenOddNumbersAuxspace(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	queue<int> evenAuxspace,oddAuxspace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter]%2 == 0){
			evenAuxspace.push(userInput[counter]);
		}else{
			oddAuxspace.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	while(!evenAuxspace.empty()){
		userInput[++fillCounter] = evenAuxspace.front();
		evenAuxspace.pop();
	}
	while(!oddAuxspace.empty()){
		userInput[++fillCounter] = oddAuxspace.front();
		oddAuxspace.pop();
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
bool seoSortFunc(int firstUserInput,int secondUserInput){
	return firstUserInput%2 == 0?true:false;
}

//Tested
void segregateEvenOddNumbers(vector<int> &userInput){
	sort(userInput.begin(),userInput.end(),seoSortFunc);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void segregateEvenOddNumbersON2(vector<int> &userInput){

}

#endif /* SEGREGATEEVENODDNUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
