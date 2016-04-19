/****************************************************************************************************************************************************
 *  File Name   		: tlg.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\tlg.h
 *  Created on			: Feb 3, 2015 :: 6:55:31 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/TLG
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TLG_H_
#define TLG_H_

//Tested
void printWinner() {
    int noOfRounds;
    scanf("%d",&noOfRounds);
    int firstPersonScore,secondPersonScore,maxLead = INT_MIN,maxLeadPerson,firstLead = 0,secondLead = 0;
    while(noOfRounds--) {
        scanf("%d %d",&firstPersonScore,&secondPersonScore);
        firstLead += (firstPersonScore - secondPersonScore);
        secondLead += (secondPersonScore - firstPersonScore);
        if(firstLead > maxLead) {
            maxLead = firstLead;
            maxLeadPerson = 1;
        } else if(secondLead > maxLead) {
            maxLead = secondLead;
            maxLeadPerson = 2;
        }
    }
    printf("%d %d\n",maxLeadPerson,maxLead);
}

#endif /* TLG_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
