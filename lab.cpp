#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str1,key1;
    cout << "vigenere cipher" << endl;

    int col,row;
    col = row = 62;
    char temp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";


    char mat[col][row];



    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            mat[i][j]= 0;

        }
    }

    int key =0,key2=0;
    int cnt=0;
    for(int i=0;i<col;i++){


    key=i;
        for(int j=0;j<row;j++){

            mat[i][j] = temp[key%62];

             key++;
        }

    }



    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << " " << mat[i][j];
        }
        cout<<" "<<endl;
    }


    cout<<endl<<endl;
    cout << "Enter alphanumeric plaintext: " << endl;
    cin >> str1;
    cout << "Enter the key: "<<endl;
    cin >> key1;

    cout << "Encrypted text is: "<<endl;
    int k=0,i=0;
    string  encrypt_result="";
    string  decrypt_result="";
    int p,q;
    while( str1[i]!= 0){

        //for selecting coloumn
        if(str1[i]>='A' && str1[i]<='Z'){
            q = (str1[i]-'A')+1;
        }
        else if(str1[i]>='a' && str1[i]<='z'){
             q = (str1[i]-'a')+1+26;
        }
        else if(str1[i]>='0' && str1[i]<='9'){
             q = (str1[i]-'0')+1+52;
        }

        //for selecting row
        if(key1[k%(key1.length())]>='A' && key1[k%(key1.length())]<='Z'){
            p = key1[k%(key1.length())]-'A';

        }
        else if(key1[k%(key1.length())]>='a' && key1[k%(key1.length())]<='z'){
             p = (key1[k%(key1.length())]-'a');

        }
        else if(key1[k%(key1.length())]>='0' && key1[k%(key1.length())]<='9'){
             p = (key1[k%(key1.length())]-'0');

        }

    encrypt_result+=mat[p][q];

    i++;
    k++;
    }

    cout<< encrypt_result<<endl;

    //decryption ..............!!
    cout<< "Decryption result is: "<<endl;

     i=0;k=0;
    while(encrypt_result[i]!=0){

        if(encrypt_result[i]>='A' && encrypt_result[i]<='Z'){
            q = (encrypt_result[i]-'A')+1;
        }
        else if(encrypt_result[i]>='a' && encrypt_result[i]<='z'){
            q = (encrypt_result[i]-'a')+1-26-2;
        }
        else if(encrypt_result[i]>='0' && encrypt_result[i]<='9'){
            q = (encrypt_result[i]-'0')+1-52-2;
        }
        ////////////////
        if(encrypt_result[i]>='A' && encrypt_result[i]<='Z'){
             p = 60-(key1[k%(key1.length())]-'A');
        }
        else if(encrypt_result[i]>='a' && encrypt_result[i]<='z'){
             p = 60-(key1[k%(key1.length())]-'a');
        }
        else if(encrypt_result[i]>='0' && encrypt_result[i]<='9'){
            p = 60 -(key1[k%(key1.length())]-'0');
        }

     i++;
    k++;
    decrypt_result+=mat[p][q];
    }
    cout<< decrypt_result <<endl;
    return 0;
}