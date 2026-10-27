class Solution {
    public String[] createGrid(int m, int n) {
        String[] grid = new String[m];

        for(int i = 0; i<m; i++){
            StringBuilder row = new StringBuilder();
            for(int j = 0; j<n; j++){
                if(i==m-1 || j== 0){
                    row.append('.') ;
                    continue;
                }
                row.append('#');
            }
            grid[i] = row.toString();
        }

        return grid;
    }
}