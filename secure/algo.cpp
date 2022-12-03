#include<iostream>
#include<string>
#include<vector>
using namespace std;

class encrypt{
    protected:
 
 
    string plaintext;   //Original string
    string output;      //Encrypted string

    unsigned char checksum;
    vector<int> key;        // vector of Master key
    int s[256];              // array of Algorithm generated key

    // algorithm works in two parts

  void key_schedule(vector<int> &key);       //1. Getting  algorithm genrated Key in array s 
  void get_encrypt();                         //2. Using generated key apply operation on string
  void add_checksum();                         // Add the checksum value at the end of the encrypted output

 public:
  encrypt()=default;
   encrypt(string masterkey,string plaintext){
        this->plaintext=plaintext;
        this->output=plaintext;

        // coverting master key string to int vector of master key
        for(int i=0;i<masterkey.length();i++){
            this->key.push_back(masterkey[i]);
        }

    key_schedule(key);
    get_encrypt();
    add_checksum();
  }

  string  get_output(){             // Returns the encrypted or decrypted string
    return output;
   }


};

class decrypt : public encrypt{
    public:
    decrypt(string masterkey,string plaintext) {
            this->plaintext=plaintext;
            this->output=plaintext;
            for(int i=0;i<masterkey.length();i++){
                this->key.push_back(masterkey[i]);
            }
            add_checksum();                 // checksum value of the received message is added at the end
            rm_checksum();                  // checksum value is removed to decrypt message
            key_schedule(key);              // decryption done with the same method as encryption
            get_encrypt();                      



    }
    bool check_checksum(){
        return (checksum==0)?true:false;
    }

    void rm_checksum(){
        if(output.size()!=0){
            output.erase(output.size()-1);
            output.erase(output.size()-1);
        }
    }

};


void encrypt:: key_schedule(vector<int> &key){

    int temp[256];
   
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

// string encrypt:: get_output(){
//     return output;
// }


void encrypt:: add_checksum(){
    vector<unsigned char> text(output.length());
    
    for(int i=0;i<output.size();i++){
        text[i]=output[i];
    }
    
    int sum=0;
  // algorithm for checksum
    for(int i=0;i<output.length();i++){
    
        if(sum+text[i]>255){
    
            sum+=text[i];
    
            sum=sum^(1<<8);
            sum+=1;
    
        }
        else{
        sum+=text[i];
    
        }
        
    }
    
    for(int i=0;i<8;i++){
       sum^=(1<<i);
    }
     checksum=sum;
    output+=checksum;

    //
      
}


