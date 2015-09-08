/****************************************************************************************************************************************************
 *  File Name   		: printlistitemsforword.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page05\printlistitemsforword.h
 *  Created on			: Dec 4, 2014 :: 9:38:25 AM
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRINTLISTITEMSFORWORD_H_
#define PRINTLISTITEMSFORWORD_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
hash_map<char,unsigned int> getCharsFrequencyMap(char *userInput){
	hash_map<char,unsigned int> frequencyMap;
	while(*userInput != '\0'){
		if(frequencyMap.find(userInput[0]) == frequencyMap.end()){
			frequencyMap[userInput[0]] = 1;
		}else{
			frequencyMap[userInput[0]] += 1;
		}
		userInput++;
	}
	return frequencyMap;
}

bool wordContainsAllCharacters(char *word,hash_map<char,unsigned int> &frequencyMap){
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	while(*word != '\0'){
		if((itToFrequencyMap = frequencyMap.find(word[0])) == frequencyMap.end()){
			return false;
		}else{
			if(itToFrequencyMap->second == 1){
				frequencyMap.erase(itToFrequencyMap->first);
			}else{
				itToFrequencyMap->second--;
			}
		}
		word++;
	}
	return true;
}

vector<char *> printListItemsForWordON(vector<char *> wordsList,char *userInput){
	vector<char *> resultList;
	if(resultList.size() == 0){
		return resultList;
	}
	hash_map<char,unsigned int> frequencyMap;
	hash_map<char,unsigned int>::iterator itToFrequencyMap;
	for(unsigned int counter = 0;counter < wordsList.size();counter++){
		frequencyMap = getCharsFrequencyMap(wordsList[counter]);
		if(wordContainsAllCharacters(wordsList[counter],frequencyMap)){
			resultList.push_back(wordsList[counter]);
		}
		frequencyMap.clear();
	}
	return resultList;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<char *> printListItemsForWordON2(vector<char *> wordsList,char *userInput){
	vector<char *> resultWordList;
	if(resultWordList.size() == 0){
		return resultWordList;
	}
	char *keyCrawler,*wordCrawler;
	for(unsigned int counter = 0;counter < wordsList.size();counter++){
		wordCrawler = wordsList[counter];
		keyCrawler = userInput;
		while(*keyCrawler != '\0'){
			while(*wordCrawler != '\0' && *wordCrawler != keyCrawler[0]){
				wordCrawler++;
			}
			if(*wordCrawler == '\0'){
				break;
			}
			keyCrawler++;
		}
		if(keyCrawler[0] == '\0'){
			resultWordList.push_back(wordCrawler[counter]);
		}
	}
	return resultWordList;
}

#endif /* PRINTLISTITEMSFORWORD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
