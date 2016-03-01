#include <iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main()
{
    string data;

    cout << "Enter data : " << endl;
    cin >> data ;
    int i=0,val=0;
    char ch;
    int j=0,k=0;
    int mat1[3];
    int row=3;int col=3;
    int key_mat[row][col];
    int inverse_mat[row][col];

    while(i < data.length() && i<3){

        ch = data[i];
        cout<< ch <<endl;

        val = ch - 97;
        mat1[i]= val;
        cout<< val <<endl;
        i++;
    }

    for(i=0;i<3;i++){

            cout <<" "<<mat1[i];

    }
    cout << endl;
    // Accept key matrix...!
    cout << "Accept key matrix" <<endl;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){

            cin >> key_mat[i][j];
        }

    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){

            cout <<" "<<key_mat[i][j] ;
        }
        cout<<endl;

    }
    int encrypt_arr[3],final_encrypt[3];
    int decrypt_arr[3],final_decrypt[3];
    //Matrix Multiplication
    for(i=0;i<3;i++){

        encrypt_arr[i] = mat1[0]*key_mat[0][i] + mat1[1]*key_mat[1][i] +  mat1[2]*key_mat[2][i];

    }

    char ch_arr[3];
    for(i=0;i<3;i++){

                final_encrypt[i] = (encrypt_arr[i]%26);
                cout <<" "<<final_encrypt[i];
    }
    cout<<endl;

    for(i=0;i<3;i++){

                final_encrypt[i]=final_encrypt[i]+97;
                ch_arr[i] = (char)final_encrypt[i];
                cout <<" "<<ch_arr[i];
    }
    cout<<endl;

    //process to calculate inverse

    inverse_mat[0][0] = pow(-1,0)*(key_mat[1][1]*key_mat[2][2] - key_mat[2][1]*key_mat[1][2]);
    inverse_mat[0][1] = pow(-1,1)*(key_mat[0][1]*key_mat[2][2] - key_mat[2][1]*key_mat[0][2]);
    inverse_mat[0][2] = pow(-1,2)*(key_mat[0][1]*key_mat[1][2] - key_mat[1][1]*key_mat[0][2]);

    inverse_mat[1][0] = pow(-1,1)*(key_mat[1][0]*key_mat[2][2] - key_mat[2][0]*key_mat[1][2]);
    inverse_mat[1][1] = pow(-1,2)*(key_mat[0][0]*key_mat[2][2] - key_mat[2][0]*key_mat[0][2]);
    inverse_mat[1][2] = pow(-1,3)*(key_mat[0][0]*key_mat[1][2] - key_mat[1][0]*key_mat[0][2]);

    inverse_mat[2][0] = pow(-1,2)*(key_mat[1][0]*key_mat[2][1] - key_mat[2][0]*key_mat[1][1]);
    inverse_mat[2][1] = pow(-1,3)*(key_mat[0][0]*key_mat[2][1] - key_mat[2][0]*key_mat[0][1]);
    inverse_mat[2][2] = pow(-1,4)*(key_mat[0][0]*key_mat[1][1] - key_mat[1][0]*key_mat[0][1]);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cout<<" "<< inverse_mat[i][j];
        }
        cout<<endl;
    }

    int det_val;
    int new_det_val;

    det_val = (key_mat[0][0]*(key_mat[1][1]*key_mat[2][2] - key_mat[2][1]*key_mat[1][2])-(key_mat[0][1]*(key_mat[1][0]*key_mat[2][2] - key_mat[2][0]*key_mat[1][2]))+key_mat[0][2]*(key_mat[1][0]*key_mat[2][1] - key_mat[2][0]*key_mat[1][1]));
    cout<< det_val<<endl;

    if(det_val < 0){
        det_val = det_val%26;
        det_val += 26;
    }

    cout<<"new val: " <<det_val<<endl;
    int x;

    for(x=1;x<26;x++){
       if((det_val*x)%26==1){
            break;
        }
    }

    new_det_val = x;
    cout<<"new val x: " <<new_det_val<<endl;

//mu;tiply by x
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            inverse_mat[i][j] =(inverse_mat[i][j] * new_det_val)%26;
        }
    }

    for(i=0;i<3;i++){

        decrypt_arr[i] = (final_encrypt[0]*inverse_mat[0][i] + final_encrypt[1]*inverse_mat[1][i] +  final_encrypt[2]*inverse_mat[2][i])%26;

    }

    char ch_arr1[3];

    for(i=0;i<3;i++){

                final_decrypt[i]=final_decrypt[i]+97;
                ch_arr1[i] = (char)final_decrypt[i];
                cout <<" "<<ch_arr1[i];
    }
    cout<<endl;

     // cout<< new_det_val <<endl;
    return 0;
}
