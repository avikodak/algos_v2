/****************************************************************************************************************************************************
 *  File Name                   : kgp14a.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/kgp14a.h
 *  Created on                  : 17-Sep-2015 :: 11:20:30 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/KGP14A
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

#ifndef KGP14A_H_
#define KGP14A_H_

//Tested
int getSumMinDiff(vector<int> kidsHeights,vector<int> pencilHeights){
	sort(kidsHeights.begin(),kidsHeights.end());
	sort(pencilHeights.begin(),pencilHeights.end());
	int sum = 0;
	for(unsigned int counter = 0;counter < kidsHeights.size();counter++){
		sum += abs(kidsHeights[counter] - pencilHeights[counter]);
	}
	return sum;
}

//Tested
void printResults(){
	int testCases,input,size;
	scanf("%u",&testCases);
	vector<int> kidsHeights;
	vector<int> pencilHeights;
	for(int testCase = 1;testCase <= testCases;testCase++){
		kidsHeights.clear();
		pencilHeights.clear();
		scanf("%u",&size);
		for(int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			kidsHeights.push_back(input);
		}
		for(int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			pencilHeights.push_back(input);
		}
		cout << "Case "<< testCase << ": " << getSumMinDiff(kidsHeights,pencilHeights) << endl;
	}

}
#endif /* KGP14A_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
