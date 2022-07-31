#include <iostream>
using namespace std;
#include <sys/shm.h>
#include <string>
#include<vector>
#include<string.h>
#include<cstring>
#include<bits/stdc++.h>
void arr(string& temp)
{
	stringstream check(temp);
	vector<string> tokens;
	string temp_str;
	while(getline(check,temp_str,'\n'))
	{
		tokens.push_back(temp_str);
	}
	vector<int> a;
	int sum=0;
	for(int i=0;i<tokens.size();i++)
	{
		int c=stoi(tokens[i]);
		a.push_back(c);
	
	}
	 for(int i=0;i<a.size();i++)
	 {
	 	sum=sum+a[i];
	 }
	 cout<<"sum is:"<<sum<<endl;
	 cout<<"Average is:"<<(float)sum/a.size()<<endl;
}
int main(int argc,char*argv[])
{
 cout<<"In Server Process..."<<endl;
 int key=shmget(12321, 1024, 0 );
 char* shared_memory;
 string temp="";
 cout<<"Reading from shared memory..."<<endl;
 shared_memory=(char *)shmat(key,NULL,0);
 cout<<"Reading Successfully..."<<endl;
 for(int i=0;i<strlen(shared_memory);i++)
 {
 	temp=temp+shared_memory[i];
 }
 arr(temp);
 shmdt(shared_memory);
 shmctl(key, IPC_RMID, NULL); 
} 

