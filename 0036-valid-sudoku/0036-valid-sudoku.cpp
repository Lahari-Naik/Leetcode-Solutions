class Solution {
public:
    bool row(int m, int n, vector<vector<char>>& b)
    {
        for(int j=0;j<9;j++)
        {
            if(j!=n && b[m][j] == b[m][n])
            {
                return false;
            }
        }
        return true;
    }
    bool colomn(int m, int n, vector<vector<char>>& b)
    {
        for(int i=0;i<9;i++)
        {
            if(i!=m && b[i][n] == b[m][n])
            {
                return false;
            }
        }
        return true;
    }
    bool grid(int m, int n, vector<vector<char>>& b)
    {
        if(m<=2)
        {
            if(n<=2)
            {
                for(int i=0;i<=2;i++)
                {
                    for(int j=0;j<=2;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else if(n>2 && n<=5)
            {
                for(int i=0;i<=2;i++)
                {
                    for(int j=3;j<=5;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else
            {
                for(int i=0;i<=2;i++)
                {
                    for(int j=6;j<9;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        else if(m>2 && m<=5)
        {
            if(n<=2)
            {
                for(int i=3;i<=5;i++)
                {
                    for(int j=0;j<=2;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else if(n>2 && n<=5)
            {
                for(int i=3;i<=5;i++)
                {
                    for(int j=3;j<=5;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else
            {
                for(int i=3;i<=5;i++)
                {
                    for(int j=6;j<9;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        else
        {
            if(n<=2)
            {
                for(int i=6;i<9;i++)
                {
                    for(int j=0;j<=2;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else if(n>2 && n<=5)
            {
                for(int i=6;i<9;i++)
                {
                    for(int j=3;j<=5;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
            else
            {
                for(int i=6;i<9;i++)
                {
                    for(int j=6;j<9;j++)
                    {
                        if(i!=m && j!=n && b[m][n]==b[i][j])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(isdigit(b[i][j]))
                {
                    if(!row(i,j,b))
                    {
                        return false;
                    }
                    else if(!colomn(i,j,b))
                    {
                        return false;
                    }
                    else if(!grid(i,j,b))
                    {
                        return false;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return true;
    }
};