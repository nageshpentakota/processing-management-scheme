#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;
struct process
{
	int prior;
	int burst;
	int processid;
	int flag;
	int io;
	int escape;
};
main()
{
	cout<<"\n\t\t\tProcess Management System\n\n\n";
	int n;
	int count=0,incr=0,excount=0,sum=0,l=0;
	cout<<"enter the number of jobs ";
	cin>>n;
	if(n<=0)
	{
		cout<<"\nInvalid";
		exit(0);
	}
	struct process obj[n];
	for(int j=0;j<n;j++)
	{
	  cout<<"\nProcess id "<<j+1<<"\n";
	  obj[j].processid=j+1;
	  cout<<"enter priority :";
	  cin>>obj[j].prior;
	  cout<<"enter CPU burst time :";
	  cin>>obj[j].burst;
	  cout<<"enter IO burst time :";
	  cin>>obj[j].io;	
	}
    for(int j=0;j<n;j++)
	{
	  obj[j].flag=1;
	}
	struct process temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(obj[i].burst>obj[j].burst)
			{
				temp=obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
		}
		
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(obj[i].burst==obj[j].burst)
			{
				if(obj[i].prior<obj[j].prior)   //sjs and prior scheduling sorting process accordingly
				{
					temp=obj[i];
				    obj[i]=obj[j];
				    obj[j]=temp;
				}
				    
			}
		}
		
	}
	for(int i=0;i<100;i++)
	{
		if(obj[incr].flag==0)
		 {
		 	excount++;
		 }
		 if(obj[incr].flag==1)
		 {
		 	count++;
		 }
		 if(excount==n)
		 {
		 	break;
		 }
		 if(obj[incr].flag==1)
		 {
		 	l++;
		 	cout<<"\n\n"<<l<<"--Stage";
		    cout<<"\nNmber of process in ready state= "<<(n-count);
	        cout<<"\nNumber of process in running state ="<<count;
	        cout<<"\n\n";
		 	if(obj[incr].burst>5)
		 	{
		 		i+=5;
		 		obj[incr].burst-=5;
		 	}
		 	else if(obj[incr].burst<=5)
		 	{

		 		i+=obj[incr].burst;
		 		obj[incr].escape=i;
				 if(obj[incr].io==0)
				 {
				 	obj[incr].flag=0;
				 } 
				else if(obj[incr].io>0)
		        {
		        	 cout<<"p"<<obj[incr].processid<<": is at IO state";
			         i+=obj[incr].io;
			         obj[incr].flag=0;
			         
		       }	
		 	}
		}	
	incr++;	
	incr=incr%n;
	}
	cout<<"\n\nFinally";
	cout<<"\nNmber of process in ready state= "<<(n-count);
	cout<<"\nNumber of process in running state ="<<count;
	cout<<"\n\n";
	cout<<"Total escape time per process :\n";
	for(int k=0;k<n;k++)
	{
		cout<<" P"<<obj[k].processid<<":"<<obj[k].escape;
		sum+=obj[k].escape;
		cout<<"\n";
	}
	cout<<"\nTotal escape time :"<<sum;
	cout<<"\ndone--";
}
