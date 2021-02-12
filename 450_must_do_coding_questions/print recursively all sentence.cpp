void printUtil(string arr[R][C], int m, int n, string output[R])
{
    output[m] = arr[m][n];
    if (m==R-1)
    {
        for (int i=0; i<R; i++)
           cout << output[i] << " ";
        cout << endl;
        return;
    }
    for (int i=0; i<C; i++)
       if (arr[m+1][i] != "")
          printUtil(arr, m+1, i, output);
}
void print(string arr[R][C])
{
   string output[R];
   for (int i=0; i<C; i++)
     if (arr[0][i] != "")
        printUtil(arr, 0, i, output);
}