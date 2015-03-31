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
