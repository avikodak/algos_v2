/****************************************************************************************************************************************************
 *  File Name                   : isomorphicstrings.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/isomorphicstrings.h
 *  Created on                  : Jan 31, 2016 :: 4:52:43 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=284
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ISOMORPHICSTRINGS_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ISOMORPHICSTRINGS_H_

//Tested
void solveProblem(){
	unsigned int testCases;
	string firstInput,secondInput;
	scanf("%u",&testCases);
	map<char,char>::iterator itToFirstCharMapping,itToSecondCharMapping;
	while(testCases--){
		cin >> firstInput >> secondInput;
		map<char,char> firstCharMapping,secondCharMapping;
		firstCharMapping.clear();
		secondCharMapping.clear();
		bool isIsomorphic = true;
		for(unsigned int counter = 0;counter < firstInput.size();counter++){
			itToFirstCharMapping = firstCharMapping.find(firstInput[counter]);
			itToSecondCharMapping = secondCharMapping.find(secondInput[counter]);
			if(itToFirstCharMapping == firstCharMapping.end() && itToSecondCharMapping == secondCharMapping.end()){
				firstCharMapping.insert(pair<char,char>(firstInput[counter],secondInput[counter]));
				secondCharMapping.insert(pair<char,char>(secondInput[counter],firstInput[counter]));
			}else if(itToFirstCharMapping != firstCharMapping.end() && itToSecondCharMapping != secondCharMapping.end()){
				if(itToFirstCharMapping->second != secondInput[counter] || itToSecondCharMapping->second != firstInput[counter]){
					isIsomorphic = false;
					break;
				}
			}else{
				isIsomorphic = false;
				break;
			}
		}
		printf("%d\n",isIsomorphic);
	}
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_ISOMORPHICSTRINGS_H_ */
