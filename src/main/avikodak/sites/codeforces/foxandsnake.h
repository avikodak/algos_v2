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
