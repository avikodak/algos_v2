/****************************************************************************************************************************************************
 *  File Name                   : chewbaccaandnumber.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\chewbaccaandnumber.h
 *  Created on                  : Apr 12, 2015 :: 10:09:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/514/A
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

#ifndef CHEWBACCAANDNUMBER_H_
#define CHEWBACCAANDNUMBER_H_

//Tested
void getMinimumNumberInvertDigits(){
	long long unsigned int userInput;
	cin >> userInput;
	stack<unsigned int> digits;
	long long unsigned int result = 0;
	unsigned int lastDigit;
	while(userInput > 0){
		lastDigit = userInput % 10;
		if(lastDigit > (9 - lastDigit) && userInput != 9){
			digits.push(9-lastDigit);
		}else{
			digits.push(lastDigit);
		}
		userInput /= 10;
	}
	while(!digits.empty()){
		result = (result << 3) + (result << 1) + digits.top();
		digits.pop();
	}
	cout << result;
}

#endif /* CHEWBACCAANDNUMBER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
