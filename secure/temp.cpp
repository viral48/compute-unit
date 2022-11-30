#include "algo.cpp"

int main(){
    encrypt temp1("123456","project is related to distributed system");
     for(int i=0;i<temp1.output.length();i++) cout<<i<<"="<<temp1.output[i]<<"    ";
     cout<<temp1.output[3]<<"#"<<endl;
     cout<<endl;
    cout<<temp1.output<<endl;
    cout<<endl;

    decrypt temp2("123456",temp1.output);
    cout<<temp2.output<<endl;

    return 0;
}