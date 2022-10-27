#include"knight.h"

bool isAvailable(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos){

    bool safe = true;
    if(x_pos < 1 || x_pos > TABLE_SIZE){
        safe = false;
    }
    if(y_pos < 1 || y_pos > TABLE_SIZE){
        safe = false;
    }    
    if(path[x_pos][y_pos] != -1){
        safe = false;
    }
    return safe;

}


bool knightTour(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos, int32_t x_move[], int32_t y_move[], int32_t step_cnt){
    
    //bool done = false;
    if(step_cnt >= TABLE_SIZE * TABLE_SIZE){
        //done = true;
        return 1;
    }
    else{
        
        for(int32_t i = 0; i < 8; i++){
        
            int32_t x_next = x_pos + x_move[i];
            int32_t y_next = y_pos + y_move[i];
            
            if(isAvailable(path, x_next, y_next)){
                path[x_next][y_next] = step_cnt;
                if(knightTour(path, x_next, y_next, x_move, y_move, step_cnt + 1)){
                    return 1;
                    //done = true;
                    //break;
                }
                //else{
                    path[x_next][y_next] = -1;
                    
                //}            
            }
                        
        }
    
    }
    return 0;
    //return done;
}



bool putKnight(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos){

    int32_t x_move[] = {2,1,-2,-1,-1,-2,1,2};
    int32_t y_move[] = {1,2,1,2,-2,-1,-2,-1};   
    int32_t step_cnt = 1;
    bool done = false;
    
    
    for(int32_t i = 1; i <= TABLE_SIZE; i++){
        for(int32_t j = 1; j <= TABLE_SIZE; j++){
            path[i][j] = -1;
        }
    }
    
    path[x_pos][y_pos] = 0;
    
    if(knightTour(path, x_pos, y_pos, x_move, y_move, step_cnt)){
        done = true;
        printf("putKnight");
    }    
      
    return done;
    
}



int main(){

    int32_t path[TABLE_SIZE+1][TABLE_SIZE+1];
    
    if(putKnight(path, 1, 1))
        for(int32_t i = 1; i <= TABLE_SIZE; i++){
            for(int32_t j = 1; j <= TABLE_SIZE; j++){
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}
