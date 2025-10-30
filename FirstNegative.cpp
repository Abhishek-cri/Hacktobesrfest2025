 #include<bits/stdc++.h>
 using namespace std;
 vector<int> firstNegInt(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>temp;
        vector<int>vec;
        int i=0,j=0;
        while(j<n){
            if(arr[j]<0){
                temp.push_back(arr[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(temp.size()==0){
                    vec.push_back(0);
                }
                else{
                    vec.push_back(temp[0]);
                }
                
               if(temp.size()>0 && arr[i]==temp[0]){
                   temp.erase(temp.begin());
               }
                i++;
                j++;
            }
        }
        return vec;
    }
    int main(){
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k;
    cin >> k;
    vector<int>ans = firstNegInt(arr, k);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }
    }