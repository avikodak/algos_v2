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
