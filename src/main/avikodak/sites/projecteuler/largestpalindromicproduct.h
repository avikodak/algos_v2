/****************************************************************************************************************************************************
 *  File Name                   : largestpalindromicproduct.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\largestpalindromicproduct.h
 *  Created on                  : Jul 25, 2015 :: 7:17:21 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=4
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

#ifndef LARGESTPALINDROMICPRODUCT_H_
#define LARGESTPALINDROMICPRODUCT_H_

//Tested
bool isPalindrome(unsigned int number){
	unsigned int originalNumber = number,revNumber = 0;
	while(number){
		revNumber *= 10;
		revNumber += (number%10);
		number /= 10;
	}
	return originalNumber == revNumber;
}

//Tested
//906609
void getLargestPalindromicProduct(){
	unsigned int maxProduct = 1,result;
	for(unsigned int outerCounter = 100;outerCounter < 1000;outerCounter++){
		for(unsigned int innerCounter = 100;innerCounter < 1000;innerCounter++){
			result = outerCounter * innerCounter;
			if(isPalindrome(result)){
				maxProduct = max(maxProduct,outerCounter*innerCounter);
			}
		}
	}
	cout << maxProduct;
}

#endif /* LARGESTPALINDROMICPRODUCT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
