#include <bits/stdc++.h>
using namespace std;

#define Key(A) (A)
#define Less(A, B) (Key(A)<=Key(B))
#define pii pair<int,int>


vector<int> retorno;
void merge(vector<pii> &v,int l,int r1,int r2){
    int *v2 = (int*)malloc(sizeof(int)*(r2-l+1));
    int *v3 = (int*)malloc(sizeof(int)*(r2-l+1));
    int i = l, j = r1+1, k = 0;

    while(i<=r1 && j<=r2){
        if(Less(v[i].first, v[j].first)){
            retorno[v[i].second] += (j-r1-1);
            v3[k] = v[i].second;
            v2[k++] = v[i++].first;
        }
        else{
            v3[k] = v[j].second;
            v2[k++] = v[j++].first;
        }
    }
    while(i<=r1){
        retorno[v[i].second] += (j-r1-1);
        v3[k] = v[i].second;
        v2[k++] = v[i++].first;
    }
    while(j<=r2){
        v3[k] = v[j].second;
        v2[k++] = v[j++].first;
    }
    k = 0;
    for(int i=l; i<=r2; i++){
        v[i].second = v3[k];
        v[i].first = v2[k++];
    }
    free(v2);
    free(v3);
}

void mergesort(vector<pii> &v, int l, int r){
    if(l>=r) return;
    int meio = l + (r-l)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

vector<int> countSmaller(vector<int>& nums) {
    int s = nums.size();
    retorno.resize(s, 0);
    vector<pii> pos;

    for(int i=0; i<s; ++i)
        pos.push_back(pii(nums[i],i));
    
    mergesort(pos, 0, s-1);
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
    vector<int> c = countSmaller(v1);
    for(int i=0; i<j; ++i)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}