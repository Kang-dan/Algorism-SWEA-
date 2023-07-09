/* 1974. 스도쿠 검증
스도쿠는 숫자퍼즐로, 가로 9칸 세로 9칸으로 이루어져 있는 표에 1 부터 9 까지의 숫자를 채워넣는 퍼즐이다.

같은 줄에 1 에서 9 까지의 숫자를 한번씩만 넣고, 3 x 3 크기의 작은 격자 또한, 1 에서 9 까지의 숫자가 겹치지 않아야 한다.
입력으로 9 X 9 크기의 스도쿠 퍼즐의 숫자들이 주어졌을 때, 위와 같이 겹치는 숫자가 없을 경우, 1을 정답으로 출력하고 그렇지 않을 경우 0 을 출력한다.

[제약 사항]
1. 퍼즐은 모두 숫자로 채워진 상태로 주어진다.
2. 입력으로 주어지는 퍼즐의 모든 숫자는 1 이상 9 이하의 정수이다.

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.
테스트 케이스는 9 x 9 크기의 퍼즐의 데이터이다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

#include <stdio.h>
int num[10][10];

int check1(int i){
    int num_check[9] = {0}; //겹치는 숫자 확인
    for(int j=0; j<9; j++){
        num_check[num[i][j]-1]++;
        if(num_check[num[i][j]-1] > 1){
            return 1;
        }
    }
    return 0;
}

int check2(int j){
    int num_check[9] = {0};
    for(int i=0; i<9; i++){
        num_check[num[i][j]-1]++;
        if(num_check[num[i][j]-1] >1){
            return 1;
        }
    }
    return 0;
}

int check3(int i){
    int a=0, k=i;
    for(int count=0; count<3; count++){
        int num_check[9] = {0};
        for(; i<k+3; i++){
            for(int j=a; j<a+3; j++){
                num_check[num[i][j]-1]++;
                if(num_check[num[i][j]-1] > 1){
                    return 1;
                }
            }
        }
        a+=3;
        i=k;
    }
    return 0;
}

int main(){
    int T, Test_case, i, j;
    scanf("%d", &T);
    for(Test_case=1; Test_case<=T; Test_case++){

        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                scanf("%d", &num[i][j]);
            }
        }

        int flag = 0;
        //가로줄 확인
        for(i=0; i<9; i++){
            if(check1(i) == 1){ //겹치는 숫자 있음
                flag = 1;
                printf("#%d 0\n", Test_case);
                break;
            }
        }
        if(flag == 1) continue;

        //세로줄 확인
        for(j=0; j<9; j++){
            if(check2(j) == 1){ //겹치는 숫자 있음
                flag = 1;
                printf("#%d 0\n", Test_case);
                break;
            }
        }
        if(flag == 1) continue;

        //정사각형 확인
        for(i=0; i<9; i++){
            if(i==0 || i==3 || i==6){
                if(check3(i) == 1){ //겹치는 숫자 있음
                    flag = 1;
                    printf("#%d 0\n", Test_case);
                    break;
                }
            }
        }
        if(flag == 1) continue;

        printf("#%d 1\n", Test_case);

    }
    return 0;
}