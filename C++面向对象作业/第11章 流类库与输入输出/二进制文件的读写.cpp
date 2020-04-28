#include <iostream>
#include <fstream>
using namespace std;
struct student
{
	short stu_id,score;
};
int main()
{
	int n;
	cin>>n;
	student a[n];
	for(int i=0;i<n;i++)
		cin>>a[i].stu_id>>a[i].score;
	ofstream os("out.txt",ios_base::binary);
	os.write(reinterpret_cast<char *>(&a),sizeof(a));
	os.close();
	
	student b[n];
	ifstream is("out.txt",ios_base::binary);
	if(is)
	{
		for(int i=0;i<n;i++)
		{
			short id,sc;
			is.read(reinterpret_cast<char *>(&id),sizeof(id));
			b[i].stu_id=id;
			is.read(reinterpret_cast<char *>(&sc),sizeof(sc));
			b[i].score=sc;
		}
	}
	else
	{
		cout<<"ERROR: Cannot open file 'out.txt'."<<endl;
	}
	is.close();
	//for(int i=0;i<n;i++)
	//	cout<<b[i].stu_id<<" "<<b[i].score<<endl;
	
	ofstream OS("out.txt",ios_base::app);
	OS.write(reinterpret_cast<char *>(&b),sizeof(b));
	OS.close();
	return 0;
}
