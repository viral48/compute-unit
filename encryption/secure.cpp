#include<iostream>
#include<string>
#include<vector>
using namespace std;

class encrypt{
    public:
    string plaintext;
    string output;

    vector<int> key;
    int s[256];

  encrypt(string masterkey,string plaintext){
        this->plaintext=plaintext;
        this->output=plaintext;
        for(int i=0;i<masterkey.length();i++){
            this->key.push_back(masterkey[i]);
        }

    key_schedule(key);
    get_encrypt();
  }

  void key_schedule(vector<int> &key);
  void get_encrypt();

};


void encrypt:: key_schedule(vector<int> &key){

    int temp[256];
   // cout<<"start";

    for(int i=0;i<256;i++){
            s[i]=i;
            temp[i]=key[i%key.size()];
           // cout<<i<<" "<<t[i]<<endl;
    }

    int j=0;

    for(int i=0;i<256;i++){
        j=(j+s[i]+temp[i])%256;
        swap(s[i],s[j]);
    }

    for(int i=0;i<256;i++){
       // cout<<i<<" "<<s[i]<<endl;
    }

}

void encrypt:: get_encrypt(){
    int i=0,j=0,k=0;

    for(int len=0;len<plaintext.length();len++){
        i=(i+1)%256;
        j=(j+s[i])%256;
        swap(s[i],s[j]);
        k=s[ (s[i]+s[j]) %256];
        output[len]^=k;
        
    }
}




