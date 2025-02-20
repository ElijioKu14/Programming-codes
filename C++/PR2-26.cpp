#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n; //repeat times
    for(int i=0; i<n; i++)
    {
        int r, c, r_s, c_s, start_r, start_c, commend_count = 0;
        //r=row index
        //c=column index
        //r_s and c_s size of maze
        //start_r, c = start point
        cin >> r_s >> c_s >> start_r >> start_c;
        int commend[2][r_s*c_s-1]; //commend times = r_s*c_s-1
        char maze[r_s+1][c_s*2+1];

        commend[0][0] = start_r; //set starting point
        commend[1][0] = start_c;

        for(r=0; r<r_s+1; r++){  //generate maze
            for(c=0; c<c_s*2+1; c++){
                if(r == 0){
                    if((c+1) % 2 == 0){ // priority (% > +)
                        maze[r][c] = '_';
                    }else{
                        maze[r][c] = ' ';
                    }
                }else{
                    if((c+1) % 2 != 0)
                        maze[r][c] = '|';
                    else
                        maze[r][c] = '_';
                }
            }
        }                        //generate maze

        int flag_y = start_r, flag_x = start_c;
        int temp=1;
        while(1)
        {
            char order; //input commend
            if(commend_count == r_s*c_s-1)
                break;
            cin >> order;
            if(order == 'U'){
                commend_count++;
                maze[r_s - flag_y][flag_x*2-1] = ' ';//break wall
                flag_y += 1;
                commend[0][temp] = flag_y;
                commend[1][temp] = flag_x;
                temp++;
                continue;
            }
            if(order == 'D'){
                commend_count++;
                maze[r_s - flag_y + 1][flag_x*2-1] = ' ';
                flag_y -= 1;
                commend[0][temp] = flag_y;
                commend[1][temp] = flag_x;
                temp++;
                continue;
            }
            if(order == 'L'){
                commend_count++;
                maze[r_s - flag_y + 1][(flag_x*2-1) - 1] = ' ';
                flag_x -= 1;
                commend[0][temp] = flag_y;
                commend[1][temp] = flag_x;
                temp++;
                continue;
            }
            if(order == 'R'){
                commend_count++;
                maze[r_s - flag_y + 1][(flag_x*2-1) + 1] = ' ';
                flag_x += 1;
                commend[0][temp] = flag_y;
                commend[1][temp] = flag_x;
                temp++;
                continue;
            }
            if(order == 'F'){//flip from last to F, = come back to the fork
                int F_temp;
                cin >> F_temp;
                flag_y = commend[0][commend_count - F_temp];
                flag_x = commend[1][commend_count - F_temp];
            }
        }

        for(c=0; c<c_s*2; c++) //print maze, ignored last space
            cout << maze[0][c];
        cout <<endl;

        for(r=1; r<r_s+1; r++){
            for(c=0; c<c_s*2+1; c++){
                cout << maze[r][c];
            }
            cout <<endl;
        }
        cout <<endl;           //print maze
    }
    return 0;
}