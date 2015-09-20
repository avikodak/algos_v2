/****************************************************************************************************************************************************
 *  File Name                   : igcdmat.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/ignitedcoders/igcdmat.h
 *  Created on                  : 20-Sep-2015 :: 11:50:09 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/IGCD2015/problems/IGCDMAT
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
#include <stdint.h>
#include <iomanip>
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
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef IGCDMAT_H_
#define IGCDMAT_H_

//Tested
void scanuint(unsigned int &x){
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

//Tested
unsigned int countTotalIdentityMatrix(unsigned int matrix[][100],unsigned int size,unsigned int row,unsigned int column){
	unsigned int total = 0;
	for(unsigned int counter = 2;row+counter-1 < size&& column+counter-1 < size;counter++){
		for(unsigned int rowCounter = row;rowCounter < row+counter;rowCounter++){
			for(unsigned int columnCounter = column;columnCounter < column+counter;columnCounter++){
				if(rowCounter-row == columnCounter-column){
					if(matrix[rowCounter][columnCounter] != 1){
						return total;
					}
				}else if(matrix[rowCounter][columnCounter] != 0){
					return total;
				}
			}
		}
		total++;
	}
	return total;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	unsigned int matrix[100][100];
	scanuint(testCases);
	unsigned int totalOnes,totalZeros;
	while(testCases--){
		scanuint(size);
		totalOnes = totalZeros = 0;
		for(unsigned int rowCounter = 0;rowCounter < size;rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < size;columnCounter++){
				scanuint(matrix[rowCounter][columnCounter]);
				if(matrix[rowCounter][columnCounter] == 1){
					totalOnes++;
				}else if(matrix[rowCounter][columnCounter] == 0){
					totalZeros++;
				}
			}
		}
		if(totalZeros > 1){
			for(unsigned int rowCounter = 0;rowCounter < size-1;rowCounter++){
				for(unsigned int columnCounter = 0;columnCounter < size-1;columnCounter++){
					if(matrix[rowCounter][columnCounter] == 1){
						totalOnes += countTotalIdentityMatrix(matrix,size,rowCounter,columnCounter);
					}
				}
			}
		}
		cout << totalOnes << endl;
	}
}

#endif /* IGCDMAT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
