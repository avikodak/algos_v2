/****************************************************************************************************************************************************
 *  File Name   		: almostsorted.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\sorting\almostsorted.h
 *  Created on			: Feb 13, 2015 :: 1:34:11 PM
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

#ifndef ALMOSTSORTED_H_
#define ALMOSTSORTED_H_

//Tested
bool isVectorSorted(vector<long int> &userInput){
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter] > userInput[counter+1]){
			return false;
		}
	}
	return true;
}

//Tested
void reverseSubArray(vector<long int> &userInput,int start,int end){
	while(start < end){
		swap(userInput[start],userInput[end]);
		start++;
		end--;
	}
}

//Tested
void isArrayAlmostSorted(){
	unsigned int size;
	long int input;
	scanf("%u",&size);
	vector<long int> userInput;
	while(size--){
		scanf("%ld",&input);
		userInput.push_back(input);
	}
	unsigned int firstIndex,secondIndex,improperCount = 0;
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		if(userInput[counter] > userInput[counter+1]){
			improperCount++;
			if(improperCount == 1){
				firstIndex = counter;
			}else if(improperCount == 2){
				secondIndex = counter;
			}
		}
	}
	if(improperCount == 0){
		printf("yes\n");
	}else if(improperCount == 1){
		swap(userInput[firstIndex],userInput[firstIndex+1]);
		if(isVectorSorted(userInput)){
			printf("yes\n");
			printf("swap %d %d",firstIndex+1,firstIndex+2);
		}else{
			printf("no");
		}
	}else if(improperCount == 2){
		swap(userInput[firstIndex],userInput[secondIndex+1]);
		if(isVectorSorted(userInput)){
			printf("yes\n");
			printf("swap %d %d",firstIndex+1,secondIndex+2);
		}else{
			printf("no");
		}
	}else{
		if(firstIndex + improperCount >= userInput.size()){
			printf("no");
		}else{
			reverseSubArray(userInput,firstIndex,firstIndex+improperCount);
			if(isVectorSorted(userInput)){
				printf("yes\n");
				printf("reverse %d %d",firstIndex+1,firstIndex+improperCount+1);
			}else{
				printf("no");
			}
		}
	}
}

#endif /* ALMOSTSORTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
