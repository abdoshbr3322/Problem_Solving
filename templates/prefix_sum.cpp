vvi prefix_sum_2d(vvi &a) {
   int n = a.size();
   int m = a[0].size();
   vvi prefix(n+1, vi(m+1, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i+1][j] + a[i][j];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i][j+1];
      }
   }

   return prefix;
}

// for 1 based
int rect_sum(int x1, int y1, int x2, int y2, vvi &p) {
   return (p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1]);
}
// for 0 based
// int rect_sum(vvi& prefix, int x1, int y1, int x2, int y2) {
//    int sum = prefix[x2][y2];
//    if (y1 > 0) sum -= prefix[x2][y1-1];
//    if (x1 > 0) sum -= prefix[x1-1][y2];
//    if (x1 > 0 && y1 > 0) sum += prefix[x1-1][y1-1];
//    return sum;
// }