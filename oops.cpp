#include<iostream>
#include "characters.cpp"

using namespace std;

class superhero{
	private:
	int health;
	
	public:
	char level;


	//constructor
	superhero(){
		cout<<"Inside the constructor\n";
	}


	void print(){
		cout<<"Level: "<<level<<endl;
	}

	char getLevel(){
		return level;
	}

	int getHealth(){
		return health;
	}

	void setHealth(int hlth){
		health=hlth;
	}
	void setLevel(char ch){
		level=ch;
	}
};

int main(int argc, char const *argv[])
{
	// Hero h1;
	// cout<<sizeof(h1)<<endl;

	superhero ramesh;
	ramesh.setHealth(100);
	ramesh.setLevel('S');

	cout<<"Health: "<<ramesh.getHealth()<<" Level: "<<ramesh.getLevel()<<endl;
	
	return 0;
}