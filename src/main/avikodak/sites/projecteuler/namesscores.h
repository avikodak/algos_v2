/****************************************************************************************************************************************************
 *  File Name                   : namesscores.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\namesscores.h
 *  Created on                  : Aug 11, 2015 :: 9:36:28 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=22
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef NAMESSCORES_H_
#define NAMESSCORES_H_

//Tested
unsigned long long int getNameScore(string userInput){
	unsigned long long int score = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		score += (userInput[counter] - 'A' + 1);
	}
	return score;
}

//Tested
//Ans : 871198282
unsigned long long int getTotalNamesScores(){
	unsigned int testCases;
	scanf("%u",&testCases);
	vector<string> userInput;
	string input;
	while(testCases--){
		cin >> input;
		userInput.push_back(input);
	}
	sort(userInput.begin(),userInput.end());
	unsigned long long int sum = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		sum += ((counter+1)*getNameScore(userInput[counter]));
	}
	return sum;
}

#endif /* NAMESSCORES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
