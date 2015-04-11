/****************************************************************************************************************************************************
 *  File Name                   : littleponyandcrystalmine.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\littleponyandcrystalmine.h
 *  Created on                  : Apr 11, 2015 :: 12:10:50 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://codeforces.com/problemset/problem/454/A
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

#ifndef LITTLEPONYANDCRYSTALMINE_H_
#define LITTLEPONYANDCRYSTALMINE_H_

void getCrystal(){
	unsigned int size;
	scanf("%u",size);
	vector<vector<char> > matrix(size);
	for(unsigned int rowCounter = 0;rowCounter < size;rowCounter++){
		matrix[rowCounter].assign(size,'*');
	}
	int columnStart = 0;
	for(int rowCounter = size/2;rowCounter >= 0;rowCounter--){
		for(unsigned int columnCounter = columnStart;columnCounter <size-columnStart;columnCounter++){
			matrix[rowCounter][columnCounter] = 'D';
		}
		columnStart++;
	}
	columnStart = 1;
	for(unsigned int rowCounter = (size/2)+1;rowCounter < size;rowCounter++){
		for(int columnCounter = columnStart;columnCounter <size-columnStart;columnCounter++){
			matrix[rowCounter][columnCounter] = 'D';
		}
		columnStart++;
	}
	for(unsigned int rowCounter = 0;rowCounter < size;rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < size;columnCounter++){
			printf("%c",matrix[rowCounter][columnCounter]);
		}
		printf("\n");
	}
}

#endif /* LITTLEPONYANDCRYSTALMINE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
