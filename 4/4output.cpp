#include <bits/stdc++.h>
using namespace std;

#define Key(A) (A)
#define Less(A, B) (Key(A)<Key(B))

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size();
    int *v3 = (int*) malloc(sizeof(int)*(s1+s2));
    int k = 0, j = 0, i = 0;
    while(k<=(s1-1) && j<=(s2-1)){
        if(Less(nums2[j], nums1[k]))
            v3[i++] = nums2[j++];
        else 
            v3[i++] = nums1[k++];
    }
    while(k<=(s1-1))
        v3[i++] = nums1[k++];
    while(j<=(s2-1))
        v3[i++] = nums2[j++];
    double retorno = 0;

    if((s1+s2)%2==1)
        retorno = v3[(s1+s2-1)/2];
    else{
        retorno = v3[(s1+s2)/2] + v3[(s1+s2)/2-1];
        free(v3);
        return retorno/2;
    }
    free(v3);
    return retorno;
}

int main(){
    int r[7];
    int i = 0;
    scanf("%d", &r[i]);
    vector<int> v1(r[i]);
    int j = 0;
    while(j<r[i])
        scanf("%d", &v1[j++]);
    i++;
    scanf("%d", &r[i]);
    vector<int> v2(r[i]);
    j=0;
    while(j<r[i])
        scanf("%d", &v2[j++]);
    i++;
    double c = findMedianSortedArrays(v1, v2);
    printf("%f\n", c);
    return 0;
}