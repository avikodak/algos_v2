/****************************************************************************************************************************************************
 *  File Name                   : sortsills0s1s2s.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/easy/sortsills0s1s2s.h
 *  Created on                  : Jan 28, 2016 :: 8:55:07 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/probfunc-page.php?pid=700028
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SORTSILLS0S1S2S_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SORTSILLS0S1S2S_H_

struct node {
    int data;
    struct node *next;
};

//Tested
void sortList(struct node *head) {
    if(head == NULL) {
        return;
    }
    unsigned int zeroFrequency = 0,oneFrequency = 0,twoFrequency = 0;
    node *crawler = head;
    while(crawler != NULL) {
        switch (crawler->data) {
        case 0:
            zeroFrequency++;
            break;
        case 1:
            oneFrequency++;
            break;
        case 2:
            twoFrequency++;
            break;
        }
        crawler = crawler->next;
    }
    crawler = head;
    while(crawler != null) {
        if(zeroFrequency > 0) {
            crawler->data = 0;
            zeroFrequency--;
        } else if(oneFrequency > 0) {
            crawler->data = 1;
            oneFrequency--;
        } else {
            crawler->data = 2;
            twoFrequency--;
        }
        crawler = crawler->next;
    }
}


#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_EASY_SORTSILLS0S1S2S_H_ */
