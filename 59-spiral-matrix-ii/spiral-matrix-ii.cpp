class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int dir=0;

        int top=0;
        int down = n-1;

        int left = 0;
        int right = n-1;

        int count = 1;


        /*
            dir 0: left to right
            dir 1: top to down
            dir 2: right to left
            dir 3: down to top
        */

        vector<int> result;

        while(top<=down && left<=right){
            if(dir == 0){
                for(int i=left;i<=right;i++){
                    matrix[top][i] = count;
                    count++;
                }
                top++;
            }

            if(dir == 1){
                for(int i=top;i<=down;i++){
                    matrix[i][right] = count;
                    count++;
                }
                right--;
            }

            if(dir == 2){
                for(int i=right;i>=left;i--){
                    matrix[down][i] = count;
                    count++;
                }
                down--;
            }

            if(dir == 3){
                for(int i=down;i>=top;i--){
                    matrix[i][left] = count;
                    count++;
                }
                left++;
            }

            dir++;
            if(dir == 4) dir = 0;
        }

        return matrix;
    }
};