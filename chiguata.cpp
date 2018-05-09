#include <iostream>

using namespace std;





void infecta(char m[9][9], int f, int c,int &x)
{
	
	if(m[f][c]=='A'){
		x++;
		m[f][c]='T';
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(( f+i >= 0 && f+i <= 9) && (c+j >=0 && c+j <= 9))
					if(m[f+i][c+j]=='A'){
						infecta(m,f+i,c+j,x);
					}

			}	
		}
	}

}

int main()
{
	int n = 9,m = 9,f = 3,c = 2,x=0;
	char mm[9][9]=
	{
		{'T','T','T','T','T','T','T','T','T'},
		{'T','T','A','A','T','T','A','T','T'},
		{'T','A','A','T','T','T','T','T','T'},
		{'T','A','A','A','T','A','A','T','T'},
		{'T','T','T','A','A','A','T','T','T'},
		{'T','T','T','T','T','T','T','T','T'},
		{'T','T','T','A','A','T','T','A','T'},
		{'T','T','A','T','A','T','T','T','T'},
		{'T','T','T','T','T','T','T','T','T'},
	};

	infecta(mm,3,2,x);
	cout<<x<<endl;

}
