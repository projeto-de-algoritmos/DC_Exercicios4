#define Key(A) (A)
#define Great(A, B) (Key(A)>Key(B))
#define Less(A, B) (Key(A)<=Key(B))

class Solution {
public:
    int merge(vector<int> &v,int l,int r1,int r2){
        int *v2 = (int*)malloc(sizeof(int)*(r2-l+1));
        int retorno = 0;
        int i = l, j = r1+1, k = 0;

        while(i<=r1 && j<=r2){
            if(Great(v[i], (long)v[j]*2)){
                retorno += r1-i+1;
                ++j;
            }   
            else
                ++i;
        }
        i = l;
        j = r1+1;

        while(i<=r1 && j<=r2){
            if(Less(v[i], v[j]))
                v2[k++] = v[i++];
            else
                v2[k++] = v[j++];
        }
        while(i<=r1)
            v2[k++] = v[i++];
        
        while(j<=r2)
            v2[k++] = v[j++];
        
        k = 0;
        
        for(int i=l; i<=r2; i++)
            v[i] = v2[k++];
        
        free(v2);
        return retorno;
    }
    int mergesort(vector<int> &v, int l, int r){
        if(l>=r) return 0;
        int meio = l + (r-l)/2, x = 0;
        x += mergesort(v, l, meio);
        x += mergesort(v, meio+1, r);
        x += merge(v, l, meio, r);
        return x;
    }
    
    int reversePairs(vector<int>& nums) {
        int s = nums.size();
        int inversions = 0;
        inversions = mergesort(nums, 0, s-1);
        return inversions;
    }

};