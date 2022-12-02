#include "algo.cpp"
#include<algorithm>
//int checksum(string);
int main(){

    
encrypt obj1("1234","Our project is about distributed system.");

cout<<"size of the encrypted message with checksum"<<" = "<<obj1.output.size()<<endl;
cout<<"Encrypted message:---->    "<<obj1.get_output()<<endl;
//obj1.output="Our project is about distributed system.";
decrypt obj2("1234",obj1.output);


cout<<"size of the decrypted message after removing checksum"<<" = "<<obj2.output.size()<<endl;

if(obj2.check_checksum()){
    cout<<"Decrypted message:---->    "<<obj2.get_output()<<endl;
}
else{
    cout<<"Message is altered:";
}

    return 0;
}

