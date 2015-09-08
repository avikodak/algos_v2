/****************************************************************************************************************************************************
 *  File Name                   : sherlockandanagrams.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\strings\sherlockandanagrams.h
 *  Created on                  : Jul 14, 2015 :: 7:18:16 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/sherlock-and-anagrams
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

#ifndef SHERLOCKANDANAGRAMS_H_
#define SHERLOCKANDANAGRAMS_H_

//Tested
void getTotalUnorderedAnagramicPairs(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string userInput;
	map<string,int> strFrequency;
	map<string,int>::iterator itToStrFrequency;
	unsigned int totalPairs;
	while(testCases--){
		cin >> userInput;
		strFrequency.clear();
		for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
			for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
				string subString = userInput.substr(outerCounter,innerCounter-outerCounter+1);
				sort(subString.begin(),subString.end());
				if((itToStrFrequency = strFrequency.find(subString)) != strFrequency.end()){
					strFrequency[subString] += 1;
				}else{
					strFrequency.insert(pair<string,int>(subString,1));
				}
			}
		}
		totalPairs = 0;
		for(itToStrFrequency = strFrequency.begin();itToStrFrequency != strFrequency.end();itToStrFrequency++){
			if(itToStrFrequency->second > 1){
				totalPairs += ((itToStrFrequency->second)*(itToStrFrequency->second-1))/2;
			}
		}
		cout << totalPairs << endl;
	}
}

#endif /* SHERLOCKANDANAGRAMS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
