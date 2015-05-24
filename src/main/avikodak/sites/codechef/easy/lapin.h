/****************************************************************************************************************************************************
 *  File Name   		: lapin.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\lapin.h
 *  Created on			: Feb 9, 2015 :: 10:06:30 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/LAPIN
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
#define MAX_INPUT_SIZE 1001
#define ALPHABET_SIZE 26

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef LAPIN_H_
#define LAPIN_H_

//Tested
bool isStringLapindrome(char *user){
	unsigned int length = strlen(user);
	unsigned int secondCrawler = 0,size;
	if(length&1){
		secondCrawler = (length/2)+1;
	}else{
		secondCrawler = length/2;
	}
	size = (length/2);
	unsigned frequencies[ALPHABET_SIZE] = {0};
	for(unsigned int counter = 0;counter < size;counter++){
		frequencies[user[counter]-'a']++;
	}
	for(unsigned int counter = secondCrawler;counter < length;counter++){
		if(frequencies[user[counter]-'a'] == 0){
			return false;
		}
		frequencies[user[counter]-'a']--;
	}
	for(unsigned int counter = 0;counter < ALPHABET_SIZE;counter++){
		if(frequencies[counter] > 0){
			return false;
		}
	}
	return true;
}

//Tested
void areStringLapindromes(){
	unsigned int testCases;
	scanf("%u",&testCases);
	char userInput[MAX_INPUT_SIZE];
	while(testCases--){
		scanf("%s",userInput);
		if(isStringLapindrome(userInput)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}

#endif /* LAPIN_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
