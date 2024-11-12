class Solution {
public:
   void dfs(int node , vector<int> &visitado , vector<vector<int>> &salas )
   {
       visitado[node] = 1 ;
       for( auto c : salas[node])
       {
           if( !visitado[c])
           {
               dfs(c,visitado,salas);
           }
       }
   }

    bool visitarTodasSalas(vector<vector<int>>& salas) {
        
        vector<int> visitado(salas.size());
        dfs(0,visitado ,salas);
        for( int i = 0 ; i < salas.size() ; ++i )
        {
            if( visitado[i] == 0 )
            return false;
        }
        return true;

    }
};