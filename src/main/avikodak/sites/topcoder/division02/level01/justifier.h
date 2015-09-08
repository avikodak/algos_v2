/****************************************************************************************************************************************************
 *  File Name                   : justifier.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\justifier.h
 *  Created on                  : Mar 30, 2015 :: 5:49:18 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=1757
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

#ifndef JUSTIFIER_H_
#define JUSTIFIER_H_

class Justifier{
public:
	vector<string> justify(vector<string> textIn){
		int maxSize = INT_MIN,spaceToBeFilled;
		for(unsigned int counter = 0;counter < textIn.size();counter++){
			maxSize = max(maxSize,textIn[counter].size());
		}
		vector<string> justifiedStrings;
		for(unsigned int outerCounter = 0;outerCounter < textIn.size();outerCounter++){
			if(textIn.size() != maxSize){
				spaceToBeFilled = maxSize - textIn[outerCounter].size();
				string result;
				while(spaceToBeFilled--){
					result.push_back(' ');
				}
				for(unsigned int innerCounter = 0;innerCounter < textIn[outerCounter].size();innerCounter++){
					result.push_back(textIn[outerCounter][innerCounter]);
				}
				justifiedStrings.push_back(result);
			}else{
				justifiedStrings.push_back(textIn[outerCounter]);
			}
		}
	}
};

#endif /* JUSTIFIER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
