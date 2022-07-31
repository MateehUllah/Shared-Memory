#include <iostream>
using namespace std;
#include <sys/shm.h>
#include <string>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
int main(int argc,char*argv[])
{
	if(argc==1)
	{
		cout<<"Please Enter file name"<<endl;
		return 0;
	}
	cout<<"In client Process..."<<endl;
	void*shared_memory;
	char arr[100];
	int i=0;
	int size=0;
	string temp="";
	int key=shmget(12321, 1024, IPC_CREAT | IPC_EXCL | 0666);  
	cout<<"shm created with id= "<<key<<endl;
	shared_memory=shmat(key,NULL,0);
	int fd=open(argv[1],O_RDONLY);
	cout<<"File opened Successfully..."<<endl;
	cout<<"Reading data..."<<endl;
	while(read(fd,&arr[i],sizeof(char))>0)
	{
		i++;
		size=i;
	}
	cout<<"Read Successfully...."<<endl;
	arr[i]='\0';
	char*arr2=new char[strlen(arr)+1];
	for(int k=0;k<strlen(arr);k++)
	{
		arr2[k]=arr[k];
	}
	
	strcpy((char*)shared_memory,arr2);
	cout<<"Data Successfuly copied to shared Memory"<<endl;
}

