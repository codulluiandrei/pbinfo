int nr_sa(int a[][100], int m, int n) {
    int sa = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            int min_lin, max_lin, min_col, max_col;
            min_lin = max_lin = min_col = max_col = a[i][j];
            for (int k = 0; k < n; k++) {
                if (a[i][k] > max_lin) max_lin = a[i][k];
                if (a[i][k] < min_lin) min_lin = a[i][k];
            } for (int k = 0; k < m; k++) {
                if (a[k][j] > max_col) max_col = a[k][j];
                if (a[k][j] < min_col) min_col = a[k][j];
            }
            if ((a[i][j] == min_col && a[i][j] == max_lin) || (a[i][j] == max_col && a[i][j] == min_lin)) sa++;
        } return sa;
}