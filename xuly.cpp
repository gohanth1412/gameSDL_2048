#include "xuly.h"
#include <cstdlib>
#include <ctime>

//sinh so 2 hoac 4
int randomNumber(){
    srand(time(NULL));
    int a = rand() % 20; //random tu 0 den 19
    if(a != 0) return 2;
    else return 4;
}


void randomvitri( int a[6][6]){
    srand(time(NULL));
    int x, y;
    do{
        x=rand() % 4 + 1; // cộng 1 để lấy x [1,4]
        y=rand() % 4 + 1;
    }while(a[x][y] != 0); //tìm ô còn trống
    a[x][y] = randomNumber();
    
}

void left(int a[6][6], int n){
    int b=0; // kiểm tra xem có gộp ô không
    int r=0; // số lượng ô còn trống

    //tính số lượng ô trống theo mỗi hàng
    for(int k=1; k<n-1; k++){
        for(int m=4; m>0; m--){
            if(a[k][m] != 0){
                for(int l=m-1; l>0; l--){ // kiểm tra ô bên trái
                    if(a[k][l] == 0) r++;
                }
            }
        }
    }
    //don cac so ve dieu huong sang trai
    for(int k=1; k<n-1; k++){
        for(int m=1; m<n-1; m++){
            if(a[k][m]==0){
                int e=m+1; 
                while(a[k][e] == 0 && e < 5){ // tìm ô số đầu tiên khác 0 bên phải của ô trống [k][m]
                    e++;
                }
                a[k][m]=a[k][e]; // ô trống đc gán giá trị số khác 0
                a[k][e]=0; // gán giá trị 0 chô ô số
            }
        }
    }

    //kiểm tra xem có thể cộng các số ở hàng hiện tại không
    for(int k=4; k>0; k--){
        for(int i=1; i<4; i++){
            if(a[k][i] == a[k][i+1] && a[k][i] != 0){
                b++;
            }
        }
    }

    //cong don cac so sang trai và thêm một phần tử vào chỗ trống
    if( b != 0){
        for(int k=1; k<n-1; k++){
            for(int i=1; i<=n-2; i++){
                if(a[k][i]==a[k][i+1]){
                    a[k][i]=a[k][i]*2;
                    for(int j=i+1; j<n-1; j++){
                        a[k][j]=a[k][j+1]; // đổi chỗ các ô sang bên trái
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b == 0){
        if(r != 0){
            randomvitri(a);
        }
    }
}

void right(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=1; m<5; m++){
            if(a[k][m] != 0){
                for(int l=m+1; l<5; l++){
                    if(a[k][l] == 0) r++;
                }
            }
        }
    }
    for(int k=4; k>0; k--){
        // don cac so ve dieu huong sang phai
        for(int m=4; m>0; m--){
            if(a[k][m]==0){
                int e=m-1;
                while(a[k][e] == 0 && e>0){
                    e--;
                }
                a[k][m]=a[k][e];
                a[k][e]=0;
                
                
            }
        }
    }
    for(int k=4; k>0; k--){
        for(int i=4; i>1; i--){
            if(a[k][i] == a[k][i-1] && a[k][i] != 0){
                b++;
            }
        }
    }
    //cong don cac so sang phai
    if(b != 0 ){
        for(int k=4; k>0; k--){
            for(int i=4; i>0; i--){
                if(a[k][i]==a[k][i-1]){
                    a[k][i]=a[k][i]*2;
                    for(int j=i-1; j>0; j--){
                        a[k][j]=a[k][j-1];
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if(b ==0){
        if(r != 0){
            randomvitri(a);
        }
    }
}

void up(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=4; m>0; m--){
            if(a[m][k] != 0){
                for(int l=m-1; l>0; l--){
                    if(a[l][k] == 0) r++;
                }
            }
        }
    }
    for(int k=1; k<n-1; k++){
        //don cac so ve huong dieu huong len tren
        for(int m=1; m<n-1; m++){
            if(a[m][k]==0){
                int e=m+1;
                while(a[e][k] == 0 && e<5){
                    e++;
                }
                a[m][k]=a[e][k];
                a[e][k]=0;
                
                
            }
        }
    }
    //cong don len tren
    for(int k=1; k<5; k++){
        for(int i=1; i<4; i++){
            if(a[i][k] == a[i+1][k] && a[i][k] !=0){
                b++;
            }
        }
    }
    if( b!=0){
        for(int k=1; k<n-1; k++){
            for(int i=1; i<=n-2; i++){
                if(a[i][k]==a[i+1][k]){
                    a[i][k]=a[i][k]*2;
                    for(int j=i+1; j<n-1; j++){
                        a[j][k]=a[j+1][k];
                        
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b==0 ){
        if(r != 0){
            randomvitri(a);
        }
    }
}

void down(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=1; m<5; m++){
            if(a[m][k] != 0){
                for(int l=m+1; l<5; l++){
                    if(a[l][k] == 0) r++;
                }
            }
        }
    }
    //don cac so ve huong dieu huong xuong
    for(int k=4; k>0; k--){
        for(int m=4; m>0; m--){
            if(a[m][k]==0){
                int e=m-1;
                while(a[e][k] == 0 && e>0){
                    e--;
                }
                a[m][k]=a[e][k];
                a[e][k]=0;
            }
        }
    }
    for(int k=1; k<5; k++){
        for(int i=4; i>1; i--){
            if(a[i][k] == a[i-1][k] && a[i][k] !=0){
                b++;
            }
        }
    }
    if( b!=0){
        // cong don cac so xuong
        for(int k=4; k>0; k--){
            for(int i=4; i>0; i--){
                if(a[i][k]==a[i-1][k]){
                    a[i][k]=a[i][k]*2;
                    for(int j=i-1; j>0; j--){
                        a[j][k]=a[j-1][k];
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b == 0 ){
        if( r != 0){
            randomvitri(a);
        }
    }
}
