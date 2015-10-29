/****************************************************************************************************************************************************
 *  File Name                   : subanagr.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/subanagr.h
 *  Created on                  : 26-Oct-2015 :: 7:46:41 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/SUBANAGR
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
#include <iomanip>
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

#ifndef SUBANAGR_H_
#define SUBANAGR_H_

//Tested
void printResults(){
	unsigned int overallFreq[26]={0},testCases;
	vector<unsigned int> freq;
	string userInput;
	scanf("%u",&testCases);
	for(unsigned int testCase = 0;testCase < testCases;testCase++){
		cin >> userInput;
		freq.clear();
		freq.assign(26,0);
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			freq[userInput[counter]-'a']++;
		}
		for(unsigned int counter = 0;counter < 26;counter++){
			overallFreq = testCase==0?freq[counter]:min(overallFreq[counter],freq[counter]);
		}
	}
	bool anagramFound = false;
	for(unsigned int counter = 0;counter < 26;counter++){
		if(overallFreq[counter] > 0){
			anagramFound = true;
			while(overallFreq[counter]--){
				printf("%c",counter+'a');
			}
		}
	}
	if(!anagramFound){
		printf("no such string");
	}
	printf("\n");
}

#endif /* SUBANAGR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
