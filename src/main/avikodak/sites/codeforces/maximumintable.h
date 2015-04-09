/****************************************************************************************************************************************************
 *  File Name                   : maximumintable.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\maximumintable.h
 *  Created on                  : Apr 9, 2015 :: 11:54:01 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/509/A
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

#ifndef MAXIMUMINTABLE_H_
#define MAXIMUMINTABLE_H_

//Tested
void getMaximumTable(){
	unsigned int size;
	scanf("%u",&size);
	vector<vector<unsigned int> > matrix(size);
	for(unsigned int counter = 0;counter < size;counter++){
		matrix[counter].assign(size,1);
	}
	for(unsigned int rowCounter = 1;rowCounter < size;rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < size;columnCounter++){
			matrix[rowCounter][columnCounter] = matrix[rowCounter-1][columnCounter] + matrix[rowCounter][columnCounter-1];
		}
	}
	printf("%d",matrix[size-1][size-1]);
}

#endif /* MAXIMUMINTABLE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
