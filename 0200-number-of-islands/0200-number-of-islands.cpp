class Solution {
    
    private :
    
    void bfs(int i , int j , vector<vector<bool>> &visited , vector<vector<char>> &grid){
        
                          int m = grid.size();
                          int n = grid[0].size();
                        queue<pair<int,int>> q;
                        visited[i][j] = 1;
                        pair<int,int> p;
                        p.first = i;
                        p.second = j;
                        q.push(p);
                    
        int dx[] = {-1,+1,0,0};
        int dy[] = {0,0,+1,-1};
        
                        while(!q.empty()){
                            
                           int row  = q.front().first;
                           int col = q.front().second; 
                           q.pop();
                            
                            // traverse its neighbour
                                for(int i = 0 ;i < 4;  i++){
                                  int  neighRow = row + dx[i];
                                  int  neighCol = col + dy[i];
                                    
                                      if(neighRow >=0 && neighRow < m
                                      && neighCol >=0 && neighCol < n
                                      && !visited[neighRow][neighCol]
                                      && grid[neighRow][neighCol] == '1'
                                      ){
                                        // cout<<neighRow<<" "<<neighCol<<endl;
                                        q.push({neighRow , neighCol});
                                        visited[neighRow][neighCol] = 1;
                                    }
                                }
                            
                        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
            
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n , 0));
        int ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(!visited[i][j] &&  grid[i][j] == '1'){   
                    // it means that this is my starting point
                    bfs(i,j,visited,grid);  
                   ans++;
                }
            }
        }
        return ans;
    }
};