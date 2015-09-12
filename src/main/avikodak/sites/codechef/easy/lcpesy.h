/****************************************************************************************************************************************************
 *  File Name                   : lcpesy.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/lcpesy.h
 *  Created on                  : 12-Sep-2015 :: 8:28:31 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LCPESY
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
#include <stdint.h>
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

#ifndef LCPESY_H_
#define LCPESY_H_

//Tested
void printLongestCommonPattern(string firstUserInput,string secondUserInput){
	map<char,unsigned int> frequencyMap;
	for(unsigned int counter = 0;counter < firstUserInput.length();counter++){
		if(frequencyMap.find(firstUserInput[counter]) == frequencyMap.end()){
			frequencyMap[firstUserInput[counter]] = 1;
		}else{
			frequencyMap[firstUserInput[counter]]++;
		}
	}
	unsigned int commonChars = 0;
	for(unsigned int counter = 0;counter < secondUserInput.length();counter++){
		if(frequencyMap.find(secondUserInput[counter]) != frequencyMap.end()){
			commonChars++;
			if(frequencyMap[secondUserInput[counter]] == 1){
				frequencyMap.erase(secondUserInput[counter]);
			}else{
				frequencyMap[secondUserInput[counter]]--;
			}
		}
	}
	cout << commonChars << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string firstUserInput,secondUserInput;
	while(testCases--){
		cin >> firstUserInput >> secondUserInput;
		printLongestCommonPattern(firstUserInput,secondUserInput);
	}
}

#endif /* LCPESY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
