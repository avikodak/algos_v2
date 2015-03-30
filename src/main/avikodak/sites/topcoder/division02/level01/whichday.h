/****************************************************************************************************************************************************
 *  File Name                   : whichday.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\whichday.h
 *  Created on                  : Mar 30, 2015 :: 5:09:41 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=11553
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

#ifndef WHICHDAY_H_
#define WHICHDAY_H_

//Tested
class WhichDay{
public:
	string getDay(vector<string> notOnThisDay){
		bool flags[7] = {false};
		string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
		string input;
		for(unsigned int counter = 0;counter < notOnThisDay.size();counter++){
			input = notOnThisDay[counter];
			if(input.compare("Sunday")){
				flags[0] = true;
			}else if(input.compare("Monday")){
				flags[1] = true;
			}else if(input.compare("Tuesday")){
				flags[2] = true;
			}else if(input.compare("Wednesday")){
				flags[3] = true;
			}else if(input.compare("Thursday")){
				flags[4] = true;
			}else if(input.compare("Friday")){
				flags[5] = true;
			}else if(input.compare("Saturday")){
				flags[6] = true;
			}
		}
		for(unsigned int counter = 0;counter < 7;counter++){
			if(!flags[counter]){
				return days[counter];
			}
		}
	}
};

#endif /* WHICHDAY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
