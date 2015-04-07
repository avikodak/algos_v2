/****************************************************************************************************************************************************
 *  File Name                   : foxandsnake.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\foxandsnake.h
 *  Created on                  : Apr 8, 2015 :: 12:24:53 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/510/A
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

#ifndef FOXANDSNAKE_H_
#define FOXANDSNAKE_H_

//Tested
void printSnakePattern(){
	unsigned int inputRow,inputColumn;
	scanf("%u %u",&inputRow,&inputColumn);
	bool flag = false;
	for(unsigned int rowCounter = 0;rowCounter < inputRow;rowCounter++){
		if(rowCounter%2 == 0){
			for(unsigned int columnCounter = 0;columnCounter < inputColumn;columnCounter++){
				printf("#");
			}
		}else{
			for(unsigned int columnCounter = 0;columnCounter < inputColumn;columnCounter++){
				if(columnCounter == 0){
					printf("%c",flag?'#':'.');
				}else if(columnCounter == inputColumn-1){
					printf("%c",flag?'.':'#');
				}else{
					printf(".");
				}
			}
			flag = !flag;
		}
		printf("\n");
	}
}

#endif /* FOXANDSNAKE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
