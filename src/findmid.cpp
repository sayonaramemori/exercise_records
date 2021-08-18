#include<map>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		return dowork(nums1,nums2);
    }
private:
	bool odd;
	int pos;
	map<int,int> res;
	double dowork(vector<int>& nums1,vector<int>& nums2);;
	void init(const vector<int> &nums1,vector<int>&nums2){
		for(auto &v:nums1)++res[v];
		for(auto &v:nums2)++res[v];
		int totalsize = nums1.size()+nums2.size();
		odd = totalsize%2; 
		pos = totalsize/2;
	}

};

double Solution::dowork(vector<int>& nums1,vector<int> &nums2){
	init(nums1,nums2);
	int travelit = -1;
	if(odd){
		for(auto &v:res){
			travelit += v.second;
			if(travelit>=pos){
				return v.first;
			}
		}
	}else{
		int index = pos -1;
		int valt;
		int flag = false;
		for(auto &v:res){
			travelit += v.second;
			if(travelit<index)continue;
			if(travelit==index){
				valt = v.first;
				flag = true;
			}else{
				if(flag){
					return (v.first + valt)/2.0;
				}else{
					return v.first;
				}
			}
		}
	}
}
				


int main(int argc,char *argv[]){
	Solution t;
	vector<int> tmp1{1,2,3,4},tmp2{5,6,7,9};
cout<<t.findMedianSortedArrays(tmp1,tmp2)<<endl;
	return 0;
}
			
			



