#include<string>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		init(num1,num2);
        dowk(num1,num2);
		if(res.back()==0)res.pop_back();
		string ret(res.rbegin(),res.rend());
		for(auto &v:ret)v += 48;
		return ret;
    }
private:
	typedef pair<int,int> valpos;
	vector<int> res;
	void init(string &,string &);
	void dowk(string &num1,string &num2);
	void calcu(const valpos &rhs,const valpos &lhs);
	void plus(const int &val,const int &high);
};
void Solution::plus(const int &val,const int &high){
	int tmp = res[high] + val;
	if(tmp<10)res[high] = tmp;
	else{
		res[high] = tmp%10;
		plus(1,high+1);
	}
}
void Solution::calcu(const valpos &rhs,const valpos &lhs){
	int res = rhs.first * lhs.first;
	int high = rhs.second + lhs.second;
	if(res>=10){
		plus(res%10,high);
		plus(res/10,high+1);
	}else plus(res,high);
}
		

void Solution::init(string&s1,string &s2){
	res.resize(s1.size()+s2.size(),0);
	return;
}
void Solution::dowk(string &s1,string &s2){
	auto sz1 = s1.size();auto sz2 = s2.size();
	for(int i=0;i<sz1;++i){
		valpos tmp{s1[i]-48,sz1-i-1};
		for(int j=0;j<sz2;++j)
			calcu(tmp,{s2[j]-48,sz2-j-1});
	}
	return;
}

int main(int argc,char *argv[])
{
	Solution s;
	cout<<"res:"<<s.multiply(argv[1],argv[2])<<endl;
	return 0;
}



