#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	string num;
	for(int i=1; i<=n; i++)
	{
		if(i == 1)
			num = "1";
		else
		{
			string temp = "";
			
			for(int j=0; j<num.size();)
			{
				int count=1;
				char ch = num[j];
				
				while(ch == num[++j] && j<num.size())
					count++;
					
				temp += to_string(count)+ch;
			}
			
			num = temp;
		}
	}
	
	return num;
}