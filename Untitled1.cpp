#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Doct{
	string str;
	public:
	Doct(){
	ifstream in;
	     in.open("f1.txt");
	     while(in.eof()==0){
	     	getline(in,str);
	    	cout<<str<<endl;
	}
	in.close();
	}
	~Doct(){
		cout<<"please continue with further process"<<endl;
		cout<<"\n"<<endl;
	}
};
template <class T1>
class Doctavl : virtual public Doct{
	T1 str;
	public:
	    void showd(){
		ifstream in;
	     in.open("f2.txt");
	     while(in.eof()==0){
	     	getline(in,str);
	    	cout<<str<<endl;
	}
	in.close();
	}
	void showd(int a,int b){
		ifstream in;
		a=1,b=2;
		
	     in.open("f4.txt");
	     while(in.eof()==0){
	     	getline(in,str);
	    	cout<<str<<endl;
	}
	int c=a+b;
	cout<<c;
	
	in.close();
	}
	
};   
typedef struct opt{
	int cnt;
	string pnt;
	
	opt operator + (opt &o){
		return opt{cnt + o.cnt, pnt};
	}
}xrx;
class Ptnt{
	public:
	xrx y1,y2;
    friend void addptnt(Ptnt &p);
	void ptntdisp(){
			ifstream in;
	        in.open("f3.txt");
	        while(in.eof()==0){
	     	getline(in,y1.pnt);
	    	cout<<y1.pnt<<endl;
	      }
	in.close();
	}

};
void addptnt(Ptnt &p){
	ofstream out;
		cout<<"HOW MANY PATIENTS DATA YOU WANT TO ADD"<<endl;
		cin>>p.y1.cnt;
		cout<<"ENTER NAME OF PATIENTS"<<endl;
	out.open("f3.txt",ios::app);
	for(int i=1;i<=p.y1.cnt;i++){
		fflush(stdin);
	    getline(cin,p.y2.pnt);
		out<<i+6<<") "<<p.y2.pnt<<endl;
	}
	out.close();
}

template <class X>
class Ptntbill : public Ptnt{
	public:
		int operator + (Ptntbill &m){
			
		}
		void billgen(){
	   string str;
	    X z=0;
	    X z2= 5000;
	        ifstream in;
	        in.open("f3.txt");
	        ofstream out;
	        out.open("billdet.txt");
	        while(in.eof()==0){
	        getline(in,str);
	        out<<str<<" TOTAL BILL IS = "<<z2*(z+1)<<endl;
	    	z++;
	    }
        
out.close();
in.close();;
}
};
class Cotr{
	public:
		void showdt(){
			cout<<" COST OF TREATMENTS AS FOLLOWS (cost may vary on as long as treatment) "<<endl;
			cout<<"1) Influenza (RS.1000) "<<endl;
			cout<<"2) Cardiovascular Illnesses (RS.90000)"<<endl;
			cout<<"3) Respiratory Diseases (RS.35000)"<<endl;
			cout<<"4) Alzheimer's disease (RS.10000)"<<endl;
			cout<<"5) Malignant and Other Tumors (RS.40000)"<<endl;
			cout<<"6) Fractures (RS.2000)"<<endl;
			cout<<"7) Conjunctivitis (RS.9000)"<<endl;
			cout<<"8) Mononucleosis (RS.16000)"<<endl;
			cout<<"9) Aids (RS.150000) "<<endl;
		}
};
class Equip {
	public:
		xrx y1;
		void showd(){
			ifstream in;
	        in.open("equip.txt");
	        while(in.eof()==0){
	     	getline(in,y1.pnt);
	    	cout<<y1.pnt<<endl;
		}
	}
};
int main(){
while(true){
	start:
	cout<<"----- LIFELINE HMS -----"<<endl;
	cout<<"--- M A I N  M E N U ---"<<endl;
	cout<<"1. DOCTORS"<<endl;//DOCTOR AVAILABILITY CLASS
	cout<<"2. COST OF TREATMENTS"<<endl;
	cout<<"3. PATIENTS"<<endl; //DATA , BILL 
	cout<<"4. EQUIPMENTS"<<endl; //EQIPMENTS AVAILABLE,
    cout<<"5. EXIT"<<endl;
	cout<<endl;

	
	int ch;
	cin>>ch;
	if(ch==1){
		Doctavl <string>a1;
		int n;
			cout<<"press 9 for checking availability of doctors on duty or 8 for non availability"<<endl;
			cin>>n;
			if(n==9){
				a1.showd();
			}
			else if(n==8){
				a1.showd(4,5);
			}
			
			
		cout<<"\n"<<endl;
	}
	else if(ch == 2){
		Cotr c;
		c.showdt();
		cout<<"\n"<<endl;
	}
    else if(ch == 3){
		Ptntbill <int> p;
		int n;
		cout<<"\n\n press 1 for getting patients detail and 2 for adding patients detail"<<endl;
		cin>>n;
		if(n==1){
		    int n;
			p.ptntdisp();
		}
		else if(n==2){
			addptnt(p);
		}
		else{
			cout<<"wrong choice"<<endl;
			break;
		}
		cout<<"\n"<<endl;
	}
    else if(ch == 4){
			Equip e;
			e.showd();
			cout<<"\n"<<endl;
	}	
	else if(ch == 5){
		exit(0);
	}	
	else{
		goto start;
	}
}
	return 0;
}

